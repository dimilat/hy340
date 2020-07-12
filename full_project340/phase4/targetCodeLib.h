#include "quadlib.h"
unsigned funcstart_flag = 0; /*erxomai apo funcstart*/
unsigned func_counter = 0; /* metraei emfaniseis synartisewn . to xrisimopoioume gia na vroyme to index sto pinaka synartisewn*/
typedef enum vmopcode {
    assign_v,
    add_v,
    sub_v,
    mul_v,
    div_v,
    mod_v,
    uminus_v,
    and_v,
    or_v,
    not_v,
    jeq_v,
    jne_v,
    jle_v,
    jge_v,
    jlt_v,
    jgt_v,
    call_v,
    pusharg_v,
    funcenter_v,
    funcexit_v,
    newtable_v,
    tablegetelem_v,
    tablesetelem_v,
    nop_v,
    jump_v
} vmopcode;

typedef enum vmarg_t {
    label_a = 0,
    global_a = 1,
    formal_a = 2,
    local_a = 3,
    number_a = 4,
    string_a = 5,
    bool_a = 6,
    nil_a = 7,
    userfunc_a = 8,
    libfunc_a = 9,
    retval_a = 10
} vmarg_t;

typedef struct vmarg {
    vmarg_t type;
    unsigned val;
} vmarg;

typedef struct instruction {
    vmopcode opcode;
    vmarg result;
    vmarg arg1;
    vmarg arg2;
    unsigned srcLine;
} instruction;

instruction* instructions = (instruction*)0;

typedef struct userfunc {
    unsigned address;
    unsigned localSize;
    unsigned saved_index;
    char* id;
} userfunc;

double* numConsts;
unsigned totalNumConsts = 0;
unsigned currNumConst = 0;
char** stringConsts;
unsigned totalStringConsts = 0;
unsigned currStringConst = 0;
char** namedLibfuncs;
unsigned currLibfunct = 0;
unsigned totalNameLibfuncs = 0;
userfunc* userFuncs;
unsigned totalUserFuncs = 0;
unsigned currUserfunct = 0;

unsigned currInstructions = 0;
unsigned totalInstructions = 0;

unsigned nextinstructionlabel() {
    return currInstructions;
}

void num_expand() {
    assert(totalNumConsts == currNumConst);
    double* p = (double*)malloc(EXPAND_SIZE * sizeof(double) + totalNumConsts * sizeof(double));
    if (numConsts) {
        memcpy(p, numConsts, totalNumConsts * sizeof(double));
        free(numConsts);
    }
    numConsts = p;
    totalNumConsts += EXPAND_SIZE;
}

void string_expand() {
    assert(totalStringConsts == currStringConst);
    char** p = (char**)malloc(EXPAND_SIZE * sizeof + totalStringConsts * sizeof(char*));
    if (stringConsts) {
        memcpy(p, stringConsts, totalStringConsts * sizeof(char*));
        free(stringConsts);
    }
    stringConsts = p;
    totalStringConsts += EXPAND_SIZE;
}

void userfunc_expand() {
    assert(totalUserFuncs == currUserfunct);
    userfunc* p = (userfunc*)malloc(EXPAND_SIZE * sizeof(userfunc) + totalUserFuncs * sizeof(userfunc));
    if (userFuncs) {
        memcpy(p, userFuncs, totalUserFuncs * sizeof(userfunc));
        free(userFuncs);
    }
    userFuncs = p;
    totalUserFuncs += EXPAND_SIZE;
}

void libfunc_expand() {
    assert(totalNameLibfuncs == currLibfunct);
    char** p = (char**)malloc(EXPAND_SIZE * sizeof(char*) + totalNameLibfuncs * sizeof(char*));
    if (namedLibfuncs) {
        memcpy(p, namedLibfuncs, totalNameLibfuncs * sizeof(char*));
        free(namedLibfuncs);
    }
    namedLibfuncs = p;
    totalNameLibfuncs += EXPAND_SIZE;
}

unsigned consts_newstring(char* s) {
    if (currStringConst == totalStringConsts) {
        string_expand();
    }
    char** p = stringConsts + currStringConst++;
    *p = s;
    return currStringConst - 1;
}
unsigned consts_newnumber(double n) {
    if (currNumConst == totalNumConsts) {
        num_expand();
    }
    double* p = numConsts + currNumConst++;
    *p = n;
    return currNumConst - 1;
}
unsigned libfuncts_newused(char* s) {
    if (currLibfunct == totalNameLibfuncs) {
        libfunc_expand();
    }
    char** p = namedLibfuncs + currLibfunct++;
    *p = s;
    return currLibfunct - 1;
}
unsigned userfuncts_newfunc(symrec_t* sym) {
    if (currUserfunct == totalUserFuncs) {
        userfunc_expand();
    }
    userfunc* p = userFuncs + currUserfunct++;
    p->id = sym->name;
    p->address = sym->taddress;
    p->localSize = sym->totallocals;
    p->saved_index = func_counter++;

    return currUserfunct - 1;
}

void instruction_expand() {
    assert(totalInstructions == currInstructions);
    instruction* p = (instruction*)malloc(EXPAND_SIZE * sizeof(instruction) + totalInstructions * sizeof(instruction));
    if (instructions) {
        memcpy(p, instructions, totalInstructions * sizeof(instruction));
        free(instructions);
    }
    instructions = p;
    totalInstructions += EXPAND_SIZE;
}

void emitInstruction(instruction* temp) {
    if (currInstructions == totalInstructions) {
        instruction_expand();
    }

    instruction* i = instructions + currInstructions++;

    i->opcode = temp->opcode;
    i->result = temp->result;
    i->arg1 = temp->arg1;
    i->arg2 = temp->arg2;
    i->srcLine = temp->srcLine;
}

typedef struct incomplete_jump {
    unsigned instrNo;
    unsigned iaddress;
    struct incomplete_jump* next;
} incomplete_jump;

incomplete_jump* ij_head = (incomplete_jump*)0;
unsigned ij_total = 0;

void add_incomplete_jump(unsigned instrNo, unsigned iaddress) {
    incomplete_jump* inc_j = (incomplete_jump*)malloc(sizeof(incomplete_jump));
    inc_j->instrNo = instrNo;
    inc_j->iaddress = iaddress;

    inc_j->next = ij_head;
    ij_head = inc_j;
    ij_total++;
}

void patch_incomplete_jumps() {
    incomplete_jump* temp = ij_head;
    while (temp != NULL) {
        if (temp->iaddress == nextquadlabel()) {
            instructions[temp->instrNo].result.val = nextinstructionlabel(); /* to result einai vmarg ara to target label mpainei sto val toy*/
        } else {
            instructions[temp->instrNo].result.val = quads[temp->iaddress].taddress;
        }
    }
}

void make_operand(expr* e, vmarg* arg) {
    if (e != NULL) {
        switch (e->type) {
            case var_e: {
                assert(e->sym);
                arg->val = e->sym->offset;
                if(e->sym->type == USERFUNC){
                    arg->type = userfunc_a;
                }else if(e->sym->type == LIBFUNC){
                    arg->type = libfunc_a;
                }else{
                    switch (e->sym->space) {
                        case programvar:
                            arg->type = global_a;
                            break;
                        case functionlocal:
                            arg->type = local_a;
                            break;
                        case formalarg:
                            arg->type = formal_a;
                            break;
                        default:
                            assert(0);
                    }
                }
                break;
            }
            case tableitem_e: {
                switch (e->sym->space) {
                        case programvar:
                            arg->type = global_a;
                            break;
                        case functionlocal:
                            arg->type = local_a;
                            break;
                        case formalarg:
                            arg->type = formal_a;
                            break;
                        default:
                            assert(0);
                    }
                break;
            }
            case arithexpr_e: {
                assert(e->sym);
                arg->val = e->sym->offset;
                switch (e->sym->space) {
                    case programvar:
                        arg->type = global_a;
                        break;
                    case functionlocal:
                        arg->type = local_a;
                        break;
                    case formalarg:
                        arg->type = formal_a;
                        break;
                    default:
                        assert(0);
                }
                break;
            }
            case boolexpr_e: {
                break;
            }
            case assignexpr_e: { /* auto edw eleipeeeeeeeeeeeeeeeee */
                assert(e->sym);
                arg->val = e->sym->offset;
                switch (e->sym->space) {
                    case programvar:
                        arg->type = global_a;
                        break;
                    case functionlocal:
                        arg->type = local_a;
                        break;
                    case formalarg:
                        arg->type = formal_a;
                        break;
                    default:
                        assert(0);
                }
                break;
            }
            case newtable_e: {
                assert(e->sym);
                arg->val = e->sym->offset;
                switch (e->sym->space) {
                    case programvar:
                        arg->type = global_a;
                        break;
                    case functionlocal:
                        arg->type = local_a;
                        break;
                    case formalarg:
                        arg->type = formal_a;
                        break;
                    default:
                        assert(0);
                }
                break;
            }
            case constbool_e: {
                arg->val = e->boolConst;
                arg->type = bool_a;
                break;
            }
            case conststring_e: {
                arg->val = consts_newstring(e->charConst);
                arg->type = string_a;
                break;
            }
            case constnum_e: {
                arg->val = consts_newnumber(e->numConst);
                arg->type = number_a;
                break;
            }
            case nil_e: {
                arg->type = nil_a;
                break;
            }

            case programfunc_e: {
                arg->type = userfunc_a;
                if(funcstart_flag){
                    e->sym->taddress = nextinstructionlabel();
                    arg->val = userfuncts_newfunc(e->sym);
                    funcstart_flag = 0;
                }else{
                    int i;
                    for(i = currUserfunct; i>=0; i--){/*pairnoume ton pinaka ap to telos kai psaxnoume na vroume idia onomata*/
                        if((func_counter - userFuncs[i].saved_index < 2) && userFuncs[i].id == e->sym->name){
                            arg->val = i;
                            break;
                        }
                    }
                }

                break;
            }
            case libraryfunc_e: {
                arg->type = libfunc_a;
                arg->val = libfuncts_newused(strdup(e->sym->name));
                break;
            }
            default:
                assert(0);
        }
    }
}

struct stackFunc {
    unsigned top;
    symrec_t* stack_array[STACK_SIZE];
};

struct stackFunc* functionStack;

void makestack() {
    functionStack = malloc(sizeof(struct stackFunc)); /*4i fasi gia functs*/
    functionStack->top = -1;
}

void pushf(struct stackFunc* s, symrec_t* sym) {
    if (s->top != STACK_SIZE) { /*is full*/
        s->top += 1;
        s->stack_array[s->top] = sym;
    } else {
        printf("ERROR, stack is full!\n");
    }
}

symrec_t* topf(struct stackFunc* s) {
    return s->stack_array[s->top];
}

symrec_t* popf(struct stackFunc* s) {
    symrec_t* tmp_offset = NULL;
    if (s->top != -1) {
        tmp_offset = topf(s);
        s->top--;
    } else {
        printf("ERROR, stack is empty!\n");
    }
    return tmp_offset;
}

void make_numberoperand(vmarg* arg, double val) {
    arg->val = consts_newnumber(val);
    arg->type = number_a;
}

void make_booloperand(vmarg* arg, unsigned val) {
    arg->val = val;
    arg->type = bool_a;
}

void make_retvaloperand(vmarg* arg) {
    arg->type = retval_a;
}
void reset_operand(vmarg* arg) {
    arg = (vmarg*)0;
}

void generate_relational(vmopcode op, quad* q) {
    instruction* t = (instruction*)malloc(sizeof(instruction));
    t->opcode = op;
    make_operand(q->arg1, &(t->arg1));
    make_operand(q->arg2, &(t->arg2));
    t->result.type = label_a;
    if (q->result->numConst < q->label) {
        t->result.val = quads[q->label].result->numConst; /* ???t->result.val = quads[q->label].taddress;?? To taddress exei to rolo tou result numconst se jumps (target adress) */
    } else {
        add_incomplete_jump(nextinstructionlabel(), q->label);
    }
    q->taddress = nextinstructionlabel();
    emitInstruction(t);
}

void generate(vmopcode opcode, quad* q) {
    instruction* tempInstruction = (instruction*)malloc(sizeof(instruction));
    tempInstruction->opcode = opcode;
    tempInstruction->srcLine = q->line;
    q->taddress = nextinstructionlabel();

    make_operand(q->arg1, &(tempInstruction->arg1));
    make_operand(q->arg2, &(tempInstruction->arg2));
    make_operand(q->result, &(tempInstruction->result));

    emitInstruction(tempInstruction);
}

void generate_ADD(quad* q) { generate(add_v, q); }
void generate_SUB(quad* q) { generate(sub_v, q); }
void generate_MUL(quad* q) { generate(mul_v, q); }
void generate_DIV(quad* q) { generate(div_v, q); }
void generate_MOD(quad* q) { generate(mod_v, q); }
void generate_NEWTABLE(quad* q) { generate(newtable_v, q); }
void generate_TABLEGETELEM(quad* q) { generate(tablegetelem_v, q); }
void generate_TABLESETELEM(quad* q) { generate(tablesetelem_v, q); }
void generate_ASSIGN(quad* q) { generate(assign_v, q); }
void generate_NOP(quad* q) {
    instruction* t = (instruction*)malloc(sizeof(instruction));
    t->opcode = nop_v;
    emitInstruction(t);
}
void generate_JUMP(quad* q) { generate_relational(jump_v, q); }
void generate_IF_EQ(quad* q) { generate_relational(jeq_v, q); }
void generate_IF_NOTEQ(quad* q) { generate_relational(jne_v, q); }
void generate_IF_GREATER(quad* q) { generate_relational(jgt_v, q); }
void generate_IF_GREATEREQ(quad* q) { generate_relational(jge_v, q); }
void generate_IF_LESS(quad* q) { generate_relational(jlt_v, q); }
void generate_IF_LESSEQ(quad* q) { generate_relational(jle_v, q); }
void generate_NOT(quad* q) {
    q->taddress = nextinstructionlabel();
    instruction* t = (instruction*)malloc(sizeof(instruction));
    t->opcode = jeq_v;

    make_operand(q->arg1, &(t->arg1));
    make_booloperand(&(t->arg2), 0);
    t->result.type = label_a;
    t->result.val = nextinstructionlabel() + 3;
    emitInstruction(t);

    t->opcode = assign_v;
    make_booloperand(&(t->arg1), 0);
    reset_operand(&(t->arg2));
    make_operand(q->result, &(t->result));
    emitInstruction(t);

    t->opcode = jump_v;
    reset_operand(&(t->arg1));
    reset_operand(&(t->arg2));
    t->result.type = label_a;
    t->result.val = nextinstructionlabel() + 2;
    emitInstruction(t);

    t->opcode = assign_v;
    make_booloperand(&(t->arg1), 1);
    reset_operand(&(t->arg2));
    make_operand(q->result, &(t->result));
    emitInstruction(t);
}

void generate_OR(quad* q) {
    q->taddress = nextinstructionlabel();
    instruction* t = (instruction*)malloc(sizeof(instruction));
    t->opcode = jeq_v;
    make_operand(q->arg1, &(t->arg1));
    make_booloperand(&(t->arg2), 1);
    t->result.type = label_a;
    t->result.val = nextinstructionlabel() + 4;
    emitInstruction(t);

    make_operand(q->arg2, &(t->arg1));
    t->result.val = nextinstructionlabel() + 3;
    emitInstruction(t);

    t->opcode = assign_v;
    make_booloperand(&(t->arg1), 0);
    reset_operand(&(t->arg2));
    make_operand(q->result, &(t->result));
    emitInstruction(t);

    t->opcode = jump_v;
    reset_operand(&(t->arg1));
    reset_operand(&(t->arg2));
    t->result.type = label_a;
    t->result.val = nextinstructionlabel() + 2;
    emitInstruction(t);

    t->opcode = assign_v;
    make_booloperand(&(t->arg1), 1);
    reset_operand(&(t->arg2));
    make_operand(q->result, &(t->result));
    emitInstruction(t);
}
void generate_AND(quad* q) {
    q->taddress = nextinstructionlabel();
    instruction* t = (instruction*)malloc(sizeof(instruction));
    t->opcode = jeq_v;
    make_operand(q->arg1, &(t->arg1));
    make_booloperand(&(t->arg2), 0);
    t->result.type = label_a;
    t->result.val = nextinstructionlabel() + 4;
    emitInstruction(t);

    make_operand(q->arg2, &(t->arg1));
    t->result.val = nextinstructionlabel() + 3;
    emitInstruction(t);

    t->opcode = assign_v;
    make_booloperand(&(t->arg1), 1);
    reset_operand(&(t->arg2));
    make_operand(q->result, &(t->result));
    emitInstruction(t);

    t->opcode = jump_v;
    reset_operand(&(t->arg1));
    reset_operand(&(t->arg2));
    t->result.type = label_a;
    t->result.val = nextinstructionlabel() + 2;
    emitInstruction(t);

    t->opcode = assign_v;
    make_booloperand(&(t->arg1), 0);
    reset_operand(&(t->arg2));
    make_operand(q->result, &(t->result));
    emitInstruction(t);
}
void generate_PARAM(quad* q) {
    q->taddress = nextinstructionlabel();
    instruction* t = (instruction*)malloc(sizeof(instruction));
    t->opcode = pusharg_v;
    make_operand(q->result, &(t->result));
    emitInstruction(t);
}
void generate_CALL(quad* q) {
    q->taddress = nextinstructionlabel();
    instruction* t = (instruction*)malloc(sizeof(instruction));
    t->opcode = call_v;
    make_operand(q->result, &(t->result));
    emitInstruction(t);
}

void generate_GETRETVAL(quad* q) {
    q->taddress = nextinstructionlabel();
    instruction* t = (instruction*)malloc(sizeof(instruction));
    t->opcode = assign_v;
    make_operand(q->result, &(t->result));
    make_retvaloperand(&(t->arg1));
    emitInstruction(t);
}

void generate_FUNCSTART(quad* q) {
    symrec_t* f;
    f = q->result->sym;
    f->taddress = nextinstructionlabel();
    q->taddress = nextinstructionlabel();

    pushf(functionStack, f);
    instruction* t = (instruction*)malloc(sizeof(instruction));
    t->opcode = funcenter_v;
    funcstart_flag = 1;
    make_operand(q->result, &(t->result));
    emitInstruction(t);
}
void generate_RETURN(quad* q) {
    q->taddress = nextinstructionlabel();
    instruction* t = (instruction*)malloc(sizeof(instruction));
    t->opcode = assign_v;
    make_retvaloperand(&(t->result));
    make_operand(q->arg1, &(t->arg1));
    emitInstruction(t);

    /* to emit tou jump ginetai sto intermediate code. 8a xeiristei epomenws apo tin generate_all */
}
void generate_FUNCEND(quad* q) {
    q->taddress = nextinstructionlabel();
    instruction* t = (instruction*)malloc(sizeof(instruction));
    t->opcode = funcexit_v;
    func_counter--;
    make_operand(q->result, &(t->result));
    
    emitInstruction(t);
    
}

typedef void (*generator_func_t)(quad*);

generator_func_t generators[] = {
    generate_ADD,
    generate_SUB,
    generate_MUL,
    generate_DIV,
    generate_MOD,
    generate_NEWTABLE,
    generate_TABLEGETELEM,
    generate_TABLESETELEM,
    generate_ASSIGN,
    generate_NOP,
    generate_JUMP,
    generate_IF_EQ,
    generate_IF_NOTEQ,
    generate_IF_GREATER,
    generate_IF_GREATEREQ,
    generate_IF_LESS,
    generate_IF_LESSEQ,
    generate_NOT,
    generate_OR,
    generate_AND,
    generate_PARAM,
    generate_CALL,
    generate_GETRETVAL,
    generate_FUNCSTART,
    generate_RETURN,
    generate_FUNCEND};

void generate_all(void) {
    unsigned i;
    makestack();

    for (i = 0; i < nextquadlabel(); ++i) { /* to total au3anetai me EXPAND SIZE kai ginetai terastio!!! */
        generators[quads[i].op](quads + i);
    }
    
}

void printInstructions() {
    int i = 0;
    for (i = 0; i < nextinstructionlabel(); i++) {
        switch (instructions[i].opcode) {
            case assign_v:
                if(instructions[i].arg1.type == number_a){
                    printf("%d | assign | %d %d | %d %d:%d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, (int)numConsts[instructions[i].arg1.val]);
                }else if(instructions[i].arg1.type == string_a){
                    printf("%d | assign | %d %d | %d %d:\"%s\"\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, stringConsts[instructions[i].arg1.val]);
                }else if(instructions[i].arg1.type == userfunc_a){
                    printf("%d | assign | %d %d | %d %d:%s\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, userFuncs[instructions[i].arg1.val].id);
                }else if(instructions[i].arg1.type == libfunc_a){
                    printf("%d | assign | %d %d | %d %d:%s\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, namedLibfuncs[instructions[i].arg1.val]);
                }else if(instructions[i].arg1.type == retval_a){
                    printf("%d | assign | %d %d | %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type);
                }else{/*2nd assign*/
                    printf("%d | assign | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val);                   
                }
                break;
            case add_v:
                printf("%d | add | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
              
                break;
            case sub_v:
                printf("%d | sub | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
                break;
            case mul_v:
                printf("%d | mul | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
                break;
            case div_v:
                printf("%d | div | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
                break;
            case mod_v:
                printf("%d | mod | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
                break;
            case jeq_v:
                printf("%d | if_eq | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
                break;
            case jne_v:
                printf("%d | if_noteq | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
                break;
            case jle_v:
                printf("%d | if_lesseq | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
                break;
            case jge_v:
                printf("%d | if_greatereq | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
                break;
            case jlt_v:
                printf("%d | if_less | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
                break;
            case jgt_v:
                printf("%d | if_greater | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
                break;
            case call_v:
                printf("%d | callfunc | %d %d\n", i, instructions[i].result.type, instructions[i].result.val);
                break;
            case pusharg_v:
                 printf("%d | pusharg | %d %d\n", i, instructions[i].result.type, instructions[i].result.val);
                break;
            case funcenter_v:
                printf("%d | enterfunc | %d %d\n", i, instructions[i].result.type, instructions[i].result.val);
                break;
            case funcexit_v:
                printf("%d | exitfunc | %d %d\n", i, instructions[i].result.type, instructions[i].result.val);
                break;
            case newtable_v:
                printf("%d | tablecreate | %d %d\n", i, instructions[i].result.type, instructions[i].result.val);
                break;
            case tablegetelem_v:
                printf("%d | tablegetelement | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
                break;
            case tablesetelem_v:
                printf("%d | tablesetelement | %d %d | %d %d | %d %d\n", i, instructions[i].result.type, instructions[i].result.val, instructions[i].arg1.type, instructions[i].arg1.val, instructions[i].arg2.type, instructions[i].arg2.val);
                break;
            case nop_v:
                printf("%d | nop \n", i);
                break;
            case jump_v:
                printf("%d | jump | %d %d\n", i, instructions[i].result.type, instructions[i].result.val);
                break;
            default:
                break;
        }
    }
}