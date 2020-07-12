%{
	#include "quadlib.h"

	#define YY_DECL int alpha_yylex (void* ylval) 

	int yyerror (char* yaccProvidedMessage);
	int yylex(void);
	
	int dollar_counter = 0;
	char * buffer;
	struct stack * functionLocalsStack;
	struct stack * loopcounterstack;
	struct stacklist * breakstacklist;
	struct stacklist * contstacklist;
	struct stmt * breaklist_head;
	struct stmt * contlist_head;

	symrec_t * tmp_rec;
	
	extern int yylineno;
	extern char * yytext;
	extern FILE * yyin;
	extern FILE * yyout;

%}

%start program

%union {
	char*	stringValue;
	int		intValue;
	double	doubleValue;
	struct expr* node;
	struct forVar* forpref;
	struct stmt* stmt_node;
}

%token IF
%token ELSE
%token WHILE
%token FOR
%token FUNCTION
%token RETURN
%token BREAK
%token CONTINUE
%token AND
%token NOT
%token OR
%token LOCAL
%token TRUE
%token FALSE
%token NIL

%token ASSIGN
%token ADD
%token MINUS
%token MULTIPLICATION
%token DIVISION
%token MODULO
%token EQUAL
%token INEQUAL
%token INCREMENT
%token DECREMENT
%token GREATER
%token GREATER_EQUAL
%token LESS
%token LESS_EQUAL

%token LEFT_CURLY_BRACKET
%token RIGHT_CURLY_BRACKET
%token LEFT_SQUARE_BRACKET
%token RIGHT_SQUARE_BRACKET
%token LEFT_PARENTHESIS
%token RIGHT_PARENTHESIS
%token SEMICOLON
%token COMMA
%token COLON
%token DOUBLE_COLON
%token DOT
%token DOUBLE_DOT
%token SINGLE_LINE_COMMENT
%token OTHERCHAR

%token <stringValue> IDENT
%token <intValue> INTEGER
%token <doubleValue> REAL
%token <stringValue> STRINGCONST


%right ASSIGN
%left AND OR 
%left EQUAL INEQUAL
%nonassoc GREATER GREATER_EQUAL LESS LESS_EQUAL NOT 

%left ADD MINUS

%left MULTIPLICATION DIVISION MODULO

%right DECREMENT INCREMENT
%nonassoc UMINUS

%left DOT DOUBLE_DOT

%left LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET

%left LEFT_PARENTHESIS RIGHT_PARENTHESIS

%left RIGHT_CURLY_BRACKET LEFT_CURLY_BRACKET

%type <node> term
%type <node> assignexpr
%type <node> expr
%type <node> lvalue
%type <node> primary
%type <node> const
%type <node> member
%type <node> funcdef
%type <node> methodcall
%type <node> elist
%type <node> callsuffix
%type <node> normcall
%type <node> call
%type <node> elist_expressions
%type <node> objectdef
%type <node> indexedelem_list
%type <node> indexedelem
%type <node> indexed
%type <node> ifprefix
%type <node> elseprefix
%type <node> whilestart
%type <forpref> forprefix
%type <intValue> whilecond
%type <intValue> N
%type <intValue> M
%type <stmt_node> stmt
%type <stmt_node> stmt_list

%expect 2
%%

program:	stmt_list
			;

stmt:		expr SEMICOLON {tempcounter=0; $$ = NULL;  FINALemits($1, yylineno);  }
			|ifstmt	{tempcounter=0; $$ = NULL;}
			|whilestmt{tempcounter=0; $$ = NULL;}
			|forstmt{tempcounter=0; $$ = NULL;}
			|returnstmt{tempcounter=0; $$ = NULL;}
			|BREAK{if(!loopcounter){yyerror("Use of 'break' while not in a loop");}} SEMICOLON{tempcounter=0; $$ = newstmt(nextquadlabel()); 
												$$->next = topstacklist(breakstacklist)->next; topstacklist(breakstacklist)->next = $$;
												emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);}
			|CONTINUE{if(!loopcounter){yyerror("Use of 'return' while not in a loop");}} SEMICOLON{tempcounter=0; $$ = newstmt(nextquadlabel());
												$$->next = topstacklist(contstacklist)->next; topstacklist(contstacklist)->next = $$;
												emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);}
			|block{tempcounter=0; $$ = NULL;}
			|funcdef{tempcounter=0; $$ = NULL;}
			|SEMICOLON{tempcounter=0; $$ = NULL;}
			;
			
stmt_list:	stmt stmt_list { $$ = $1;}
			|{$$ = NULL;}
			;

expr:		assignexpr {$$=$1;}
			|expr ADD expr { if(validtype($1, $3)){ $$ = newexpr(arithexpr_e); $$->type = returnType($$,$1,$3); $$->sym = returnTempName($1,$3); emit(add, $$, $1, $3, currQuad, yylineno);} }
			|expr MINUS expr {if(validtype($1, $3)){ $$ = newexpr(arithexpr_e); $$->type = returnType($$,$1,$3);  $$->sym = returnTempName($1,$3); emit(sub, $$, $1, $3, currQuad, yylineno);} }
			|expr MULTIPLICATION expr {if(validtype($1, $3)){ $$ = newexpr(arithexpr_e); $$->type = returnType($$,$1,$3);  $$->sym = returnTempName($1,$3); emit(mul, $$, $1, $3, currQuad, yylineno);} }
			|expr DIVISION expr {if(validtype($1, $3)){ $$ = newexpr(arithexpr_e); $$->type = returnType($$,$1,$3);  $$->sym = returnTempName($1,$3); emit(div_, $$, $1, $3, currQuad, yylineno);} }
			|expr MODULO expr {if(validtype($1, $3)){ $$ = newexpr(arithexpr_e); $$->type = returnType($$,$1,$3);  $$->sym = returnTempName($1,$3); emit(mod, $$, $1, $3, currQuad, yylineno);} }
			|expr GREATER expr {$$ = newexpr(boolexpr_e);  $$->sym = returnTempName($1,$3); $$ = emitPartialRelop($$, $1, $3, if_greater, yylineno); makeFinalEmits=1;}
			|expr GREATER_EQUAL expr {$$ = newexpr(boolexpr_e);  $$->sym = returnTempName($1,$3); $$ = emitPartialRelop($$, $1, $3, if_greatereq, yylineno); makeFinalEmits=1; }
			|expr LESS expr {$$ = newexpr(boolexpr_e);  $$->sym = returnTempName($1,$3); $$ = emitPartialRelop($$, $1, $3, if_less, yylineno); makeFinalEmits=1; }
			|expr LESS_EQUAL expr {$$ = newexpr(boolexpr_e);  $$->sym = returnTempName($1,$3); $$ = emitPartialRelop($$, $1, $3, if_lesseq, yylineno); makeFinalEmits=1; }
			|expr EQUAL expr {$$ = newexpr(boolexpr_e);  $$->sym = returnTempName($1,$3); $$ = emitPartialRelop($$, $1, $3, if_eq, yylineno);  makeFinalEmits=1; }
			|expr INEQUAL expr {$$ = newexpr(boolexpr_e);  $$->sym = returnTempName($1,$3); $$ = emitPartialRelop($$, $1, $3, if_noteq, yylineno);  makeFinalEmits=1; }
			|expr AND{ emitBoolConversion($1, yylineno);  } M expr {$$ = newexpr(boolexpr_e);  $$->sym = returnTempName($1,$5); 
														emitBoolConversion($5, yylineno);
														Mlabel = $5->truelist->label;
														/*
														if(ANDcounter < 0){
															backpatch($1->truelist, Mlabel);
															backpatch($1->falselist, $1->falselist->numConst);
														}else{
															backpatch($1->truelist, Mlabel);
															backpatch($1->falselist, $1->falselist->numConst+2);
														}*/
														backpatch($1->truelist, Mlabel);
														backpatch($1->falselist, $1->falselist->numConst+2);
														
														if(ORcounter == 1){
															backpatch(ORQuadNo, Mlabel+2);
														}
														
														//tempQuadNo2 = cloneList($1->falselist);
														$$->truelist = $5->truelist;
														$$->falselist = mergePartial($1->falselist, $5->falselist);
														makeFinalEmits = 1; 
														ANDcounter = 1;
												} 
			|expr OR{ emitBoolConversion($1, yylineno);  } M expr {$$ = newexpr(boolexpr_e);  $$->sym = returnTempName($1,$5); 
														emitBoolConversion($5, yylineno);
														Mlabel=$5->truelist->label;
														/*if(ORcounter < 0){
															backpatch($1->falselist, Mlabel);
															backpatch($1->truelist, $1->truelist->numConst+2);
														}else{
															backpatch($1->falselist, Mlabel);
															backpatch($1->truelist, $1->truelist->numConst+2);
														}*/
														backpatch($1->falselist, Mlabel);
														backpatch($1->truelist, $1->truelist->numConst+2);

														/*if(ANDcounter == 1){
															backpatch(tempQuadNo2->next, Mlabel);
														}*/

														tempQuadNo = cloneList($1->truelist);
														if(ORQuadNo == NULL){
															ORQuadNo = tempQuadNo;
														}else{
															expr * tempOR = ORQuadNo;
															while(tempOR->next != NULL){
																tempOR = tempOR->next;
															}
															tempOR->next = tempQuadNo;
														}
														$$->truelist = mergePartial($1->truelist, $5->truelist);
														$$->falselist = $5->falselist;

														makeFinalEmits = 1;
														ORcounter=1;
														}
			|term {$$=$1;}
			;

term:		LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {$$=$2;}
			|MINUS expr {checkuminus($2); $$=newexpr(arithexpr_e); $$->sym = newtemp(); emit(uminus, $$, $2, (expr *) 0, currQuad, yylineno);} 
			|NOT expr {$$=newexpr(boolexpr_e); $$->sym = newtemp(); $2->isNot=1;
																	if($2->type!=boolexpr_e){
																		$2->truelist = makeTrueList(nextquadlabel());
																		$2->falselist= makeFalseList(nextquadlabel());  
																		emit(if_eq, $2->falselist, $2, newexpr_constbool('1'), currQuad, yylineno);
																		emit(jump, $2->truelist, (expr*) 0, (expr*) 0, currQuad, yylineno);

																		/*emit(assign, $$, newexpr_constbool(1), (expr*) 0, currQuad, yylineno);
    																	emit(jump, newexpr_constnum(nextquadlabel()+2), (expr*) 0, (expr*) 0, currQuad, yylineno);
    																	emit(assign, $$, newexpr_constbool(0), (expr*) 0, currQuad, yylineno);*/
																	}
																	$$->truelist = $2->falselist; 
																	$$->falselist = $2->truelist; 
																	makeFinalEmits = 1;     }
			|INCREMENT lvalue {if(token_is_func){yyerror("cannot increment function value"); token_is_func = 0;} 
								if($2->type == tableitem_e){
									$$ = emit_iftableitem($2);
									emit(add, $$, $$, newexpr_constnum(1), currQuad, yylineno);
									emit(tablesetelem, $$, $2, $2->index, currQuad, yylineno);
								}else{
									emit(add, $2, $2, newexpr_constnum(1), currQuad, yylineno);
									$$ = newexpr(arithexpr_e);
									$$->sym = newtemp();
									emit(assign, $$, $2, (expr*) 0, currQuad, yylineno);
								}
							}
			|lvalue INCREMENT {if(token_is_func){yyerror("cannot increment function value"); token_is_func = 0;}
								$$ = newexpr(var_e); $$->sym = newtemp();
								if($1->type == tableitem_e){
									expr * value = emit_iftableitem($1);
									emit(assign, $$, value, (expr*) 0, currQuad, yylineno);
									emit(add, value, value, newexpr_constnum(1), currQuad, yylineno);
									emit(tablesetelem, value, $1, $1->index, currQuad, yylineno);
								}else{
									emit(assign, $$, $1, (expr*) 0, currQuad, yylineno);
									emit(add, $1, $1, newexpr_constnum(1), currQuad, yylineno);
								}
							}
			|DECREMENT lvalue {if(token_is_func){yyerror("cannot decrement function value"); token_is_func = 0;} 
								if($2->type == tableitem_e){
									$$ = emit_iftableitem($2);
									emit(sub, $$, $$, newexpr_constnum(1), currQuad, yylineno);
									emit(tablesetelem, $$, $2, $2->index, currQuad, yylineno);
								}else{
									emit(sub, $2, $2, newexpr_constnum(1), currQuad, yylineno);
									$$ = newexpr(arithexpr_e);
									$$->sym = newtemp();
									emit(assign, $$, $2, (expr*) 0, currQuad, yylineno);
								}
							}
			|lvalue DECREMENT {if(token_is_func){yyerror("cannot decrement function value"); token_is_func = 0;} 
								$$ = newexpr(var_e); $$->sym = newtemp();
								if($1->type == tableitem_e){
									expr * value = emit_iftableitem($1);
									emit(assign, $$, value, (expr*) 0, currQuad, yylineno);
									emit(sub, value, value, newexpr_constnum(1), currQuad, yylineno);
									emit(tablesetelem, value, $1, $1->index, currQuad, yylineno);
								}else{
									emit(assign, $$, $1, (expr*) 0, currQuad, yylineno);
									emit(sub, $1, $1, newexpr_constnum(1), currQuad, yylineno);
								}
							}
			|primary {$$ = $1;}
			;

assignexpr:	lvalue{		
						if($1 != NULL && $1->sym->type == LIBFUNC){
							yyerror("Invalid insertion,0 trying to shadow LIBFUNC, before"); 
						}
						if($1 != NULL && $1->sym->type == USERFUNC ){
							yyerror("variable already defined as function");
						}
						if(assignInRow){
							if(scope){
								tmp_rec = insert(scope, yylineno, LOCALVAR, yylval.stringValue);
								extraSets(tmp_rec);
							}else{
								tmp_rec = insert(scope, yylineno, GLOBAL, yylval.stringValue);
								extraSets(tmp_rec);
							}
							assignInRow = 0;
							$1 = lvalue_expr(tmp_rec);
						}
						
				} ASSIGN{afterAssign = 1; } expr { afterAssign = 0; 
													
													FINALemits($5, yylineno);
													
													if($1 != NULL && $1->type == tableitem_e){
														emit(tablesetelem, $5, $1, $1->index, currQuad, yylineno);
														$$ = emit_iftableitem($1);
														$$->type = assignexpr_e;
													}else{
														emit(assign, $1, $5, (expr*)0, currQuad, yylineno); 
														$$ = newexpr(assignexpr_e); 
														$$->sym = returnTempName($5,(expr*)0); 
														emit(assign, $$, $1, (expr*)0, currQuad, yylineno); 
													}
												}
			;

primary:	lvalue { 
					if(assignInRow){
						if(scope == 0){
							tmp_rec = insert(scope, yylineno, GLOBAL, yylval.stringValue);
							extraSets(tmp_rec);
						}else{
							tmp_rec = insert(scope, yylineno, LOCALVAR, yylval.stringValue);
							extraSets(tmp_rec);
						}
						assignInRow = 0;
						$1 = lvalue_expr(tmp_rec);
					}
					if(islibfunc){
						if(global_LIB_use){
							yyerror("Invalid insertion,1 trying to shadow LIBFUNC, before"); 
							global_LIB_use = 0;
						}
						islibfunc = 0;
					}else if(not_accessible && afterAssign && !call_depth){
						yyerror("Invalid insertion, before");
						not_accessible = 0;
						afterAssign = 0;
					}
					$$ = emit_iftableitem($1);
			}
			|call {global_LIB_use = 0; $$ = $1;}
			|objectdef {$$ = $1;}
			|LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS{ $$ = $2; }
			|const{
				if(islibfunc && !call_depth){ 
						yyerror("Invalid insertion,3 trying to shadow LIBFUNC, before"); 
						islibfunc = 0;
				}
				$$ = $1;
			}
			;

lvalue:		IDENT{	
					if((tmp_rec = lookupLIBFUNCTs(yylval.stringValue))!= NULL){
						if(scope){
							global_LIB_use = 1;
						}else{
							global_LIB_use = 0;
						}
						islibfunc = 1;
					}else if( (tmp_rec = lookup(yylval.stringValue, scope)) != NULL){
						not_accessible = 0;
						islibfunc = 0;
					}else if( (tmp_rec = lookupFormal(yylval.stringValue, scope)) != NULL){
						not_accessible = 0;
						islibfunc = 0;
					}else if( (tmp_rec = lookupAbove(yylval.stringValue, scope)) != NULL){
						if(infunc && tmp_rec->type != USERFUNC && tmp_rec->func_scope < infunc){ /*an vrw parapanw variable kai eimai mesa se funct ->error*/
							yyerror("variable is not accesible in function");
						}
						not_accessible = 1;
						islibfunc = 0;
					}else if( (tmp_rec = lookup(yylval.stringValue, 0)) != NULL){
						glo_bal = 1;
						not_accessible = 0;
						islibfunc = 0;
					}else if(afterAssign){
						assignInRow = 1;
						afterAssign = 0;
						islibfunc = 0;
					}else{
						islibfunc =0;
						if(!call_depth){
								if(scope == 0){
									tmp_rec = insert(scope, yylineno, GLOBAL, yylval.stringValue);
									extraSets(tmp_rec);
								}else{
									tmp_rec = insert(scope, yylineno, LOCALVAR, yylval.stringValue);
									extraSets(tmp_rec);
								}
						}
					}
					/* i parakatw if einai gia increment decrement error checking for functions*/
					
					if(tmp_rec != NULL && (tmp_rec->type == USERFUNC || tmp_rec->type == LIBFUNC)){
						token_is_func = 1;
					}else{
						token_is_func = 0;
					}
					if(tmp_rec == NULL){
						$$ = NULL;
					}else{
						$$ = lvalue_expr(tmp_rec);
					}
					
				}
			|LOCAL IDENT{
							if(scope && ((tmp_rec = lookupLIBFUNCTs(yylval.stringValue)) !=NULL)){
								yyerror("Invalid insertion,4 trying to shadow LIBFUNC");
							}else if((tmp_rec = lookup(yylval.stringValue, scope)) != NULL){
								
							}else{
								if(scope == 0){
									tmp_rec = insert(scope, yylineno, GLOBAL, yylval.stringValue);
									extraSets(tmp_rec);
								}else{
									tmp_rec = insert(scope, yylineno, LOCALVAR, yylval.stringValue);
									extraSets(tmp_rec);
								}
							}
							if(tmp_rec == NULL){
								$$ = NULL;
							}else{
								$$ = lvalue_expr(tmp_rec);
							}
						}
			|DOUBLE_COLON IDENT {
						if((tmp_rec = lookup(yylval.stringValue, 0)) == NULL){
							yyerror("undefined global variable");
						}else{
							$$ = lvalue_expr(tmp_rec);
						}
				}
			|member {$$ = $1;}
			;

member:		lvalue DOT IDENT { if($1 != NULL){ $$ = member_item($1, $3); } }
			|lvalue LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET { $1 = emit_iftableitem($1); $$ = newexpr(tableitem_e); $$->sym = $1->sym; $$->index = $3; }
			|call DOT IDENT {islibfunc = 0; $$ = NULL;}
			|call LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET {$$ = NULL;}
			;

call:		
			call LEFT_PARENTHESIS elist	RIGHT_PARENTHESIS {$$ = make_call($1, $3, yylineno);}
			|lvalue callsuffix {
									if($2->boolConst == '1'){
										expr * self = $1;
										$1 = emit_iftableitem(member_item(self, $2->charConst));
										self->next = $2->next; /*add self front*/
										$2 = self;
									}
									$$ = make_call($1, $2->next, yylineno);
								}
			|LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS{
																			expr* func = newexpr(programfunc_e);
																			func->sym = $2->sym;
																			$$ = make_call(func, $5, yylineno);
																		}
			;

callsuffix:	normcall{$$ = $1;}
			|methodcall{$$ = $1;}
			;

normcall:	LEFT_PARENTHESIS{call_depth++; } elist RIGHT_PARENTHESIS {	call_depth--;
																		$$ = newexpr(nil_e);
																		$$->next = $3;
																		$$->charConst = NULL;
																		$$->boolConst = '0';
																	}
			;

methodcall:	DOUBLE_DOT IDENT LEFT_PARENTHESIS{call_depth++; } elist RIGHT_PARENTHESIS{
																		call_depth--;
																		$$ = newexpr(tableitem_e);
																		$$->next = $5;
																		$$->charConst = $2;
																		$$->boolConst = '1';
																	}
			;

elist:		expr elist_expressions{$$ = $1; $$->next=$2;}
			|{$$ = NULL;}
			;

elist_expressions: COMMA expr elist_expressions{ $$=$2; $$->next=$3;}
					|{$$=NULL;}
					;

objectdef:	LEFT_SQUARE_BRACKET elist RIGHT_SQUARE_BRACKET{
													int i = 0;
													expr* t = newexpr(newtable_e);
													t->sym = newtemp();
													emit(tablecreate, t, (expr*) 0, (expr*) 0, currQuad, yylineno);
													while($2 != NULL){
														emit(tablesetelem, $2, t, newexpr_constnum(i++), currQuad, yylineno);
														$2 = $2->next;
													}
													$$ = t;
												}
			|LEFT_SQUARE_BRACKET indexed RIGHT_SQUARE_BRACKET {
													expr* t = newexpr(newtable_e);
													t->sym = newtemp();
													emit(tablecreate, t, (expr*) 0, (expr*) 0, currQuad, yylineno);
													while($2!=NULL){
														emit(tablesetelem, $2, t, $2->index, currQuad, yylineno);
														$2 = $2->next;
													}
													$$ = t;		
												}
			;

indexed:	indexedelem indexedelem_list {$$ = $1; $$->next = $2;}
			;

indexedelem_list:	COMMA indexedelem indexedelem_list {$$ = $2; $$->next = $3;}
					| {$$ = NULL;}
					;

indexedelem:LEFT_CURLY_BRACKET expr COLON{afterAssign = 0;} expr RIGHT_CURLY_BRACKET {$$ = $5; $$->index = $2; afterAssign = 1;} 
			;

block:		LEFT_CURLY_BRACKET{scope++;} stmt_list RIGHT_CURLY_BRACKET {hide_scope(scope); scope--;}
			|LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET
			;

funcdef:	FUNCTION{infunc++;} IDENT{ 
							if(lookupLIBFUNCTs(yylval.stringValue)){
								yyerror("Invalid insertion, trying to shadow LIBFUNC");
							}else if(lookup(yylval.stringValue, scope) != NULL){
								yyerror("Invalid function name, defined");
							}else if(lookupFormal(yylval.stringValue, scope) != NULL){
								yyerror("Invalid function name, defined as formal argument");
							}else{
								$<node>$ = lvalue_expr(insert(scope, yylineno, USERFUNC, yylval.stringValue));
								$<node>$->sym->iaddress = nextquadlabel();
								currQuadFuncStart = nextquadlabel();
								emit(jump, newexpr_constnum(0), (expr*) 0, (expr*) 0, currQuad, yylineno);
								emit(funcstart, $<node>$, (expr *) 0, (expr *) 0, currQuad, yylineno);
								push(functionLocalsStack, functionLocalOffset);
								tmp_expr = $<node>$;
							}
							resetformalargsoffset();
						} LEFT_PARENTHESIS{scope++; enterscopespace();} idlist RIGHT_PARENTHESIS{scope--; enterscopespace(); resetfunctionlocalsoffset(); push(loopcounterstack, loopcounter); loopcounter = 0;} 
						block {
								infunc--; exitscopecounter(); exitscopecounter();
								$$ = tmp_expr;
								$$->sym->totallocals = functionLocalOffset;
								functionLocalOffset = pop(functionLocalsStack);
								emit(funcend, $$, (expr *) 0, (expr *) 0, currQuad, yylineno);
								/*patchlabel(returnStart, nextquadlabel()); jump gia return an xreiastei tlk*/
								patchlabel(currQuadFuncStart, nextquadlabel());
								loopcounter = pop(loopcounterstack);
						}
			|FUNCTION{	
						infunc++;
						buffer = malloc(sizeof(char*));
						sprintf(buffer, "$%d", dollar_counter);
						buffer = strndup(buffer, sizeof(char*));
						$<node>$ = lvalue_expr(insert(scope, yylineno, USERFUNC, buffer));
						currQuadFuncStart = nextquadlabel();
						emit(jump, newexpr_constnum(0), (expr*) 0, (expr*) 0, currQuad, yylineno);
						emit(funcstart, $<node>$, (expr *) 0, (expr *) 0, currQuad, yylineno);
						push(functionLocalsStack, functionLocalOffset);
						tmp_expr = $<node>$;
						dollar_counter++;
						resetformalargsoffset();
					}LEFT_PARENTHESIS{scope++; enterscopespace();} idlist RIGHT_PARENTHESIS{scope--; enterscopespace();} block {
																			infunc--;
																			exitscopecounter(); exitscopecounter();
																			$$ = tmp_expr; 
																			$$->sym->totallocals = functionLocalOffset;
																			functionLocalOffset = pop(functionLocalsStack);
																			emit(funcend, $$, (expr *) 0, (expr *) 0, currQuad, yylineno);
																			/*patchlabel(returnStart, nextquadlabel()); jump gia return an xreiastei tlk*/
																			patchlabel(currQuadFuncStart, nextquadlabel());
																		}
			;

const:		INTEGER { $$ = newexpr_constnum(yylval.intValue); } 
			| REAL { $$ = newexpr_constnum(yylval.doubleValue); }
			| STRINGCONST { $$ = newexpr_conststring(yylval.stringValue); }
			| NIL {afterAssign = 0; $$ = newexpr(nil_e);}
			| TRUE {afterAssign = 0; $$ = newexpr_constbool('1');}
			| FALSE {afterAssign = 0; $$ = newexpr_constbool('0');}
			;

idlist:		IDENT{	formalArgOffset++;
				if(lookupLIBFUNCTs(yylval.stringValue)){
					yyerror("Invalid insertion, trying to shadow LIBFUNC");
				}else if(lookupFormal(yylval.stringValue, scope) != NULL){
					yyerror("duplicate formal names");
				}else{
					insert(scope, yylineno, FORMAL, yylval.stringValue);
				}
			} idlist_list
			|
			;

idlist_list:COMMA IDENT {	formalArgOffset++;
				if(lookupLIBFUNCTs(yylval.stringValue)){
					yyerror("Invalid insertion, trying to shadow LIBFUNC");
				}else if(lookupFormal(yylval.stringValue, scope) != NULL){
					yyerror("duplicate formal names");
				}else{
					insert(scope, yylineno, FORMAL, yylval.stringValue);
				}
			}idlist_list
			|  							
			;

ifprefix: IF LEFT_PARENTHESIS{makeFinalEmits = 0;} expr RIGHT_PARENTHESIS{FINALemits($4, yylineno); emit(if_eq, newexpr_constnum(nextquadlabel()+2), $4, newexpr_constbool('1'), currQuad, yylineno); 
									$$ = newexpr(var_e); $$->numConst = nextquadlabel(); 
									emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);
									}
elseprefix: ELSE{ $$ = newexpr(var_e); $$->numConst = nextquadlabel(); emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno); } 

ifstmt:		ifprefix stmt {patchlabel((int)($1->numConst), nextquadlabel()); }
			|ifprefix stmt elseprefix stmt {patchlabel((int)($1->numConst), (int)($3->numConst) + 1); patchlabel((int)($3->numConst), nextquadlabel()); }
			;

whilestart: WHILE{$$ = newexpr_constnum(nextquadlabel()); }
			;	

whilecond: 	LEFT_PARENTHESIS expr RIGHT_PARENTHESIS{ ++loopcounter; 
										FINALemits($2, yylineno);
										breaklist_head = newstmt(-1); contlist_head = newstmt(-1);
										pushstacklist(breakstacklist, breaklist_head); pushstacklist(contstacklist, contlist_head); 
										emit(if_eq, newexpr_constnum(nextquadlabel()+2), $2, newexpr_constbool('1'), currQuad, yylineno); 
										$$ = nextquadlabel();   
										emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);  }
			;

whilestmt: 	whilestart whilecond stmt{ --loopcounter;	
				emit(jump, $1, (expr *)0, (expr *)0, currQuad, yylineno);   
				patchlabel($2, nextquadlabel());   

				patchBreakContinue(breakstacklist, nextquadlabel());
				popstacklist(breakstacklist);
				patchBreakContinue(contstacklist, (int)($1->numConst));
				popstacklist(contstacklist);
			}
			;

N: 			{ $$ = nextquadlabel();  emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);  };

M: 			{  $$ = nextquadlabel(); };

forprefix:  FOR LEFT_PARENTHESIS{makeFinalEmits = 0;} elist  SEMICOLON M expr SEMICOLON{
				FINALemits($7, yylineno); 	
				$$ = malloc(sizeof(struct forVar));
				$$->test = $6; $$->enter = nextquadlabel();
				emit(if_eq, newexpr_constnum(1), $7, newexpr_constbool('1'), currQuad, yylineno);
				
			}
			;

forstmt:	forprefix N elist RIGHT_PARENTHESIS{ prev = infunc; infunc = 0; ++loopcounter;
					breaklist_head = newstmt(-1); contlist_head = newstmt(-1);
					pushstacklist(breakstacklist, breaklist_head); pushstacklist(contstacklist, contlist_head);
			} N stmt N {
				--loopcounter; infunc = prev;
				patchlabel($1->enter, $6+1);
				patchlabel($2, nextquadlabel());
				patchlabel($6, $1->test);
				patchlabel($8, $2+1);

				patchBreakContinue(breakstacklist, nextquadlabel());
				popstacklist(breakstacklist);
				patchBreakContinue(contstacklist, $2+1);
				popstacklist(contstacklist);
			}
			;
		
returnstmt: RETURN{afterAssign = 0; inReturn = 1;  /*emit(jump, newexpr_constnum(0), (expr*) 0, (expr*) 0, currQuad, yylineno); */
			if(!infunc){yyerror("Use of 'return' while not in a function");}} expr  SEMICOLON { inReturn = 1; emit(ret, $3, (expr *) 0, (expr *) 0,currQuad, yylineno); }
			| RETURN{if(!infunc){yyerror("Use of 'return' while not in a function");}} SEMICOLON	{emit(ret, (expr *) 0, (expr *) 0, (expr *) 0,currQuad, yylineno);}		
			;

%%

int yyerror (char* yaccProvideMessage){
	printIntermediate = 1;
	fprintf(stderr, "ERROR, %s token: %s, at line %d\n",yaccProvideMessage, yytext, yylineno);
}

int main(int argc, char** argv) {
	FILE *f = fopen("IntermediateCodefile.txt", "w");
		
	tmp_expr = newexpr(var_e);
	functionLocalsStack = malloc(sizeof(struct stack));
	functionLocalsStack->top = -1;
	loopcounterstack = malloc(sizeof(struct stack));
	loopcounterstack->top = -1;
	breakstacklist = malloc(sizeof(struct stacklist));
	breakstacklist->top = -1;
	contstacklist = malloc(sizeof(struct stacklist));
	contstacklist->top = -1;
	
	myHashTable = newHashTable();
	insert_LIBFUNCTs();
	if(argc > 1){
		if(!(yyin = fopen(argv[1], "r"))){
			fprintf(stderr, "Cannot read file: %s\n", argv[1]);
			return 1;
		}
	}else{
		yyin = stdin;
	}
	
	yyparse();

	print_results();
	if (f == NULL){
    	printf("\nERROR, cannot open output file!\n");
	}
	if(!printIntermediate){
		printQuads(f);
	}else{
		printf("\nERROR at compile time!\n");
	}
	fclose(f);

	return 0;
}