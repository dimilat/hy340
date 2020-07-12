/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    FOR = 261,
    FUNCTION = 262,
    RETURN = 263,
    BREAK = 264,
    CONTINUE = 265,
    AND = 266,
    NOT = 267,
    OR = 268,
    LOCAL = 269,
    TRUE = 270,
    FALSE = 271,
    NIL = 272,
    ASSIGN = 273,
    ADD = 274,
    MINUS = 275,
    MULTIPLICATION = 276,
    DIVISION = 277,
    MODULO = 278,
    EQUAL = 279,
    INEQUAL = 280,
    INCREMENT = 281,
    DECREMENT = 282,
    GREATER = 283,
    GREATER_EQUAL = 284,
    LESS = 285,
    LESS_EQUAL = 286,
    LEFT_CURLY_BRACKET = 287,
    RIGHT_CURLY_BRACKET = 288,
    LEFT_SQUARE_BRACKET = 289,
    RIGHT_SQUARE_BRACKET = 290,
    LEFT_PARENTHESIS = 291,
    RIGHT_PARENTHESIS = 292,
    SEMICOLON = 293,
    COMMA = 294,
    COLON = 295,
    DOUBLE_COLON = 296,
    DOT = 297,
    DOUBLE_DOT = 298,
    SINGLE_LINE_COMMENT = 299,
    OTHERCHAR = 300,
    IDENT = 301,
    INTEGER = 302,
    REAL = 303,
    STRINGCONST = 304,
    UMINUS = 305
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define WHILE 260
#define FOR 261
#define FUNCTION 262
#define RETURN 263
#define BREAK 264
#define CONTINUE 265
#define AND 266
#define NOT 267
#define OR 268
#define LOCAL 269
#define TRUE 270
#define FALSE 271
#define NIL 272
#define ASSIGN 273
#define ADD 274
#define MINUS 275
#define MULTIPLICATION 276
#define DIVISION 277
#define MODULO 278
#define EQUAL 279
#define INEQUAL 280
#define INCREMENT 281
#define DECREMENT 282
#define GREATER 283
#define GREATER_EQUAL 284
#define LESS 285
#define LESS_EQUAL 286
#define LEFT_CURLY_BRACKET 287
#define RIGHT_CURLY_BRACKET 288
#define LEFT_SQUARE_BRACKET 289
#define RIGHT_SQUARE_BRACKET 290
#define LEFT_PARENTHESIS 291
#define RIGHT_PARENTHESIS 292
#define SEMICOLON 293
#define COMMA 294
#define COLON 295
#define DOUBLE_COLON 296
#define DOT 297
#define DOUBLE_DOT 298
#define SINGLE_LINE_COMMENT 299
#define OTHERCHAR 300
#define IDENT 301
#define INTEGER 302
#define REAL 303
#define STRINGCONST 304
#define UMINUS 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 29 "parser.y" /* yacc.c:1909  */

	char*	stringValue;
	int		intValue;
	double	doubleValue;
	struct expr* node;
	struct forVar* forpref;
	struct stmt* stmt_node;

#line 163 "parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
