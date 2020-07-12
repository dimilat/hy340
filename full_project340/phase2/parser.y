%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "SymTable.h"
	#define YY_DECL int alpha_yylex (void* ylval) 

	int yyerror (char* yaccProvidedMessage);
	int yylex(void);
	int dollar_counter = 0;
	char buffer[5];
	int scope = 0;
	int notInsert = 0;
	int global_LIB_use = 0;	/*flag gia LIB function pou einai se scope diaforetiko tou 0*/
	int not_accessible = 0;	/*flag gia an to an den exw prosvasi sto token*/
	int infunc = 0;			/*counter gia to an eimaste mesa se sunartisi*/
	int call_depth = 0; 	/*counter gia to an eimaste se call*/
	int islibfunc = 0;	 	/* flag gia to an einai library func*/
	int prev = 0; 			/*kratame to swsto vathos tis sunartisis*/
	int token_is_func = 0;
	int glo_bal = 0;
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
	struct SymbolTableEntry* node;
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
%left OR
%left AND
%nonassoc EQUAL INEQUAL
%nonassoc GREATER GREATER_EQUAL LESS LESS_EQUAL

%left ADD MINUS

%left MULTIPLICATION DIVISION MODULO

%right NOT DECREMENT INCREMENT
%nonassoc UMINUS

%left DOT DOUBLE_DOT

%left LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET

%left LEFT_PARENTHESIS RIGHT_PARENTHESIS

%left RIGHT_CURLY_BRACKET LEFT_CURLY_BRACKET

%type <node> lvalue

%expect 2 
%%

program:	stmt_list
			;

stmt:		expr SEMICOLON
			|ifstmt
			|whilestmt
			|forstmt
			|returnstmt
			|BREAK SEMICOLON
			|CONTINUE SEMICOLON
			|block
			|funcdef
			|SEMICOLON
			;

			
stmt_list:	stmt stmt_list
			|
			;


expr:		assignexpr
			|expr ADD expr 
			|expr MINUS expr 
			|expr MULTIPLICATION expr 
			|expr DIVISION expr 
			|expr MODULO expr 
			|expr GREATER expr 
			|expr GREATER_EQUAL expr 
			|expr LESS expr 
			|expr LESS_EQUAL expr 
			|expr EQUAL expr 
			|expr INEQUAL expr 
			|expr AND expr 
			|expr OR expr 
			|term
			;


term:		LEFT_PARENTHESIS expr RIGHT_PARENTHESIS 
			|UMINUS expr
			|NOT expr
			|INCREMENT lvalue {if(token_is_func){yyerror("cannot increment function value"); token_is_func = 0;}}
			|lvalue INCREMENT {if(token_is_func){yyerror("cannot increment function value"); token_is_func = 0;}}
			|DECREMENT lvalue {if(token_is_func){yyerror("cannot decrement function value"); token_is_func = 0;}}
			|lvalue DECREMENT {if(token_is_func){yyerror("cannot decrement function value"); token_is_func = 0;}}
			|primary
			;


assignexpr:	lvalue{		if($1 != NULL && $1->type == USERFUNC ){
							yyerror("variable already defined as function");
						}
				} ASSIGN{notInsert = 1;} expr {notInsert = 0;}
			;

primary:	lvalue { 
					if($1 != NULL && $1->type == USERFUNC && glo_bal){
						insert(scope, yylineno, LOCALVAR, yylval.stringValue);
						glo_bal = 0;
					}
					
					if($1 != NULL && $1->type == USERFUNC && !not_accessible){
						yyerror("variable already defined as function");
					}
					if(islibfunc){
						if(global_LIB_use){
							yyerror("Invalid insertion,, trying to shadow LIBFUNC, before"); 
							global_LIB_use = 0;
							islibfunc = 0;
						}else{
							if(notInsert){
								yyerror("Invalid insertion, trying to shadow LIBFUNC, before");
								notInsert = 0; 
							}
							islibfunc = 0;
						}
					}else if(not_accessible && notInsert && !call_depth){
						yyerror("Invalid insertion, before");
						not_accessible = 0;
						notInsert = 0;
					}
			}
			|call {global_LIB_use = 0;}
			|objectdef
			|LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS
			|const{
				if(islibfunc && !call_depth){
						yyerror("Invalid insertion, trying to shadow LIBFUNC, before"); 
						islibfunc = 0;
				}
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
						$$ = tmp_rec;
					}else if( (tmp_rec = lookup(yylval.stringValue, scope)) != NULL){
						not_accessible = 0;
						notInsert = 1;
						islibfunc = 0;
						$$ = tmp_rec;
					}else if( (tmp_rec = lookupFormal(yylval.stringValue, scope)) != NULL){
						islibfunc = 0;
						not_accessible = 0;
						notInsert = 1;
						$$ = tmp_rec;
					}else if( (tmp_rec = lookupAbove(yylval.stringValue, scope)) != NULL){
						if(infunc){
							if(tmp_rec->type == USERFUNC){
								//insert(scope, yylineno, LOCALVAR, yylval.stringValue);
							}else{
								yyerror("variable is not accesible in function");
							}
						}
						not_accessible = 1;
						islibfunc = 0;
						notInsert = 1;
						$$ = tmp_rec;
					}else if( (tmp_rec = lookup(yylval.stringValue, 0)) != NULL){
						glo_bal = 1;
						not_accessible = 0;
						notInsert = 1;
						islibfunc = 0;
						$$ = tmp_rec;
					}else if(notInsert){
						yyerror("NOT INSERT");
						notInsert = 0;
						islibfunc = 0;
						$$ = tmp_rec;
						
					}else{
						
						islibfunc =0;
						if(!call_depth){
								if(scope == 0){
									
									insert(scope, yylineno, GLOBAL, yylval.stringValue);
								}else{
									insert(scope, yylineno, LOCALVAR, yylval.stringValue);
								}
						}
						$$ = tmp_rec;
					}
					/* i parakatw if einai gia increment decrement error checking for functions*/
					
					if(tmp_rec != NULL && (tmp_rec->type == USERFUNC || tmp_rec->type == LIBFUNC)){
						token_is_func = 1;
					}else{
						token_is_func = 0;
					}
				}
			|LOCAL IDENT{	
							if(scope && ((tmp_rec = lookupLIBFUNCTs(yylval.stringValue)) !=NULL)){
								yyerror("Invalid insertion, trying to shadow LIBFUNC");
								$$ = tmp_rec;
							}else if((tmp_rec = lookup(yylval.stringValue, scope)) != NULL){
								$$ = tmp_rec;
							}else if((tmp_rec = lookupFormal(yylval.stringValue, scope)) != NULL){
								$$ = tmp_rec;
							}else{
								if(scope == 0){
									insert(scope, yylineno, GLOBAL, yylval.stringValue);
								}else{
									insert(scope, yylineno, LOCALVAR, yylval.stringValue);
								}
								$$ = tmp_rec;
							}
						}
			|DOUBLE_COLON IDENT {
						if((tmp_rec = lookup(yylval.stringValue, 0)) == NULL){
							yyerror("undefined global variable");
							$$ = tmp_rec;
						}
				}
			|member
			;

member:		lvalue DOT IDENT 
			|lvalue LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET
			|call DOT IDENT {islibfunc = 0;}
			|call LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET 
			;

call:		
			call LEFT_PARENTHESIS elist	RIGHT_PARENTHESIS 
			|lvalue callsuffix 
			|LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS
			;


callsuffix:	normcall
			|methodcall
			;

normcall:	LEFT_PARENTHESIS{call_depth++; } elist RIGHT_PARENTHESIS {call_depth--;}
			;

methodcall:	DOUBLE_DOT IDENT LEFT_PARENTHESIS elist RIGHT_PARENTHESIS
			;

elist:		expr elist_expressions
			|
			;

elist_expressions: COMMA expr elist_expressions
					|
					;

objectdef:	LEFT_SQUARE_BRACKET elist RIGHT_SQUARE_BRACKET
			|LEFT_SQUARE_BRACKET indexed RIGHT_SQUARE_BRACKET
			;

indexed:	indexedelem indexedelem_list
			;

indexedelem_list:	COMMA indexedelem indexedelem_list
					|
					;

indexedelem:LEFT_CURLY_BRACKET expr COLON{notInsert = 0; } expr RIGHT_CURLY_BRACKET {notInsert = 1;} 
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
								insert(scope, yylineno, USERFUNC, yylval.stringValue);
							}

						} LEFT_PARENTHESIS{scope++;} idlist RIGHT_PARENTHESIS{scope--;} block {infunc--;}
			|FUNCTION{	
						infunc++;
						sprintf(buffer, "$%d", dollar_counter);
						insert(scope, yylineno, USERFUNC, buffer);
						dollar_counter++;
					}
					LEFT_PARENTHESIS{scope++;} idlist RIGHT_PARENTHESIS{scope--;} block {infunc--;}
			
			;

const:		INTEGER
			| REAL
			| STRINGCONST
			| NIL {notInsert = 0;}
			| TRUE {notInsert = 0;}
			| FALSE {notInsert = 0;}
			;

idlist:		IDENT{
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

idlist_list:COMMA IDENT {
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

ifstmt:		IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt
			|IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt
			;
		
whilestmt: 	WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt
			;
			
forstmt:	FOR LEFT_PARENTHESIS elist  SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS{ prev = infunc; infunc = 0;} stmt {infunc = prev;}
			;
		
returnstmt: RETURN{notInsert = 0;} expr  SEMICOLON	{notInsert = 1;}
			| RETURN SEMICOLON			;

%%

int yyerror (char* yaccProvideMessage){
	fprintf(stderr, "ERROR, %s token: %s, at line %d\n",yaccProvideMessage, yytext, yylineno);
	//fprintf(stderr, "INPUT NOT VALID\n");
}

int main(int argc, char** argv) {
	
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
	return 0;
}