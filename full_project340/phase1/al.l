%{
    /*
     *  HY340, Phase1
     *
     *  Manos Smyrnakis
     *  Giwrgos Kostomanwlakis
     *  Dimitris Milathianakis
     */
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define YY_DECL int alpha_yylex (void* ylval) /*parametrized yylex*/

	typedef struct alpha_token_t{
		int line_num;
		int token_num;
		char* token_context;
		char* token_category;
		char* types_var;
		char* regex_name;
		struct alpha_token_t* next;
	} al_token;

	al_token* Lhead = NULL;
	int token_num_count = 0;
	int comm_nest_counter = 0;

	al_token* Token_Set(char* regex_name_par, char* types_var_par, int line_num_par, int token_num_par, char* token_context_par, char* token_category_par, al_token* L){
		al_token* temp=L;
		al_token* node=(al_token*)malloc(sizeof(al_token));
		
		node->regex_name = strdup(regex_name_par); /*strdup copies dup strings plus '\0'*/
		node->types_var = types_var_par;
		node->line_num = line_num_par;
		node->token_num = token_num_par;
		node->token_context = strdup(token_context_par); /*strdup copies dup strings plus '\0'*/
		node->token_category = token_category_par;
		node->next = NULL;

		if(temp == NULL){
			temp = node;
			return temp;
		}else{
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = node;
			return L;
		}
	}

	void print_list(al_token* L){
		al_token* temp = L;

		if(temp == NULL){
			printf("====> Empty List, NO text included to your file!\n");
		}else{
			while(temp != NULL){
				if(temp->token_category == "STRINGCONST"){
					printf("%d: #%d\t%s\t%s %s <- %s\n", 
					temp->line_num, temp->token_num, temp->token_context, temp->token_category, temp->regex_name, temp->types_var);
				}else if(temp->token_category == "IDENT"){
					printf("%d: #%d\t\"%s\"\t%s \"%s\" <- %s\n", 
					temp->line_num, temp->token_num, temp->token_context, temp->token_category, temp->regex_name, temp->types_var);
				}else if(temp->token_category == "NESTED_COMMENT" || temp->token_category == "MULTILINE_COMMENT"){
					printf("%d: #%d\t\"/* %s */\"\t%s  %s <- %s\n", 
					temp->line_num, temp->token_num, temp->token_context, temp->token_category, temp->regex_name, temp->types_var);
				}else{
					printf("%d: #%d\t\"%s\"\t%s  %s <- %s\n", 
					temp->line_num, temp->token_num, temp->token_context, temp->token_category, temp->regex_name, temp->types_var);
				}
				temp = temp->next;
			}
		}
	}
%}

%option yylineno
%option	noyywrap
%option	prefix = "PREFIX"

IF 					"if"
ELSE 				"else"
WHILE 				"while"
FOR 				"for"
FUNCTION 			"function"
RETURN 				"return"
BREAK 				"break"
CONTINUE 			"continue"
AND 				"and"
NOT 				"not"
OR 					"or"
LOCAL 				"local"
TRUE 				"true"
FALSE 				"false"
NIL 				"nil"

ASSIGN 				"="
ADD 				"+"
MINUS 				"-"
MULTIPLICATION 		"*"
DIVISION 			"/"
MODULO 				"%"
EQUAL 				"=="
INEQUAL 			"!="
INCREMENT 			"++"
DECREMENT 			"--"
GREATER 			">"
GREATER_EQUAL 		">="
LESS 				"<"
LESS_EQUAL 			"<="

LEFT_CURLY_BRACKET	 	"{"
RIGHT_CURLY_BRACKET		"}"
LEFT_SQUARE_BRACKET	 	"["
RIGHT_SQUARE_BRACKET	"]"
LEFT_PARENTHESIS		"("
RIGHT_PARENTHESIS		")"
SEMICOLON				";"
COMMA					","
COLON					":"
DOUBLE_COLON			"::"
DOT						"."
DOUBLE_DOT				".."
SINGLE_LINE_COMMENT		"//"[^\n]*

IDENT 		[a-zA-Z][a-zA-Z_0-9]*
INTEGER 	(0[xX][0-9A-Fa-f]+)|([0-9]+)
REAL 		[0-9]*\.[0-9](e|E)?[0-9]*


%%

{IF} 		{Lhead = Token_Set("IF","enumerated",yylineno,++token_num_count,"if","KEYWORD",Lhead);}
{ELSE} 		{Lhead = Token_Set("ELSE","enumerated",yylineno,++token_num_count,"else","KEYWORD",Lhead);}
{WHILE} 	{Lhead = Token_Set("WHILE","enumerated",yylineno,++token_num_count,"while","KEYWORD",Lhead);}
{FOR} 		{Lhead = Token_Set("FOR","enumerated",yylineno,++token_num_count,"for","KEYWORD",Lhead);}
{FUNCTION} 	{Lhead = Token_Set("FUNCTION","enumerated",yylineno,++token_num_count,"function","KEYWORD",Lhead);}
{RETURN} 	{Lhead = Token_Set("RETURN","enumerated",yylineno,++token_num_count,"return","KEYWORD",Lhead);}
{BREAK} 	{Lhead = Token_Set("BREAK","enumerated",yylineno,++token_num_count,"break","KEYWORD",Lhead);}
{CONTINUE} 	{Lhead = Token_Set("CONTINUE","enumerated",yylineno,++token_num_count,"continue","KEYWORD",Lhead);}
{AND} 		{Lhead = Token_Set("AND","enumerated",yylineno,++token_num_count,"and","KEYWORD",Lhead);}
{NOT} 		{Lhead = Token_Set("NOT","enumerated",yylineno,++token_num_count,"not","KEYWORD",Lhead);}
{OR} 		{Lhead = Token_Set("OR","enumerated",yylineno,++token_num_count,"or","KEYWORD",Lhead);}
{LOCAL} 	{Lhead = Token_Set("LOCAL","enumerated",yylineno,++token_num_count,"local","KEYWORD",Lhead);}
{TRUE} 		{Lhead = Token_Set("TRUE","enumerated",yylineno,++token_num_count,"true","KEYWORD",Lhead);}
{FALSE} 	{Lhead = Token_Set("FALSE","enumerated",yylineno,++token_num_count,"false","KEYWORD",Lhead);}
{NIL} 		{Lhead = Token_Set("NIL","enumerated",yylineno,++token_num_count,"nil","KEYWORD",Lhead);}

{ASSIGN} 			{Lhead=Token_Set("ASSIGN","enumerated",yylineno,++token_num_count,"=","OPERATOR",Lhead);}
{ADD} 				{Lhead=Token_Set("ADD","enumerated",yylineno,++token_num_count,"+","OPERATOR",Lhead);}
{MINUS} 			{Lhead=Token_Set("MINUS","enumerated",yylineno,++token_num_count,"-","OPERATOR",Lhead);}
{MULTIPLICATION} 	{Lhead=Token_Set("MULTIPLICATION","enumerated",yylineno,++token_num_count,"*","OPERATOR",Lhead);}
{DIVISION} 			{Lhead=Token_Set("DIVISION","enumerated",yylineno,++token_num_count,"/","OPERATOR",Lhead);}
{MODULO} 			{Lhead=Token_Set("MODULO","enumerated",yylineno,++token_num_count,"%","OPERATOR",Lhead);}
{EQUAL} 			{Lhead=Token_Set("EQUAL","enumerated",yylineno,++token_num_count,"==","OPERATOR",Lhead);}
{INEQUAL} 			{Lhead=Token_Set("INEQUAL","enumerated",yylineno,++token_num_count,"!=","OPERATOR",Lhead);}
{INCREMENT} 		{Lhead=Token_Set("INCREMENT","enumerated",yylineno,++token_num_count,"++","OPERATOR",Lhead);}
{DECREMENT} 		{Lhead=Token_Set("DECREMENT","enumerated",yylineno,++token_num_count,"--","OPERATOR",Lhead);}
{GREATER} 			{Lhead=Token_Set("GREATER","enumerated",yylineno,++token_num_count,">","OPERATOR",Lhead);}
{GREATER_EQUAL} 	{Lhead=Token_Set("GREATER_EQUAL","enumerated",yylineno,++token_num_count,">=","OPERATOR",Lhead);}
{LESS} 				{Lhead=Token_Set("LESS","enumerated",yylineno,++token_num_count,"<","OPERATOR",Lhead);}
{LESS_EQUAL} 		{Lhead=Token_Set("LESS_EQUAL","enumerated",yylineno,++token_num_count,"<=","OPERATOR",Lhead);}

{IDENT} 	{Lhead = Token_Set(yytext,"char*",yylineno, ++token_num_count, yytext,"IDENT", Lhead);}
{INTEGER}	{Lhead = Token_Set(yytext,"integer",yylineno, ++token_num_count, yytext,"INTCONST", Lhead);}
{REAL} 		{Lhead = Token_Set(yytext,"real",yylineno, ++token_num_count, yytext,"FLOATCONST", Lhead);}
\"			{
				int line_no = yylineno;
				int c;
				int j = 0;
				int flag_close_string = 0;
				char* buff = malloc(sizeof(char));
				while((c = input()) != EOF){
					if(c == '\\'){
						if((c = input()) == '\"'){
							*(buff+j) = '\"';
						}else if(c == 't'){ /*den auxanw to i giati exei auxithi apo panw*/
                            *(buff+j) = '\t';
						}else if(c == '\\'){
							*(buff+j) = '\\';
						}else if(c == 'n'){
							*(buff+j) = '\n';			
						}else{
							printf("WARNING, INVALID ESCAPE CHARACTER \\%c, line: %d.\n", c, yylineno);
                            *(buff+j) = c;
                        }
					}else if(c == '\"'){
						flag_close_string = 1;
						break;
					}else{
						*(buff+j) = c;
					}
					j++;
					buff = realloc(buff, (j+1) * sizeof(char));
				}
				*(buff+j) = '\0';
				if(!flag_close_string){
					fprintf(stderr, "ERROR, STRING DOESNT CLOSE! STARTS IN LINE: %d.\n", line_no);
				}else{
					Lhead = Token_Set(buff,"char*",yylineno, ++token_num_count, buff,"STRINGCONST", Lhead);
				}
                free(buff);
			}


{LEFT_CURLY_BRACKET}	{Lhead=Token_Set("LEFT_CURLY_BRACKET","enumerated",yylineno, ++token_num_count, "{","PUNCTUATION", Lhead);}
{RIGHT_CURLY_BRACKET}	{Lhead=Token_Set("RIGHT_CURLY_BRACKET","enumerated",yylineno, ++token_num_count, "}","PUNCTUATION", Lhead);}
{LEFT_SQUARE_BRACKET}	{Lhead=Token_Set("LEFT_SQUARE_BRACKET","enumerated",yylineno, ++token_num_count, "[","PUNCTUATION", Lhead);}
{RIGHT_SQUARE_BRACKET}	{Lhead=Token_Set("RIGHT_SQUARE_BRACKET","enumerated",yylineno, ++token_num_count, "]","PUNCTUATION", Lhead);}
{LEFT_PARENTHESIS}		{Lhead=Token_Set("LEFT_PARENTHESIS","enumerated",yylineno, ++token_num_count, "(","PUNCTUATION", Lhead);}
{RIGHT_PARENTHESIS}		{Lhead=Token_Set("RIGHT_PARENTHESIS","enumerated",yylineno, ++token_num_count, ")","PUNCTUATION", Lhead);}
{SEMICOLON}				{Lhead=Token_Set("SEMICOLON","enumerated",yylineno, ++token_num_count, ";","PUNCTUATION", Lhead);}
{COMMA}					{Lhead=Token_Set("COMMA","enumerated",yylineno, ++token_num_count, ",","PUNCTUATION", Lhead);}
{COLON}					{Lhead=Token_Set("COLON","enumerated",yylineno, ++token_num_count, ":","PUNCTUATION", Lhead);}
{DOUBLE_COLON}			{Lhead=Token_Set("DOUBLE_COLON","enumerated",yylineno, ++token_num_count, "::","PUNCTUATION", Lhead);}
{DOT}					{Lhead=Token_Set("DOT","enumerated",yylineno, ++token_num_count, ".","PUNCTUATION", Lhead);}
{DOUBLE_DOT}			{Lhead=Token_Set("DOUBLE_DOT","enumerated",yylineno, ++token_num_count, "..","PUNCTUATION", Lhead);}
{SINGLE_LINE_COMMENT}	{Lhead=Token_Set("COMMENT","enumerated",yylineno, ++token_num_count, "//","SINGLE_LINE_COMMENT", Lhead);}
"\n"					{ }
" "						{ }
"\t"					{ }
"/*"					{   
                            int flag_for_nestedComments = 1;
							int c;
							int open_comment_counter = 0;
							int close_comment_counter = 0;
							int comm_nest_counter = 1; 		/*starts 1 because we have already read one*/
							while((c = input()) != EOF){
								if(c == '/'){
									if((c = input()) == '*'){
                                        if(comm_nest_counter==1 && flag_for_nestedComments==1){ /*first nested*/
                                        	Lhead=Token_Set("COMMENT","enumerated", yylineno, ++token_num_count, "", "NESTED_COMMENT", Lhead);
                                        	flag_for_nestedComments=0;
                                        }
                                        open_comment_counter++;
										++comm_nest_counter;
										if(open_comment_counter>=2){
											Lhead=Token_Set("COMMENT","enumerated", yylineno, ++token_num_count, "", "NESTED_COMMENT", Lhead);
										}

									}else{
										unput(c);
									}
								}else if(c == '*'){
									if((c = input()) == '/'){
                                        --comm_nest_counter;
										if(comm_nest_counter == 0){
											break;
										}
										if(close_comment_counter==0){ 	/*first multiline comment*/
											Lhead=Token_Set("COMMENT","enumerated", yylineno, ++token_num_count, "", "MULTILINE_COMMENT", Lhead);
											close_comment_counter++;
										}else if(open_comment_counter>close_comment_counter){
											close_comment_counter++;
										}
										if(close_comment_counter==open_comment_counter){ /*starts counting comments from the start*/
											close_comment_counter=0;
											open_comment_counter=0;
										}
									}else{
										unput(c);
									}
								}
							}
                            if(comm_nest_counter > 0){
                                fprintf(stderr, "ERROR, nested comment doesnt close, line: %d\n", yylineno);
                                exit(0);
                            }
                            if(flag_for_nestedComments==1){ /*single multiline comment*/
                            	Lhead=Token_Set("COMMENT","enumerated", yylineno, ++token_num_count, "", "MULTILINE_COMMENT", Lhead);
                            }
							
						}

.                       {fprintf(stderr,"ERROR, UNDEFINED CHARACTER %s FOUND! line: %d\n",yytext, yylineno); /*dot is for all undef chars*/}

%%

int main(int argc, char** argv) {
	if(argc > 1){
		if(!(yyin = fopen(argv[1], "r"))){
			fprintf(stderr, "Cannot read file: %s\n", argv[1]);
			return 1;
		}
	}else{
		yyin = stdin;
	}

	alpha_yylex(NULL);
	print_list(Lhead);
	return 0;
}