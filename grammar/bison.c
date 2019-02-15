/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "pyparser.y" /* yacc.c:339  */

  /*Prologue section */
#include "heading.h"

// stuff from flex that bison needs to know about:
int yylex(void);
int yyerror(char *s);

extern "C" FILE *yyin;

#define YYSTYPE int

#line 79 "pyparser.tab.c" /* yacc.c:339  */

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
   by #include "pyparser.tab.h".  */
#ifndef YY_YY_PYPARSER_TAB_H_INCLUDED
# define YY_YY_PYPARSER_TAB_H_INCLUDED
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
    ASYNC = 258,
    AWAIT = 259,
    DEDENT = 260,
    INDENT = 261,
    NEWLINE = 262,
    ENDMARKER = 263,
    NAME = 264,
    NUMBER = 265,
    STRING = 266
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "pyparser.y" /* yacc.c:355  */

  int		int_val;
  string*	op_val;

#line 136 "pyparser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PYPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 153 "pyparser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  153
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1697

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  103
/* YYNRULES -- Number of rules.  */
#define YYNRULES  313
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  494

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    17,    81,     2,
      22,    23,    53,    14,    27,    15,    51,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,    29,
      71,    28,    72,     2,    21,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    82,     2,    83,    80,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    79,    85,    13,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    18,    19,
      20,    24,    26,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    52,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    73,    74,    75,    76,    77,    78,    86,    87,
      88,    89,    90
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    71,    72,    73,    74,    76,    77,    86,    87,
      88,    91,    92,    95,    96,    97,   100,   101,   102,   104,
     105,   114,   115,   116,   118,   119,   121,   122,   131,   132,
     133,   135,   136,   138,   140,   140,   142,   143,   145,   146,
     149,   149,   149,   149,   150,   150,   150,   150,   151,   152,
     154,   155,   157,   158,   159,   160,   162,   163,   165,   166,
     167,   168,   169,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   187,   188,   189,   189,
     189,   189,   189,   190,   191,   192,   193,   195,   196,   197,
     198,   200,   200,   201,   204,   205,   206,   207,   209,   210,
     211,   213,   214,   215,   216,   217,   218,   220,   221,   223,
     224,   226,   227,   228,   230,   231,   233,   234,   236,   237,
     239,   240,   242,   243,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   247,   248,   249,   251,   252,   254,   255,
     257,   258,   260,   261,   263,   264,   265,   266,   267,   269,
     270,   272,   273,   274,   278,   279,   280,   282,   283,   285,
     285,   287,   288,   289,   291,   291,   292,   293,   295,   296,
     298,   299,   301,   302,   304,   304,   305,   306,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   312,
     313,   314,   316,   317,   319,   320,   322,   323,   324,   326,
     327,   328,   330,   331,   332,   333,   334,   335,   337,   338,
     339,   340,   342,   343,   345,   346,   347,   349,   350,   352,
     353,   354,   355,   356,   357,   358,   359,   359,   359,   360,
     360,   360,   360,   362,   363,   364,   365,   367,   368,   369,
     370,   371,   372,   374,   375,   376,   377,   380,   381,   383,
     384,   386,   387,   388,   389,   390,   391,   392,   395,   396,
     398,   399,   400,   401,   403,   404,   406,   407,   409,   410,
     412,   413,   414,   415,   417,   418,   419,   420,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     436,   437,   438,   441,   442,   444,   445,   458,   459,   460,
     461,   462,   465,   466,   468,   469,   470,   471,   473,   474,
     480,   481,   484,   485
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASYNC", "AWAIT", "DEDENT", "INDENT",
  "NEWLINE", "ENDMARKER", "NAME", "NUMBER", "STRING", "\"**\"", "'~'",
  "'+'", "'-'", "'/'", "'%'", "\"//\"", "\">>\"", "\"<<\"", "'@'", "'('",
  "')'", "\"def\"", "':'", "\"->\"", "','", "'='", "';'", "\"+=\"",
  "\"-=\"", "\"*=\"", "\"@=\"", "\"/=\"", "\"%=\"", "\"&=\"", "\"|=\"",
  "\"^=\"", "\"<<=\"", "\">>=\"", "\"**=\"", "\"//=\"", "\"del\"",
  "\"pass\"", "\"break\"", "\"continue\"", "\"return\"", "\"raise\"",
  "\"from\"", "\"import\"", "'.'", "\"...\"", "'*'", "\"as\"",
  "\"global\"", "\"nonlocal\"", "\"assert\"", "\"if\"", "\"while\"",
  "\"else\"", "\"for\"", "\"in\"", "\"try\"", "\"finally\"", "\"with\"",
  "\"except\"", "\"lambda\"", "\"or\"", "\"and\"", "\"not\"", "'<'", "'>'",
  "\"==\"", "\">=\"", "\"<=\"", "\"<>\"", "\"!=\"", "\"is\"", "'|'", "'^'",
  "'&'", "'['", "']'", "'{'", "'}'", "\"None\"", "\"True\"", "\"False\"",
  "\"class\"", "\"yield\"", "$accept", "file_content", "file_input",
  "decorator", "decorators", "decorated", "async_funcdef", "funcdef",
  "parameters", "typedargslist", "typedarg", "tfpdef", "varargslist",
  "vararg", "vfpdef", "stmt", "small_stmts_star", "simple_stmt",
  "small_stmt", "expr_aux", "expr_aux_star", "expr_stmt", "annassign",
  "testlist_star_expr", "augassign", "del_stmt", "pass_stmt", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "yield_stmt", "raise_stmt",
  "import_stmt", "import_name", "import_points_plus", "import_points_star",
  "import_from", "import_as_name", "dotted_as_name", "import_as_names",
  "dotted_as_names", "dotted_name", "global_stmt", "nonlocal_stmt",
  "assert_stmt", "compound_stmt", "async_stmt", "if_stmt", "while_stmt",
  "for_stmt", "except_clause_plus", "try_stmt", "with_item_star",
  "with_stmt", "with_item", "except_clause", "stmt_plus", "suite", "test",
  "test_nocond", "lambdef", "lambdef_nocond", "or_test", "and_test",
  "not_test", "comparison", "comp_op", "star_expr", "expr", "xor_expr",
  "and_expr", "shift_expr", "arith_expr", "term", "factor", "power",
  "atom_expr", "string_plus", "atom", "testlist_comp_aux", "testlist_comp",
  "trailer", "subscript_star", "subscriptlist", "subscript", "sliceop",
  "exprlist_aux", "exprlist", "testlist_aux", "testlist",
  "dictorsetmaker_aux", "dictorsetmaker_aux2", "dictorsetmaker",
  "classdef", "arglist_aux", "arglist", "argument", "comp_iter",
  "comp_for", "comp_if", "yield_expr", "yield_arg", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   126,    43,    45,    47,    37,   268,   269,
     270,    64,    40,    41,   271,    58,   272,    44,    61,    59,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,    46,   294,    42,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,    60,    62,   312,   313,   314,   315,   316,   317,   124,
      94,    38,    91,    93,   123,   125,   318,   319,   320,   321,
     322
};
# endif

#define YYPACT_NINF -433

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-433)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     421,    25,    46,  -433,  -433,  -433,  -433,  -433,  1609,  1609,
    1609,    97,   370,   115,  1513,  -433,  -433,  -433,  1416,  1416,
     -31,    97,  -433,  1609,   142,   152,  1416,  1416,  1416,  1513,
      34,  1416,    86,  1528,  1142,   993,  -433,  -433,  -433,   173,
    1247,   509,   187,  -433,    29,  -433,  -433,  -433,  -433,  -433,
    -433,   507,  -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,
    -433,  -433,  -433,   175,   178,  -433,  -433,  -433,  -433,  -433,
    -433,  -433,  -433,  -433,  -433,    19,   141,  -433,   423,  -433,
     135,   138,   143,   150,   216,   182,  -433,  -433,    72,   221,
    -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,
    -433,   130,  -433,   912,   912,   204,   217,   228,  -433,   135,
     225,  -433,  -433,   233,  -433,   215,  -433,  -433,   157,   108,
    -433,   238,   120,   135,  -433,  -433,   239,   242,   243,   207,
      26,  -433,   219,  -433,  1416,   114,   244,   246,  -433,  -433,
     192,  1609,  -433,   102,    77,   185,   155,  1416,  -433,  -433,
    -433,  -433,  -433,  -433,   252,  -433,  -433,  -433,  -433,    78,
    1416,  1269,  -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,
    -433,  -433,  -433,  -433,  -433,   250,  -433,   868,   270,   271,
    1528,  1528,  1528,  -433,   220,  -433,  -433,  -433,  -433,  -433,
    -433,  -433,   211,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1015,   277,  1291,
    -433,  -433,  -433,  1039,   279,   229,  1269,  1513,   262,   265,
    -433,   266,  -433,  -433,  -433,   153,   212,  1513,  1416,  1416,
      36,  -433,  -433,  -433,  -433,   195,    97,   285,  1416,    26,
      26,  1416,   289,  -433,   149,   194,  1609,  -433,  1416,   287,
    -433,  1416,  -433,    40,  1416,  1269,   272,  -433,   273,  -433,
    -433,  1120,    26,  -433,  -433,  -433,   772,   269,  -433,  -433,
     822,  -433,  -433,  -433,  -433,  -433,    98,   141,  -433,  -433,
    -433,   135,   138,   143,   150,  -433,  -433,   182,   182,  -433,
    -433,  -433,  -433,  -433,  -433,  1416,  -433,  1416,   112,   274,
     275,  -433,  -433,  1416,   278,   224,  -433,  -433,   303,   288,
    -433,  1513,  -433,  -433,   254,  -433,  1269,  -433,   292,  -433,
     156,   291,   286,    26,  1416,  -433,   135,  -433,  -433,   267,
     310,  -433,   293,   295,   133,  -433,  -433,  -433,  -433,   264,
     300,   685,   301,  1416,   125,   302,    26,  1416,   135,  -433,
    -433,  -433,  1372,   305,  -433,   123,  -433,  -433,  1269,  1269,
     304,   307,  -433,  -433,  -433,  1416,   309,  -433,  1416,  -433,
    -433,  1416,  -433,  1166,  -433,   312,  1416,  -433,   311,  -433,
     327,   281,  1528,  -433,  -433,  1416,  -433,   332,  -433,  1416,
    -433,   320,   339,   167,  -433,   310,   310,  -433,   295,   324,
      26,  -433,   597,    26,   308,   329,   330,   333,    26,  -433,
    -433,  1609,   340,  1394,   341,  -433,  -433,  -433,    26,   342,
    -433,  -433,  -433,  -433,  1416,  -433,   312,  1291,  -433,  1528,
      41,  -433,  -433,  -433,    26,  -433,  -433,   343,   169,    26,
     297,  -433,  -433,  -433,   357,    26,    26,    26,  -433,   135,
    1416,  1609,   344,  1394,  -433,    26,  -433,  -433,  -433,    41,
    1497,  -433,  -433,  -433,  -433,  -433,  -433,  -433,   346,  -433,
     314,  -433,  -433,  -433,   135,  1416,  -433,  -433,   147,    85,
    -433,   318,    26,   347,  -433,  1497,   198,  -433,  -433,    26,
    -433,  1497,  -433,  -433
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     6,   226,   227,   217,     0,     0,
       0,     0,     0,     0,     0,    77,    83,    84,    85,    88,
      98,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   231,   232,     0,
     310,     0,     0,    11,     0,   131,   129,     3,    34,    36,
      40,    50,    41,    42,    43,    78,    79,    80,    82,    81,
      44,    91,    92,    45,    46,    47,    35,   132,   124,   125,
     126,   127,   128,    58,   163,   161,   170,   172,   175,    59,
     176,   190,   192,   194,   196,   199,   202,   211,   212,   228,
     215,   130,    87,   133,   135,   134,   214,   210,   208,   209,
     116,     0,   219,     0,     0,     0,     0,     0,   261,   260,
     264,    76,   266,   269,    86,    89,    94,    95,     0,     0,
     114,    93,   109,   189,   118,   120,   122,     0,     0,     0,
       0,   149,   152,    33,     0,     0,    28,    31,   174,   222,
       0,     0,   224,     0,     0,     0,     0,     0,   313,   311,
       4,     7,     5,     1,     0,    12,    15,    14,    13,     0,
       0,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    55,    52,     0,     0,     0,
       0,     0,     0,   185,     0,   178,   179,   180,   181,   182,
     183,   184,   187,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,   218,     8,     0,     0,     0,     0,     0,   239,     0,
     237,   242,   240,   221,   220,     0,     0,   265,   268,     0,
       0,    96,    97,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,   159,     0,     0,     0,   166,     0,     0,
      29,     0,   223,     0,     0,     0,   287,   284,   289,   285,
     225,     0,     0,   312,    16,    38,     0,    56,    60,    61,
       0,    51,    54,    53,   119,   121,     0,   171,   173,   186,
     188,   177,   191,   193,   195,   198,   197,   200,   201,   205,
     206,   207,   204,   203,   213,     0,   243,     0,   297,   296,
       0,   293,   246,   258,   251,     0,   247,   257,     0,     0,
     117,     0,   233,   234,     0,   238,     0,   241,    26,    19,
       0,    21,    24,     0,     0,   263,   262,   267,    90,   107,
       0,   104,     0,   106,     0,   115,   110,   123,   136,   138,
       0,     0,     0,   154,   144,     0,     0,     0,   153,   167,
      30,    32,     0,   282,   281,     0,   274,   275,   286,   288,
       0,     0,   290,    39,    37,     0,    49,    48,     0,   300,
     301,     0,   298,   295,   244,   255,   252,   245,   249,     9,
       0,     0,     0,   235,   236,     0,    20,     0,    22,     0,
      17,     0,     0,     0,   111,     0,     0,   101,   103,     0,
       0,   157,     0,     0,   155,     0,     0,     0,     0,   151,
     150,     0,     0,   283,   279,   278,   276,   277,     0,     0,
      57,   162,   299,   294,   258,   256,   253,   250,    10,     0,
     304,    27,    23,    25,     0,   108,   105,   112,     0,     0,
     140,   160,   158,   148,     0,     0,     0,     0,   142,   271,
       0,     0,     0,   280,   291,     0,   259,   254,   248,   305,
       0,   306,   302,   303,    18,   113,   102,   139,     0,   156,
     145,   146,   143,   270,   273,     0,   292,   307,     0,   308,
     165,   164,     0,     0,   272,     0,     0,   309,   141,     0,
     168,     0,   147,   169
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -433,  -433,  -433,   338,  -433,  -433,  -433,    10,  -433,  -433,
       2,  -433,   -90,   146,  -433,   -39,  -433,     1,   124,  -433,
    -433,  -433,  -433,   121,  -433,  -433,  -433,  -433,  -433,  -433,
    -433,  -433,  -433,  -433,  -433,  -433,  -433,  -433,     3,   160,
    -296,  -433,     6,  -433,  -433,  -433,  -433,  -433,  -433,  -433,
     396,  -433,  -433,  -433,   398,    55,    56,  -433,   -95,   -12,
    -388,  -433,  -433,  -176,   223,   -25,  -433,  -433,    17,    -5,
     213,   210,   214,    50,    63,    53,  -433,  -433,  -433,   406,
     313,   119,  -433,  -433,  -433,   -18,  -362,  -433,   -24,  -433,
     -30,    58,   276,  -433,   367,  -433,  -201,    43,  -432,   -78,
    -433,    -9,  -433
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    41,    42,    43,    44,    45,   156,    46,   226,   320,
     321,   322,   135,   136,   137,    47,   159,   243,    49,   271,
     175,    50,   176,    51,   177,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   118,   119,    62,   332,   120,
     333,   121,   122,    63,    64,    65,    66,    67,    68,    69,
      70,   344,    71,   245,    72,   131,   345,   402,   244,    73,
     479,    74,   480,    75,    76,    77,    78,   193,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
     218,   219,   210,   378,   305,   306,   307,   110,   111,   113,
     114,   353,   256,   145,    91,   299,   300,   301,   461,   462,
     463,    92,   149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     103,    48,   152,   106,   276,   129,   112,   115,   138,   109,
     148,    93,   309,   425,   126,   127,   128,   101,   123,   132,
     116,   117,   103,   143,   109,   220,   222,   477,   112,   104,
       2,   108,   154,   242,   393,     5,     6,     7,   398,     8,
       9,    10,    48,   215,   215,   329,   108,   487,    12,    13,
      11,   104,   144,    13,   157,     5,     6,     7,   330,   130,
     361,    97,    98,    99,   457,   257,   259,   352,    12,    14,
      15,    16,    17,    18,    19,    20,    21,   180,    22,    23,
     215,    24,    25,    26,   206,   265,    29,   181,   215,   331,
      31,   103,   103,    32,   207,   133,    33,   490,    22,   460,
     438,   217,   217,   493,   255,   215,   100,   266,    34,   181,
      35,   134,    36,    37,    38,   215,    40,   100,    39,   194,
     104,   104,   247,   208,   107,   235,   215,   254,    34,   255,
      35,   105,    36,    37,    38,   263,   253,   212,   217,   248,
     371,   249,   329,   460,   338,   339,   217,   272,   267,   268,
     352,   124,   213,   140,   209,   396,   133,   278,   368,   233,
     234,   125,   318,   217,   264,   112,   181,   362,   273,   197,
     198,   214,   485,   217,   237,   354,   319,   261,   269,   386,
     262,   214,   146,   387,   217,   405,   397,   153,   281,   406,
     436,   343,   466,   314,   395,   298,   395,   304,   201,   202,
     203,   298,   178,   204,   312,   179,   430,   230,   231,   232,
     182,   340,   109,   342,   194,   343,   327,   328,   195,   346,
     372,   347,   326,   491,   196,   249,   337,   223,   390,   112,
     199,   200,   211,   313,   108,   205,   349,   323,   324,   351,
     224,   348,   355,   356,   325,   334,   214,   285,   286,   298,
     225,   409,   227,   459,   289,   290,   291,   292,   293,   294,
     228,   367,   287,   288,   229,   236,   238,   239,   240,   241,
     260,   250,   357,   246,   251,   252,    13,   415,   270,   274,
     275,   280,   279,   369,   481,   370,   302,   381,   310,   315,
     311,   375,   316,   317,   336,   341,   133,   365,   374,   358,
     359,   373,   401,   376,   383,   440,   109,   377,   443,   481,
     379,   380,   391,   448,   389,   481,   382,   385,   388,   329,
     394,   392,   395,   454,   399,   400,   403,   408,   108,   418,
     419,   404,   413,   384,   428,   132,   161,   424,   427,   464,
     412,   318,    48,   429,   467,   434,   416,   416,   435,   439,
     470,   471,   472,   420,   445,   446,   421,   468,   447,   422,
     476,   298,   444,   442,   426,   450,   469,   455,   453,   475,
     465,   482,   489,   431,     2,   417,   417,   433,   483,     5,
       6,     7,   155,     8,     9,    10,   181,   488,   486,   432,
     364,   366,    12,   102,   492,   350,   335,    94,   437,    95,
     407,   452,   410,    48,   277,   283,   449,   282,    96,   458,
     284,   158,   456,   414,     0,   304,   423,   221,     0,     0,
     258,     0,    22,    23,     1,     2,     0,     0,     3,     4,
       5,     6,     7,     0,     8,     9,    10,    32,   473,     0,
      33,   452,    11,    12,     0,    13,   474,     0,     0,     0,
       0,     0,    34,     0,    35,     0,    36,    37,    38,     0,
      40,     0,     0,   484,    14,    15,    16,    17,    18,    19,
      20,    21,     0,    22,    23,     0,    24,    25,    26,    27,
      28,     0,    29,     0,    30,   183,    31,     0,    32,     0,
       0,    33,     0,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,    34,     0,    35,     0,    36,    37,    38,
      39,    40,     1,     2,     0,     0,   150,   151,     5,     6,
       7,     0,     8,     9,    10,     0,     0,     0,     0,     0,
      11,    12,   160,    13,   161,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
       0,    22,    23,     0,    24,    25,    26,    27,    28,     0,
      29,     0,    30,     0,    31,     0,    32,     0,     0,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,    35,     0,    36,    37,    38,    39,    40,
       1,     2,   441,     0,     0,     0,     5,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,    11,    12,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
      23,     0,    24,    25,    26,    27,    28,     0,    29,     0,
      30,     0,    31,     0,    32,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,    35,     0,    36,    37,    38,    39,    40,     1,     2,
       0,     0,     0,     0,     5,     6,     7,     0,     8,     9,
      10,     0,     0,     0,     0,     0,    11,    12,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    22,    23,     0,
      24,    25,    26,    27,    28,     0,    29,     0,    30,     0,
      31,     0,    32,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     0,    35,
       0,    36,    37,    38,    39,    40,     2,     0,     0,   363,
       0,     5,     6,     7,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,    23,     2,    24,    25,    26,
       0,     5,     6,     7,     0,     8,     9,    10,     0,    32,
       0,     0,    33,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,    35,     0,    36,    37,
      38,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,    22,    23,     0,     5,     6,     7,
       0,     8,     9,    10,     0,     0,     0,     0,     0,    32,
      12,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,    35,     0,    36,    37,
      38,     0,    40,     0,     0,   215,     2,     0,     0,     0,
      22,     5,     6,     7,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,    12,    32,     0,     0,    33,   216,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,    35,     0,    36,    37,    38,     0,    40,     0,
       0,     0,     0,     0,    22,    23,     0,     0,     0,     0,
       0,     0,     0,   217,     0,     0,     0,     0,     0,    32,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,    35,     2,    36,    37,
      38,     0,     5,     6,     7,   141,     8,     9,    10,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     2,
       0,     0,     0,     0,     5,     6,     7,   295,     8,     9,
      10,     0,     0,     0,     0,     0,     0,    12,   296,     0,
       0,     0,     0,     2,     0,    22,    23,     0,     5,     6,
       7,   295,     8,     9,    10,     0,     0,     0,     0,     0,
      32,    12,   308,    33,     0,     0,     0,    22,   297,     0,
       0,     0,     0,     0,     0,    34,     0,    35,   142,    36,
      37,    38,    32,     0,     0,    33,     0,     0,     0,     0,
       0,    22,   297,     0,     0,     0,     0,    34,     0,    35,
       0,    36,    37,    38,     0,     0,    32,     0,     0,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,    35,     2,    36,    37,    38,     0,     5,
       6,     7,   295,     8,     9,    10,     0,     0,     0,     0,
       0,     0,    12,   360,     0,     0,     2,     0,     0,     0,
       0,     5,     6,     7,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       2,     0,    22,   297,     0,     5,     6,     7,   295,     8,
       9,    10,     0,     0,     0,     0,     0,    32,    12,     0,
      33,     0,     0,     0,    22,    23,     0,     0,     0,     0,
       0,     0,    34,     0,    35,     0,    36,    37,    38,    32,
       0,     0,    33,     0,     0,     0,     0,     0,    22,   297,
       0,     0,     0,     0,    34,   139,    35,     0,    36,    37,
      38,     0,     0,    32,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,     0,
      35,     2,    36,    37,    38,     0,     5,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     2,     0,     0,     0,     0,     5,     6,
       7,     0,     8,     9,    10,     0,     0,     0,     0,     0,
       0,    12,     0,     0,     0,     2,   147,     0,     0,    22,
       5,     6,     7,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,    12,    32,     0,   303,    33,     0,     0,
       0,    22,    23,     0,     0,     0,     0,     0,     0,    34,
       0,    35,     0,    36,    37,    38,    32,     0,     0,    33,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    34,     0,    35,     0,    36,    37,    38,    32,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,    35,     2,    36,    37,    38,
       0,     5,     6,     7,   411,     8,     9,    10,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     2,     0,
       0,     0,     0,     5,     6,     7,   451,     8,     9,    10,
       0,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       2,     0,     0,     0,    22,     5,     6,     7,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,    12,    32,
       0,     0,    33,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,    34,     0,    35,     0,    36,    37,
      38,    32,     0,     0,    33,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,    34,     0,    35,     0,
      36,    37,    38,    32,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,     0,
      35,     2,    36,    37,    38,     0,     5,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     2,     0,    12,
       0,     0,     5,     6,     7,     0,     8,     9,    10,     0,
       0,     0,     2,     0,     0,    12,     0,     5,     6,     7,
       0,     8,     9,    10,     0,     0,     0,     0,     0,    22,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   478,    22,    23,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      22,    35,     0,    36,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,    35,    33,    36,
      37,    38,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,    35,     2,    36,    37,    38,     0,     5,     6,
       7,     0,     8,     9,    10,     0,     0,     0,     0,     0,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,    35,     0,    36,    37,    38
};

static const yytype_int16 yycheck[] =
{
      12,     0,    41,    12,   180,    29,    18,    19,    33,    14,
      40,     1,   213,   375,    26,    27,    28,    11,    23,    31,
      51,    52,    34,    35,    29,   103,   104,   459,    40,    12,
       4,    14,     3,     7,   330,     9,    10,    11,   334,    13,
      14,    15,    41,     3,     3,     9,    29,   479,    22,    24,
      21,    34,    35,    24,    44,     9,    10,    11,    22,    25,
     261,     8,     9,    10,   426,   143,   144,    27,    22,    43,
      44,    45,    46,    47,    48,    49,    50,    58,    52,    53,
       3,    55,    56,    57,    12,     7,    61,    68,     3,    53,
      65,   103,   104,    67,    22,     9,    70,   485,    52,    58,
     396,    61,    61,   491,    27,     3,     9,    29,    82,    68,
      84,    25,    86,    87,    88,     3,    90,     9,    89,    79,
     103,   104,   134,    51,     9,   119,     3,    25,    82,    27,
      84,    12,    86,    87,    88,   147,   141,     7,    61,    25,
      28,    27,     9,    58,   239,   240,    61,   177,   160,   161,
      27,     9,    22,    34,    82,    22,     9,   182,    60,    51,
      52,     9,     9,    61,   154,   177,    68,   262,   177,    19,
      20,    51,    25,    61,    54,   253,    23,    22,   161,    23,
      25,    51,     9,    27,    61,    60,    53,     0,   193,    64,
      23,    66,    23,   217,    27,   207,    27,   209,    16,    17,
      18,   213,    27,    21,   216,    27,   382,    50,    51,    52,
      69,   241,   217,    64,    79,    66,   228,   229,    80,    25,
     298,    27,   227,    25,    81,    27,   238,    23,   323,   241,
      14,    15,    11,   216,   217,    53,   248,    25,    26,   251,
      23,   246,   254,   255,   227,    50,    51,   197,   198,   261,
      22,   346,    27,   429,   201,   202,   203,   204,   205,   206,
      27,   270,   199,   200,    49,    27,    27,    25,    25,    62,
      85,    27,   255,    54,    28,    83,    24,   355,    28,     9,
       9,    70,    62,   295,   460,   297,     9,   311,     9,    27,
      61,   303,    27,    27,     9,     6,     9,    28,    23,    27,
      27,    27,   341,    25,   316,   400,   311,    83,   403,   485,
       7,    23,   324,   408,    28,   491,    62,    25,    27,     9,
      27,    54,    27,   418,    60,    25,    25,    25,   311,    25,
      23,   343,    27,   316,     7,   347,    27,    25,    27,   434,
     352,     9,   341,    62,   439,    25,   358,   359,     9,    25,
     445,   446,   447,   365,    25,    25,   368,    60,    25,   371,
     455,   373,    54,   402,   376,    25,     9,    25,    27,    25,
      27,    25,    25,   385,     4,   358,   359,   389,    64,     9,
      10,    11,    44,    13,    14,    15,    68,   482,   478,   387,
     266,   270,    22,    23,   489,   249,   236,     1,   395,     1,
     344,   413,   347,   402,   181,   195,   411,   194,     2,   427,
     196,    44,   424,   355,    -1,   427,   373,   104,    -1,    -1,
     144,    -1,    52,    53,     3,     4,    -1,    -1,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    67,   450,    -1,
      70,   453,    21,    22,    -1,    24,   451,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    88,    -1,
      90,    -1,    -1,   475,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    -1,    55,    56,    57,    58,
      59,    -1,    61,    -1,    63,    62,    65,    -1,    67,    -1,
      -1,    70,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    82,    -1,    84,    -1,    86,    87,    88,
      89,    90,     3,     4,    -1,    -1,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      21,    22,    25,    24,    27,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    -1,    55,    56,    57,    58,    59,    -1,
      61,    -1,    63,    -1,    65,    -1,    67,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    84,    -1,    86,    87,    88,    89,    90,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    -1,    55,    56,    57,    58,    59,    -1,    61,    -1,
      63,    -1,    65,    -1,    67,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    84,    -1,    86,    87,    88,    89,    90,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    21,    22,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    61,    -1,    63,    -1,
      65,    -1,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    84,
      -1,    86,    87,    88,    89,    90,     4,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,     4,    55,    56,    57,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    67,
      -1,    -1,    70,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    84,    -1,    86,    87,
      88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,    52,    53,    -1,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    67,
      22,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    84,    -1,    86,    87,
      88,    -1,    90,    -1,    -1,     3,     4,    -1,    -1,    -1,
      52,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    67,    -1,    -1,    70,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    84,    -1,    86,    87,    88,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    84,     4,    86,    87,
      88,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,     4,    -1,    52,    53,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      67,    22,    23,    70,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    84,    85,    86,
      87,    88,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    -1,    82,    -1,    84,
      -1,    86,    87,    88,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    84,     4,    86,    87,    88,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    -1,    -1,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    52,    53,    -1,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    67,    22,    -1,
      70,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    88,    67,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    86,    87,
      88,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      84,     4,    86,    87,    88,    -1,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,     4,    49,    -1,    -1,    52,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    67,    -1,    25,    70,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    84,    -1,    86,    87,    88,    67,    -1,    -1,    70,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    84,    -1,    86,    87,    88,    67,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    84,     4,    86,    87,    88,
      -1,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
       4,    -1,    -1,    -1,    52,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    67,
      -1,    -1,    70,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    84,    -1,    86,    87,
      88,    67,    -1,    -1,    70,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    84,    -1,
      86,    87,    88,    67,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      84,     4,    86,    87,    88,    -1,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,     4,    -1,    22,
      -1,    -1,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,     4,    -1,    -1,    22,    -1,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    52,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    52,    53,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      52,    84,    -1,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    84,    70,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    84,     4,    86,    87,    88,    -1,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    84,    -1,    86,    87,    88
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     7,     8,     9,    10,    11,    13,    14,
      15,    21,    22,    24,    43,    44,    45,    46,    47,    48,
      49,    50,    52,    53,    55,    56,    57,    58,    59,    61,
      63,    65,    67,    70,    82,    84,    86,    87,    88,    89,
      90,    92,    93,    94,    95,    96,    98,   106,   108,   109,
     112,   114,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   128,   134,   135,   136,   137,   138,   139,   140,
     141,   143,   145,   150,   152,   154,   155,   156,   157,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   185,   192,    98,   141,   145,   170,   166,   166,   166,
       9,   133,    23,   150,   159,   172,   192,     9,   159,   160,
     178,   179,   150,   180,   181,   150,    51,    52,   126,   127,
     130,   132,   133,   160,     9,     9,   150,   150,   150,   179,
      25,   146,   150,     9,    25,   103,   104,   105,   156,    83,
     172,    12,    85,   150,   159,   184,     9,    49,   181,   193,
       7,     8,   106,     0,     3,    94,    97,    98,   185,   107,
      25,    27,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   111,   113,   115,    27,    27,
      58,    68,    69,    62,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   158,    79,    80,    81,    19,    20,    14,
      15,    16,    17,    18,    21,    53,    12,    22,    51,    82,
     173,    11,     7,    22,    51,     3,    27,    61,   171,   172,
     190,   171,   190,    23,    23,    22,    99,    27,    27,    49,
      50,    51,    52,    51,    52,   133,    27,    54,    27,    25,
      25,    62,     7,   108,   149,   144,    54,   150,    25,    27,
      27,    28,    83,   160,    25,    27,   183,   190,   183,   190,
      85,    22,    25,   150,    98,     7,    29,   150,   150,   159,
      28,   110,   181,   192,     9,     9,   154,   155,   156,    62,
      70,   160,   161,   162,   163,   164,   164,   165,   165,   166,
     166,   166,   166,   166,   166,    12,    23,    53,   150,   186,
     187,   188,     9,    25,   150,   175,   176,   177,    23,   187,
       9,    61,   150,   159,   179,    27,    27,    27,     9,    23,
     100,   101,   102,    25,    26,   159,   160,   150,   150,     9,
      22,    53,   129,   131,    50,   130,     9,   150,   149,   149,
     181,     6,    64,    66,   142,   147,    25,    27,   160,   150,
     104,   150,    27,   182,   190,   150,   150,   159,    27,    27,
      23,   187,   149,     7,   109,    28,   114,   192,    60,   150,
     150,    28,   190,    27,    23,   150,    25,    83,   174,     7,
      23,   179,    62,   150,   159,    25,    23,    27,    27,    28,
     149,   150,    54,   131,    27,    27,    22,    53,   131,    60,
      25,   106,   148,    25,   150,    60,    64,   147,    25,   149,
     146,    12,   150,    27,   182,   190,   150,   159,    25,    23,
     150,   150,   150,   188,    25,   177,   150,    27,     7,    62,
     154,   150,   101,   150,    25,     9,    23,   129,   131,    25,
     149,     5,   106,   149,    54,    25,    25,    25,   149,   160,
      25,    12,   150,    27,   149,    25,   150,   177,   176,   154,
      58,   189,   190,   191,   149,    27,    23,   149,    60,     9,
     149,   149,   149,   150,   160,    25,   149,   189,    67,   151,
     153,   154,    25,    64,   150,    25,   103,   189,   149,    25,
     151,    25,   149,   151
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    92,    92,    92,    93,    93,    94,    94,
      94,    95,    95,    96,    96,    96,    97,    98,    98,    99,
      99,   100,   100,   100,   101,   101,   102,   102,   103,   103,
     103,   104,   104,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   109,   109,   109,   109,   109,   109,   110,   110,
     111,   111,   112,   112,   112,   112,   113,   113,   114,   114,
     114,   114,   114,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   116,   117,   118,   118,
     118,   118,   118,   119,   120,   121,   121,   122,   123,   123,
     123,   124,   124,   125,   126,   126,   126,   126,   127,   127,
     127,   128,   128,   128,   128,   128,   128,   129,   129,   130,
     130,   131,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   138,   138,   138,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   143,   143,   143,   144,
     144,   145,   146,   146,   147,   147,   147,   148,   148,   149,
     149,   150,   150,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   155,   155,   156,   156,   157,   157,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   159,
     160,   160,   161,   161,   162,   162,   163,   163,   163,   164,
     164,   164,   165,   165,   165,   165,   165,   165,   166,   166,
     166,   166,   167,   167,   168,   168,   168,   169,   169,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   171,   171,   171,   171,   172,   172,   172,
     172,   172,   172,   173,   173,   173,   173,   174,   174,   175,
     175,   176,   176,   176,   176,   176,   176,   176,   177,   177,
     178,   178,   178,   178,   179,   179,   180,   180,   181,   181,
     182,   182,   182,   182,   183,   183,   183,   183,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     185,   185,   185,   186,   186,   187,   187,   188,   188,   188,
     188,   188,   189,   189,   190,   190,   190,   190,   191,   191,
     192,   192,   193,   193
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     2,     3,     5,
       6,     1,     2,     2,     2,     2,     2,     5,     7,     2,
       3,     1,     2,     3,     1,     3,     1,     3,     1,     2,
       3,     1,     3,     1,     1,     1,     0,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       0,     2,     2,     3,     3,     2,     2,     4,     1,     1,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       4,     1,     1,     2,     1,     1,     2,     2,     0,     2,
       2,     5,     7,     5,     4,     6,     4,     1,     3,     1,
       3,     2,     3,     4,     1,     3,     1,     3,     2,     3,
       2,     3,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     4,     4,     4,     7,
       6,     9,     3,     4,     4,     7,     7,    10,     6,     0,
       3,     5,     1,     3,     1,     2,     4,     1,     2,     1,
       4,     1,     5,     1,     1,     1,     3,     4,     3,     4,
       1,     3,     1,     3,     2,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     2,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     2,     2,
       2,     1,     1,     3,     2,     1,     2,     1,     2,     2,
       3,     3,     2,     3,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     3,     2,     3,     2,
       2,     3,     2,     2,     3,     3,     2,     0,     3,     2,
       3,     1,     2,     3,     4,     2,     3,     1,     1,     2,
       1,     1,     3,     3,     1,     2,     1,     3,     2,     1,
       4,     3,     5,     4,     2,     2,     3,     3,     4,     4,
       5,     3,     3,     4,     2,     2,     3,     2,     3,     2,
       4,     6,     7,     1,     3,     2,     1,     1,     2,     3,
       2,     2,     1,     1,     4,     5,     5,     6,     2,     3,
       1,     2,     2,     1
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
      
#line 1863 "pyparser.tab.c" /* yacc.c:1646  */
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
#line 491 "pyparser.y" /* yacc.c:1906  */

  /*Epilogue */

int yyerror(string s)
{
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << yylineno << endl;
  exit(1);
}

int yyerror(char *s)
{
  return yyerror(string(s));
}


