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


#line 92 "parser.c" /* yacc.c:339  */

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
#line 29 "parser.y" /* yacc.c:355  */

	char*	stringValue;
	int		intValue;
	double	doubleValue;
	struct expr* node;
	struct forVar* forpref;
	struct stmt* stmt_node;

#line 241 "parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 256 "parser.c" /* yacc.c:358  */

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
#define YYLAST   505

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

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
     176,   200,   200,   233,   236,   237,   238,   252,   264,   276,
     288,   300,   303,   322,   303,   339,   364,   365,   366,   367,
     376,   430,   450,   457,   460,   461,   462,   463,   467,   468,
     477,   484,   485,   488,   488,   496,   496,   505,   506,   509,
     510,   513,   524,   536,   539,   540,   543,   543,   546,   546,
     547,   550,   550,   567,   567,   550,   578,   591,   591,   578,
     603,   604,   605,   606,   607,   608,   611,   611,   620,   623,
     623,   632,   635,   635,   639,   641,   642,   645,   648,   657,
     668,   670,   672,   672,   681,   681,   698,   698,   700,   700
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
  "program", "stmt", "$@1", "$@2", "stmt_list", "expr", "$@3", "$@4",
  "term", "assignexpr", "$@5", "$@6", "primary", "lvalue", "member",
  "call", "callsuffix", "normcall", "$@7", "methodcall", "$@8", "elist",
  "elist_expressions", "objectdef", "indexed", "indexedelem_list",
  "indexedelem", "$@9", "block", "$@10", "funcdef", "$@11", "@12", "$@13",
  "$@14", "@15", "$@16", "$@17", "const", "idlist", "$@18", "idlist_list",
  "$@19", "ifprefix", "$@20", "elseprefix", "ifstmt", "whilestart",
  "whilecond", "whilestmt", "N", "M", "forprefix", "$@21", "forstmt",
  "$@22", "returnstmt", "$@23", "$@24", YY_NULLPTR
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

#define YYPACT_NINF -184

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-184)))

#define YYTABLE_NINF -119

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-119)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -32,  -184,   -25,    -6,   -16,  -184,  -184,   185,   -10,
    -184,  -184,  -184,   185,    20,    20,     6,   147,    97,  -184,
      -2,  -184,  -184,  -184,  -184,    32,    11,  -184,   259,  -184,
    -184,  -184,    92,  -184,    -1,  -184,  -184,  -184,  -184,    11,
    -184,    14,  -184,  -184,  -184,  -184,  -184,  -184,    17,    28,
     185,    44,    46,    56,   187,  -184,    57,    91,    49,    -1,
      49,  -184,    11,   185,   238,    64,    65,    62,   322,    66,
    -184,  -184,  -184,  -184,  -184,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,  -184,  -184,  -184,   185,
    -184,    59,    60,    84,  -184,  -184,  -184,   185,   185,    69,
     112,   185,    11,   185,   185,   185,  -184,  -184,   280,  -184,
    -184,  -184,    83,    88,   216,   185,  -184,  -184,  -184,    90,
    -184,  -184,    89,  -184,  -184,    57,    57,  -184,  -184,  -184,
     474,   474,   187,   187,   187,   187,   385,   185,  -184,    94,
    -184,   406,    95,  -184,  -184,    11,   343,  -184,    99,   364,
     101,   104,    81,  -184,    89,  -184,  -184,   238,    62,   185,
     185,   185,  -184,   100,  -184,   185,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,   105,   185,  -184,  -184,   110,
     461,   461,  -184,   185,   448,  -184,   185,    81,   102,  -184,
     427,  -184,   111,    11,   301,   113,   103,  -184,   122,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,   122,   102,  -184,
    -184
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      16,     0,   107,     0,    81,   116,     8,    10,     0,     0,
      94,    95,    93,     0,     0,     0,    78,    68,     0,    14,
       0,    50,    90,    91,    92,     0,    16,     2,     0,    33,
      17,    41,    45,    53,    46,    47,    12,    13,    49,     0,
       4,     0,     5,   110,     6,     7,   102,   112,     0,     0,
       0,     0,     0,     0,    36,    51,    35,     0,    37,     0,
      39,    80,    16,     0,    70,     0,     0,    75,     0,     0,
      52,     1,    15,    29,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,    38,    40,     0,
      63,     0,     0,     0,    59,    61,    62,     0,    68,     0,
     105,     0,     0,    68,     0,    68,    82,    87,     0,   119,
       9,    11,     0,     0,     0,     0,    67,    71,    72,     0,
      73,    34,    48,   111,   111,    18,    19,    20,    21,    22,
      27,    28,    23,    24,    25,    26,     0,    68,    54,     0,
      43,     0,     0,    56,   104,     0,     0,   109,     0,     0,
       0,     0,    98,   117,     0,    79,    76,    70,    75,    68,
       0,     0,    55,     0,    65,     0,    57,    58,   106,   108,
     114,   103,   111,    83,    96,     0,     0,    69,    74,     0,
      30,    32,    64,    68,    44,   110,     0,    98,   101,    88,
       0,    60,     0,     0,     0,     0,     0,    97,     0,    77,
      66,   110,   113,    84,    99,    89,   115,     0,   101,    85,
     100
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,   -37,  -184,  -184,   -14,    -8,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,    39,  -184,    73,  -184,  -184,  -184,
    -184,  -184,   -97,     1,  -184,  -184,    -3,    41,  -184,  -183,
    -184,   -11,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
     -22,  -184,   -42,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -172,  -121,  -184,  -184,  -184,  -184,  -184,  -184,  -184
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    52,    53,    27,    28,   123,   124,    29,
      30,    93,   165,    31,    32,    33,    34,    94,    95,   137,
      96,   183,    65,   116,    35,    66,   120,    67,   176,    36,
      62,    37,    48,   151,   187,   207,    49,   152,   198,    38,
     175,   188,   197,   208,    39,   104,   145,    40,    41,   102,
      42,   103,   160,    43,   105,    44,   185,    45,    50,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   142,   100,   161,    46,    56,   148,    69,   150,    64,
      68,    47,    72,   193,     1,   205,     2,     3,     4,     5,
       6,     7,  -118,     8,   209,     9,    10,    11,    12,   206,
     -86,    13,    71,    97,     9,    98,    55,    14,    15,    61,
     163,    99,   108,    16,    70,    17,   112,    18,   113,    19,
     101,   186,    20,    58,    60,   114,    57,    21,    22,    23,
      24,    20,   179,   106,   107,   147,    21,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    77,    78,
      79,   136,   109,    89,   110,    90,   192,    59,    59,   141,
      64,    91,    92,   146,   111,    64,   149,    64,     4,   117,
     118,   119,   140,   122,     4,   138,   139,   157,   168,     8,
     -42,     9,    10,    11,    12,   143,   144,    13,    87,    88,
     154,   155,    63,    14,    15,   159,    89,   174,    90,    64,
     164,    17,   167,    18,    91,    92,   170,   182,    20,   172,
     173,   196,   189,    21,    22,    23,    24,   191,   200,   204,
     203,    64,   180,   181,    16,   178,   201,   184,   177,     8,
     158,     9,    10,    11,    12,   195,   210,    13,   190,     0,
       0,     0,     0,    14,    15,    64,     0,     0,   194,    63,
       0,    17,     0,    18,     0,     0,     0,     0,    20,     0,
       0,     0,     0,    21,    22,    23,    24,     8,     0,     9,
      10,    11,    12,     0,     0,    13,    75,    76,    77,    78,
      79,    14,    15,     0,     0,  -119,  -119,  -119,  -119,    17,
       0,    18,     0,     0,     0,     0,    20,    73,     0,    74,
       0,    21,    22,    23,    24,    75,    76,    77,    78,    79,
      80,    81,     0,     0,    82,    83,    84,    85,     0,    73,
       0,    74,     0,     0,     0,     0,   156,    75,    76,    77,
      78,    79,    80,    81,     0,     0,    82,    83,    84,    85,
      73,     0,    74,     0,     0,     0,     0,   115,    75,    76,
      77,    78,    79,    80,    81,     0,     0,    82,    83,    84,
      85,    73,     0,    74,     0,     0,     0,    86,     0,    75,
      76,    77,    78,    79,    80,    81,     0,     0,    82,    83,
      84,    85,    73,     0,    74,     0,     0,     0,   153,     0,
      75,    76,    77,    78,    79,    80,    81,     0,     0,    82,
      83,    84,    85,    73,     0,    74,     0,     0,     0,   202,
       0,    75,    76,    77,    78,    79,    80,    81,     0,     0,
      82,    83,    84,    85,    73,     0,    74,     0,     0,   121,
       0,     0,    75,    76,    77,    78,    79,    80,    81,     0,
       0,    82,    83,    84,    85,    73,     0,    74,     0,     0,
     169,     0,     0,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    82,    83,    84,    85,    73,     0,    74,     0,
       0,   171,     0,     0,    75,    76,    77,    78,    79,    80,
      81,     0,     0,    82,    83,    84,    85,    73,     0,    74,
     162,     0,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    81,     0,     0,    82,    83,    84,    85,    73,     0,
      74,   166,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,     0,     0,    82,    83,    84,    85,    73,
     199,    74,     0,     0,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,     0,     0,    82,    83,    84,    85,
      75,    76,    77,    78,    79,    80,    81,     0,     0,    82,
      83,    84,    85,    75,    76,    77,    78,    79,     0,     0,
       0,     0,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
       8,    98,    39,   124,    36,    13,   103,    18,   105,    17,
      18,    36,    26,   185,     3,   198,     5,     6,     7,     8,
       9,    10,    38,    12,   207,    14,    15,    16,    17,   201,
      36,    20,     0,    34,    14,    36,    46,    26,    27,    33,
     137,    42,    50,    32,    46,    34,    57,    36,    62,    38,
      36,   172,    41,    14,    15,    63,    36,    46,    47,    48,
      49,    41,   159,    46,    36,   102,    46,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    21,    22,
      23,    89,    38,    34,    38,    36,   183,    14,    15,    97,
      98,    42,    43,   101,    38,   103,   104,   105,     7,    35,
      35,    39,    18,    37,     7,    46,    46,   115,   145,    12,
      18,    14,    15,    16,    17,    46,     4,    20,    26,    27,
      37,    33,    32,    26,    27,    36,    34,    46,    36,   137,
      36,    34,    37,    36,    42,    43,    37,    37,    41,    38,
      36,    39,    37,    46,    47,    48,    49,    37,    37,    46,
      37,   159,   160,   161,    32,   158,   193,   165,   157,    12,
     119,    14,    15,    16,    17,   187,   208,    20,   176,    -1,
      -1,    -1,    -1,    26,    27,   183,    -1,    -1,   186,    32,
      -1,    34,    -1,    36,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    12,    -1,    14,
      15,    16,    17,    -1,    -1,    20,    19,    20,    21,    22,
      23,    26,    27,    -1,    -1,    28,    29,    30,    31,    34,
      -1,    36,    -1,    -1,    -1,    -1,    41,    11,    -1,    13,
      -1,    46,    47,    48,    49,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    -1,    11,
      -1,    13,    -1,    -1,    -1,    -1,    40,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      11,    -1,    13,    -1,    -1,    -1,    -1,    39,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    11,    -1,    13,    -1,    -1,    -1,    38,    -1,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    11,    -1,    13,    -1,    -1,    -1,    38,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    11,    -1,    13,    -1,    -1,    -1,    38,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    11,    -1,    13,    -1,    -1,    37,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    11,    -1,    13,    -1,    -1,
      37,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    11,    -1,    13,    -1,
      -1,    37,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    11,    -1,    13,
      35,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    11,    -1,
      13,    35,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    31,    11,
      33,    13,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    12,    14,
      15,    16,    17,    20,    26,    27,    32,    34,    36,    38,
      41,    46,    47,    48,    49,    52,    53,    56,    57,    60,
      61,    64,    65,    66,    67,    75,    80,    82,    90,    95,
      98,    99,   101,   104,   106,   108,    36,    36,    83,    87,
     109,   110,    54,    55,    57,    46,    57,    36,    65,    67,
      65,    33,    81,    32,    57,    73,    76,    78,    57,    82,
      46,     0,    56,    11,    13,    19,    20,    21,    22,    23,
      24,    25,    28,    29,    30,    31,    38,    26,    27,    34,
      36,    42,    43,    62,    68,    69,    71,    34,    36,    42,
      53,    36,   100,   102,    96,   105,    46,    36,    57,    38,
      38,    38,    82,    56,    57,    39,    74,    35,    35,    39,
      77,    37,    37,    58,    59,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    70,    46,    46,
      18,    57,    73,    46,     4,    97,    57,    53,    73,    57,
      73,    84,    88,    38,    37,    33,    40,    57,    78,    36,
     103,   103,    35,    73,    36,    63,    35,    37,    53,    37,
      37,    37,    38,    36,    46,    91,    79,    74,    77,    73,
      57,    57,    37,    72,    57,   107,   103,    85,    92,    37,
      57,    37,    73,   102,    57,    91,    39,    93,    89,    33,
      37,    53,    38,    37,    46,    80,   102,    86,    94,    80,
      93
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    53,    54,    53,
      55,    53,    53,    53,    53,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    58,
      57,    59,    57,    57,    60,    60,    60,    60,    60,    60,
      60,    60,    62,    63,    61,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    66,    66,    66,    66,    67,    67,
      67,    68,    68,    70,    69,    72,    71,    73,    73,    74,
      74,    75,    75,    76,    77,    77,    79,    78,    81,    80,
      80,    83,    84,    85,    86,    82,    87,    88,    89,    82,
      90,    90,    90,    90,    90,    90,    92,    91,    91,    94,
      93,    93,    96,    95,    97,    98,    98,    99,   100,   101,
     102,   103,   105,   104,   107,   106,   109,   108,   110,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     0,     3,
       0,     3,     1,     1,     1,     2,     0,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     0,
       5,     0,     5,     1,     3,     2,     2,     2,     2,     2,
       2,     1,     0,     0,     5,     1,     1,     1,     3,     1,
       1,     2,     2,     1,     3,     4,     3,     4,     4,     2,
       6,     1,     1,     0,     4,     0,     6,     2,     0,     3,
       0,     3,     3,     2,     3,     0,     0,     6,     0,     4,
       2,     0,     0,     0,     0,    10,     0,     0,     0,     8,
       1,     1,     1,     1,     1,     1,     0,     3,     0,     0,
       4,     0,     0,     5,     1,     2,     4,     1,     3,     3,
       0,     0,     0,     8,     0,     8,     0,     4,     0,     3
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
    {tempcounter=0; (yyval.stmt_node) = NULL;  FINALemits((yyvsp[-1].node), yylineno);  }
#line 1553 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 145 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1559 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 146 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1565 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 147 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1571 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 148 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1577 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 149 "parser.y" /* yacc.c:1646  */
    {if(!loopcounter){yyerror("Use of 'break' while not in a loop");}}
#line 1583 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 149 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = newstmt(nextquadlabel()); 
												(yyval.stmt_node)->next = topstacklist(breakstacklist)->next; topstacklist(breakstacklist)->next = (yyval.stmt_node);
												emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);}
#line 1591 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 152 "parser.y" /* yacc.c:1646  */
    {if(!loopcounter){yyerror("Use of 'return' while not in a loop");}}
#line 1597 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 152 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = newstmt(nextquadlabel());
												(yyval.stmt_node)->next = topstacklist(contstacklist)->next; topstacklist(contstacklist)->next = (yyval.stmt_node);
												emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);}
#line 1605 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 155 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1611 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 156 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1617 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 157 "parser.y" /* yacc.c:1646  */
    {tempcounter=0; (yyval.stmt_node) = NULL;}
#line 1623 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = (yyvsp[-1].stmt_node);}
#line 1629 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt_node) = NULL;}
#line 1635 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1641 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 165 "parser.y" /* yacc.c:1646  */
    { if(validtype((yyvsp[-2].node), (yyvsp[0].node))){ (yyval.node) = newexpr(arithexpr_e); (yyval.node)->type = returnType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emit(add, (yyval.node), (yyvsp[-2].node), (yyvsp[0].node), currQuad, yylineno);} }
#line 1647 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 166 "parser.y" /* yacc.c:1646  */
    {if(validtype((yyvsp[-2].node), (yyvsp[0].node))){ (yyval.node) = newexpr(arithexpr_e); (yyval.node)->type = returnType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emit(sub, (yyval.node), (yyvsp[-2].node), (yyvsp[0].node), currQuad, yylineno);} }
#line 1653 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 167 "parser.y" /* yacc.c:1646  */
    {if(validtype((yyvsp[-2].node), (yyvsp[0].node))){ (yyval.node) = newexpr(arithexpr_e); (yyval.node)->type = returnType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emit(mul, (yyval.node), (yyvsp[-2].node), (yyvsp[0].node), currQuad, yylineno);} }
#line 1659 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 168 "parser.y" /* yacc.c:1646  */
    {if(validtype((yyvsp[-2].node), (yyvsp[0].node))){ (yyval.node) = newexpr(arithexpr_e); (yyval.node)->type = returnType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emit(div_, (yyval.node), (yyvsp[-2].node), (yyvsp[0].node), currQuad, yylineno);} }
#line 1665 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 169 "parser.y" /* yacc.c:1646  */
    {if(validtype((yyvsp[-2].node), (yyvsp[0].node))){ (yyval.node) = newexpr(arithexpr_e); (yyval.node)->type = returnType((yyval.node),(yyvsp[-2].node),(yyvsp[0].node));  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); emit(mod, (yyval.node), (yyvsp[-2].node), (yyvsp[0].node), currQuad, yylineno);} }
#line 1671 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 170 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node) = emitPartialRelop((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), if_greater, yylineno); makeFinalEmits=1;}
#line 1677 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 171 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node) = emitPartialRelop((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), if_greatereq, yylineno); makeFinalEmits=1; }
#line 1683 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node) = emitPartialRelop((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), if_less, yylineno); makeFinalEmits=1; }
#line 1689 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 173 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node) = emitPartialRelop((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), if_lesseq, yylineno); makeFinalEmits=1; }
#line 1695 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node) = emitPartialRelop((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), if_eq, yylineno);  makeFinalEmits=1; }
#line 1701 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node) = emitPartialRelop((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), if_noteq, yylineno);  makeFinalEmits=1; }
#line 1707 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 176 "parser.y" /* yacc.c:1646  */
    { emitBoolConversion((yyvsp[-1].node), yylineno);  }
#line 1713 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-4].node),(yyvsp[0].node)); 
														emitBoolConversion((yyvsp[0].node), yylineno);
														Mlabel = (yyvsp[0].node)->truelist->label;
														/*
														if(ANDcounter < 0){
															backpatch($1->truelist, Mlabel);
															backpatch($1->falselist, $1->falselist->numConst);
														}else{
															backpatch($1->truelist, Mlabel);
															backpatch($1->falselist, $1->falselist->numConst+2);
														}*/
														backpatch((yyvsp[-4].node)->truelist, Mlabel);
														backpatch((yyvsp[-4].node)->falselist, (yyvsp[-4].node)->falselist->numConst+2);
														
														if(ORcounter == 1){
															backpatch(ORQuadNo, Mlabel+2);
														}
														
														//tempQuadNo2 = cloneList($1->falselist);
														(yyval.node)->truelist = (yyvsp[0].node)->truelist;
														(yyval.node)->falselist = mergePartial((yyvsp[-4].node)->falselist, (yyvsp[0].node)->falselist);
														makeFinalEmits = 1; 
														ANDcounter = 1;
												}
#line 1742 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 200 "parser.y" /* yacc.c:1646  */
    { emitBoolConversion((yyvsp[-1].node), yylineno);  }
#line 1748 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr(boolexpr_e);  (yyval.node)->sym = returnTempName((yyvsp[-4].node),(yyvsp[0].node)); 
														emitBoolConversion((yyvsp[0].node), yylineno);
														Mlabel=(yyvsp[0].node)->truelist->label;
														/*if(ORcounter < 0){
															backpatch($1->falselist, Mlabel);
															backpatch($1->truelist, $1->truelist->numConst+2);
														}else{
															backpatch($1->falselist, Mlabel);
															backpatch($1->truelist, $1->truelist->numConst+2);
														}*/
														backpatch((yyvsp[-4].node)->falselist, Mlabel);
														backpatch((yyvsp[-4].node)->truelist, (yyvsp[-4].node)->truelist->numConst+2);

														/*if(ANDcounter == 1){
															backpatch(tempQuadNo2->next, Mlabel);
														}*/

														tempQuadNo = cloneList((yyvsp[-4].node)->truelist);
														if(ORQuadNo == NULL){
															ORQuadNo = tempQuadNo;
														}else{
															expr * tempOR = ORQuadNo;
															while(tempOR->next != NULL){
																tempOR = tempOR->next;
															}
															tempOR->next = tempQuadNo;
														}
														(yyval.node)->truelist = mergePartial((yyvsp[-4].node)->truelist, (yyvsp[0].node)->truelist);
														(yyval.node)->falselist = (yyvsp[0].node)->falselist;

														makeFinalEmits = 1;
														ORcounter=1;
														}
#line 1786 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 233 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1792 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 236 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 1798 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 237 "parser.y" /* yacc.c:1646  */
    {checkuminus((yyvsp[0].node)); (yyval.node)=newexpr(arithexpr_e); (yyval.node)->sym = newtemp(); emit(uminus, (yyval.node), (yyvsp[0].node), (expr *) 0, currQuad, yylineno);}
#line 1804 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 238 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=newexpr(boolexpr_e); (yyval.node)->sym = newtemp(); (yyvsp[0].node)->isNot=1;
																	if((yyvsp[0].node)->type!=boolexpr_e){
																		(yyvsp[0].node)->truelist = makeTrueList(nextquadlabel());
																		(yyvsp[0].node)->falselist= makeFalseList(nextquadlabel());  
																		emit(if_eq, (yyvsp[0].node)->falselist, (yyvsp[0].node), newexpr_constbool('1'), currQuad, yylineno);
																		emit(jump, (yyvsp[0].node)->truelist, (expr*) 0, (expr*) 0, currQuad, yylineno);

																		/*emit(assign, $$, newexpr_constbool(1), (expr*) 0, currQuad, yylineno);
    																	emit(jump, newexpr_constnum(nextquadlabel()+2), (expr*) 0, (expr*) 0, currQuad, yylineno);
    																	emit(assign, $$, newexpr_constbool(0), (expr*) 0, currQuad, yylineno);*/
																	}
																	(yyval.node)->truelist = (yyvsp[0].node)->falselist; 
																	(yyval.node)->falselist = (yyvsp[0].node)->truelist; 
																	makeFinalEmits = 1;     }
#line 1823 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 252 "parser.y" /* yacc.c:1646  */
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
#line 1840 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 264 "parser.y" /* yacc.c:1646  */
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
#line 1857 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 276 "parser.y" /* yacc.c:1646  */
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
#line 1874 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 288 "parser.y" /* yacc.c:1646  */
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
#line 1891 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 300 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1897 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 303 "parser.y" /* yacc.c:1646  */
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
#line 1922 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 322 "parser.y" /* yacc.c:1646  */
    {afterAssign = 1; }
#line 1928 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 322 "parser.y" /* yacc.c:1646  */
    { afterAssign = 0; 
													
													FINALemits((yyvsp[0].node), yylineno);
													
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
#line 1948 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 339 "parser.y" /* yacc.c:1646  */
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
					(yyval.node) = emit_iftableitem((yyvsp[0].node));
			}
#line 1978 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 364 "parser.y" /* yacc.c:1646  */
    {global_LIB_use = 0; (yyval.node) = (yyvsp[0].node);}
#line 1984 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 365 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1990 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 366 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1996 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 367 "parser.y" /* yacc.c:1646  */
    {
				if(islibfunc && !call_depth){ 
						yyerror("Invalid insertion,3 trying to shadow LIBFUNC, before"); 
						islibfunc = 0;
				}
				(yyval.node) = (yyvsp[0].node);
			}
#line 2008 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 376 "parser.y" /* yacc.c:1646  */
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
#line 2067 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 430 "parser.y" /* yacc.c:1646  */
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
#line 2092 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 450 "parser.y" /* yacc.c:1646  */
    {
						if((tmp_rec = lookup(yylval.stringValue, 0)) == NULL){
							yyerror("undefined global variable");
						}else{
							(yyval.node) = lvalue_expr(tmp_rec);
						}
				}
#line 2104 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 457 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2110 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 460 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-2].node) != NULL){ (yyval.node) = member_item((yyvsp[-2].node), (yyvsp[0].stringValue)); } }
#line 2116 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 461 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-3].node) = emit_iftableitem((yyvsp[-3].node)); (yyval.node) = newexpr(tableitem_e); (yyval.node)->sym = (yyvsp[-3].node)->sym; (yyval.node)->index = (yyvsp[-1].node); }
#line 2122 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 462 "parser.y" /* yacc.c:1646  */
    {islibfunc = 0; (yyval.node) = NULL;}
#line 2128 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 463 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2134 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 467 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_call((yyvsp[-3].node), (yyvsp[-1].node), yylineno);}
#line 2140 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 468 "parser.y" /* yacc.c:1646  */
    {
									if((yyvsp[0].node)->boolConst == '1'){
										expr * self = (yyvsp[-1].node);
										(yyvsp[-1].node) = emit_iftableitem(member_item(self, (yyvsp[0].node)->charConst));
										self->next = (yyvsp[0].node)->next; /*add self front*/
										(yyvsp[0].node) = self;
									}
									(yyval.node) = make_call((yyvsp[-1].node), (yyvsp[0].node)->next, yylineno);
								}
#line 2154 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 477 "parser.y" /* yacc.c:1646  */
    {
																			expr* func = newexpr(programfunc_e);
																			func->sym = (yyvsp[-4].node)->sym;
																			(yyval.node) = make_call(func, (yyvsp[-1].node), yylineno);
																		}
#line 2164 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 484 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2170 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 485 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2176 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 488 "parser.y" /* yacc.c:1646  */
    {call_depth++; }
#line 2182 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 488 "parser.y" /* yacc.c:1646  */
    {	call_depth--;
																		(yyval.node) = newexpr(nil_e);
																		(yyval.node)->next = (yyvsp[-1].node);
																		(yyval.node)->charConst = NULL;
																		(yyval.node)->boolConst = '0';
																	}
#line 2193 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 496 "parser.y" /* yacc.c:1646  */
    {call_depth++; }
#line 2199 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 496 "parser.y" /* yacc.c:1646  */
    {
																		call_depth--;
																		(yyval.node) = newexpr(tableitem_e);
																		(yyval.node)->next = (yyvsp[-1].node);
																		(yyval.node)->charConst = (yyvsp[-4].stringValue);
																		(yyval.node)->boolConst = '1';
																	}
#line 2211 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 505 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); (yyval.node)->next=(yyvsp[0].node);}
#line 2217 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 506 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2223 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 509 "parser.y" /* yacc.c:1646  */
    { (yyval.node)=(yyvsp[-1].node); (yyval.node)->next=(yyvsp[0].node);}
#line 2229 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 510 "parser.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 2235 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 513 "parser.y" /* yacc.c:1646  */
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
#line 2251 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 524 "parser.y" /* yacc.c:1646  */
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
#line 2266 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 536 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); (yyval.node)->next = (yyvsp[0].node);}
#line 2272 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 539 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); (yyval.node)->next = (yyvsp[0].node);}
#line 2278 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 540 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2284 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 543 "parser.y" /* yacc.c:1646  */
    {afterAssign = 0;}
#line 2290 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 543 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); (yyval.node)->index = (yyvsp[-4].node); afterAssign = 1;}
#line 2296 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 546 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 2302 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 546 "parser.y" /* yacc.c:1646  */
    {hide_scope(scope); scope--;}
#line 2308 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 550 "parser.y" /* yacc.c:1646  */
    {infunc++;}
#line 2314 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 550 "parser.y" /* yacc.c:1646  */
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
								currQuadFuncStart = nextquadlabel();
								emit(jump, newexpr_constnum(0), (expr*) 0, (expr*) 0, currQuad, yylineno);
								emit(funcstart, (yyval.node), (expr *) 0, (expr *) 0, currQuad, yylineno);
								push(functionLocalsStack, functionLocalOffset);
								tmp_expr = (yyval.node);
							}
							resetformalargsoffset();
						}
#line 2337 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 567 "parser.y" /* yacc.c:1646  */
    {scope++; enterscopespace();}
#line 2343 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 567 "parser.y" /* yacc.c:1646  */
    {scope--; enterscopespace(); resetfunctionlocalsoffset(); push(loopcounterstack, loopcounter); loopcounter = 0;}
#line 2349 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 568 "parser.y" /* yacc.c:1646  */
    {
								infunc--; exitscopecounter(); exitscopecounter();
								(yyval.node) = tmp_expr;
								(yyval.node)->sym->totallocals = functionLocalOffset;
								functionLocalOffset = pop(functionLocalsStack);
								emit(funcend, (yyval.node), (expr *) 0, (expr *) 0, currQuad, yylineno);
								/*patchlabel(returnStart, nextquadlabel()); jump gia return an xreiastei tlk*/
								patchlabel(currQuadFuncStart, nextquadlabel());
								loopcounter = pop(loopcounterstack);
						}
#line 2364 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 578 "parser.y" /* yacc.c:1646  */
    {	
						infunc++;
						buffer = malloc(sizeof(char*));
						sprintf(buffer, "$%d", dollar_counter);
						buffer = strndup(buffer, sizeof(char*));
						(yyval.node) = lvalue_expr(insert(scope, yylineno, USERFUNC, buffer));
						currQuadFuncStart = nextquadlabel();
						emit(jump, newexpr_constnum(0), (expr*) 0, (expr*) 0, currQuad, yylineno);
						emit(funcstart, (yyval.node), (expr *) 0, (expr *) 0, currQuad, yylineno);
						push(functionLocalsStack, functionLocalOffset);
						tmp_expr = (yyval.node);
						dollar_counter++;
						resetformalargsoffset();
					}
#line 2383 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 591 "parser.y" /* yacc.c:1646  */
    {scope++; enterscopespace();}
#line 2389 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 591 "parser.y" /* yacc.c:1646  */
    {scope--; enterscopespace();}
#line 2395 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 591 "parser.y" /* yacc.c:1646  */
    {
																			infunc--;
																			exitscopecounter(); exitscopecounter();
																			(yyval.node) = tmp_expr; 
																			(yyval.node)->sym->totallocals = functionLocalOffset;
																			functionLocalOffset = pop(functionLocalsStack);
																			emit(funcend, (yyval.node), (expr *) 0, (expr *) 0, currQuad, yylineno);
																			/*patchlabel(returnStart, nextquadlabel()); jump gia return an xreiastei tlk*/
																			patchlabel(currQuadFuncStart, nextquadlabel());
																		}
#line 2410 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 603 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = newexpr_constnum(yylval.intValue); }
#line 2416 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 604 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = newexpr_constnum(yylval.doubleValue); }
#line 2422 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 605 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = newexpr_conststring(yylval.stringValue); }
#line 2428 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 606 "parser.y" /* yacc.c:1646  */
    {afterAssign = 0; (yyval.node) = newexpr(nil_e);}
#line 2434 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 607 "parser.y" /* yacc.c:1646  */
    {afterAssign = 0; (yyval.node) = newexpr_constbool('1');}
#line 2440 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 608 "parser.y" /* yacc.c:1646  */
    {afterAssign = 0; (yyval.node) = newexpr_constbool('0');}
#line 2446 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 611 "parser.y" /* yacc.c:1646  */
    {	formalArgOffset++;
				if(lookupLIBFUNCTs(yylval.stringValue)){
					yyerror("Invalid insertion, trying to shadow LIBFUNC");
				}else if(lookupFormal(yylval.stringValue, scope) != NULL){
					yyerror("duplicate formal names");
				}else{
					insert(scope, yylineno, FORMAL, yylval.stringValue);
				}
			}
#line 2460 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 623 "parser.y" /* yacc.c:1646  */
    {	formalArgOffset++;
				if(lookupLIBFUNCTs(yylval.stringValue)){
					yyerror("Invalid insertion, trying to shadow LIBFUNC");
				}else if(lookupFormal(yylval.stringValue, scope) != NULL){
					yyerror("duplicate formal names");
				}else{
					insert(scope, yylineno, FORMAL, yylval.stringValue);
				}
			}
#line 2474 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 635 "parser.y" /* yacc.c:1646  */
    {makeFinalEmits = 0;}
#line 2480 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 635 "parser.y" /* yacc.c:1646  */
    {FINALemits((yyvsp[-1].node), yylineno); emit(if_eq, newexpr_constnum(nextquadlabel()+2), (yyvsp[-1].node), newexpr_constbool('1'), currQuad, yylineno); 
									(yyval.node) = newexpr(var_e); (yyval.node)->numConst = nextquadlabel(); 
									emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);
									}
#line 2489 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 639 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = newexpr(var_e); (yyval.node)->numConst = nextquadlabel(); emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno); }
#line 2495 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 641 "parser.y" /* yacc.c:1646  */
    {patchlabel((int)((yyvsp[-1].node)->numConst), nextquadlabel()); }
#line 2501 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 642 "parser.y" /* yacc.c:1646  */
    {patchlabel((int)((yyvsp[-3].node)->numConst), (int)((yyvsp[-1].node)->numConst) + 1); patchlabel((int)((yyvsp[-1].node)->numConst), nextquadlabel()); }
#line 2507 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 645 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = newexpr_constnum(nextquadlabel()); }
#line 2513 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 648 "parser.y" /* yacc.c:1646  */
    { ++loopcounter; 
										FINALemits((yyvsp[-1].node), yylineno);
										breaklist_head = newstmt(-1); contlist_head = newstmt(-1);
										pushstacklist(breakstacklist, breaklist_head); pushstacklist(contstacklist, contlist_head); 
										emit(if_eq, newexpr_constnum(nextquadlabel()+2), (yyvsp[-1].node), newexpr_constbool('1'), currQuad, yylineno); 
										(yyval.intValue) = nextquadlabel();   
										emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);  }
#line 2525 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 657 "parser.y" /* yacc.c:1646  */
    { --loopcounter;	
				emit(jump, (yyvsp[-2].node), (expr *)0, (expr *)0, currQuad, yylineno);   
				patchlabel((yyvsp[-1].intValue), nextquadlabel());   

				patchBreakContinue(breakstacklist, nextquadlabel());
				popstacklist(breakstacklist);
				patchBreakContinue(contstacklist, (int)((yyvsp[-2].node)->numConst));
				popstacklist(contstacklist);
			}
#line 2539 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 668 "parser.y" /* yacc.c:1646  */
    { (yyval.intValue) = nextquadlabel();  emit(jump, newexpr_constnum(0), (expr *)0, (expr *)0, currQuad, yylineno);  }
#line 2545 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 670 "parser.y" /* yacc.c:1646  */
    {  (yyval.intValue) = nextquadlabel(); }
#line 2551 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 672 "parser.y" /* yacc.c:1646  */
    {makeFinalEmits = 0;}
#line 2557 "parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 672 "parser.y" /* yacc.c:1646  */
    {
				FINALemits((yyvsp[-1].node), yylineno); 	
				(yyval.forpref) = malloc(sizeof(struct forVar));
				(yyval.forpref)->test = (yyvsp[-2].intValue); (yyval.forpref)->enter = nextquadlabel();
				emit(if_eq, newexpr_constnum(1), (yyvsp[-1].node), newexpr_constbool('1'), currQuad, yylineno);
				
			}
#line 2569 "parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 681 "parser.y" /* yacc.c:1646  */
    { prev = infunc; infunc = 0; ++loopcounter;
					breaklist_head = newstmt(-1); contlist_head = newstmt(-1);
					pushstacklist(breakstacklist, breaklist_head); pushstacklist(contstacklist, contlist_head);
			}
#line 2578 "parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 684 "parser.y" /* yacc.c:1646  */
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
#line 2595 "parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 698 "parser.y" /* yacc.c:1646  */
    {afterAssign = 0; inReturn = 1;  /*emit(jump, newexpr_constnum(0), (expr*) 0, (expr*) 0, currQuad, yylineno); */
			if(!infunc){yyerror("Use of 'return' while not in a function");}}
#line 2602 "parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 699 "parser.y" /* yacc.c:1646  */
    { inReturn = 1; emit(ret, (yyvsp[-1].node), (expr *) 0, (expr *) 0,currQuad, yylineno); }
#line 2608 "parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 700 "parser.y" /* yacc.c:1646  */
    {if(!infunc){yyerror("Use of 'return' while not in a function");}}
#line 2614 "parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 700 "parser.y" /* yacc.c:1646  */
    {emit(ret, (expr *) 0, (expr *) 0, (expr *) 0,currQuad, yylineno);}
#line 2620 "parser.c" /* yacc.c:1646  */
    break;


#line 2624 "parser.c" /* yacc.c:1646  */
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
#line 703 "parser.y" /* yacc.c:1906  */


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
