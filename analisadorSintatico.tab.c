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
  #include "uthash.h"

  int yylex();
  extern int current_line;
  int tem_erro = 0;
  extern void printError();
  void yyerror(const char* msg) {
    tem_erro = 1;
    fprintf(stderr, "Erro sintatico encontrado na linha %d: %s\n", current_line, msg);
  }
  extern int yylex_destroy(void);
  extern FILE *yyin;

  struct node {
    char *node_type;
    char *symbolName;
    char *symbolType;
    struct node *left;
    struct node *right;
  };

  struct s_table_entry {
    char* symbolName;
    char* id;
    char* var_type;
    char* entry_type;
    char* scope;
    UT_hash_handle hh;
  };

  char* current_scope = "GLOBAL";

  struct s_table_entry *symbol_table = NULL;

  struct node* syntax_tree = NULL;
  struct node* add_regular_node(char * node_type, struct node *left, struct node *right);
  struct node* add_variable_node(char * symbolType, char * symbolName);
  struct node* add_operator_node(char * symbolName);
  struct node* add_value_node(char * symbolName);
  struct node* add_function_node(char * symbolType, char * symbolName, struct node *left, struct node *right);
  char* concat(const char *s1, const char *s2);
  void add_to_symbol_table(char* id, char* var_type, char* entry_type, char* scope);
  void gen_table_symbol(char * type, char * name);
  void print_tree(struct node * tree, int prof);
  void print_s_table();


#line 117 "analisadorSintatico.tab.c" /* yacc.c:339  */

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
    STRING = 266,
    INT = 267,
    FLOAT = 268,
    VECTOR = 269,
    DISTANCE = 270,
    NORMALIZE = 271,
    BOOLEAN = 272,
    OPEN_PARENTESES = 273,
    CLOSE_PARENTESES = 274,
    OPEN_BRACKETS = 275,
    CLOSE_BRACKETS = 276,
    OPEN_CURLY = 277,
    CLOSE_CURLY = 278,
    QUOTES = 279,
    ASSING = 280,
    COMPARABLES = 281,
    ADD = 282,
    SUB = 283,
    TIMES = 284,
    DIV = 285,
    OR = 286,
    AND = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 56 "analisadorSintatico.y" /* yacc.c:355  */

  char *string;
  struct node *node;

#line 195 "analisadorSintatico.tab.c" /* yacc.c:355  */
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

#line 226 "analisadorSintatico.tab.c" /* yacc.c:358  */

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
#define YYLAST   108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

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
       2,     2,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    89,    93,   100,   104,   111,   119,   128,
     132,   139,   143,   150,   158,   165,   169,   177,   181,   188,
     192,   196,   200,   204,   208,   212,   216,   223,   230,   235,
     243,   250,   254,   261,   266,   275,   280,   289,   293,   300,
     309,   316,   323,   328,   335,   342,   347,   354,   358,   362,
     366,   370,   374,   381,   385,   392,   396,   400,   404,   408,
     412,   416,   423,   431,   435,   442,   446
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TYPE", "WHILE", "IF", "ELSE",
  "RETURN", "WRITE", "READ", "STRING", "INT", "FLOAT", "VECTOR",
  "DISTANCE", "NORMALIZE", "BOOLEAN", "OPEN_PARENTESES",
  "CLOSE_PARENTESES", "OPEN_BRACKETS", "CLOSE_BRACKETS", "OPEN_CURLY",
  "CLOSE_CURLY", "QUOTES", "ASSING", "COMPARABLES", "ADD", "SUB", "TIMES",
  "DIV", "OR", "AND", "';'", "','", "$accept", "prog", "declaration_list",
  "declaration", "var_declaration", "func_declaration", "params",
  "params_list", "param", "compound_statement", "local_declarations",
  "statement_list", "statement", "expression_statement",
  "conditional_statement", "iteration_statement", "return_statement",
  "io_statement", "vector_statement", "vector_param", "assing_statement",
  "expression", "var", "simple_expression", "relop", "op_expression",
  "operators", "term", "factor", "call", "args", "arg_list", YY_NULLPTR
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
     285,   286,   287,    59,    44
};
# endif

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       0,     8,    12,     0,   -67,   -67,   -67,    -8,   -67,   -67,
      13,   -67,    18,    25,    -5,   -67,   -67,     9,    13,   -67,
     -67,   -67,    44,    34,   -67,    52,    16,    32,    36,    38,
      10,    45,    54,   -67,   -67,   -67,    55,    56,   -67,     2,
     -67,    44,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
      26,   -67,    53,     2,   -67,   -67,     2,     2,     2,   -67,
      19,   -67,    59,    68,    68,    33,    33,    57,     2,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,     2,     2,   -67,   -67,
      73,    60,    74,    76,   -67,   -67,    77,    78,   -67,    64,
     -67,    80,   -67,    67,    59,     2,    69,     2,     9,     9,
      70,    71,    33,   -67,   -67,   -67,   -67,   -67,    94,   -67,
     -67,    86,     9,   -67,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     6,     5,     0,     1,     3,
      10,     7,     0,     0,     9,    12,    13,     0,     0,    16,
       8,    11,    18,     0,    15,    16,     0,    41,     0,     0,
       0,     0,     0,    58,    59,    60,     0,     0,    61,     0,
      14,    26,    17,    19,    20,    21,    22,    23,    24,    25,
      56,    27,    43,    46,    54,    57,    64,     0,     0,    32,
       0,    56,    40,     0,     0,     0,     0,     0,     0,    44,
      47,    48,    49,    50,    51,    52,     0,     0,    53,    66,
       0,    63,     0,     0,    31,    41,     0,     0,    38,     0,
      37,     0,    55,     0,    42,    45,     0,     0,     0,     0,
       0,     0,     0,    35,    39,    62,    65,    30,    28,    34,
      33,     0,     0,    36,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,    75,   -15,   -67,   -67,   -67,    88,   -66,
      82,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -60,
     -67,   -38,   -25,   -49,   -67,   -23,   -67,    31,   -50,   -67,
     -67,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    13,    14,    15,    20,
      22,    25,    42,    43,    44,    45,    46,    47,    48,    89,
      49,    60,    61,    51,    76,    62,    77,    53,    54,    55,
      80,    81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    67,    52,    78,     1,    27,    91,    24,    82,    83,
      10,     7,     8,    27,    33,    34,    35,    12,    79,    38,
      39,    16,    33,    34,    35,    11,    24,    38,    39,    18,
      93,    19,   107,   108,    52,    52,    85,    26,    86,    87,
      90,    90,   111,    59,    17,    78,   114,    88,    23,    11,
      56,    68,    84,    94,    57,    27,    58,    28,    29,   106,
      30,    31,    32,    63,    33,    34,    35,    36,    37,    38,
      39,    85,    64,    65,    66,    40,    92,    90,     9,    69,
      70,    71,    72,    73,    74,    75,    70,    71,    72,    73,
      74,    75,    96,    98,    97,    99,   100,   101,   102,   103,
     104,   112,   105,   109,   110,   113,    21,    41,    95
};

static const yytype_uint8 yycheck[] =
{
      25,    39,    25,    53,     4,     3,    66,    22,    57,    58,
      18,     3,     0,     3,    12,    13,    14,     4,    56,    17,
      18,     3,    12,    13,    14,    33,    41,    17,    18,    34,
      68,    22,    98,    99,    57,    58,     3,     3,    63,    64,
      65,    66,   102,    33,    19,    95,   112,    14,     4,    33,
      18,    25,    33,    76,    18,     3,    18,     5,     6,    97,
       8,     9,    10,    18,    12,    13,    14,    15,    16,    17,
      18,     3,    18,    18,    18,    23,    19,   102,     3,    26,
      27,    28,    29,    30,    31,    32,    27,    28,    29,    30,
      31,    32,    19,    19,    34,    19,    19,    19,    34,    19,
      33,     7,    33,    33,    33,    19,    18,    25,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    36,    37,    38,    39,    40,     3,     0,    38,
      18,    33,     4,    41,    42,    43,     3,    19,    34,    22,
      44,    43,    45,     4,    39,    46,     3,     3,     5,     6,
       8,     9,    10,    12,    13,    14,    15,    16,    17,    18,
      23,    45,    47,    48,    49,    50,    51,    52,    53,    55,
      57,    58,    60,    62,    63,    64,    18,    18,    18,    33,
      56,    57,    60,    18,    18,    18,    18,    56,    25,    26,
      27,    28,    29,    30,    31,    32,    59,    61,    63,    56,
      65,    66,    58,    58,    33,     3,    57,    57,    14,    54,
      57,    54,    19,    56,    60,    62,    19,    34,    19,    19,
      19,    19,    34,    19,    33,    33,    56,    44,    44,    33,
      33,    54,     7,    19,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    39,    40,    41,
      41,    42,    42,    43,    44,    45,    45,    46,    46,    47,
      47,    47,    47,    47,    47,    47,    47,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      56,    57,    58,    58,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    64,    65,    65,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       0,     3,     1,     2,     4,     2,     0,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     7,
       5,     3,     2,     5,     5,     4,     6,     1,     1,     4,
       1,     1,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     5,     1,     0,     3,     1
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
#line 82 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("prog <- declaration_list\n");
    syntax_tree = (yyvsp[0].node);
  }
#line 1483 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 89 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration_list <- declaration_list declation\n");
    (yyval.node) = add_regular_node("DECLARATION", (yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1492 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 93 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration_list <- declaration\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1501 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 100 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration <- func_declaration\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1510 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 104 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration <- var_declaration\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1519 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 111 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("var_declaration <- TYPE ID;\n");
    (yyval.node) = add_variable_node((yyvsp[-2].string), (yyvsp[-1].string));
    add_to_symbol_table((yyvsp[-1].string), (yyvsp[-2].string), "VARIABLE", current_scope);
  }
#line 1529 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 119 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("func_declaration <- TYPE ID (params) compound_statement;\n");
    (yyval.node) = add_function_node((yyvsp[-5].string), (yyvsp[-4].string), (yyvsp[-2].node), (yyvsp[0].node));
    add_to_symbol_table((yyvsp[-4].string), (yyvsp[-5].string), "FUNCTION", "GLOBAL");
    current_scope = "GLOBAL";
  }
#line 1540 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 128 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("params <- params_list\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1549 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 132 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("params <- \n");
    (yyval.node) = NULL;
  }
#line 1558 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 139 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("params_list <- params_list, param\n");
    (yyval.node) = add_regular_node("PARAMS", (yyvsp[-2].node), (yyvsp[0].node));
  }
#line 1567 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 143 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("params_list <- param\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1576 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 150 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("param <- TYPE ID\n");
    (yyval.node) = add_variable_node((yyvsp[-1].string), (yyvsp[0].string));
    add_to_symbol_table((yyvsp[0].string), (yyvsp[-1].string), "VARIABLE", "-");
  }
#line 1586 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 158 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("compound_statement <- { local_declarations statement_list}\n");
    (yyval.node) = add_regular_node("STATEMENT", (yyvsp[-2].node), (yyvsp[-1].node));
  }
#line 1595 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 165 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("local_declarations <- local_declarations var_declaration\n");
    (yyval.node) = add_regular_node("DECLARATION", (yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1604 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 169 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    current_scope = "-";
    printf("local_declarations <- \n");
    (yyval.node) = NULL;
  }
#line 1614 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 177 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement_list <- statement_list statement\n");
    (yyval.node) = add_regular_node("STATEMENT", (yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1623 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 181 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement_list <- \n");
    (yyval.node) = NULL;
  }
#line 1632 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 188 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- expression_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1641 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 192 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- conditional_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1650 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 196 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- iteration_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1659 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 200 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- return_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1668 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 204 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- io_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1677 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 208 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- vector_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1686 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 212 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- assing_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1695 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 216 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- local_declaration\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1704 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 223 "analisadorSintatico.y" /* yacc.c:1646  */
    {
   printf("expression_statement <- simple_expression\n");
   (yyval.node) = (yyvsp[0].node);
  }
#line 1713 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 230 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("conditional_statement <- if(expression)compound_statement\n");
    struct node *aux = add_regular_node("STATEMENT", (yyvsp[0].node), NULL);
    (yyval.node) = add_regular_node("CONDITIONAL", (yyvsp[-2].node), aux);
  }
#line 1723 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 235 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("conditional_statement <- if(expression)compound_statement eles compund_statement\n");
    struct node *aux = add_regular_node("STATEMENT", (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node) = add_regular_node("CONDITIONAL", (yyvsp[-4].node), aux);
  }
#line 1733 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 243 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("iteration_statement <- while(expression)compound_statement\n");
    (yyval.node) = add_regular_node("ITERATOR", (yyvsp[-2].node), (yyvsp[0].node));
  }
#line 1742 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 250 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("return_statement <- RETURN expression;\n");
    (yyval.node) = add_regular_node("RETURN", (yyvsp[-1].node), NULL);
  }
#line 1751 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 254 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("return_statement <- RETURN ;\n");
    (yyval.node) = add_regular_node("RETURN", NULL, NULL);
  }
#line 1760 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 261 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("io_statement <- read(var)\n");
    struct node *aux = add_operator_node((yyvsp[-4].string));
    (yyval.node) = add_regular_node("IO", (yyvsp[-2].node), aux);
  }
#line 1770 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 266 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("io_statement <- write(var)\n");
    printf("io_statement <- read(var)\n");
    struct node *aux = add_operator_node((yyvsp[-4].string));
    (yyval.node) = add_regular_node("IO", (yyvsp[-2].node), aux);
  }
#line 1781 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 275 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("vector_statement <- normallize(vector_param)\n");
    struct node *aux = add_operator_node((yyvsp[-3].string));
    (yyval.node) = add_regular_node("VECTOR", (yyvsp[-1].node), aux);
  }
#line 1791 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 280 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("vector_statement <- distance(vector_param, vector_param)\n");
    struct node *aux = add_operator_node((yyvsp[-5].string));
    struct node *aux2 = add_regular_node("VECTOR", (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node) = add_regular_node("VECTOR", aux2, aux);
  }
#line 1802 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 289 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("vector_param <- var\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1811 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 293 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("vector_param <- vector\n");
    (yyval.node) = add_value_node((yyvsp[0].string));
  }
#line 1820 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 300 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    struct node *aux = add_operator_node((yyvsp[-2].string));
    struct node *aux2 = add_regular_node("STATEMENT", aux, (yyvsp[-1].node));
    (yyval.node) = add_regular_node("STATEMENT", (yyvsp[-3].node), aux2);
    printf("assing_expression <- var ASSING expression\n");
  }
#line 1831 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 309 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("expression <- op_expression\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1840 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 316 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("var <- ID\n");
    (yyval.node) = add_variable_node(NULL, (yyvsp[0].string));
  }
#line 1849 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 323 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("simple_expression <- op_expression relop op_expression\n");
    struct node *aux = add_regular_node("EXPRESSION", (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node) = add_regular_node("EXPRESSION", (yyvsp[-2].node), aux);
  }
#line 1859 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 328 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("simple_expression <- op_expression\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1868 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 335 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("relop <- comparables\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1877 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 342 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("op_expression <- op_expression operators term\n");
    struct node* aux = add_regular_node("EXPRESSION", (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node) = add_regular_node("EXPRESSION", (yyvsp[-2].node), aux);
  }
#line 1887 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 347 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("op_expression <- term\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1896 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 354 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- add\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1905 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 358 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- sub\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1914 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 362 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- times\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1923 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 366 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- div\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1932 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 370 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- or\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1941 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 374 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- and\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1950 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 381 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("term <- term factor\n");
    (yyval.node) = add_regular_node("TERM", (yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1959 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 385 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("term <- factor\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1968 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 392 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- (expression)\n");
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1977 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 396 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- var\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1986 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 400 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- call\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1995 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 404 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- INT\n");
    (yyval.node) = add_value_node((yyvsp[0].string));
  }
#line 2004 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 408 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- FLOAT\n");
    (yyval.node) = add_value_node((yyvsp[0].string));
  }
#line 2013 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 412 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- VECTOR\n");
    (yyval.node) = add_value_node((yyvsp[0].string));
  }
#line 2022 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 416 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- BOOLEAN\n");
    (yyval.node) = add_value_node((yyvsp[0].string));
  }
#line 2031 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 423 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("call <- (args)\n");
    struct node *aux = add_function_node(NULL, (yyvsp[-4].string), NULL, NULL);
    (yyval.node) = add_regular_node("CALL", aux, (yyvsp[-2].node));
  }
#line 2041 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 431 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("args <- arg_list\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 2050 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 435 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("args <- \n");
    (yyval.node) = NULL;
  }
#line 2059 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 442 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("arg_list <- arg_list , expression\n");
    (yyval.node) = add_regular_node("ARG", (yyvsp[-2].node), (yyvsp[0].node));
  }
#line 2068 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 446 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("arg_list <- expression\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 2077 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;


#line 2081 "analisadorSintatico.tab.c" /* yacc.c:1646  */
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
#line 451 "analisadorSintatico.y" /* yacc.c:1906  */


struct node * add_regular_node(char * node_type, struct node *left, struct node *right){
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

void add_to_symbol_table(char* id, char* var_type, char* entry_type, char* scope) {
  struct s_table_entry *s_table_entry;
  char *auxid = concat("::", scope);
  char *auxid2 = concat("::", entry_type);
  char *identifier = concat(id, auxid);
  identifier = concat(identifier, auxid2);
  HASH_FIND_STR(symbol_table, identifier, s_table_entry);
  if(s_table_entry == NULL) {
    struct s_table_entry *s = (struct s_table_entry *)malloc(sizeof *s);
    s->id = identifier;
    s->symbolName = id;
    s->var_type = var_type;
    s->entry_type = entry_type;
    s->scope = scope;
    HASH_ADD_STR(symbol_table, id, s);
    if(strcmp(entry_type, "FUNCTION") == 0) {
      for(s=symbol_table; s != NULL; s=s->hh.next) {
        if(strcmp(s->entry_type, "VARIABLE") == 0 && strcmp(s->scope, "-") == 0) {
          s->scope = (char *) strdup(id);
          char *auxid = concat("::", s->scope);
          char *auxid2 = concat("::", s->entry_type);
          char *identifier = concat(s->symbolName, auxid);
          identifier = concat(identifier, auxid2);
          s->id = identifier;
        }
      }
    }
  }
}

char* concat(const char *s1, const char *s2){
  char *result = malloc(strlen(s1) + strlen(s2) + 1);
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}

struct node* add_value_node(char * symbolName) {
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  node->node_type = "VALUE";
  node->symbolName = symbolName;
  if(strcmp(symbolName, "BOLLEAN") == 0) {
    node->symbolType = "bool";
  } else if(strcmp(symbolName, "INT") == 0) {
    node->symbolType = "int";
  } else if(strcmp(symbolName,"FLOAT")  == 0) {
    node->symbolName = "float";
  } else if(strcmp(symbolName, "VECTOR") == 0) {
    node->symbolName = "vector";
  }
  node->symbolType = NULL;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void print_s_table() {
  struct s_table_entry *s;

  printf("Tabela de Símbolos:\n");
  for(s=symbol_table; s != NULL; s=s->hh.next) {
    printf("id: %s | var_type: %s | s_node_type: %s | scope: %s\n", s->id, s->var_type, s->entry_type, s->scope);
  }

}

void print_tree(struct node *tree, int prof) {
  int j;
  for(j=0;j<prof;j++){
    printf("  ");
  }
  if (tree) {
    printf("| node_type: %s  |", tree->node_type);
    if(tree->symbolName != NULL) {
      printf("symbolName: %s |", tree->symbolName);
    }
    if(tree->symbolType != NULL) {
      printf("symbolType: %s |", tree->symbolType);
    }
    printf("\n");
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
  printError();
  print_tree(syntax_tree, 0);
  if(tem_erro == 0) {
    print_s_table();
  }
  yylex_destroy();
  return 0;
}
