/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */


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


#line 96 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
#line 33 "parser.y" /* yacc.c:355  */

	char*	stringValue;
	int		intValue;
	double	doubleValue;
	struct SymbolTableEntry* node;

#line 243 "parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 258 "parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   531

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   134,   135,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     157,   158,   159,   160,   161,   162,   163,   164,   168,   171,
     168,   174,   201,   202,   203,   204,   212,   276,   293,   299,
     302,   303,   304,   305,   309,   310,   311,   315,   316,   319,
     319,   322,   325,   326,   329,   330,   333,   334,   337,   340,
     341,   344,   344,   347,   347,   348,   351,   351,   362,   362,
     351,   363,   369,   369,   363,   373,   374,   375,   376,   377,
     378,   381,   381,   390,   393,   393,   402,   405,   406,   409,
     412,   412,   415,   415,   416
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "FOR", "FUNCTION",
  "RETURN", "BREAK", "CONTINUE", "AND", "NOT", "OR", "LOCAL", "TRUE",
  "FALSE", "NIL", "ASSIGN", "ADD", "MINUS", "MULTIPLICATION", "DIVISION",
  "MODULO", "EQUAL", "INEQUAL", "INCREMENT", "DECREMENT", "GREATER",
  "GREATER_EQUAL", "LESS", "LESS_EQUAL", "LEFT_CURLY_BRACKET",
  "RIGHT_CURLY_BRACKET", "LEFT_SQUARE_BRACKET", "RIGHT_SQUARE_BRACKET",
  "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "SEMICOLON", "COMMA", "COLON",
  "DOUBLE_COLON", "DOT", "DOUBLE_DOT", "SINGLE_LINE_COMMENT", "OTHERCHAR",
  "IDENT", "INTEGER", "REAL", "STRINGCONST", "UMINUS", "$accept",
  "program", "stmt", "stmt_list", "expr", "term", "assignexpr", "$@1",
  "$@2", "primary", "lvalue", "member", "call", "callsuffix", "normcall",
  "$@3", "methodcall", "elist", "elist_expressions", "objectdef",
  "indexed", "indexedelem_list", "indexedelem", "$@4", "block", "$@5",
  "funcdef", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "const",
  "idlist", "$@13", "idlist_list", "$@14", "ifstmt", "whilestmt",
  "forstmt", "$@15", "returnstmt", "$@16", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -178

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-178)))

#define YYTABLE_NINF -82

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-82)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      86,   -32,   -29,   -21,   -12,   -11,    -4,    11,   195,     2,
    -178,  -178,  -178,     4,     4,    18,   167,   139,  -178,     8,
    -178,  -178,  -178,  -178,   195,    55,    86,  -178,   270,  -178,
    -178,  -178,   -13,  -178,   -14,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,   195,   195,   195,    12,    20,  -178,   195,
    -178,  -178,  -178,  -178,    50,   -17,   -14,   -17,  -178,    86,
     195,   249,    24,    25,    23,   333,    39,  -178,  -178,  -178,
    -178,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,  -178,  -178,  -178,   195,  -178,    31,
      32,    62,  -178,  -178,  -178,   195,   195,    35,   354,   375,
      44,  -178,  -178,   291,    46,    51,   227,   195,  -178,  -178,
    -178,    53,  -178,  -178,    54,   487,   474,    10,    10,  -178,
    -178,  -178,   500,   500,   204,   204,   204,   204,   396,   195,
    -178,    61,  -178,   417,    68,  -178,    86,    86,   195,    70,
      63,  -178,    54,  -178,  -178,   249,    23,   195,  -178,    71,
     195,   195,  -178,  -178,   106,  -178,   312,  -178,  -178,    74,
     195,  -178,  -178,    77,  -178,    78,   459,    86,   195,    63,
      80,  -178,   438,  -178,  -178,  -178,    79,    89,    82,  -178,
      85,  -178,  -178,  -178,  -178,  -178,    86,    85,    80,  -178,
    -178,  -178
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      14,     0,     0,     0,    76,   102,     0,     0,     0,     0,
      89,    90,    88,     0,     0,    73,    63,     0,    12,     0,
      46,    85,    86,    87,     0,     0,    14,     2,     0,    29,
      15,    37,    41,    49,    42,    43,    10,    11,    45,     4,
       5,     6,     7,     0,     0,    63,     0,     0,   104,     0,
       8,     9,    32,    47,     0,    33,     0,    35,    75,    14,
       0,    65,     0,     0,    70,     0,     0,    48,    31,     1,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,    34,    36,     0,    59,     0,
       0,     0,    55,    57,    58,     0,    63,     0,     0,     0,
       0,    77,    82,     0,     0,     0,     0,     0,    62,    66,
      67,     0,    68,    30,    44,    27,    28,    16,    17,    18,
      19,    20,    25,    26,    21,    22,    23,    24,     0,    63,
      50,     0,    39,     0,     0,    52,     0,     0,     0,     0,
      93,   103,     0,    74,    71,    65,    70,    63,    51,     0,
      63,     0,    53,    54,    97,    99,     0,    78,    91,     0,
       0,    64,    69,     0,    60,     0,    40,     0,    63,    93,
      96,    83,     0,    56,    61,    98,     0,     0,     0,    92,
       0,    72,   100,    79,    94,    84,     0,     0,    96,   101,
      80,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,  -125,   -20,    -8,  -178,  -178,  -178,  -178,  -178,
      30,  -178,    33,  -178,  -178,  -178,  -178,   -43,   -22,  -178,
    -178,   -15,    26,  -178,  -177,  -178,   -16,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,   -40,  -178,   -50,  -178,  -178,
    -178,  -178,  -178,  -178,  -178
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    91,   151,    31,
      32,    33,    34,    92,    93,   129,    94,    62,   108,    35,
      63,   112,    64,   160,    36,    59,    37,    46,   139,   169,
     187,    47,   140,   180,    38,   159,   170,   179,   188,    39,
      40,    41,   186,    42,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    66,   100,   185,    43,   -38,    70,    44,    61,    65,
     190,   154,   155,    85,    86,    45,    68,    87,     9,    88,
      95,    87,    96,    88,   -81,    89,    90,    48,    97,    89,
      90,    75,    76,    77,    50,    98,    99,    61,   104,   105,
      54,   103,   175,    55,    57,    19,    56,    56,    53,    51,
      20,    58,   106,   134,    67,    69,   102,     4,   101,   109,
     110,   189,   111,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   114,   130,   131,   128,
     132,   135,   138,   142,   143,    60,   149,   133,    61,     1,
     147,     2,     3,     4,     5,     6,     7,   150,     8,   145,
       9,    10,    11,    12,   163,   153,   157,   165,   164,   158,
     167,   171,    13,    14,   173,   174,   182,    15,    15,   178,
      16,    61,    17,   161,    18,   176,   183,    19,   184,   177,
     156,   162,    20,    21,    22,    23,    24,   146,   191,    61,
       0,     0,    61,   166,     0,     0,     4,     0,     0,     0,
       0,     8,   172,     9,    10,    11,    12,     0,     0,     0,
      61,     0,     0,     0,     0,    13,    14,     0,     0,     0,
       0,     0,     0,    16,     0,    17,     0,     0,     0,     8,
      19,     9,    10,    11,    12,    20,    21,    22,    23,    24,
       0,     0,     0,    13,    14,     0,     0,     0,     0,    60,
       0,    16,     0,    17,     0,     0,     0,     8,    19,     9,
      10,    11,    12,    20,    21,    22,    23,    24,     0,     0,
       0,    13,    14,    73,    74,    75,    76,    77,     0,    16,
       0,    17,   -82,   -82,   -82,   -82,    19,     0,    71,     0,
      72,    20,    21,    22,    23,    24,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    80,    81,    82,    83,     0,
      71,     0,    72,     0,     0,     0,     0,   144,    73,    74,
      75,    76,    77,    78,    79,     0,     0,    80,    81,    82,
      83,    71,     0,    72,     0,     0,     0,     0,   107,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    80,    81,
      82,    83,    71,     0,    72,     0,     0,     0,    84,     0,
      73,    74,    75,    76,    77,    78,    79,     0,     0,    80,
      81,    82,    83,    71,     0,    72,     0,     0,     0,   141,
       0,    73,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,    82,    83,    71,     0,    72,     0,     0,     0,
     168,     0,    73,    74,    75,    76,    77,    78,    79,     0,
       0,    80,    81,    82,    83,    71,     0,    72,     0,     0,
     113,     0,     0,    73,    74,    75,    76,    77,    78,    79,
       0,     0,    80,    81,    82,    83,    71,     0,    72,     0,
       0,   136,     0,     0,    73,    74,    75,    76,    77,    78,
      79,     0,     0,    80,    81,    82,    83,    71,     0,    72,
       0,     0,   137,     0,     0,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,    82,    83,    71,     0,
      72,   148,     0,     0,     0,     0,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    80,    81,    82,    83,    71,
       0,    72,   152,     0,     0,     0,     0,    73,    74,    75,
      76,    77,    78,    79,     0,     0,    80,    81,    82,    83,
      71,   181,    72,     0,     0,     0,     0,     0,    73,    74,
      75,    76,    77,    78,    79,    71,     0,    80,    81,    82,
      83,     0,     0,    73,    74,    75,    76,    77,    78,    79,
       0,     0,    80,    81,    82,    83,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    80,    81,    82,    83,    73,
      74,    75,    76,    77,   -82,   -82,     0,     0,    80,    81,
      82,    83
};

static const yytype_int16 yycheck[] =
{
       8,    17,    45,   180,    36,    18,    26,    36,    16,    17,
     187,   136,   137,    26,    27,    36,    24,    34,    14,    36,
      34,    34,    36,    36,    36,    42,    43,    38,    42,    42,
      43,    21,    22,    23,    38,    43,    44,    45,    54,    59,
      36,    49,   167,    13,    14,    41,    13,    14,    46,    38,
      46,    33,    60,    96,    46,     0,    36,     7,    46,    35,
      35,   186,    39,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    37,    46,    46,    87,
      18,    46,    38,    37,    33,    32,   129,    95,    96,     3,
      36,     5,     6,     7,     8,     9,    10,    36,    12,   107,
      14,    15,    16,    17,   147,    37,    36,   150,    37,    46,
       4,    37,    26,    27,    37,    37,    37,    32,    32,    39,
      34,   129,    36,   145,    38,   168,    37,    41,    46,   169,
     138,   146,    46,    47,    48,    49,    50,   111,   188,   147,
      -1,    -1,   150,   151,    -1,    -1,     7,    -1,    -1,    -1,
      -1,    12,   160,    14,    15,    16,    17,    -1,    -1,    -1,
     168,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    36,    -1,    -1,    -1,    12,
      41,    14,    15,    16,    17,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    32,
      -1,    34,    -1,    36,    -1,    -1,    -1,    12,    41,    14,
      15,    16,    17,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    26,    27,    19,    20,    21,    22,    23,    -1,    34,
      -1,    36,    28,    29,    30,    31,    41,    -1,    11,    -1,
      13,    46,    47,    48,    49,    50,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    31,    -1,
      11,    -1,    13,    -1,    -1,    -1,    -1,    40,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    11,    -1,    13,    -1,    -1,    -1,    -1,    39,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    11,    -1,    13,    -1,    -1,    -1,    38,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    11,    -1,    13,    -1,    -1,    -1,    38,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    11,    -1,    13,    -1,    -1,    -1,
      38,    -1,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    11,    -1,    13,    -1,    -1,
      37,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    11,    -1,    13,    -1,
      -1,    37,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    11,    -1,    13,
      -1,    -1,    37,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    11,    -1,
      13,    35,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    31,    11,
      -1,    13,    35,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      11,    33,    13,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    11,    -1,    28,    29,    30,
      31,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    31,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    12,    14,
      15,    16,    17,    26,    27,    32,    34,    36,    38,    41,
      46,    47,    48,    49,    50,    52,    53,    54,    55,    56,
      57,    60,    61,    62,    63,    70,    75,    77,    85,    90,
      91,    92,    94,    36,    36,    36,    78,    82,    38,    95,
      38,    38,    55,    46,    36,    61,    63,    61,    33,    76,
      32,    55,    68,    71,    73,    55,    77,    46,    55,     0,
      54,    11,    13,    19,    20,    21,    22,    23,    24,    25,
      28,    29,    30,    31,    38,    26,    27,    34,    36,    42,
      43,    58,    64,    65,    67,    34,    36,    42,    55,    55,
      68,    46,    36,    55,    77,    54,    55,    39,    69,    35,
      35,    39,    72,    37,    37,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    66,
      46,    46,    18,    55,    68,    46,    37,    37,    38,    79,
      83,    38,    37,    33,    40,    55,    73,    36,    35,    68,
      36,    59,    35,    37,    53,    53,    55,    36,    46,    86,
      74,    69,    72,    68,    37,    68,    55,     4,    38,    80,
      87,    37,    55,    37,    37,    53,    68,    86,    39,    88,
      84,    33,    37,    37,    46,    75,    93,    81,    89,    53,
      75,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    58,    59,
      57,    60,    60,    60,    60,    60,    61,    61,    61,    61,
      62,    62,    62,    62,    63,    63,    63,    64,    64,    66,
      65,    67,    68,    68,    69,    69,    70,    70,    71,    72,
      72,    74,    73,    76,    75,    75,    78,    79,    80,    81,
      77,    82,    83,    84,    77,    85,    85,    85,    85,    85,
      85,    87,    86,    86,    89,    88,    88,    90,    90,    91,
      93,    92,    95,    94,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     2,     0,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     1,     0,     0,
       5,     1,     1,     1,     3,     1,     1,     2,     2,     1,
       3,     4,     3,     4,     4,     2,     6,     1,     1,     0,
       4,     5,     2,     0,     3,     0,     3,     3,     2,     3,
       0,     0,     6,     0,     4,     2,     0,     0,     0,     0,
      10,     0,     0,     0,     8,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     0,     4,     0,     5,     7,     5,
       0,    10,     0,     4,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 33:
#line 160 "parser.y" /* yacc.c:1646  */
    {if(token_is_func){yyerror("cannot increment function value"); token_is_func = 0;}}
#line 1548 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 161 "parser.y" /* yacc.c:1646  */
    {if(token_is_func){yyerror("cannot increment function value"); token_is_func = 0;}}
#line 1554 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 162 "parser.y" /* yacc.c:1646  */
    {if(token_is_func){yyerror("cannot decrement function value"); token_is_func = 0;}}
#line 1560 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 163 "parser.y" /* yacc.c:1646  */
    {if(token_is_func){yyerror("cannot decrement function value"); token_is_func = 0;}}
#line 1566 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 168 "parser.y" /* yacc.c:1646  */
    {		if((yyvsp[0].node) != NULL && (yyvsp[0].node)->type == USERFUNC ){
							yyerror("variable already defined as function");
						}
				}
#line 1575 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 171 "parser.y" /* yacc.c:1646  */
    {notInsert = 1;}
#line 1581 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 171 "parser.y" /* yacc.c:1646  */
    {notInsert = 0;}
#line 1587 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 174 "parser.y" /* yacc.c:1646  */
    { 
					if((yyvsp[0].node) != NULL && (yyvsp[0].node)->type == USERFUNC && glo_bal){
						insert(scope, yylineno, LOCALVAR, yylval.stringValue);
						glo_bal = 0;
					}
					
					if((yyvsp[0].node) != NULL && (yyvsp[0].node)->type == USERFUNC && !not_accessible){
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
#line 1619 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 201 "parser.y" /* yacc.c:1646  */
    {global_LIB_use = 0;}
#line 1625 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 204 "parser.y" /* yacc.c:1646  */
    {
				if(islibfunc && !call_depth){
						yyerror("Invalid insertion, trying to shadow LIBFUNC, before"); 
						islibfunc = 0;
				}
			}
#line 1636 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 212 "parser.y" /* yacc.c:1646  */
    {	
					if((tmp_rec = lookupLIBFUNCTs(yylval.stringValue))!= NULL){
						if(scope){
							global_LIB_use = 1;
						}else{
							global_LIB_use = 0;
						}
						islibfunc = 1;
						(yyval.node) = tmp_rec;
					}else if( (tmp_rec = lookup(yylval.stringValue, scope)) != NULL){
						not_accessible = 0;
						notInsert = 1;
						islibfunc = 0;
						(yyval.node) = tmp_rec;
					}else if( (tmp_rec = lookupFormal(yylval.stringValue, scope)) != NULL){
						islibfunc = 0;
						not_accessible = 0;
						notInsert = 1;
						(yyval.node) = tmp_rec;
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
						(yyval.node) = tmp_rec;
					}else if( (tmp_rec = lookup(yylval.stringValue, 0)) != NULL){
						glo_bal = 1;
						not_accessible = 0;
						notInsert = 1;
						islibfunc = 0;
						(yyval.node) = tmp_rec;
					}else if(notInsert){
						yyerror("NOT INSERT");
						notInsert = 0;
						islibfunc = 0;
						(yyval.node) = tmp_rec;
						
					}else{
						
						islibfunc =0;
						if(!call_depth){
								if(scope == 0){
									
									insert(scope, yylineno, GLOBAL, yylval.stringValue);
								}else{
									insert(scope, yylineno, LOCALVAR, yylval.stringValue);
								}
						}
						(yyval.node) = tmp_rec;
					}
					/* i parakatw if einai gia increment decrement error checking for functions*/
					
					if(tmp_rec != NULL && (tmp_rec->type == USERFUNC || tmp_rec->type == LIBFUNC)){
						token_is_func = 1;
					}else{
						token_is_func = 0;
					}
				}
#line 1705 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 276 "parser.y" /* yacc.c:1646  */
    {	
							if(scope && ((tmp_rec = lookupLIBFUNCTs(yylval.stringValue)) !=NULL)){
								yyerror("Invalid insertion, trying to shadow LIBFUNC");
								(yyval.node) = tmp_rec;
							}else if((tmp_rec = lookup(yylval.stringValue, scope)) != NULL){
								(yyval.node) = tmp_rec;
							}else if((tmp_rec = lookupFormal(yylval.stringValue, scope)) != NULL){
								(yyval.node) = tmp_rec;
							}else{
								if(scope == 0){
									insert(scope, yylineno, GLOBAL, yylval.stringValue);
								}else{
									insert(scope, yylineno, LOCALVAR, yylval.stringValue);
								}
								(yyval.node) = tmp_rec;
							}
						}
#line 1727 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 293 "parser.y" /* yacc.c:1646  */
    {
						if((tmp_rec = lookup(yylval.stringValue, 0)) == NULL){
							yyerror("undefined global variable");
							(yyval.node) = tmp_rec;
						}
				}
#line 1738 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 304 "parser.y" /* yacc.c:1646  */
    {islibfunc = 0;}
#line 1744 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 319 "parser.y" /* yacc.c:1646  */
    {call_depth++; }
#line 1750 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 319 "parser.y" /* yacc.c:1646  */
    {call_depth--;}
#line 1756 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 344 "parser.y" /* yacc.c:1646  */
    {notInsert = 0; }
#line 1762 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 344 "parser.y" /* yacc.c:1646  */
    {notInsert = 1;}
#line 1768 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 347 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 1774 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 347 "parser.y" /* yacc.c:1646  */
    {hide_scope(scope); scope--;}
#line 1780 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 351 "parser.y" /* yacc.c:1646  */
    {infunc++;}
#line 1786 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 351 "parser.y" /* yacc.c:1646  */
    { 
							if(lookupLIBFUNCTs(yylval.stringValue)){
								yyerror("Invalid insertion, trying to shadow LIBFUNC");
							}else if(lookup(yylval.stringValue, scope) != NULL){
								yyerror("Invalid function name, defined");
							}else if(lookupFormal(yylval.stringValue, scope) != NULL){
								yyerror("Invalid function name, defined as formal argument");
							}else{
								insert(scope, yylineno, USERFUNC, yylval.stringValue);
							}

						}
#line 1803 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 362 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 1809 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 362 "parser.y" /* yacc.c:1646  */
    {scope--;}
#line 1815 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 362 "parser.y" /* yacc.c:1646  */
    {infunc--;}
#line 1821 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 363 "parser.y" /* yacc.c:1646  */
    {	
						infunc++;
						sprintf(buffer, "$%d", dollar_counter);
						insert(scope, yylineno, USERFUNC, buffer);
						dollar_counter++;
					}
#line 1832 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 369 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 1838 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 369 "parser.y" /* yacc.c:1646  */
    {scope--;}
#line 1844 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 369 "parser.y" /* yacc.c:1646  */
    {infunc--;}
#line 1850 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 376 "parser.y" /* yacc.c:1646  */
    {notInsert = 0;}
#line 1856 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 377 "parser.y" /* yacc.c:1646  */
    {notInsert = 0;}
#line 1862 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 378 "parser.y" /* yacc.c:1646  */
    {notInsert = 0;}
#line 1868 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 381 "parser.y" /* yacc.c:1646  */
    {
				if(lookupLIBFUNCTs(yylval.stringValue)){
					yyerror("Invalid insertion, trying to shadow LIBFUNC");
				}else if(lookupFormal(yylval.stringValue, scope) != NULL){
					yyerror("duplicate formal names");
				}else{
					insert(scope, yylineno, FORMAL, yylval.stringValue);
				}
			}
#line 1882 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 393 "parser.y" /* yacc.c:1646  */
    {
				if(lookupLIBFUNCTs(yylval.stringValue)){
					yyerror("Invalid insertion, trying to shadow LIBFUNC");
				}else if(lookupFormal(yylval.stringValue, scope) != NULL){
					yyerror("duplicate formal names");
				}else{
					insert(scope, yylineno, FORMAL, yylval.stringValue);
				}
			}
#line 1896 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 412 "parser.y" /* yacc.c:1646  */
    { prev = infunc; infunc = 0;}
#line 1902 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 412 "parser.y" /* yacc.c:1646  */
    {infunc = prev;}
#line 1908 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 415 "parser.y" /* yacc.c:1646  */
    {notInsert = 0;}
#line 1914 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 415 "parser.y" /* yacc.c:1646  */
    {notInsert = 1;}
#line 1920 "parser.c" /* yacc.c:1646  */
    break;


#line 1924 "parser.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 418 "parser.y" /* yacc.c:1906  */


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
