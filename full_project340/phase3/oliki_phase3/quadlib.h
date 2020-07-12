#include <assert.h>
#include "SymTable.h"

unsigned total = 0;
unsigned int currQuad = 0;
unsigned programVarOffset = 0;
unsigned functionLocalOffset = 0;
unsigned formalArgOffset = 0;
unsigned scopeSpaceCounter = 1;
unsigned tempcounter = 0;


#define EXPAND_SIZE 1024
#define CURR_SIZE   (total*sizeof(quad))
#define NEW_SIZE    (EXPAND_SIZE*sizeof(quad) + CURR_SIZE)

typedef enum iopcode{
    assign,         add,            sub,
    mul,            div_,           mod,
    uminus,         and,            or,
    not,            if_eq,          if_noteq,
    if_lesseq,      if_greatereq,   if_less,
    if_greater,     call,           param,
    ret,            getretval,      funcstart,
    funcend,        tablecreate,    jump,
    tablegetelem,   tablesetelem
}iopcode;

typedef enum expr_t{
    var_e,
    tableitem_e,

    programfunc_e,
    libraryfunc_e,

    arithexpr_e,
    boolexpr_e,
    assignexpr_e,
    newtable_e,

    constnum_e,
    constbool_e,
    conststring_e,

    nil_e
}expr_t;

typedef struct expr{
    expr_t type;
    symrec_t* sym;
    struct expr * index;
    double numConst;
    char * charConst;
    unsigned char boolConst;
    struct expr * next;
}expr;

expr * tmp_expr;

typedef struct quad{
    iopcode op;
    expr * result;
    expr * arg1;
    expr * arg2;
    unsigned label;
    unsigned line;
}quad;

quad * quads = (quad*) 0;

typedef struct forVar{
    unsigned test;
    unsigned enter;
}forVar;


void expand(){
    assert(total == currQuad);
    quad * p = (quad*)malloc(NEW_SIZE);
    if(quads){
        memcpy(p, quads, CURR_SIZE);
        free(quads);
    }
    quads = p;
    total += EXPAND_SIZE;
}

unsigned int istempname(char * s){
    return *s == '_';
}

void emit(iopcode op, expr * result, expr * arg1, expr * arg2, unsigned label, unsigned line){
    if(currQuad == total){
        expand();
    }
    quad * p    = quads + currQuad++;
    if(arg1!= NULL && arg1->sym != NULL && istempname(arg1->sym->name)){ arg1->charConst = arg1->sym->name;}
    p->arg1     = arg1;
    if(arg2!= NULL && arg2->sym != NULL && istempname(arg2->sym->name)){ arg2->charConst = arg2->sym->name;}
    
    p->arg2     = arg2;
    p->op       = op;
    p->result   = result;
    p->label    = label;
    p->line     = line;
    
}

scopespace_t currscopespace(){
    if(scopeSpaceCounter == 1){
        return programvar;
    }else if(scopeSpaceCounter % 2 == 0){
        return formalarg;
    }else{
        return functionlocal;
    }
}

unsigned currscopeoffset(){
    switch(currscopespace()){
        case programvar:
            return programVarOffset;
        case functionlocal:
            return functionLocalOffset;
        case formalarg:
            return formalArgOffset;
        default:
            assert(0);
    }
}

void inccurrscopeoffset(){
    switch(currscopespace()){
        case programvar:
            ++programVarOffset;
            break;
        case functionlocal:
            ++functionLocalOffset;
            break;
        case formalarg:
            ++formalArgOffset;
            break;
        default:
            assert(0);
    }
}

void enterscopespace(){
    ++scopeSpaceCounter;
}

void exitscopecounter(){
    assert(scopeSpaceCounter > 1);
    --scopeSpaceCounter;
}

void resetformalargsoffset(){
    formalArgOffset = 0;
}

void resetfunctionlocalsoffset(){
    functionLocalOffset = 0;
}

void restorecurrscopeoffset(unsigned n){
    switch(currscopespace()){
        case programvar:
            programVarOffset = n;
            break;
        case functionlocal:
            functionLocalOffset = n;
            break;
        case formalarg:
            formalArgOffset = n;
            break;
        default:
            assert(0);
    }
}

unsigned nextquadlabel(){
    return currQuad;
}

void patchlabel(unsigned quadNo, unsigned label){
    assert(quadNo < currQuad);
    //quads[quadNo].label = label;
    quads[quadNo].result->numConst = (float)label;
}

void patchBreakContinue(struct stacklist * s, int label){
    while(topstacklist(s)->next != NULL){
		patchlabel(topstacklist(s)->next->label, label);
		topstacklist(s)->next = topstacklist(s)->next->next;
	}
}

expr * lvalue_expr(symrec_t * sym){
    assert(sym);
    expr * e = (expr *)malloc(sizeof(expr));
    memset(e, 0, sizeof(expr));

    e->next = (expr *) 0;
    e->sym = sym;
    e->charConst = e->sym->name;

    switch (sym->type){
        case LOCALVAR:
            e->type = var_e;
            break;
        case GLOBAL:
            e->type = var_e;
            break;
        case FORMAL:
            e->type = var_e;
            break;
        case USERFUNC:
            e->type = programfunc_e;
            break;
        case LIBFUNC:
            e->type = libraryfunc_e;
            break;
        default:
            assert(0);
    }
    return e;
}

expr * newexpr(expr_t t){
    expr * e = (expr *)malloc(sizeof(expr));
    memset(e, 0, sizeof(expr));
    e->type = t;
    return e;
}

expr * newexpr_conststring(char * s){
    expr * e = newexpr(conststring_e);
    e->charConst = strdup(s);
    return e;
}

char * newtempname(){
    char * buffer;
    buffer = (char *)malloc(sizeof(char *));
    
    sprintf(buffer, "_t%d", tempcounter);
    tempcounter++;
    buffer = strndup(buffer, sizeof(buffer)); /*works*/
    return buffer;
}

symrec_t * newtemp(){
    char * name = newtempname();
    symrec_t * sym;
    sym = lookup(name, scope);
    if(sym == NULL){
        return insert(scope, 0, LOCALVAR, name); /*LOCAL VAR ??????????????/*/
    }else{
        return sym;
    }
    
}

expr * emit_iftableitem(expr * e){
    if(e->type != tableitem_e){
        return e;
    }else{
        expr * result = newexpr(var_e);
        result->sym = newtemp();
        emit(tablegetelem, result, e, e->index, currQuad, e->sym->line); /*!!!!!!!!!!!!!ta dyo teleutaia orismata*/
        return result;
    }
}


expr * member_item(expr * lvalue, char * name){
    lvalue = emit_iftableitem(lvalue);
    expr * item = newexpr(tableitem_e);
    item->sym = lvalue->sym;
    item->index = newexpr_conststring(name);
    return item;
}

expr * newexpr_constnum(double i){
    expr * e = newexpr(constnum_e);
    e->numConst = i;
    return e;
}

expr * newexpr_constbool(unsigned char i){
    expr * e = newexpr(constbool_e);
    e->boolConst = i;
    if(i == '1'){
        e->charConst = "\'true\'";
    }else{
        e->charConst = "\'false\'";
    }
    return e;
}

void comperror(char * format){
    printIntermediate = 1;
    fprintf(stderr, "ERROR, %s\n",format);
}

int validtype(expr * e, expr * e1){
    if(e->type == programfunc_e || e->type == libraryfunc_e || e->type == boolexpr_e || e->type == newtable_e || 
    e->type == constbool_e || e->type == conststring_e || e->type == nil_e ||
    e1->type == programfunc_e || e1->type == libraryfunc_e || e1->type == boolexpr_e || e1->type == newtable_e || 
    e1->type == constbool_e || e1->type == conststring_e || e1->type == nil_e){
        comperror("invalid arithmetic expresion!");
        return 0;
    }
    return 1;
}

expr_t returnType(expr * temp, expr * a, expr * b){

    if(a->type == constnum_e && a->type == constnum_e){
        return constnum_e;
    }
    return temp->type;
}

void checkuminus(expr * e){
    if(e->type == constbool_e || e->type == conststring_e || 
    e->type == nil_e || e->type == newtable_e || 
    e->type == programfunc_e || e->type == libraryfunc_e || e->type == boolexpr_e){
        comperror("Illegal expr to unary -");
    }
}



unsigned int istempexpr(expr * e){
    return e->sym && (e->sym->type == LOCALVAR ||  e->sym->type == GLOBAL) && istempname(e->sym->name);
}

symrec_t * returnTempName(expr * expr1, expr * expr3){
    if(expr1 != NULL && istempexpr(expr1)){
		return expr1->sym;
	}else if(expr3 != NULL && istempexpr(expr3)){
		return expr3->sym;
	}else{
		return newtemp();
	}
}

void extraSets(symrec_t * sym){
    sym->space = currscopespace();
    sym->offset = currscopeoffset();
    inccurrscopeoffset();
}

expr * make_call(expr* lvalue, expr* elist, int line){
    expr* func = emit_iftableitem(lvalue);
    expr* result;
    while(elist != NULL){
        emit(param, elist, (expr*) 0, (expr*) 0, currQuad, line);
        elist = elist->next;
    }
    emit(call, func, (expr*) 0, (expr*) 0, currQuad, line);
    result = newexpr(var_e);
    result->sym = newtemp();
    emit(getretval, result, (expr*) 0, (expr*) 0, currQuad, line);
    return result;
}

void emitRelop(expr * result, expr * arg1, expr * arg2, iopcode op, int line){
    /*pername sto result toy emit ena neo expresion me numConst = nextquadlabel()+3 gia to "jump" tis entolis*/
    emit(op, newexpr_constnum(nextquadlabel()+3), arg1, arg2, currQuad,line);
    emit(assign, result, newexpr_constbool(0), (expr*) 0, currQuad, line);
    emit(jump, newexpr_constnum(nextquadlabel()+2), (expr*) 0, (expr*) 0, currQuad, line);
    emit(assign, result, newexpr_constbool(1), (expr*) 0, currQuad, line);
    
}

void printSetElem(int i, FILE * f){
    if((quads+i)->result->type == var_e || (quads+i)->result->type == arithexpr_e){
        if((quads+i)->arg2->type == var_e) {
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %s [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->sym->name, (quads+i)->line);
        }else if((quads+i)->arg2->type == constnum_e){
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %d [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (int)(quads+i)->arg2->numConst, (quads+i)->line);
        }else if((quads+i)->arg2->type == constbool_e){
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %c [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->boolConst, (quads+i)->line);
        }else if((quads+i)->arg2->type == conststring_e){
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %s [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->charConst, (quads+i)->line);
        }else{
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %s [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->charConst, (quads+i)->line);
        }
		
    }else if((quads+i)->result->type == constnum_e){
        if((quads+i)->arg2->type == var_e) {
            fprintf(f, "%d: TABLE_SET_ELEM %f %s %s [line: %d]\n", i, (quads+i)->result->numConst, (quads+i)->arg1->sym->name, (quads+i)->arg2->sym->name, (quads+i)->line);
        }else if((quads+i)->arg2->type == constnum_e){
            fprintf(f, "%d: TABLE_SET_ELEM %f %s %d [line: %d]\n", i, (quads+i)->result->numConst, (quads+i)->arg1->sym->name, (int)(quads+i)->arg2->numConst, (quads+i)->line);
        }else if((quads+i)->arg2->type == constbool_e){
            fprintf(f, "%d: TABLE_SET_ELEM %f %s %c [line: %d]\n", i, (quads+i)->result->numConst, (quads+i)->arg1->sym->name, (quads+i)->arg2->boolConst, (quads+i)->line);
        }else if((quads+i)->arg2->type == conststring_e){
            fprintf(f, "%d: TABLE_SET_ELEM %f %s %s [line: %d]\n", i, (quads+i)->result->numConst, (quads+i)->arg1->sym->name, (quads+i)->arg2->charConst, (quads+i)->line);
        }else{
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %s [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->charConst, (quads+i)->line);
        }
    }else if((quads+i)->result->type == constbool_e){
        if((quads+i)->arg2->type == var_e) {
            fprintf(f, "%d: TABLE_SET_ELEM %c %s %s [line: %d]\n", i, (quads+i)->result->boolConst, (quads+i)->arg1->sym->name, (quads+i)->arg2->sym->name, (quads+i)->line);
        }else if((quads+i)->arg2->type == constnum_e){
            fprintf(f, "%d: TABLE_SET_ELEM %c %s %d [line: %d]\n", i, (quads+i)->result->boolConst, (quads+i)->arg1->sym->name, (int)(quads+i)->arg2->numConst, (quads+i)->line);
        }else if((quads+i)->arg2->type == constbool_e){
            fprintf(f, "%d: TABLE_SET_ELEM %c %s %c [line: %d]\n", i, (quads+i)->result->boolConst, (quads+i)->arg1->sym->name, (quads+i)->arg2->boolConst, (quads+i)->line);
        }else if((quads+i)->arg2->type == conststring_e){
            fprintf(f, "%d: TABLE_SET_ELEM %c %s %s [line: %d]\n", i, (quads+i)->result->boolConst, (quads+i)->arg1->sym->name, (quads+i)->arg2->charConst, (quads+i)->line);
        }else{
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %s [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->charConst, (quads+i)->line);
        }
    }else if((quads+i)->result->type == conststring_e){
        if((quads+i)->arg2->type == var_e) {
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %s [line: %d]\n", i, (quads+i)->result->charConst, (quads+i)->arg1->sym->name, (quads+i)->arg2->sym->name, (quads+i)->line);
        }else if((quads+i)->arg2->type == constnum_e){
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %d [line: %d]\n", i, (quads+i)->result->charConst, (quads+i)->arg1->sym->name, (int)(quads+i)->arg2->numConst, (quads+i)->line);
        }else if((quads+i)->arg2->type == constbool_e){
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %c [line: %d]\n", i, (quads+i)->result->charConst, (quads+i)->arg1->sym->name, (quads+i)->arg2->boolConst, (quads+i)->line);
        }else if((quads+i)->arg2->type == conststring_e){
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %s [line: %d]\n", i, (quads+i)->result->charConst, (quads+i)->arg1->sym->name, (quads+i)->arg2->charConst, (quads+i)->line);
        }else{
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %s [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->charConst, (quads+i)->line);
        }
    }else{
        if((quads+i)->arg2->type == var_e) {
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %s [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->sym->name, (quads+i)->line);
        }else if((quads+i)->arg2->type == constnum_e){
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %d [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (int)(quads+i)->arg2->numConst, (quads+i)->line);
        }else if((quads+i)->arg2->type == constbool_e){
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %c [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->boolConst, (quads+i)->line);
        }else if((quads+i)->arg2->type == conststring_e){
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %s [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->charConst, (quads+i)->line);
        }else{
            fprintf(f, "%d: TABLE_SET_ELEM %s %s %s [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->charConst, (quads+i)->line);
        }
    }

}

void print_arith_exprs(char * op, int i, FILE * f){
    if((quads+i)->arg2->type == constnum_e && (quads+i)->arg1->type == constnum_e){
        fprintf(f, "%d: %s %s %f %f [line: %d]\n",i, op, (quads+i)->result->sym->name, (quads+i)->arg1->numConst, (quads+i)->arg2->numConst, (quads+i)->line);
    }else if((quads+i)->arg2->type == constnum_e){
        fprintf(f, "%d: %s %s %s %f [line: %d]\n",i, op, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->numConst, (quads+i)->line);
    }else if((quads+i)->arg1->type == constnum_e){
        fprintf(f, "%d: %s %s %f %s [line: %d]\n",i, op, (quads+i)->result->sym->name, (quads+i)->arg1->numConst, (quads+i)->arg2->sym->name, (quads+i)->line);
    }else{
        fprintf(f, "%d: %s %s %s %s [line: %d]\n",i, op, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->sym->name, (quads+i)->line);
    }
}

void print_and_or_exprs(char * op, int i, FILE * f){
    if((quads+i)->arg2->type == constnum_e && (quads+i)->arg1->type == constnum_e){
        fprintf(f, "%d: %s %s %f %f [line: %d]\n",i, op, (quads+i)->result->sym->name, (quads+i)->arg1->numConst, (quads+i)->arg2->numConst, (quads+i)->line);
    }else if((quads+i)->arg2->type == constnum_e){
        fprintf(f, "%d: %s %s %s %f [line: %d]\n",i, op, (quads+i)->result->sym->name, (quads+i)->arg1->charConst, (quads+i)->arg2->numConst, (quads+i)->line);
    }else if((quads+i)->arg1->type == constnum_e){
        fprintf(f, "%d: %s %s %f %s [line: %d]\n",i, op, (quads+i)->result->sym->name, (quads+i)->arg1->numConst, (quads+i)->arg2->charConst, (quads+i)->line);
    }else{
        fprintf(f, "%d: %s %s %s %s [line: %d]\n",i, op, (quads+i)->result->sym->name, (quads+i)->arg1->charConst, (quads+i)->arg2->charConst, (quads+i)->line);
    } 
}

void print_equal_exprs(char * op, int i, FILE * f){
    if((quads+i)->arg2->type == constnum_e && (quads+i)->arg1->type == constnum_e){
        fprintf(f, "%d: %s %d %f %f [line: %d]\n",i, op, (int)((quads+i)->result->numConst), (quads+i)->arg1->numConst, (quads+i)->arg2->numConst, (quads+i)->line);
    }else if((quads+i)->arg2->type == constnum_e){
        fprintf(f, "%d: %s %d %s %f [line: %d]\n",i, op, (int)((quads+i)->result->numConst), (quads+i)->arg1->charConst, (quads+i)->arg2->numConst, (quads+i)->line);
    }else if((quads+i)->arg1->type == constnum_e){
        fprintf(f, "%d: %s %d %f %s [line: %d]\n",i, op, (int)((quads+i)->result->numConst), (quads+i)->arg1->numConst, (quads+i)->arg2->charConst, (quads+i)->line);
    }else{
        fprintf(f, "%d: %s %d %s %s [line: %d]\n",i, op, (int)((quads+i)->result->numConst), (quads+i)->arg1->charConst, (quads+i)->arg2->charConst, (quads+i)->line);
    } 
}

void print_relops(char * op, int i, FILE *f){
    if((quads+i)->arg1->type == constbool_e || (quads+i)->arg1->type == conststring_e 
    || (quads+i)->arg2->type == constbool_e || (quads+i)->arg2->type == conststring_e){
        comperror("cannot compare arguments with different types");
    }else{
        print_equal_exprs(op , i, f);
    }
}

void printQuads(FILE * f){
    int i;
    fprintf(f, "\n----------Intermediate code----------\n");
    for(i = 0; i < currQuad; i++){
	    if((quads+i)->op == assign){
            if((quads+i)->arg1->type == constnum_e){
                fprintf(f, "%d: ASSIGN %s %d [line: %d]\n",i, (quads+i)->result->sym->name, (int)((quads+i)->arg1->numConst), (quads+i)->line);
            }else if((quads+i)->arg1->type == conststring_e){
                fprintf(f, "%d: ASSIGN %s \"%s\"  [line: %d]\n",i, (quads+i)->result->sym->name, (quads+i)->arg1->charConst, (quads+i)->line);
            }else if((quads+i)->arg1->type == constbool_e){
                if((quads+i)->arg1->boolConst){
                    fprintf(f, "%d: ASSIGN %s \'true\'  [line: %d]\n",i, (quads+i)->result->sym->name, (quads+i)->line);
                }else{
                    fprintf(f, "%d: ASSIGN %s \'false\'  [line: %d]\n",i, (quads+i)->result->sym->name, (quads+i)->line);
                }
            }else if((quads+i)->arg1->type == nil_e){
                fprintf(f, "%d: ASSIGN %s nil  [line: %d]\n",i, (quads+i)->result->sym->name, (quads+i)->line);
            }else{
                fprintf(f, "%d: ASSIGN %s %s  [line: %d]\n",i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->line);
            }
        }else if((quads+i)->op == add){
            print_arith_exprs("ADD", i, f);
	    }else if((quads+i)->op == sub){
            print_arith_exprs("SUB", i, f);
	    }else if((quads+i)->op == mul){
            print_arith_exprs("MUL", i, f);
        }else if((quads+i)->op == div_){
            print_arith_exprs("DIV", i, f);
	    }else if((quads+i)->op == mod){
            print_arith_exprs("MOD", i, f);
        }else if((quads+i)->op == uminus){
            if((quads+i)->arg1->type == var_e) {
                fprintf(f, "%d: UMINUS %s %s [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->line);
            }else if((quads+i)->arg1->type == constnum_e){
		        fprintf(f, "%d: UMINUS %s %f [line: %d]\n",i, (quads+i)->result->sym->name, (quads+i)->arg1->numConst, (quads+i)->line);
            }else if((quads+i)->arg1->type == constbool_e){
                fprintf(f, "%d: UMINUS %s %c [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->boolConst, (quads+i)->line);
            }else if((quads+i)->arg1->type == conststring_e){
                fprintf(f, "%d: UMINUS %s \"%s\" [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->charConst, (quads+i)->line);
            }else{
                fprintf(f, "%d: UMINUS %s %s [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->line);

            } 
	    }else if((quads+i)->op == and){
		    print_and_or_exprs("AND", i, f);
	    }else if((quads+i)->op == or){
            print_and_or_exprs("OR", i, f);
        }else if((quads+i)->op == not){
		    fprintf(f, "%d: NOT %s %f [line: %d]\n",i, (quads+i)->result->sym->name,(quads+i)->arg1->numConst, (quads+i)->line);
	    }else if((quads+i)->op == if_eq){
            print_equal_exprs("IF_EQ", i, f);
        }else if((quads+i)->op == if_noteq){
            print_equal_exprs("IF_NOTEQ", i, f);
	    }else if((quads+i)->op == if_lesseq){
            print_relops("IF_LESS_EQUAL", i, f);
	    }else if((quads+i)->op == if_greatereq){
            print_relops("IF_GREATER_EQUAL", i, f);
        }else if((quads+i)->op == if_less){
            print_relops("IF_LESS", i, f);
	    }else if((quads+i)->op == if_greater){
            print_relops("IF_GREATER", i, f);
        }else if((quads+i)->op == call){
		    fprintf(f, "%d: CALL %s  [line: %d]\n",i, (quads+i)->result->sym->name, (quads+i)->line);
	    }else if((quads+i)->op == param){
            if((quads+i)->result->type == constnum_e) {
                fprintf(f, "%d: PARAM %f [line: %d]\n",i, (quads+i)->result->numConst, (quads+i)->line);
            } else if ((quads+i)->result->type == conststring_e || (quads+i)->result->type == constbool_e ) {
                fprintf(f, "%d: PARAM \"%s\" [line: %d]\n",i, (quads+i)->result->charConst, (quads+i)->line);
            } else {
                fprintf(f, "%d: PARAM %s [line: %d]\n",i, (quads+i)->result->sym->name, (quads+i)->line);
            }
	    }else if((quads+i)->op == ret){
            if((quads+i)->result != NULL){
                if((quads+i)->result->type == constnum_e){
                    fprintf(f, "%d: RETURN %f [line: %d]\n",i, (quads+i)->result->numConst, (quads+i)->line);
                }else{
                    fprintf(f, "%d: RETURN %s [line: %d]\n",i, (quads+i)->result->charConst, (quads+i)->line);
                }
            }else{
                fprintf(f, "%d: RETURN [line: %d]\n",i, (quads+i)->line);
            }
            
        }else if((quads+i)->op == getretval){
		    fprintf(f, "%d: GETRETVAL  %s [line: %d]\n",i, (quads+i)->result->sym->name, (quads+i)->line);
	    }else if((quads+i)->op == funcstart){
            fprintf(f, "%d: FUNC_START %s [line: %d]\n",i, (quads+i)->result->sym->name, (quads+i)->line);
        }else if((quads+i)->op == funcend){
		    fprintf(f, "%d: FUNC_END %s [line: %d]\n",i, (quads+i)->result->sym->name, (quads+i)->line);
	    }else if((quads+i)->op == tablecreate){
		    fprintf(f, "%d: TABLE_CREATE %s [line: %d]\n",i, (quads+i)->result->sym->name, (quads+i)->line);
	    }else if((quads+i)->op == tablegetelem){
            if((quads+i)->arg2->type == var_e) {
                fprintf(f, "%d: TABLE_GET_ELEM %s %s %s [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->sym->name, (quads+i)->line);
            }else if((quads+i)->arg2->type == constnum_e){
                fprintf(f, "%d: TABLE_GET_ELEM %s %s %d [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (int)(quads+i)->arg2->numConst, (quads+i)->line);
            }else if((quads+i)->arg2->type == constbool_e){
                fprintf(f, "%d: TABLE_GET_ELEM %s %s %c [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->boolConst, (quads+i)->line);
            }else if((quads+i)->arg2->type == conststring_e){
                fprintf(f, "%d: TABLE_GET_ELEM %s %s \"%s\" [line: %d]\n", i, (quads+i)->result->sym->name, (quads+i)->arg1->sym->name, (quads+i)->arg2->charConst, (quads+i)->line);
            }        
        }else if((quads+i)->op == tablesetelem){
            printSetElem(i, f);
	    }else if((quads+i)->op == jump){
            fprintf(f, "%d: JUMP %d [line: %d]\n",i, (int)((quads+i)->result->numConst), (quads+i)->line);
        }
	}
}
