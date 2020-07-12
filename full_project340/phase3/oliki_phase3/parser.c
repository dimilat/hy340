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


#line 91 "parser.c" /* yacc.c:339  */

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
#line 28 "parser.y" /* yacc.c:355  */

	char*	stringValue;
	int		intValue;
	double	doubleValue;
	struct expr* node;
	struct forVar* forpref;
	struct stmt* stmt_node;

#line 240 "parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 255 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   577

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

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
       0,   141,   141,   144,   145,   146,   147,   148,   149,   149,
     152,   152,   155,   156,   157,   160,   161,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   181,   182,   183,   184,   196,   208,   220,   232,
     235,   254,   235,   268,   304,   305,   306,   307,   316,   370,
     390,   397,   400,   401,   402,   403,   407,   408,   417,   424,
     425,   428,   428,   436,   436,   445,   446,   449,   450,   453,
     464,   476,   479,   480,   483,   483,   486,   486,   487,   490,
     490,   505,   505,   490,   514,   525,   525,   514,   535,   536,
     537,   538,   539,   540,   543,   543,   552,   555,   555,   564,
     567,   571,   573,   574,   577,   580,   580,   587,   598,   600,
     602,   609,   609,   626,   626,   627,   627
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
  "program", "stmt", "$@1", "$@2", "stmt_list", "expr", "term",
  "assignexpr", "$@3", "$@4", "primary", "lvalue", "member", "call",
  "callsuffix", "normcall", "$@5", "methodcall", "$@6", "elist",
  "elist_expressions", "objectdef", "indexed", "indexedelem_list",
  "indexedelem", "$@7", "block", "$@8", "funcdef", "$@9", "@10", "$@11",
  "$@12", "@13", "$@14", "$@15", "const", "idlist", "$@16", "idlist_list",
  "$@17", "ifprefix", "elseprefix", "ifstmt", "whilestart", "whilecond",
  "$@18", "whilestmt", "N", "M", "forprefix", "forstmt", "$@19",
  "returnstmt", "$@20", "$@21", YY_NULLPTR
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

#define YYPACT_NINF -188

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-188)))

#define YYTABLE_NINF -116

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-116)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     166,   -28,  -188,    -3,     0,   -24,  -188,  -188,   242,   -12,
    -188,  -188,  -188,   242,   -11,   -11,     4,   204,    94,  -188,
       3,  -188,  -188,  -188,  -188,    43,   166,  -188,   316,  -188,
    -188,  -188,    60,  -188,    14,  -188,  -188,  -188,  -188,   166,
    -188,     8,  -188,  -188,  -188,  -188,   242,   242,     5,    10,
     242,    20,    21,    22,  -188,  -188,   -10,    54,    11,    14,
      11,  -188,   166,   242,   295,    27,    28,    25,   379,    45,
    -188,  -188,  -188,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,  -188,  -188,  -188,   242,
    -188,    34,    37,    66,  -188,  -188,  -188,   242,   242,    39,
      84,  -188,   166,   242,   400,    55,  -188,  -188,   337,  -188,
    -188,  -188,    61,    59,   273,   242,  -188,  -188,  -188,    65,
    -188,  -188,    63,   533,   520,   -10,   -10,  -188,  -188,  -188,
     546,   546,    -2,    -2,    -2,    -2,   442,   242,  -188,    64,
    -188,   463,    67,  -188,  -188,   166,   242,  -188,    68,  -188,
    -188,    76,    69,  -188,    63,  -188,  -188,   295,    25,   242,
    -188,    79,  -188,   242,  -188,  -188,  -188,   421,  -188,   242,
    -188,  -188,    80,   242,  -188,  -188,    81,  -188,   242,   505,
    -188,  -188,   358,    69,    85,  -188,   484,  -188,    82,   166,
    -188,    86,    87,  -188,    93,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,    93,    85,  -188,  -188
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      16,     0,   104,     0,    79,   113,     8,    10,     0,     0,
      92,    93,    91,     0,     0,     0,    76,    66,     0,    14,
       0,    48,    88,    89,    90,     0,    16,     2,     0,    31,
      17,    39,    43,    51,    44,    45,    12,    13,    47,     0,
       4,     0,     5,   108,     6,     7,     0,    66,     0,     0,
       0,     0,     0,     0,    34,    49,    33,     0,    35,     0,
      37,    78,    16,     0,    68,     0,     0,    73,     0,     0,
      50,     1,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,    36,    38,     0,
      61,     0,     0,     0,    57,    59,    60,     0,    66,     0,
     102,   105,     0,    66,     0,     0,    80,    85,     0,   116,
       9,    11,     0,     0,     0,     0,    65,    69,    70,     0,
      71,    32,    46,    29,    30,    18,    19,    20,    21,    22,
      27,    28,    23,    24,    25,    26,     0,    66,    52,     0,
      41,     0,     0,    54,   101,     0,     0,   107,     0,   100,
     109,     0,    96,   114,     0,    77,    74,    68,    73,    66,
      53,     0,    63,     0,    55,    56,   103,     0,   111,     0,
      81,    94,     0,     0,    67,    72,     0,    62,    66,    42,
     106,   108,     0,    96,    99,    86,     0,    58,     0,     0,
     110,     0,     0,    95,     0,    75,    64,   108,    82,    97,
      87,   112,     0,    99,    83,    98
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,   -23,  -188,  -188,   -22,    -8,  -188,  -188,  -188,
    -188,  -188,     9,  -188,    17,  -188,  -188,  -188,  -188,  -188,
     -46,   -31,  -188,  -188,   -27,    15,  -188,  -187,  -188,   -16,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,   -56,  -188,
     -67,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -175,
    -188,  -188,  -188,  -188,  -188,  -188,  -188
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    52,    53,    27,    28,    29,    30,    93,
     163,    31,    32,    33,    34,    94,    95,   137,    96,   178,
      65,   116,    35,    66,   120,    67,   173,    36,    62,    37,
      48,   151,   183,   202,    49,   152,   194,    38,   172,   184,
     193,   203,    39,   145,    40,    41,   102,   146,    42,   103,
     169,    43,    44,   181,    45,    50,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   105,    69,     9,    72,    56,   189,   200,    46,    64,
      68,    77,    78,    79,  -115,   204,   100,    75,    76,    77,
      78,    79,   201,    58,    60,    57,  -116,  -116,  -116,  -116,
      20,    59,    59,    47,    55,    21,   -84,    61,   104,    64,
     113,   112,   108,    71,   101,    89,   107,    90,    97,    70,
      98,   106,   142,    91,    92,   114,    99,   148,   109,   110,
     111,     4,   117,   118,   119,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   -40,   147,
     138,   136,   122,   139,   140,   143,    87,    88,   144,   141,
      64,   161,   155,   150,    89,    64,    90,    63,   154,   159,
     162,     4,    91,    92,   165,   168,     8,   157,     9,    10,
      11,    12,   170,   176,    13,   171,   177,   185,   187,   196,
      14,    15,   166,   198,   192,    16,   174,   191,    17,    64,
      18,   175,   188,   199,   158,    20,   205,     0,   167,     0,
      21,    22,    23,    24,     0,     0,     0,     0,     0,     0,
       0,    64,     0,     0,     0,   179,     0,     0,     0,     0,
       0,   182,     0,     0,     0,   186,   197,     0,     0,     1,
      64,     2,     3,     4,     5,     6,     7,     0,     8,     0,
       9,    10,    11,    12,     0,     0,    13,     0,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,    16,     0,
      17,     0,    18,     0,    19,     0,     0,    20,     0,     0,
       0,     0,    21,    22,    23,    24,     8,     0,     9,    10,
      11,    12,     0,     0,    13,     0,     0,     0,     0,     0,
      14,    15,     0,     0,     0,     0,    63,     0,    17,     0,
      18,     0,     0,     0,     0,    20,     0,     0,     0,     0,
      21,    22,    23,    24,     8,     0,     9,    10,    11,    12,
       0,     0,    13,     0,     0,     0,     0,     0,    14,    15,
       0,     0,     0,     0,     0,     0,    17,     0,    18,     0,
       0,     0,     0,    20,    73,     0,    74,     0,    21,    22,
      23,    24,    75,    76,    77,    78,    79,    80,    81,     0,
       0,    82,    83,    84,    85,     0,    73,     0,    74,     0,
       0,     0,     0,   156,    75,    76,    77,    78,    79,    80,
      81,     0,     0,    82,    83,    84,    85,    73,     0,    74,
       0,     0,     0,     0,   115,    75,    76,    77,    78,    79,
      80,    81,     0,     0,    82,    83,    84,    85,    73,     0,
      74,     0,     0,     0,    86,     0,    75,    76,    77,    78,
      79,    80,    81,     0,     0,    82,    83,    84,    85,    73,
       0,    74,     0,     0,     0,   153,     0,    75,    76,    77,
      78,    79,    80,    81,     0,     0,    82,    83,    84,    85,
      73,     0,    74,     0,     0,     0,   190,     0,    75,    76,
      77,    78,    79,    80,    81,     0,     0,    82,    83,    84,
      85,    73,     0,    74,     0,     0,   121,     0,     0,    75,
      76,    77,    78,    79,    80,    81,     0,     0,    82,    83,
      84,    85,    73,     0,    74,     0,     0,   149,     0,     0,
      75,    76,    77,    78,    79,    80,    81,     0,     0,    82,
      83,    84,    85,    73,     0,    74,     0,     0,   180,     0,
       0,    75,    76,    77,    78,    79,    80,    81,     0,     0,
      82,    83,    84,    85,    73,     0,    74,   160,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,     0,
       0,    82,    83,    84,    85,    73,     0,    74,   164,     0,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    82,    83,    84,    85,    73,   195,    74,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    73,     0,    82,    83,    84,    85,     0,     0,    75,
      76,    77,    78,    79,    80,    81,     0,     0,    82,    83,
      84,    85,    75,    76,    77,    78,    79,    80,    81,     0,
       0,    82,    83,    84,    85,    75,    76,    77,    78,    79,
    -116,  -116,     0,     0,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
       8,    47,    18,    14,    26,    13,   181,   194,    36,    17,
      18,    21,    22,    23,    38,   202,    39,    19,    20,    21,
      22,    23,   197,    14,    15,    36,    28,    29,    30,    31,
      41,    14,    15,    36,    46,    46,    36,    33,    46,    47,
      62,    57,    50,     0,    36,    34,    36,    36,    34,    46,
      36,    46,    98,    42,    43,    63,    42,   103,    38,    38,
      38,     7,    35,    35,    39,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    18,   102,
      46,    89,    37,    46,    18,    46,    26,    27,     4,    97,
      98,   137,    33,    38,    34,   103,    36,    32,    37,    36,
      36,     7,    42,    43,    37,    37,    12,   115,    14,    15,
      16,    17,    36,   159,    20,    46,    37,    37,    37,    37,
      26,    27,   145,    37,    39,    32,   157,   183,    34,   137,
      36,   158,   178,    46,   119,    41,   203,    -1,   146,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,   173,   189,    -1,    -1,     3,
     178,     5,     6,     7,     8,     9,    10,    -1,    12,    -1,
      14,    15,    16,    17,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    32,    -1,
      34,    -1,    36,    -1,    38,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    12,    -1,    14,    15,
      16,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,
      36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    12,    -1,    14,    15,    16,    17,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    36,    -1,
      -1,    -1,    -1,    41,    11,    -1,    13,    -1,    46,    47,
      48,    49,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    -1,    11,    -1,    13,    -1,
      -1,    -1,    -1,    40,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    11,    -1,    13,
      -1,    -1,    -1,    -1,    39,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    11,    -1,
      13,    -1,    -1,    -1,    38,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    31,    11,
      -1,    13,    -1,    -1,    -1,    38,    -1,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      11,    -1,    13,    -1,    -1,    -1,    38,    -1,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    11,    -1,    13,    -1,    -1,    37,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    11,    -1,    13,    -1,    -1,    37,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    11,    -1,    13,    -1,    -1,    37,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    11,    -1,    13,    35,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    11,    -1,    13,    35,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    11,    33,    13,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    11,    -1,    28,    29,    30,    31,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    12,    14,
      15,    16,    17,    20,    26,    27,    32,    34,    36,    38,
      41,    46,    47,    48,    49,    52,    53,    56,    57,    58,
      59,    62,    63,    64,    65,    73,    78,    80,    88,    93,
      95,    96,    99,   102,   103,   105,    36,    36,    81,    85,
     106,   107,    54,    55,    57,    46,    57,    36,    63,    65,
      63,    33,    79,    32,    57,    71,    74,    76,    57,    80,
      46,     0,    56,    11,    13,    19,    20,    21,    22,    23,
      24,    25,    28,    29,    30,    31,    38,    26,    27,    34,
      36,    42,    43,    60,    66,    67,    69,    34,    36,    42,
      53,    36,    97,   100,    57,    71,    46,    36,    57,    38,
      38,    38,    80,    56,    57,    39,    72,    35,    35,    39,
      75,    37,    37,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    68,    46,    46,
      18,    57,    71,    46,     4,    94,    98,    53,    71,    37,
      38,    82,    86,    38,    37,    33,    40,    57,    76,    36,
      35,    71,    36,    61,    35,    37,    53,    57,    37,   101,
      36,    46,    89,    77,    72,    75,    71,    37,    70,    57,
      37,   104,    57,    83,    90,    37,    57,    37,    71,   100,
      38,    89,    39,    91,    87,    33,    37,    53,    37,    46,
      78,   100,    84,    92,    78,    91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    53,    54,    53,
      55,    53,    53,    53,    53,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      60,    61,    59,    62,    62,    62,    62,    62,    63,    63,
      63,    63,    64,    64,    64,    64,    65,    65,    65,    66,
      66,    68,    67,    70,    69,    71,    71,    72,    72,    73,
      73,    74,    75,    75,    77,    76,    79,    78,    78,    81,
      82,    83,    84,    80,    85,    86,    87,    80,    88,    88,
      88,    88,    88,    88,    90,    89,    89,    92,    91,    91,
      93,    94,    95,    95,    96,    98,    97,    99,   100,   101,
     102,   104,   103,   106,   105,   107,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     0,     3,
       0,     3,     1,     1,     1,     2,     0,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     2,     2,     2,     2,     2,     2,     1,
       0,     0,     5,     1,     1,     1,     3,     1,     1,     2,
       2,     1,     3,     4,     3,     4,     4,     2,     6,     1,
       1,     0,     4,     0,     6,     2,     0,     3,     0,     3,
       3,     2,     3,     0,     0,     6,     0,     4,     2,     0,
       0,     0,     0,    10,     0,     0,     0,     8,     1,     1,
       1,     1,     1,     1,     0,     3,     0,     0,     4,     0,
       4,     1,     2,     4,     1,     0,     4,     3,     0,     0,
       7,     0,     8,     0,     4,     0,     3
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
        case 3:
#line 144 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1563 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 145 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1569 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 146 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1575 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 147 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1581 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 148 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1587 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 149 "parser.y" /* yacc.c:1646  */
    {if(!loopcounter){yyerror("Use of 'break' while not in a loop");}}
#line 1593 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 149 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = newstmt(nextquadlabel()); 
												(yyval.stmt_node)->next = topstacklist(breakstacklist)->next; topstacklist(breakstacklist)->next = (yyval.stmt_node);
												emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);}
#line 1601 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 152 "parser.y" /* yacc.c:1646  */
    {if(!loopcounter){yyerror("Use of 'return' while not in a loop");}}
#line 1607 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 152 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = newstmt(nextquadlabel());
												(yyval.stmt_node)->next = topstacklist(contstacklist)->next; topstacklist(contstacklist)->next = (yyval.stmt_node);
												emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);}
#line 1615 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 155 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1621 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 156 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1627 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 157 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1633 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[-1].stmt_node);}
#line 1639 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt_node) = NULL;}
#line 1645 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1651 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 165 "parser.y" /* yacc.c:1646  */
    { if(validtype((yyvsp[-2].node), (yyvsp[0].node))){ (yyval.node) = newexpr(arithexpr_e); (yyval.node)->type = returnType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emit(add, (yyval.node), (yyvsp[-2].node), (yyvsp[0].node), currQuad, yylineno);} }
#line 1657 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 166 "parser.y" /* yacc.c:1646  */
    {if(validtype((yyvsp[-2].node), (yyvsp[0].node))){ (yyval.node) = newexpr(arithexpr_e); (yyval.node)->type = returnType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emit(sub, (yyval.node), (yyvsp[-2].node), (yyvsp[0].node), currQuad, yylineno);} }
#line 1663 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 167 "parser.y" /* yacc.c:1646  */
    {if(validtype((yyvsp[-2].node), (yyvsp[0].node))){ (yyval.node) = newexpr(arithexpr_e); (yyval.node)->type = returnType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emit(mul, (yyval.node), (yyvsp[-2].node), (yyvsp[0].node), currQuad, yylineno);} }
#line 1669 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 168 "parser.y" /* yacc.c:1646  */
    {if(validtype((yyvsp[-2].node), (yyvsp[0].node))){ (yyval.node) = newexpr(arithexpr_e); (yyval.node)->type = returnType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emit(div_, (yyval.node), (yyvsp[-2].node), (yyvsp[0].node), currQuad, yylineno);} }
#line 1675 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 169 "parser.y" /* yacc.c:1646  */
    {if(validtype((yyvsp[-2].node), (yyvsp[0].node))){ (yyval.node) = newexpr(arithexpr_e); (yyval.node)->type = returnType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emit(mod, (yyval.node), (yyvsp[-2].node), (yyvsp[0].node), currQuad, yylineno);} }
#line 1681 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 170 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emitRelop((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), if_greater, yylineno); }
#line 1687 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 171 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emitRelop((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), if_greatereq, yylineno); }
#line 1693 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emitRelop((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), if_less, yylineno); }
#line 1699 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 173 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emitRelop((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), if_lesseq, yylineno); }
#line 1705 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emitRelop((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), if_eq, yylineno); }
#line 1711 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emitRelop((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), if_noteq, yylineno); }
#line 1717 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emit(and, (yyval.node) , (yyvsp[-2].node), (yyvsp[0].node), currQuad, yylineno); }
#line 1723 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emit(or, (yyval.node) , (yyvsp[-2].node), (yyvsp[0].node), currQuad, yylineno); }
#line 1729 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1735 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 1741 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 182 "parser.y" /* yacc.c:1646  */
    {checkuminus((yyvsp[0].node)); (yyval.node)=newexpr(arithexpr_e); (yyval.node)->sym = newtemp(); emit(uminus, (yyval.node), (yyvsp[0].node), (expr *) 0, currQuad, yylineno);}
#line 1747 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 183 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=newexpr(boolexpr_e); (yyval.node)->sym = newtemp(); emit(not, (yyval.node), (yyvsp[0].node), (expr *) 0, currQuad, yylineno);}
#line 1753 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 184 "parser.y" /* yacc.c:1646  */
    {if(token_is_func){yyerror("cannot increment function value"); token_is_func = 0;} 
								if((yyvsp[0].node)->type == tableitem_e){
									(yyval.node) = emit_iftableitem((yyvsp[0].node));
									emit(add, (yyval.node), (yyval.node), newexpr_constnum(1), currQuad, yylineno);
									emit(tablesetelem, (yyval.node), (yyvsp[0].node), (yyvsp[0].node)->index, currQuad, yylineno);
								}else{
									emit(add, (yyvsp[0].node), (yyvsp[0].node), newexpr_constnum(1), currQuad, yylineno);
									(yyval.node) = newexpr(arithexpr_e);
									(yyval.node)->sym = newtemp();
									emit(assign, (yyval.node), (yyvsp[0].node), (expr*) 0, currQuad, yylineno);
								}
							}
#line 1770 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 196 "parser.y" /* yacc.c:1646  */
    {if(token_is_func){yyerror("cannot increment function value"); token_is_func = 0;}
								(yyval.node) = newexpr(var_e); (yyval.node)->sym = newtemp();
								if((yyvsp[-1].node)->type == tableitem_e){
									expr * value = emit_iftableitem((yyvsp[-1].node));
									emit(assign, (yyval.node), value, (expr*) 0, currQuad, yylineno);
									emit(add, value, value, newexpr_constnum(1), currQuad, yylineno);
									emit(tablesetelem, value, (yyvsp[-1].node), (yyvsp[-1].node)->index, currQuad, yylineno);
								}else{
									emit(assign, (yyval.node), (yyvsp[-1].node), (expr*) 0, currQuad, yylineno);
									emit(add, (yyvsp[-1].node), (yyvsp[-1].node), newexpr_constnum(1), currQuad, yylineno);
								}
							}
#line 1787 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 208 "parser.y" /* yacc.c:1646  */
    {if(token_is_func){yyerror("cannot decrement function value"); token_is_func = 0;} 
								if((yyvsp[0].node)->type == tableitem_e){
									(yyval.node) = emit_iftableitem((yyvsp[0].node));
									emit(sub, (yyval.node), (yyval.node), newexpr_constnum(1), currQuad, yylineno);
									emit(tablesetelem, (yyval.node), (yyvsp[0].node), (yyvsp[0].node)->index, currQuad, yylineno);
								}else{
									emit(sub, (yyvsp[0].node), (yyvsp[0].node), newexpr_constnum(1), currQuad, yylineno);
									(yyval.node) = newexpr(arithexpr_e);
									(yyval.node)->sym = newtemp();
									emit(assign, (yyval.node), (yyvsp[0].node), (expr*) 0, currQuad, yylineno);
								}
							}
#line 1804 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 220 "parser.y" /* yacc.c:1646  */
    {if(token_is_func){yyerror("cannot decrement function value"); token_is_func = 0;} 
								(yyval.node) = newexpr(var_e); (yyval.node)->sym = newtemp();
								if((yyvsp[-1].node)->type == tableitem_e){
									expr * value = emit_iftableitem((yyvsp[-1].node));
									emit(assign, (yyval.node), value, (expr*) 0, currQuad, yylineno);
									emit(sub, value, value, newexpr_constnum(1), currQuad, yylineno);
									emit(tablesetelem, value, (yyvsp[-1].node), (yyvsp[-1].node)->index, currQuad, yylineno);
								}else{
									emit(assign, (yyval.node), (yyvsp[-1].node), (expr*) 0, currQuad, yylineno);
									emit(sub, (yyvsp[-1].node), (yyvsp[-1].node), newexpr_constnum(1), currQuad, yylineno);
								}
							}
#line 1821 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 232 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1827 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 235 "parser.y" /* yacc.c:1646  */
    {		
						if((yyvsp[0].node) != NULL && (yyvsp[0].node)->sym->type == LIBFUNC){
							yyerror("Invalid insertion,0 trying to shadow LIBFUNC, before"); 
						}
						if((yyvsp[0].node) != NULL && (yyvsp[0].node)->sym->type == USERFUNC ){
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
							(yyvsp[0].node) = lvalue_expr(tmp_rec);
						}
						
				}
#line 1852 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 254 "parser.y" /* yacc.c:1646  */
    {afterAssign = 1; }
#line 1858 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 254 "parser.y" /* yacc.c:1646  */
    { afterAssign = 0; 
													if((yyvsp[-4].node) != NULL && (yyvsp[-4].node)->type == tableitem_e){
														emit(tablesetelem, (yyvsp[0].node), (yyvsp[-4].node), (yyvsp[-4].node)->index, currQuad, yylineno);
														(yyval.node) = emit_iftableitem((yyvsp[-4].node));
														(yyval.node)->type = assignexpr_e;
													}else{
														emit(assign, (yyvsp[-4].node), (yyvsp[0].node), (expr*)0, currQuad, yylineno); 
														(yyval.node) = newexpr(assignexpr_e); 
														(yyval.node)->sym = returnTempName((yyvsp[0].node),(expr*)0); 
														emit(assign, (yyval.node), (yyvsp[-4].node), (expr*)0, currQuad, yylineno); 
													}
												}
#line 1875 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 268 "parser.y" /* yacc.c:1646  */
    { 
					if(assignInRow){
						if(scope == 0){
							tmp_rec = insert(scope, yylineno, GLOBAL, yylval.stringValue);
							extraSets(tmp_rec);
						}else{
							tmp_rec = insert(scope, yylineno, LOCALVAR, yylval.stringValue);
							extraSets(tmp_rec);
						}
						assignInRow = 0;
						(yyvsp[0].node) = lvalue_expr(tmp_rec);
						//yyerror("cannot insert before");
					}
					/*
					if($1 != NULL && $1->sym->type == USERFUNC && glo_bal){
						tmp_rec = insert(scope, yylineno, LOCALVAR, yylval.stringValue);
						extraSets(tmp_rec);
						glo_bal = 0;
						$1 = lvalue_expr(tmp_rec);
					}
					if($1 != NULL && $1->sym->type == USERFUNC && !not_accessible && !inReturn){
						yyerror("variable already defined as function");
					}*/
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
					(yyval.node) = emit_iftableitem((yyvsp[0].node));
			}
#line 1916 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 304 "parser.y" /* yacc.c:1646  */
    {global_LIB_use = 0; (yyval.node) = (yyvsp[0].node);}
#line 1922 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 305 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1928 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1934 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 307 "parser.y" /* yacc.c:1646  */
    {
				if(islibfunc && !call_depth){ 
						yyerror("Invalid insertion,3 trying to shadow LIBFUNC, before"); 
						islibfunc = 0;
				}
				(yyval.node) = (yyvsp[0].node);
			}
#line 1946 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 316 "parser.y" /* yacc.c:1646  */
    {	
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
						(yyval.node) = NULL;
					}else{
						(yyval.node) = lvalue_expr(tmp_rec);
					}
					
				}
#line 2005 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 370 "parser.y" /* yacc.c:1646  */
    {
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
								(yyval.node) = NULL;
							}else{
								(yyval.node) = lvalue_expr(tmp_rec);
							}
						}
#line 2030 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 390 "parser.y" /* yacc.c:1646  */
    {
						if((tmp_rec = lookup(yylval.stringValue, 0)) == NULL){
							yyerror("undefined global variable");
						}else{
							(yyval.node) = lvalue_expr(tmp_rec);
						}
				}
#line 2042 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 397 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2048 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 400 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-2].node) != NULL){ (yyval.node) = member_item((yyvsp[-2].node), (yyvsp[0].stringValue)); } }
#line 2054 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 401 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-3].node) = emit_iftableitem((yyvsp[-3].node)); (yyval.node) = newexpr(tableitem_e); (yyval.node)->sym = (yyvsp[-3].node)->sym; (yyval.node)->index = (yyvsp[-1].node); }
#line 2060 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 402 "parser.y" /* yacc.c:1646  */
    {islibfunc = 0; (yyval.node) = NULL;}
#line 2066 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 403 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2072 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 407 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_call((yyvsp[-3].node), (yyvsp[-1].node), yylineno);}
#line 2078 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 408 "parser.y" /* yacc.c:1646  */
    {
									if((yyvsp[0].node)->boolConst == '1'){
										expr * self = (yyvsp[-1].node);
										(yyvsp[-1].node) = emit_iftableitem(member_item(self, (yyvsp[0].node)->charConst));
										self->next = (yyvsp[0].node)->next; /*add self front*/
										(yyvsp[0].node) = self;
									}
									(yyval.node) = make_call((yyvsp[-1].node), (yyvsp[0].node)->next, yylineno);
								}
#line 2092 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 417 "parser.y" /* yacc.c:1646  */
    {
																			expr* func = newexpr(programfunc_e);
																			func->sym = (yyvsp[-4].node)->sym;
																			(yyval.node) = make_call(func, (yyvsp[-1].node), yylineno);
																		}
#line 2102 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 424 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2108 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 425 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2114 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 428 "parser.y" /* yacc.c:1646  */
    {call_depth++; }
#line 2120 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 428 "parser.y" /* yacc.c:1646  */
    {	call_depth--;
																		(yyval.node) = newexpr(nil_e);
																		(yyval.node)->next = (yyvsp[-1].node);
																		(yyval.node)->charConst = NULL;
																		(yyval.node)->boolConst = '0';
																	}
#line 2131 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 436 "parser.y" /* yacc.c:1646  */
    {call_depth++; }
#line 2137 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 436 "parser.y" /* yacc.c:1646  */
    {
																		call_depth--;
																		(yyval.node) = newexpr(tableitem_e);
																		(yyval.node)->next = (yyvsp[-1].node);
																		(yyval.node)->charConst = (yyvsp[-4].stringValue);
																		(yyval.node)->boolConst = '1';
																	}
#line 2149 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 445 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); (yyval.node)->next=(yyvsp[0].node);}
#line 2155 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 446 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2161 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 449 "parser.y" /* yacc.c:1646  */
    { (yyval.node)=(yyvsp[-1].node); (yyval.node)->next=(yyvsp[0].node);}
#line 2167 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 450 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 2173 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 453 "parser.y" /* yacc.c:1646  */
    {
													int i = 0;
													expr* t = newexpr(newtable_e);
													t->sym = newtemp();
													emit(tablecreate, t, (expr*) 0, (expr*) 0, currQuad, yylineno);
													while((yyvsp[-1].node) != NULL){
														emit(tablesetelem, (yyvsp[-1].node), t, newexpr_constnum(i++), currQuad, yylineno);
														(yyvsp[-1].node) = (yyvsp[-1].node)->next;
													}
													(yyval.node) = t;
												}
#line 2189 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 464 "parser.y" /* yacc.c:1646  */
    {
													expr* t = newexpr(newtable_e);
													t->sym = newtemp();
													emit(tablecreate, t, (expr*) 0, (expr*) 0, currQuad, yylineno);
													while((yyvsp[-1].node)!=NULL){
														emit(tablesetelem, (yyvsp[-1].node), t, (yyvsp[-1].node)->index, currQuad, yylineno);
														(yyvsp[-1].node) = (yyvsp[-1].node)->next;
													}
													(yyval.node) = t;		
												}
#line 2204 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 476 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); (yyval.node)->next = (yyvsp[0].node);}
#line 2210 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 479 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); (yyval.node)->next = (yyvsp[0].node);}
#line 2216 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 480 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2222 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 483 "parser.y" /* yacc.c:1646  */
    {afterAssign = 0;}
#line 2228 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 483 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); (yyval.node)->index = (yyvsp[-4].node); afterAssign = 1;}
#line 2234 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 486 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 2240 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 486 "parser.y" /* yacc.c:1646  */
    {hide_scope(scope); scope--;}
#line 2246 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 490 "parser.y" /* yacc.c:1646  */
    {infunc++;}
#line 2252 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 490 "parser.y" /* yacc.c:1646  */
    { 
							if(lookupLIBFUNCTs(yylval.stringValue)){
								yyerror("Invalid insertion, trying to shadow LIBFUNC");
							}else if(lookup(yylval.stringValue, scope) != NULL){
								yyerror("Invalid function name, defined");
							}else if(lookupFormal(yylval.stringValue, scope) != NULL){
								yyerror("Invalid function name, defined as formal argument");
							}else{
								(yyval.node) = lvalue_expr(insert(scope, yylineno, USERFUNC, yylval.stringValue));
								(yyval.node)->sym->iaddress = nextquadlabel();
								emit(funcstart, (yyval.node), (expr *) 0, (expr *) 0, currQuad, yylineno);
								push(functionLocalsStack, functionLocalOffset);
								tmp_expr = (yyval.node);
							}
							resetformalargsoffset();
						}
#line 2273 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 505 "parser.y" /* yacc.c:1646  */
    {scope++; enterscopespace();}
#line 2279 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 505 "parser.y" /* yacc.c:1646  */
    {scope--; enterscopespace(); resetfunctionlocalsoffset(); push(loopcounterstack, loopcounter); loopcounter = 0;}
#line 2285 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 506 "parser.y" /* yacc.c:1646  */
    {
								infunc--; exitscopecounter(); exitscopecounter();
								(yyval.node) = tmp_expr;
								(yyval.node)->sym->totallocals = functionLocalOffset;
								functionLocalOffset = pop(functionLocalsStack);
								emit(funcend, (yyval.node), (expr *) 0, (expr *) 0, currQuad, yylineno);
								loopcounter = pop(loopcounterstack);
						}
#line 2298 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 514 "parser.y" /* yacc.c:1646  */
    {	
						infunc++;
						buffer = malloc(sizeof(char*));
						sprintf(buffer, "$%d", dollar_counter);
						buffer = strndup(buffer, sizeof(char*));
						(yyval.node) = lvalue_expr(insert(scope, yylineno, USERFUNC, buffer));
						emit(funcstart, (yyval.node), (expr *) 0, (expr *) 0, currQuad, yylineno);
						push(functionLocalsStack, functionLocalOffset);
						tmp_expr = (yyval.node);
						dollar_counter++;
						resetformalargsoffset();
					}
#line 2315 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 525 "parser.y" /* yacc.c:1646  */
    {scope++; enterscopespace();}
#line 2321 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 525 "parser.y" /* yacc.c:1646  */
    {scope--; enterscopespace();}
#line 2327 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 525 "parser.y" /* yacc.c:1646  */
    {
																			infunc--;
																			exitscopecounter(); exitscopecounter();
																			(yyval.node) = tmp_expr; 
																			(yyval.node)->sym->totallocals = functionLocalOffset;
																			functionLocalOffset = pop(functionLocalsStack);
																			emit(funcend, (yyval.node), (expr *) 0, (expr *) 0, currQuad, yylineno);
																		}
#line 2340 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 535 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = newexpr_constnum(yylval.intValue); }
#line 2346 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 536 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = newexpr_constnum(yylval.doubleValue); }
#line 2352 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 537 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = newexpr_conststring(yylval.stringValue); }
#line 2358 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 538 "parser.y" /* yacc.c:1646  */
    {afterAssign = 0; (yyval.node) = newexpr(nil_e);}
#line 2364 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 539 "parser.y" /* yacc.c:1646  */
    {afterAssign = 0; (yyval.node) = newexpr_constbool('1');}
#line 2370 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 540 "parser.y" /* yacc.c:1646  */
    {afterAssign = 0; (yyval.node) = newexpr_constbool('0');}
#line 2376 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 543 "parser.y" /* yacc.c:1646  */
    {	formalArgOffset++;
				if(lookupLIBFUNCTs(yylval.stringValue)){
					yyerror("Invalid insertion, trying to shadow LIBFUNC");
				}else if(lookupFormal(yylval.stringValue, scope) != NULL){
					yyerror("duplicate formal names");
				}else{
					insert(scope, yylineno, FORMAL, yylval.stringValue);
				}
			}
#line 2390 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 555 "parser.y" /* yacc.c:1646  */
    {	formalArgOffset++;
				if(lookupLIBFUNCTs(yylval.stringValue)){
					yyerror("Invalid insertion, trying to shadow LIBFUNC");
				}else if(lookupFormal(yylval.stringValue, scope) != NULL){
					yyerror("duplicate formal names");
				}else{
					insert(scope, yylineno, FORMAL, yylval.stringValue);
				}
			}
#line 2404 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 567 "parser.y" /* yacc.c:1646  */
    { emit(if_eq, newexpr_constnum(nextquadlabel()+2), (yyvsp[-1].node), newexpr_constbool('1'), currQuad, yylineno); 
									(yyval.node) = newexpr(var_e); (yyval.node)->numConst = nextquadlabel(); 
									emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);
									}
#line 2413 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 571 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = newexpr(var_e); (yyval.node)->numConst = nextquadlabel(); emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno); }
#line 2419 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 573 "parser.y" /* yacc.c:1646  */
    {patchlabel((int)((yyvsp[-1].node)->numConst), nextquadlabel());}
#line 2425 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 574 "parser.y" /* yacc.c:1646  */
    {patchlabel((int)((yyvsp[-3].node)->numConst), (int)((yyvsp[-1].node)->numConst) + 1); patchlabel((int)((yyvsp[-1].node)->numConst), nextquadlabel()); }
#line 2431 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 577 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr_constnum(nextquadlabel());}
#line 2437 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 580 "parser.y" /* yacc.c:1646  */
    {/*call_depth++;*/}
#line 2443 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 580 "parser.y" /* yacc.c:1646  */
    {/*call_depth--;*/ ++loopcounter; 
										breaklist_head = newstmt(-1); contlist_head = newstmt(-1);
										pushstacklist(breakstacklist, breaklist_head); pushstacklist(contstacklist, contlist_head); 
										emit(if_eq, newexpr_constnum(nextquadlabel()+2), (yyvsp[-1].node), newexpr_constbool('1'), currQuad, yylineno); 
										(yyval.intValue) = nextquadlabel();   emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);}
#line 2453 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 587 "parser.y" /* yacc.c:1646  */
    { --loopcounter;	
				emit(jump, (yyvsp[-2].node), (expr *)0, (expr *)0, currQuad, yylineno);   
				patchlabel((yyvsp[-1].intValue), nextquadlabel());   

				patchBreakContinue(breakstacklist, nextquadlabel());
				popstacklist(breakstacklist);
				patchBreakContinue(contstacklist, (int)((yyvsp[-2].node)->numConst));
				popstacklist(contstacklist);
			}
#line 2467 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 598 "parser.y" /* yacc.c:1646  */
    { (yyval.intValue) = nextquadlabel();  emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);  }
#line 2473 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 600 "parser.y" /* yacc.c:1646  */
    {  (yyval.intValue) = nextquadlabel(); }
#line 2479 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 602 "parser.y" /* yacc.c:1646  */
    {	
				(yyval.forpref) = malloc(sizeof(struct forVar));
				(yyval.forpref)->test = (yyvsp[-2].intValue); (yyval.forpref)->enter = nextquadlabel(); 
				emit(if_eq, newexpr_constnum(1), (yyvsp[-1].node), newexpr_constbool('1'), currQuad, yylineno);
			}
#line 2489 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 609 "parser.y" /* yacc.c:1646  */
    { prev = infunc; infunc = 0; ++loopcounter;
					breaklist_head = newstmt(-1); contlist_head = newstmt(-1);
					pushstacklist(breakstacklist, breaklist_head); pushstacklist(contstacklist, contlist_head);
			}
#line 2498 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 612 "parser.y" /* yacc.c:1646  */
    {
				--loopcounter; infunc = prev;
				patchlabel((yyvsp[-7].forpref)->enter, (yyvsp[-2].intValue)+1);
				patchlabel((yyvsp[-6].intValue), nextquadlabel());
				patchlabel((yyvsp[-2].intValue), (yyvsp[-7].forpref)->test);
				patchlabel((yyvsp[0].intValue), (yyvsp[-6].intValue)+1);

				patchBreakContinue(breakstacklist, nextquadlabel());
				popstacklist(breakstacklist);
				patchBreakContinue(contstacklist, (yyvsp[-6].intValue)+1);
				popstacklist(contstacklist);
			}
#line 2515 "parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 626 "parser.y" /* yacc.c:1646  */
    {afterAssign = 0; inReturn = 1; if(!infunc){yyerror("Use of 'return' while not in a function");}}
#line 2521 "parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 626 "parser.y" /* yacc.c:1646  */
    { inReturn = 1; emit(ret, (yyvsp[-1].node), (expr *) 0, (expr *) 0,currQuad, yylineno); }
#line 2527 "parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 627 "parser.y" /* yacc.c:1646  */
    {if(!infunc){yyerror("Use of 'return' while not in a function");}}
#line 2533 "parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 627 "parser.y" /* yacc.c:1646  */
    {emit(ret, (expr *) 0, (expr *) 0, (expr *) 0,currQuad, yylineno);}
#line 2539 "parser.c" /* yacc.c:1646  */
    break;


#line 2543 "parser.c" /* yacc.c:1646  */
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
#line 630 "parser.y" /* yacc.c:1906  */


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
