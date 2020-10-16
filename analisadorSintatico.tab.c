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
#line 5 "analisadorSintatico.y" /* yacc.c:339  */

  #include <stdlib.h>
  #include <stdio.h>

  int yylex();
  void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
  }
  extern int yylex_destroy(void);
  extern FILE *yyin;

  struct node {
    char *node_type; // "FUNCTION", "VARIABLE", "CODE_BLOCK"....
    char *symbolName;
    char *symbolType;
    struct node *left;
    struct node *right;
  };

  struct node* syntax_tree = NULL;
  struct node* add_regular_node(char * node_type, struct node *left, struct node *right);
  struct node* add_variable_node(char * symbolType, char * symbolName);
  struct node* add_operator_node(char * symbolName);
  struct node* add_value_node(char * symbolName);
  struct node* add_function_node(char * symbolType, char * symbolName, struct node *left, struct node *right);
  void gen_table_symbol(char * type, char * name);
  void print_tree(struct node * tree, int prof);


#line 96 "analisadorSintatico.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "analisadorSintatico.tab.h".  */
#ifndef YY_YY_ANALISADORSINTATICO_TAB_H_INCLUDED
# define YY_YY_ANALISADORSINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    TYPE = 259,
    WHILE = 260,
    IF = 261,
    ELSE = 262,
    RETURN = 263,
    WRITE = 264,
    READ = 265,
    FOR = 266,
    STRING = 267,
    INT = 268,
    FLOAT = 269,
    VECTOR = 270,
    COMPARABLES = 271,
    ADD = 272,
    SUB = 273,
    TIMES = 274,
    DIV = 275,
    OR = 276,
    AND = 277,
    ASSING = 278,
    DISTANCE = 279,
    NORMALIZE = 280,
    BOOLEAN = 281,
    OPEN_PARENTESES = 282,
    CLOSE_PARENTESES = 283,
    OPEN_BRACKETS = 284,
    CLOSE_BRACKETS = 285,
    OPEN_CURLY = 286,
    CLOSE_CURLY = 287,
    QUOTES = 288,
    CEQ = 289,
    CNE = 290,
    CLT = 291,
    CLE = 292,
    CGT = 293,
    CGE = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "analisadorSintatico.y" /* yacc.c:355  */

  char *string;
  struct node *node;

#line 181 "analisadorSintatico.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_ANALISADORSINTATICO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 212 "analisadorSintatico.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
       2,     2,    40,    42,    45,    43,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    72,    76,    83,    87,    94,   101,   108,
     112,   119,   123,   130,   137,   144,   148,   155,   159,   166,
     170,   174,   178,   182,   186,   190,   197,   201,   208,   213,
     221,   228,   232,   239,   244,   250,   254,   255,   255,   259,
     264,   273,   277,   284,   293,   300,   307,   312,   319,   326,
     331,   338,   342,   346,   350,   354,   358,   365,   369,   376,
     380,   384,   388,   392,   396,   400,   407,   415,   419,   426,
     430
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TYPE", "WHILE", "IF", "ELSE",
  "RETURN", "WRITE", "READ", "FOR", "STRING", "INT", "FLOAT", "VECTOR",
  "COMPARABLES", "ADD", "SUB", "TIMES", "DIV", "OR", "AND", "ASSING",
  "DISTANCE", "NORMALIZE", "BOOLEAN", "OPEN_PARENTESES",
  "CLOSE_PARENTESES", "OPEN_BRACKETS", "CLOSE_BRACKETS", "OPEN_CURLY",
  "CLOSE_CURLY", "QUOTES", "CEQ", "CNE", "CLT", "CLE", "CGT", "CGE", "'*'",
  "'/'", "'+'", "'-'", "';'", "','", "$accept", "prog", "declaration_list",
  "declaration", "var_declaration", "func_declaration", "params",
  "params_list", "param", "compound_statement", "local_declarations",
  "statement_list", "statement", "expression_statement",
  "conditional_statement", "iteration_statement", "return_statement",
  "io_statement", "string", "$@1", "vector_statement", "vector_param",
  "assing_statement", "expression", "var", "simple_expression", "relop",
  "op_expression", "operators", "term", "factor", "call", "args",
  "arg_list", YY_NULLPTR
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
      42,    47,    43,    45,    59,    44
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      12,     9,    17,    12,   -92,   -92,   -92,   -20,   -92,   -92,
      18,   -92,    22,    -7,   -17,   -92,   -92,    -2,    18,   -92,
     -92,   -92,    32,    34,   -92,    45,     0,    20,    30,    35,
       5,    36,    37,   -92,   -92,   -92,    38,    47,   -92,    53,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
      52,   -92,    66,    53,   -92,   -92,    53,    53,    53,   -92,
       1,   -92,    72,     2,    58,     8,     8,    48,    53,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,    53,    53,   -92,   -92,
      50,    51,    67,    66,    69,   -92,   -92,   -92,    70,    71,
     -92,    55,   -92,    73,   -92,    59,    72,    53,   -92,    53,
      -2,    -2,    -6,   -92,    60,    61,     8,   -92,   -92,   -92,
     -92,    95,   -92,    78,   -92,   -92,    79,    -2,    64,   -92,
     -92,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     6,     5,     0,     1,     3,
      10,     7,     0,     0,     9,    12,    13,     0,     0,    16,
       8,    11,    18,     0,    15,     0,     0,    45,     0,     0,
       0,     0,     0,    62,    63,    64,     0,     0,    65,     0,
      14,    17,    19,    20,    21,    22,    23,    24,    25,    26,
      60,    27,    44,    50,    58,    61,    68,     0,     0,    32,
       0,    60,    44,     0,     0,     0,     0,     0,     0,    48,
      51,    52,    53,    54,    55,    56,     0,     0,    57,    70,
       0,    67,     0,    47,     0,    31,    45,    37,     0,     0,
      42,     0,    41,     0,    59,     0,    46,    49,    66,     0,
       0,     0,     0,    38,     0,     0,     0,    39,    43,    69,
      30,    28,    36,     0,    34,    33,     0,     0,     0,    40,
      29,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -92,   106,    88,   -92,   -92,   -92,    93,   -91,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -63,   -92,   -26,   -25,   -43,   -92,   -24,   -92,    39,
     -51,   -92,   -92,   -92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    13,    14,    15,    20,
      22,    25,    41,    42,    43,    44,    45,    46,   102,   103,
      47,    91,    48,    49,    61,    51,    76,    62,    77,    53,
      54,    55,    80,    81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    52,    78,    93,    60,    86,   112,    10,    27,   110,
     111,    86,     7,    67,    82,    84,     1,     8,    33,    34,
      35,    17,    12,    90,    11,    16,   120,   113,    18,    19,
      79,    38,    39,    83,    83,    87,    23,    26,    88,    89,
      92,    92,    95,   116,    11,    85,    78,    56,    27,    59,
      28,    29,    96,    30,    31,    32,    27,    57,    33,    34,
      35,    86,    58,    63,    64,    65,    33,    34,    35,    36,
      37,    38,    39,   109,    66,    68,    94,    40,    98,    38,
      39,    92,    69,    70,    71,    72,    73,    74,    75,    70,
      71,    72,    73,    74,    75,   100,    99,   101,   104,   105,
     106,   107,   117,   108,   114,   115,   118,   119,   121,     9,
      24,    21,     0,     0,     0,     0,    97
};

static const yytype_int8 yycheck[] =
{
      25,    25,    53,    66,    30,     3,    12,    27,     3,   100,
     101,     3,     3,    39,    57,    58,     4,     0,    13,    14,
      15,    28,     4,    15,    44,     3,   117,    33,    45,    31,
      56,    26,    27,    57,    58,    33,     4,     3,    63,    64,
      65,    66,    68,   106,    44,    44,    97,    27,     3,    44,
       5,     6,    76,     8,     9,    10,     3,    27,    13,    14,
      15,     3,    27,    27,    27,    27,    13,    14,    15,    24,
      25,    26,    27,    99,    27,    23,    28,    32,    28,    26,
      27,   106,    16,    17,    18,    19,    20,    21,    22,    17,
      18,    19,    20,    21,    22,    28,    45,    28,    28,    28,
      45,    28,     7,    44,    44,    44,    28,    28,    44,     3,
      22,    18,    -1,    -1,    -1,    -1,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    47,    48,    49,    50,    51,     3,     0,    49,
      27,    44,     4,    52,    53,    54,     3,    28,    45,    31,
      55,    54,    56,     4,    50,    57,     3,     3,     5,     6,
       8,     9,    10,    13,    14,    15,    24,    25,    26,    27,
      32,    58,    59,    60,    61,    62,    63,    66,    68,    69,
      70,    71,    73,    75,    76,    77,    27,    27,    27,    44,
      69,    70,    73,    27,    27,    27,    27,    69,    23,    16,
      17,    18,    19,    20,    21,    22,    72,    74,    76,    69,
      78,    79,    71,    73,    71,    44,     3,    33,    70,    70,
      15,    67,    70,    67,    28,    69,    73,    75,    28,    45,
      28,    28,    64,    65,    28,    28,    45,    28,    44,    69,
      55,    55,    12,    33,    44,    44,    67,     7,    28,    28,
      55,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    51,    52,
      52,    53,    53,    54,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    60,    60,
      61,    62,    62,    63,    63,    63,    64,    65,    64,    66,
      66,    67,    67,    68,    69,    70,    71,    71,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    77,    78,    78,    79,
      79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       0,     3,     1,     2,     4,     2,     0,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     7,
       5,     3,     2,     5,     5,     7,     2,     0,     1,     4,
       6,     1,     1,     4,     1,     1,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     4,     1,     0,     3,
       1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 65 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("prog <- declaration_list\n");
    syntax_tree = (yyvsp[0].node);
  }
#line 1481 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration_list <- declaration_list declation\n");
    (yyval.node) = add_regular_node("DECLARATION", (yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1490 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 76 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration_list <- declaration\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1499 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 83 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration <- func_declaration\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1508 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 87 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration <- var_declaration\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1517 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 94 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("var_declaration <- TYPE ID;\n");
    (yyval.node) = add_variable_node((yyvsp[-2].string), (yyvsp[-1].string));
  }
#line 1526 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 101 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("func_declaration <- TYPE ID (params) compound_statement;\n");
    (yyval.node) = add_function_node((yyvsp[-5].string), (yyvsp[-4].string), (yyvsp[-2].node), (yyvsp[0].node));
  }
#line 1535 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 108 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("params <- params_list\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1544 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 112 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("params <- \n");
    (yyval.node) = NULL;
  }
#line 1553 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("params_list <- params_list, param\n");
    (yyval.node) = add_regular_node("PARAMS", (yyvsp[-2].node), (yyvsp[0].node));
  }
#line 1562 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 123 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("params_list <- param\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1571 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 130 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("param <- TYPE ID\n");
    (yyval.node) = add_variable_node((yyvsp[-1].string), (yyvsp[0].string));
  }
#line 1580 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 137 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("compound_statement <- { local_declarations statement_list}\n");
    (yyval.node) = add_regular_node("STATEMENT", (yyvsp[-2].node), (yyvsp[-1].node));
  }
#line 1589 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 144 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("local_declarations <- local_declarations var_declaration\n");
    (yyval.node) = add_regular_node("DECLARATION", (yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1598 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 148 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("local_declarations <- \n");
    (yyval.node) = NULL;
  }
#line 1607 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 155 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement_list <- statement_list statement\n");
    (yyval.node) = add_regular_node("STATEMENT", (yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1616 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 159 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement_list <- \n");
    (yyval.node) = NULL;
  }
#line 1625 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 166 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- expression_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1634 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 170 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- conditional_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1643 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 174 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- iteration_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1652 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 178 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- return_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1661 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 182 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- io_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1670 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 186 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- vector_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1679 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 190 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- assing_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1688 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 197 "analisadorSintatico.y" /* yacc.c:1646  */
    {
   printf("expression_statement <- expression\n");
   (yyval.node) = (yyvsp[0].node);
  }
#line 1697 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 201 "analisadorSintatico.y" /* yacc.c:1646  */
    {
   printf("expression_statement <- simple_expression\n");
   (yyval.node) = (yyvsp[0].node);
  }
#line 1706 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 208 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("conditional_statement <- if(expression)compound_statement\n");
    struct node *aux = add_regular_node("STATEMENT", (yyvsp[0].node), NULL);
    (yyval.node) = add_regular_node("CONDITIONAL", (yyvsp[-2].node), aux);
  }
#line 1716 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 213 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("conditional_statement <- if(expression)compound_statement eles compund_statement\n");
    struct node *aux = add_regular_node("STATEMENT", (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node) = add_regular_node("CONDITIONAL", (yyvsp[-4].node), aux);
  }
#line 1726 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 221 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("iteration_statement <- while(expression)compound_statement\n");
    (yyval.node) = add_regular_node("ITERATOR", (yyvsp[-2].node), (yyvsp[0].node));
  }
#line 1735 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 228 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("return_statement <- RETURN expression;\n");
    (yyval.node) = add_regular_node("RETURN", (yyvsp[-1].node), NULL);
  }
#line 1744 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 232 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("return_statement <- RETURN ;\n");
    (yyval.node) = add_regular_node("RETURN", NULL, NULL);
  }
#line 1753 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 239 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("io_statement <- read(var)\n");
    struct node *aux = add_operator_node((yyvsp[-4].string));
    (yyval.node) = add_regular_node("IO", (yyvsp[-2].node), aux);
  }
#line 1763 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 244 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("io_statement <- write(var)\n");
    printf("io_statement <- read(var)\n");
    struct node *aux = add_operator_node((yyvsp[-4].string));
    (yyval.node) = add_regular_node("IO", (yyvsp[-2].node), aux);
  }
#line 1774 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 250 "analisadorSintatico.y" /* yacc.c:1646  */
    {printf("io_statement <- write(quotes string quotes)\n");}
#line 1780 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 254 "analisadorSintatico.y" /* yacc.c:1646  */
    {printf("string <- string STRING\n");}
#line 1786 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 255 "analisadorSintatico.y" /* yacc.c:1646  */
    {}
#line 1792 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 255 "analisadorSintatico.y" /* yacc.c:1646  */
    {printf("string <- \n");}
#line 1798 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 259 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("vector_statement <- normallize(vector_param)\n");
    struct node *aux = add_operator_node((yyvsp[-3].string));
    (yyval.node) = add_regular_node("VECTOR", (yyvsp[-1].node), aux);
  }
#line 1808 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 264 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("vector_statement <- distance(vector_param, vector_param)\n");
    struct node *aux = add_operator_node((yyvsp[-5].string));
    struct node *aux2 = add_regular_node("VECTOR", (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node) = add_regular_node("VECTOR", aux2, aux);
  }
#line 1819 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 273 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("vector_param <- var\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1828 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 277 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("vector_param <- vector\n");
    (yyval.node) = add_value_node((yyvsp[0].string));
  }
#line 1837 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 284 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    struct node *aux = add_operator_node((yyvsp[-2].string));
    struct node *aux2 = add_regular_node("STATEMENT", aux, (yyvsp[-1].node));
    (yyval.node) = add_regular_node("STATEMENT", (yyvsp[-3].node), aux2);
    printf("assing_expression <- var ASSING expression\n");
  }
#line 1848 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 293 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("expression <- op_expression\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1857 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 300 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("var <- ID\n");
    (yyval.node) = add_variable_node(NULL, (yyvsp[0].string));
  }
#line 1866 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 307 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("simple_expression <- op_expression relop op_expression\n");
    struct node *aux = add_regular_node("EXPRESSION", (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node) = add_regular_node("EXPRESSION", (yyvsp[-2].node), aux);
  }
#line 1876 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 312 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("simple_expression <- op_expression\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1885 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 319 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("relop <- comparables\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1894 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 326 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("op_expression <- op_expression operators term\n");
    struct node* aux = add_regular_node("EXPRESSION", (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node) = add_regular_node("EXPRESSION", (yyvsp[-2].node), aux);
  }
#line 1904 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 331 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("op_expression <- term\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1913 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 338 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- add\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1922 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 342 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- sub\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1931 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 346 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- times\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1940 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 350 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- div\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1949 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 354 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- or\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1958 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 358 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- and\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1967 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 365 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("term <- term factor\n");
    (yyval.node) = add_regular_node("TERM", (yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1976 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 369 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("term <- factor\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1985 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 376 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- (expression)\n");
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1994 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 380 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- var\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 2003 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 384 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- call\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 2012 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 388 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- INT\n");
    (yyval.node) = add_value_node((yyvsp[0].string));
  }
#line 2021 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 392 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- FLOAT\n");
    (yyval.node) = add_value_node((yyvsp[0].string));
  }
#line 2030 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 396 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- VECTOR\n");
    (yyval.node) = add_value_node((yyvsp[0].string));
  }
#line 2039 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 400 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- BOOLEAN\n");
    (yyval.node) = add_value_node((yyvsp[0].string));
  }
#line 2048 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 407 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("call <- (args)\n");
    struct node *aux = add_function_node(NULL, (yyvsp[-3].string), NULL, NULL);
    (yyval.node) = add_regular_node("CALL", aux, (yyvsp[-1].node));
  }
#line 2058 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 415 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("args <- arg_list\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 2067 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 419 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("args <- \n");
    (yyval.node) = NULL;
  }
#line 2076 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 426 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("arg_list <- arg_list , expression\n");
    (yyval.node) = add_regular_node("ARG", (yyvsp[-2].node), (yyvsp[0].node));
  }
#line 2085 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 430 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("arg_list <- expression\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 2094 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;


#line 2098 "analisadorSintatico.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 435 "analisadorSintatico.y" /* yacc.c:1906  */


struct node * add_regular_node(char * node_type, struct node *left, struct node *right){
  printf("nao symbol\n");
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  node->node_type = node_type;
  node->left = left;
  node->right = right;
  node->symbolName = NULL;
  node->symbolType = NULL;
  return node;
}

struct node* add_variable_node(char * symbolType, char * symbolName) {
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  node->node_type = "VARIABLE";
  node->symbolName = symbolName;
  node->symbolType = symbolType;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct node* add_function_node(char * symbolType, char * symbolName, struct node *left, struct node *right) {
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  node->node_type = "FUNCTION";
  node->symbolName = symbolName;
  node->symbolType = symbolType;
  node->left = left;
  node->right = right;
  return node;
}

struct node* add_operator_node(char * symbolName) {
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  node->node_type = "OPERATOR";
  node->symbolName = symbolName;
  node->symbolType = NULL;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct node* add_value_node(char * symbolName) {
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  node->node_type = "VALUE";
  node->symbolName = symbolName;
  if(symbolName == "BOLLEAN") {
    node->symbolType = "bool";
  } else if(symbolName == "INT") {
    node->symbolType = "int";
  } else if(symbolName == "FLOAT") {
    node->symbolName = "float";
  } else if(symbolName == "VECTOR") {
    node->symbolName = "vector";
  }
  node->symbolType = NULL;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void print_tree(struct node *tree, int prof) {
  int j;
  for(j=0;j<prof;j++){
    printf("  ");
  }
  if (tree) {
    printf("| node_type: %s  |symbolName: %s | symbolType: %s |\n", tree->node_type, tree->symbolName, tree->symbolType);
    print_tree(tree->left, prof+1);
    print_tree(tree->right, prof+1);
  }
}

int main(int argc, char **argv) {
  ++argv, --argc;
  if(argc > 0)
      yyin = fopen( argv[0], "r" );
  else
      yyin = stdin;
  yyparse();
  print_tree(syntax_tree, 0);
  yylex_destroy();
  return 0;
}
