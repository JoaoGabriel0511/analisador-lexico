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
  #include "utlist.h"
  #define TAC_PATH "tac/"

  int yylex();
  extern int current_line;
  extern int tem_erro;
  extern void printError();
  extern void yyerror(const char* msg);
  extern int yylex_destroy(void);
  extern FILE *yyin;

  struct param {
    char* paramName;
    char* paramType;
    struct param *next, *prev;
  };

  struct node {
    char *node_type;
    char *symbolName;
    char *symbolType;
    struct param *paramsList;
    struct node *left;
    struct node *right;
  };

  struct semantic_error_msg {
    char* msg;
    struct semantic_error_msg *next, *prev;
  };

  struct s_table_entry {
    char* id;
    char* symbolName;
    char* var_type;
    char* entry_type;
    char* scope;
    struct param* params_list;
    UT_hash_handle hh;
  };

  int semantic_erro_count = 0;

  char* current_scope = "GLOBAL";
  char* resolveSyntaxTreeScope = "GLOBAL";
  char* assingReturn = NULL;
  int labelCounter = 0;

  struct s_table_entry *symbol_table = NULL;
  struct semantic_error_msg *semantic_error_table = NULL;

  struct node* syntax_tree = NULL;
  struct node* add_regular_node(char * node_type, struct node *left, struct node *right);
  struct node* add_function_call_node(struct node * function_node, struct node * arguments_node);
  struct node* add_variable_node(char * symbolType, char * symbolName);
  struct node* add_operator_node(char * symbolName);
  struct node* add_value_node(char * symbolName, char * symbolType);
  struct node* add_function_node(char * symbolType, char * symbolName, struct node *left, struct node *right);
  struct node* add_params_node(struct node* params_list_node, struct node* param_node);
  char* concat(const char *s1, const char *s2);
  void add_to_symbol_table(char* id, char* var_type, char* entry_type, char* scope, struct param* params_list);
  void gen_table_symbol(char * type, char * name);
  void print_tree(struct node * tree, int prof, char side);
  void print_s_table();
  void symbol_redeclaration_error(char* name, char* entry_type);
  void check_symbol_not_declared_error(char* name);
  void generateTacFile(struct node* tree, char* fileName);
  void add_int_to_float_node(struct node * pointingNode, struct node * nodeToPoint);
  void add_float_to_int_node(struct node * pointingNode, struct node * nodeToPoint);
  void print_semantic_erros();
  void add_semantic_error(char *msg);
  void check_main_not_declared_error();
  void generateTableInTac(FILE *tacFile);
  char* check_type_mismatch_error(struct node* first_symbol, struct node* second_symbol);
  void check_params_mismatch_error(char * functionName, struct param * paramsList);
  void check_function_return_mismatch_error(char * functionName, char * return_type, char * function_type);
  struct s_table_entry* find_symbol_in_table(char* symbolName, char* scope, char* entry_type);
  void resolveSyntaxTree(FILE *tacFile, struct node* tree);
  char* generateInstruction(char* instruction, char* arg1, char* arg2, char* arg3);
  void generateCodeInTac(FILE *tacFile, struct node* tree);
  char* generateAritmeticOperation(struct node* tree);
  char* generateOperator(char* operator);
  char* getValueOrVariable(struct node* tree);
  char* generateParmasInstruction(struct node* tree, char* aux, int* paramCounter);
  char* getLabel();

#line 157 "analisadorSintatico.tab.c" /* yacc.c:339  */

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
#line 96 "analisadorSintatico.y" /* yacc.c:355  */

  char *string;
  struct node *node;

#line 235 "analisadorSintatico.tab.c" /* yacc.c:355  */
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

#line 266 "analisadorSintatico.tab.c" /* yacc.c:358  */

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
#define YYLAST   122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

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
       0,   122,   122,   130,   134,   141,   145,   152,   160,   184,
     188,   195,   199,   210,   218,   227,   236,   240,   248,   252,
     256,   260,   264,   268,   272,   279,   286,   293,   298,   306,
     313,   319,   325,   334,   339,   348,   353,   362,   366,   373,
     392,   399,   408,   414,   421,   428,   443,   450,   454,   458,
     462,   466,   470,   477,   481,   485,   489,   493,   497,   501,
     508,   518,   522,   529,   533
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
  "params_list", "param", "compound_statement", "compound",
  "statement_list", "statement", "declaration_statement",
  "expression_statement", "conditional_statement", "iteration_statement",
  "return_statement", "io_statement", "vector_statement", "vector_param",
  "assing_statement", "expression", "var", "simple_expression", "relop",
  "op_expression", "operators", "factor", "call", "args", "arg_list", YY_NULLPTR
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

#define YYPACT_NINF -91

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-91)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,     7,    12,     1,   -91,    -7,   -91,    -5,   -91,   -91,
     -91,    26,    28,    13,     8,   -91,   -91,    15,    26,   -91,
     -91,   -91,    89,    17,    40,    29,    30,     3,    31,    36,
     -91,   -91,   -91,    37,    49,   -91,    11,   -91,   -91,    35,
      46,   -91,   -91,    21,    48,    63,    67,    44,   -91,    45,
     -91,   -91,    11,   -91,    11,    11,   -91,    75,   -91,    56,
      11,    43,     4,     4,    59,   -91,   -91,   -91,   -91,   -91,
     -91,    11,   -91,   -91,   -91,   -91,   -91,   -91,   -91,    11,
      11,   -91,    61,    76,    90,    92,   -91,    93,   -91,    94,
     -91,    80,   -91,    96,   -91,   -91,    56,   -91,   -91,    11,
      95,    95,   -91,   -91,     4,   -91,   -91,   -91,   -91,   109,
      99,    47,    95,   -91,   -91,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     5,     7,     1,     3,
       6,    10,     0,     0,     9,    12,    13,     0,     0,    17,
       8,    11,    32,    41,     0,     0,     0,     0,     0,     0,
      56,    57,    58,     0,     0,    59,     0,    25,    16,     0,
       0,    19,    20,     0,     0,     0,     0,    54,    26,    43,
      46,    55,    62,     7,     0,     0,    31,     0,    54,    40,
       0,     0,     0,     0,     0,    24,    18,    14,    21,    22,
      23,     0,    44,    47,    48,    49,    50,    51,    52,     0,
       0,    64,     0,    61,     0,     0,    30,     0,    41,     0,
      38,     0,    37,     0,    53,    39,    42,    45,    60,     0,
       0,     0,    34,    33,     0,    35,    63,    17,    29,    27,
       0,     0,     0,    36,    15,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,   -91,   116,   -20,   -91,   -91,   -91,   102,   -91,
     -90,    14,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -59,   -91,   -33,   -22,   -46,   -91,   -21,   -91,    42,   -91,
     -91,   -91
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    13,    14,    15,    20,
     108,    22,    38,    39,    40,    41,    42,    43,    44,    45,
      91,    46,    57,    58,    48,    79,    59,    80,    50,    51,
      82,    83
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      47,    49,    37,    64,    93,     1,    23,    88,    84,    85,
       7,   109,     8,    11,    23,    30,    31,    32,    90,    81,
      35,    36,   115,    30,    31,    32,    10,    87,    35,    36,
      12,    16,    17,    49,    49,    52,    56,    19,    95,    89,
      92,    92,    18,    53,    67,   110,    88,    54,    55,    60,
      23,    24,    25,    26,    61,    62,    28,    29,    96,    30,
      31,    32,    33,    34,    35,    36,   106,    63,    65,    71,
     114,    72,    73,    74,    75,    76,    77,    78,    94,    66,
      98,    68,    92,    73,    74,    75,    76,    77,    78,    47,
      49,    37,    23,    24,    25,    26,    69,    27,    28,    29,
      70,    30,    31,    32,    33,    34,    35,    36,    86,   100,
      99,   101,   102,   103,   104,   105,   112,   107,   113,     9,
      21,   111,    97
};

static const yytype_uint8 yycheck[] =
{
      22,    22,    22,    36,    63,     4,     3,     3,    54,    55,
       3,   101,     0,    18,     3,    12,    13,    14,    14,    52,
      17,    18,   112,    12,    13,    14,    33,    60,    17,    18,
       4,     3,    19,    54,    55,    18,    33,    22,    71,    61,
      62,    63,    34,     3,    23,   104,     3,    18,    18,    18,
       3,     4,     5,     6,    18,    18,     9,    10,    79,    12,
      13,    14,    15,    16,    17,    18,    99,    18,    33,    25,
      23,    26,    27,    28,    29,    30,    31,    32,    19,    33,
      19,    33,   104,    27,    28,    29,    30,    31,    32,   111,
     111,   111,     3,     4,     5,     6,    33,     8,     9,    10,
      33,    12,    13,    14,    15,    16,    17,    18,    33,    19,
      34,    19,    19,    19,    34,    19,     7,    22,    19,     3,
      18,   107,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    36,    37,    38,    39,    40,     3,     0,    38,
      33,    18,     4,    41,    42,    43,     3,    19,    34,    22,
      44,    43,    46,     3,     4,     5,     6,     8,     9,    10,
      12,    13,    14,    15,    16,    17,    18,    39,    47,    48,
      49,    50,    51,    52,    53,    54,    56,    58,    59,    61,
      63,    64,    18,     3,    18,    18,    33,    57,    58,    61,
      18,    18,    18,    18,    57,    33,    33,    23,    33,    33,
      33,    25,    26,    27,    28,    29,    30,    31,    32,    60,
      62,    57,    65,    66,    59,    59,    33,    57,     3,    58,
      14,    55,    58,    55,    19,    57,    61,    63,    19,    34,
      19,    19,    19,    19,    34,    19,    57,    22,    45,    45,
      55,    46,     7,    19,    23,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    39,    40,    41,
      41,    42,    42,    43,    44,    45,    46,    46,    47,    47,
      47,    47,    47,    47,    47,    48,    49,    50,    50,    51,
      52,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      57,    58,    59,    59,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      64,    65,    65,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     2,     6,     1,
       0,     3,     1,     2,     4,     3,     2,     0,     2,     1,
       1,     2,     2,     2,     2,     1,     1,     5,     7,     5,
       3,     2,     0,     4,     4,     4,     6,     1,     1,     3,
       1,     1,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       4,     1,     0,     3,     1
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
#line 122 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    check_main_not_declared_error();
    printf("prog <- declaration_list\n");
    syntax_tree = (yyvsp[0].node);
  }
#line 1528 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 130 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration_list <- declaration_list declation\n");
    (yyval.node) = add_regular_node("DECLARATION", (yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1537 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 134 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration_list <- declaration\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1546 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 141 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration <- func_declaration\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1555 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 145 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration <- var_declaration\n");
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1564 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 152 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("var_declaration <- TYPE ID\n");
    (yyval.node) = add_variable_node((yyvsp[-1].string), (yyvsp[0].string));
    add_to_symbol_table((yyvsp[0].string), (yyvsp[-1].string), "VARIABLE", current_scope, NULL);
  }
#line 1574 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 160 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("func_declaration <- TYPE ID (params) compound_statement\n");
    struct node *aux = add_function_node((yyvsp[-5].string), (yyvsp[-4].string), (yyvsp[-2].node), (yyvsp[0].node));
    if(strcmp((yyvsp[-5].string), "int") == 0 && strcmp((yyvsp[0].node)->symbolType, "float") == 0) {
      add_float_to_int_node(aux, (yyvsp[0].node));
    } else if(strcmp((yyvsp[-5].string), "float") == 0 && strcmp((yyvsp[0].node)->symbolType, "int") == 0) {
      add_int_to_float_node(aux, (yyvsp[0].node));
    }
    check_function_return_mismatch_error((yyvsp[-4].string), aux->right->symbolType, (yyvsp[-5].string));
    if((yyvsp[-2].node) != NULL) {
      if((yyvsp[-2].node)->paramsList != NULL) {
        add_to_symbol_table((yyvsp[-4].string), (yyvsp[-5].string), "FUNCTION", "GLOBAL", (yyvsp[-2].node)->paramsList);
      } else {
        add_to_symbol_table((yyvsp[-4].string), (yyvsp[-5].string), "FUNCTION", "GLOBAL", NULL);
      }
    } else {
      add_to_symbol_table((yyvsp[-4].string), (yyvsp[-5].string), "FUNCTION", "GLOBAL", NULL);
    }
    current_scope = "GLOBAL";
    (yyval.node) = aux;
  }
#line 1600 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 184 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("params <- params_list\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1609 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 188 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("params <- \n");
    (yyval.node) = NULL;
  }
#line 1618 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 195 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("params_list <- params_list, param\n");
    (yyval.node) = add_params_node((yyvsp[-2].node), (yyvsp[0].node));
  }
#line 1627 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 199 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("params_list <- param\n");
    struct param * param = (struct param*)calloc(1, sizeof(struct param));
    param->paramType = (yyvsp[0].node)->symbolType;
    param->paramName = (yyvsp[0].node)->symbolName;
    DL_APPEND((yyvsp[0].node)->paramsList, param);
    (yyval.node) = (yyvsp[0].node);
  }
#line 1640 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 210 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("param <- TYPE ID\n");
    (yyval.node) = add_variable_node((yyvsp[-1].string), (yyvsp[0].string));
    add_to_symbol_table((yyvsp[0].string), (yyvsp[-1].string), "VARIABLE", "-", NULL);
  }
#line 1650 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 218 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("compound_statement <- {statement_list return_statement }\n");
    struct node* aux = add_regular_node("COMPOUND", (yyvsp[-2].node), (yyvsp[-1].node));
    aux->symbolType = (yyvsp[-1].node)->symbolType;
    (yyval.node) = aux;
  }
#line 1661 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 227 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("compound <- { statement_list }\n");
    struct node* aux = add_regular_node("COMPOUND", (yyvsp[-1].node), NULL);
    aux->symbolType = NULL;
    (yyval.node) = aux;
  }
#line 1672 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 236 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement_list <- statement_list statement\n");
    (yyval.node) = add_regular_node("STATEMENT", (yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1681 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 240 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    current_scope = "-";
    printf("statement_list <- \n");
    (yyval.node) = NULL;
  }
#line 1691 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 248 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- expression_statement;\n");
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1700 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 252 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- conditional_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1709 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 256 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- iteration_statement\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1718 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 260 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- io_statement;\n");
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1727 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 264 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- vector_statement;\n");
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1736 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 268 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- assing_statement;\n");
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1745 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 272 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("statement <- declaration_statement;\n");
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1754 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 279 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("declaration_statement <- var_declaration\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1763 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 286 "analisadorSintatico.y" /* yacc.c:1646  */
    {
   printf("expression_statement <- simple_expression\n");
   (yyval.node) = (yyvsp[0].node);
  }
#line 1772 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 293 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("conditional_statement <- if(expression)compound\n");
    struct node *aux = add_regular_node("STATEMENT", (yyvsp[0].node), NULL);
    (yyval.node) = add_regular_node("CONDITIONAL", (yyvsp[-2].node), aux);
  }
#line 1782 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 298 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("conditional_statement <- if(expression)compound_statement eles compund\n");
    struct node *aux = add_regular_node("STATEMENT", (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node) = add_regular_node("CONDITIONAL", (yyvsp[-4].node), aux);
  }
#line 1792 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 306 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("iteration_statement <- while(expression)compound\n");
    (yyval.node) = add_regular_node("ITERATOR", (yyvsp[-2].node), (yyvsp[0].node));
  }
#line 1801 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 313 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("return_statement <- RETURN expression\n");
    struct node* aux = add_regular_node("RETURN", (yyvsp[-1].node), NULL);
    aux->symbolType = (yyvsp[-1].node)->symbolType;
    (yyval.node) = aux;
  }
#line 1812 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 319 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("return_statement <- RETURN\n");
    struct node* aux = add_regular_node("RETURN", NULL, NULL);
    aux->symbolType = "void";
    (yyval.node) = aux;
  }
#line 1823 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 325 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("return_statement <- \n");
    struct node* aux = add_regular_node("RETURN", NULL, NULL);
    aux->symbolType = "void";
    (yyval.node) = aux;
  }
#line 1834 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 334 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("io_statement <- read(var)\n");
    struct node *aux = add_operator_node((yyvsp[-3].string));
    (yyval.node) = add_regular_node("IO", (yyvsp[-1].node), aux);
  }
#line 1844 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 339 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("io_statement <- write(var)\n");
    printf("io_statement <- read(var)\n");
    struct node *aux = add_operator_node((yyvsp[-3].string));
    (yyval.node) = add_regular_node("IO", (yyvsp[-1].node), aux);
  }
#line 1855 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 348 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("vector_statement <- normallize(vector_param)\n");
    struct node *aux = add_operator_node((yyvsp[-3].string));
    (yyval.node) = add_regular_node("VECTOR", (yyvsp[-1].node), aux);
  }
#line 1865 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 353 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("vector_statement <- distance(vector_param, vector_param)\n");
    struct node *aux = add_operator_node((yyvsp[-5].string));
    struct node *aux2 = add_regular_node("VECTOR", (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node) = add_regular_node("VECTOR", aux2, aux);
  }
#line 1876 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 362 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("vector_param <- var\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1885 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 366 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("vector_param <- vector\n");
    (yyval.node) = add_value_node((yyvsp[0].string), "vector");
  }
#line 1894 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 373 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("assing_expression <- var ASSING expression\n");
    struct node *aux = add_operator_node((yyvsp[-1].string));
    aux->right = (yyvsp[0].node);
    aux->left = (yyvsp[-2].node);
    printf("%s \n", (yyvsp[0].node)->symbolType);
    if((yyvsp[0].node)->symbolType != NULL && (yyvsp[-2].node)->symbolType != NULL) {
      if(strcmp((yyvsp[-2].node)->symbolType, "int") == 0 && strcmp((yyvsp[0].node)->symbolType, "float") == 0) {
        add_float_to_int_node(aux, (yyvsp[0].node));
      } else if(strcmp((yyvsp[-2].node)->symbolType, "float") == 0 && strcmp((yyvsp[0].node)->symbolType, "int") == 0) {
        add_int_to_float_node(aux, (yyvsp[0].node));
      }
      check_type_mismatch_error(aux->left, aux->right);
    }
    (yyval.node) = aux;
  }
#line 1915 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 392 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("expression <- op_expression\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1924 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 399 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("var <- ID\n");
    check_symbol_not_declared_error((yyvsp[0].string));
    struct node* aux = add_variable_node(NULL, (yyvsp[0].string));
    (yyval.node) = aux;
  }
#line 1935 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 408 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("simple_expression <- op_expression relop op_expression\n");
    (yyvsp[-1].node)->right = (yyvsp[0].node);
    (yyvsp[-1].node)->left = (yyvsp[-2].node);
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1946 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 414 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("simple_expression <- op_expression\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1955 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 421 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("relop <- comparables\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 1964 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 428 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("op_expression <- op_expression operators factor\n");
    (yyvsp[-1].node)->right = (yyvsp[0].node);
    (yyvsp[-1].node)->left = (yyvsp[-2].node);
    if((yyvsp[0].node)->symbolType != NULL && (yyvsp[-2].node)->symbolType != NULL) {
      if(strcmp((yyvsp[-2].node)->symbolType, "int") == 0 && strcmp((yyvsp[0].node)->symbolType, "float") == 0) {
        add_float_to_int_node((yyvsp[-1].node), (yyvsp[0].node));

      } else if(strcmp((yyvsp[-2].node)->symbolType, "float") == 0 && strcmp((yyvsp[0].node)->symbolType, "int") == 0) {
        add_int_to_float_node((yyvsp[-1].node), (yyvsp[0].node));
      }
      (yyvsp[-1].node)->symbolType = check_type_mismatch_error((yyvsp[-1].node)->left, (yyvsp[-1].node)->right);
    }
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1984 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 443 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("op_expression <- factor\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 1993 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 450 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- add\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 2002 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 454 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- sub\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 2011 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 458 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- times\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 2020 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 462 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- div\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 2029 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 466 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- or\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 2038 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 470 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("operators <- and\n");
    (yyval.node) = add_operator_node((yyvsp[0].string));
  }
#line 2047 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 477 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- (expression)\n");
    (yyval.node) = (yyvsp[-1].node);
  }
#line 2056 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 481 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- var\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 2065 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 485 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- call\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 2074 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 489 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- INT\n");
    (yyval.node) = add_value_node((yyvsp[0].string), "int");
  }
#line 2083 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 493 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- FLOAT\n");
    (yyval.node) = add_value_node((yyvsp[0].string), "float");
  }
#line 2092 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 497 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- VECTOR\n");
    (yyval.node) = add_value_node((yyvsp[0].string), "vector");
  }
#line 2101 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 501 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("factor <- BOOLEAN\n");
    (yyval.node) = add_value_node((yyvsp[0].string), "bool");
  }
#line 2110 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 508 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("call <- (args)\n");
    check_symbol_not_declared_error((yyvsp[-3].string));
    struct node *aux = add_function_node(NULL, (yyvsp[-3].string), NULL, NULL);
    check_params_mismatch_error((yyvsp[-3].string), (yyvsp[-1].node)->paramsList);
    (yyval.node) = add_function_call_node(aux, (yyvsp[-1].node));
  }
#line 2122 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 518 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("args <- arg_list\n");
    (yyval.node) = (yyvsp[0].node);
  }
#line 2131 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 522 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("args <- \n");
    (yyval.node) = NULL;
  }
#line 2140 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 529 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("arg_list <- arg_list , expression\n");
    (yyval.node) = add_params_node((yyvsp[-2].node), (yyvsp[0].node));
  }
#line 2149 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 533 "analisadorSintatico.y" /* yacc.c:1646  */
    {
    printf("arg_list <- expression\n");
    struct param * param = (struct param*)calloc(1, sizeof(struct param));
    param->paramType = (yyvsp[0].node)->symbolType;
    param->paramName = (yyvsp[0].node)->symbolName;
    DL_APPEND((yyvsp[0].node)->paramsList, param);
    (yyval.node) = (yyvsp[0].node);
  }
#line 2162 "analisadorSintatico.tab.c" /* yacc.c:1646  */
    break;


#line 2166 "analisadorSintatico.tab.c" /* yacc.c:1646  */
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
#line 542 "analisadorSintatico.y" /* yacc.c:1906  */


struct node * add_regular_node(char * node_type, struct node *left, struct node *right){
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  node->node_type = node_type;
  node->left = left;
  node->right = right;
  node->symbolName = NULL;
  node->symbolType = NULL;
  node->paramsList = NULL;
  return node;
}

struct node* add_variable_node(char * symbolType, char * symbolName) {
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  if(symbolType == NULL) {
    struct s_table_entry* s_table_entry = find_symbol_in_table(symbolName, current_scope, "VARIABLE");
    if(s_table_entry != NULL) {
      symbolType = s_table_entry->var_type;
    } else {
      s_table_entry = find_symbol_in_table(symbolName, "GLOBAL", "VARIABLE");
      if(s_table_entry != NULL) {
        symbolType = s_table_entry->var_type;
      }
    }
  }
  node->node_type = "VARIABLE";
  node->symbolName = symbolName;
  node->symbolType = symbolType;
  node->left = NULL;
  node->right = NULL;
  node->paramsList = NULL;
  return node;
}

struct node* add_function_node(char * symbolType, char * symbolName, struct node *left, struct node *right) {
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  node->node_type = "FUNCTION";
  node->symbolName = symbolName;
  node->symbolType = symbolType;
  node->left = left;
  node->right = right;
  node->paramsList = NULL;
  return node;
}

struct node* add_operator_node(char * symbolName) {
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  node->node_type = "OPERATOR";
  node->symbolName = symbolName;
  node->symbolType = NULL;
  node->left = NULL;
  node->right = NULL;
  node->paramsList = NULL;
  return node;
}

struct node* add_params_node(struct node* params_list_node, struct node* param_node) {
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  node->node_type = "PARAMS";
  node->symbolName = NULL;
  node->symbolType = NULL;
  node->left = params_list_node;
  node->right = param_node;
  node->paramsList = params_list_node->paramsList;
  struct param* param = (struct param*)calloc(1, sizeof(struct param));
  param->paramName = param_node->symbolName;
  param->paramType = param_node->symbolType;
  DL_APPEND(node->paramsList, param);
  return node;
}

struct s_table_entry* find_symbol_in_table(char* symbolName, char* scope, char* entry_type) {
  struct s_table_entry *s_table_entry;
  char *auxid = concat("_", scope);
  char *auxid2 = concat("_", entry_type);
  char *identifier = concat(symbolName, auxid);
  identifier = concat(identifier, auxid2);
  HASH_FIND_STR(symbol_table, identifier, s_table_entry);
  return s_table_entry;
}

void add_to_symbol_table(char* id, char* var_type, char* entry_type, char* scope, struct param* params_list) {
  struct s_table_entry *s_table_entry;
  char *auxid = concat("_", scope);
  char *auxid2 = concat("_", entry_type);
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
    if(params_list != NULL) {
      s->params_list = params_list;
    } else {
      s->params_list = NULL;
    }
    HASH_ADD_STR(symbol_table, id, s);
    if(strcmp(entry_type, "FUNCTION") == 0) {
      for(s=symbol_table; s != NULL; s=s->hh.next) {
        if(strcmp(s->entry_type, "VARIABLE") == 0 && strcmp(s->scope, "-") == 0) {
          struct s_table_entry * new_s = (struct s_table_entry *)malloc(sizeof *s);
          new_s->scope = (char *) strdup(id);
          new_s->symbolName = s->symbolName;
          new_s->var_type = s->var_type;
          new_s->entry_type = s->entry_type;
          char *auxid = concat("_", new_s->scope);
          char *auxid2 = concat("_", new_s->entry_type);
          char *identifier = concat(new_s->symbolName, auxid);
          identifier = concat(identifier, auxid2);
          new_s->id = identifier;
          HASH_DEL(symbol_table, s);
          HASH_ADD_STR(symbol_table, id, new_s);
        }
      }
    }
  } else {
    symbol_redeclaration_error(id, entry_type);
  }
}

char* concat(const char *s1, const char *s2){
  char *result = malloc(strlen(s1) + strlen(s2) + 1);
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}

struct node* add_value_node(char * symbolName, char * symbolType) {
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  node->node_type = "VALUE";
  node->symbolName = symbolName;
  node->symbolType = symbolType;
  node->left = NULL;
  node->right = NULL;
  node->paramsList = NULL;
  return node;
}

struct node* add_function_call_node(struct node * function_node, struct node * arguments_node) {
  struct node* node = (struct node*)calloc(1, sizeof(struct node));
  node->node_type = "CALL";
  node->symbolName = function_node->symbolName;
  node->right = NULL;
  node->left = arguments_node;
  struct s_table_entry *s = find_symbol_in_table(node->symbolName, "GLOBAL", "FUNCTION");
  if(s != NULL) {
    node->symbolType = s->var_type;
  } else {
    node->symbolType = NULL;
  }
  node->paramsList = NULL;
  return node;
}

void print_s_table() {
  struct s_table_entry *s;

  printf("..........TABELA DE SíMBOLOS..........:\n");
  for(s=symbol_table; s != NULL; s=s->hh.next) {
    printf("id: %s | var_type: %s | s_node_type: %s | scope: %s\n", s->id, s->var_type, s->entry_type, s->scope);
  }

}

void symbol_redeclaration_error(char* name, char* entry_type) {
  char* msg =  (char *)malloc(100 * sizeof(char));
  sprintf(msg, "Redeclaration of %s %s. line: %d", entry_type, name, current_line);
  add_semantic_error(msg);
}

void add_int_to_float_node(struct node * pointingNode, struct node * nodeToPoint) {
  struct node* newNode = (struct node*)calloc(1, sizeof(struct node));
  newNode->node_type = "INTTOFLOAT";
  newNode->left = NULL;
  newNode->symbolType = "float";
  newNode->paramsList = NULL;
  newNode->right = nodeToPoint;
  pointingNode->right = newNode;
}

void add_float_to_int_node(struct node * pointingNode, struct node * nodeToPoint) {
  struct node* newNode = (struct node*)calloc(1, sizeof(struct node));
  newNode->node_type = "FLOATTOINT";
  newNode->left = NULL;
  newNode->symbolType = "int";
  newNode->paramsList = NULL;
  newNode->right = nodeToPoint;
  pointingNode->right = newNode;
}

void print_semantic_erros() {
  struct semantic_error_msg *s;
  struct semantic_error_msg *tmp;
  printf("\n\n\n------ERROS SEMANTICOS: %d--------\n", semantic_erro_count);
  DL_FOREACH_SAFE(semantic_error_table, s, tmp) {
    yyerror(s->msg);
    printf("\n");
  }
}

void print_tree(struct node *tree, int prof, char side) {
  int j;
  if (tree) {
    for(j=0;j<prof;j++){
      printf("...");
    }
    printf("| node_type: %s  |", tree->node_type);
    if(tree->symbolName != NULL) {
      printf("symbolName: %s |", tree->symbolName);
    }
    if(tree->symbolType != NULL) {
      printf("symbolType: %s |", tree->symbolType);
    }
    printf(" %c |", side);
    printf("\n");
    print_tree(tree->left, prof+1, 'l');
    print_tree(tree->right, prof+1, 'r');
  }
}

void check_symbol_not_declared_error(char* name) {
  struct s_table_entry *s;
  for(s=symbol_table; s != NULL; s=s->hh.next) {
    if(strcmp(s->symbolName, name) == 0 && (strcmp(s->scope, current_scope) == 0 || strcmp(s->scope, "GLOBAL") == 0)) {
      return;
    }
  }
  char* msg =  (char *)malloc(100 * sizeof(char));
  sprintf(msg, "Symbol %s not declared. linha %d", name, current_line);
  add_semantic_error(msg);
}

void check_params_mismatch_error(char * functionName, struct param * paramsList) {
  struct s_table_entry* s = find_symbol_in_table(functionName, "GLOBAL", "FUNCTION");
  struct param * param;
  struct param * arg;
  int i = 0;
  int j = 0;
  LL_FOREACH(paramsList, param) {
    i++;
    LL_FOREACH(s->params_list, arg) {
      j++;
      if(i == j) {
        if(strcmp(arg->paramType, param->paramType) != 0) {
          char* msg =  (char *)malloc(150 * sizeof(char));
          sprintf(msg, "Param type mismatch in function %s, expected param %d to be of type %s but it was given as %s. line: %d", functionName, i, arg->paramType, param->paramType, current_line);
          add_semantic_error(msg);
        }
      }
    }
  }
}

void check_function_return_mismatch_error(char * functionName, char * return_type, char * function_type) {
  if(strcmp(return_type, function_type) != 0) {
    char* msg =  (char *)malloc(100 * sizeof(char));
    sprintf(msg, "Return type mismatch in function %s, expected return type to bee %s but it was %s. line: %d", functionName, function_type, return_type, current_line);
    add_semantic_error(msg);
  }
}

char* check_type_mismatch_error(struct node* first_symbol, struct node* second_symbol) {
  if(strcmp(first_symbol->symbolType, second_symbol->symbolType) != 0) {
    char* msg =  (char *)malloc(100 * sizeof(char));
    sprintf(msg, "Symbol type mismatch between %s and %s. line: %d", first_symbol->symbolType, second_symbol->symbolType, current_line);
    add_semantic_error(msg);
    return "UnkownType";
  } else {
    return first_symbol->symbolType;
  }
}

void check_main_not_declared_error() {
  struct s_table_entry* s_table_entry = find_symbol_in_table("main", "GLOBAL", "FUNCTION");
  if(s_table_entry == NULL) {
    char* msg =  (char *)malloc(100 * sizeof(char));
    sprintf(msg, "Function main was not declared in line %d", current_line);
    add_semantic_error(msg);
  }
}

void add_semantic_error(char *msg) {
  semantic_erro_count++;
  struct semantic_error_msg* s = (struct semantic_error_msg *)malloc(sizeof *s);
  s->msg = msg;
  DL_APPEND(semantic_error_table, s);
}

void generateTableInTac(FILE *tacFile) {
  struct s_table_entry* s;
  char aux[100];
  fputs(".table\n", tacFile);
  for(s=symbol_table; s != NULL; s=s->hh.next) {
    if(strcmp(s->entry_type, "FUNCTION") != 0){
      if(strcmp(s->var_type, "bool") == 0) {
        strcpy(aux, "int");
      } else {
        strcpy(aux, s->var_type);
      }
      strcat(aux, " ");
      strcat(aux, s->id);
      strcat(aux, "\n");
      fputs(aux, tacFile);
    }
  }
}

char* generateInstruction(char* instruction, char* arg1, char* arg2, char* arg3) {
  char *aux = (char*)malloc(50* sizeof(char));
  strcpy(aux, instruction);
  if(arg1 != NULL){
    strcat(aux, " ");
    strcat(aux, arg1);
    if(arg2 != NULL){
      strcat(aux, ", ");
      strcat(aux, arg2);
      if(arg3 != NULL){
        strcat(aux, ", ");
        strcat(aux, arg3);
      }
    }
  }
  strcat(aux, "\n");
  return aux;
}

char* generateParmasInstruction(struct node* tree, char* aux, int* paramCounter) {
  if(tree != NULL) {
    if(strcmp(tree->node_type, "PARAMS") == 0) {
      if(tree->left != NULL) {
        if(strcmp(tree->left->node_type, "PARAMS") == 0) {
          aux = concat(aux, generateParmasInstruction(tree->left, aux, paramCounter));
        } else if(strcmp(tree->left->node_type, "VALUE") == 0 || strcmp(tree->left->node_type, "VARIABLE") == 0) {
          aux = concat(aux, generateInstruction("param", getValueOrVariable(tree->left), NULL, NULL));
          *paramCounter++;
        }
      }
      if(tree->right != NULL) {
        if(strcmp(tree->right->node_type, "VALUE") == 0 || strcmp(tree->right->node_type, "VARIABLE") == 0) {
          aux = concat(aux, generateInstruction("param", getValueOrVariable(tree->right), NULL, NULL));
          *paramCounter++;
        }
      }
    } else if(strcmp(tree->node_type, "VALUE") == 0 || strcmp(tree->node_type, "VARIABLE") == 0) {
      aux = concat(aux, generateInstruction("param", getValueOrVariable(tree), NULL, NULL));
    }
  }
  return aux;
}

void resolveSyntaxTree(FILE *tacFile, struct node* tree) {
  char *aux = NULL;
  if(tree) {
    if(strcmp(tree->node_type, "FUNCTION") == 0) {
      resolveSyntaxTreeScope = tree->symbolName;
      aux = "";
      struct param * param;
      struct s_table_entry * s = find_symbol_in_table(tree->symbolName, "GLOBAL", tree->node_type);
      LL_FOREACH(s->params_list, param) {
        char *paramId = concat("_", tree->symbolName);
        paramId = concat(paramId, "_VARIABLE");
        paramId = concat(param->paramName, paramId);
        aux = concat(generateInstruction("pop", paramId, NULL, NULL), aux);
      }
      aux = concat(generateInstruction(concat(tree->symbolName, ":"), NULL, NULL, NULL), aux);
    } else if(strcmp(tree->node_type, "OPERATOR") == 0) {
      if(strcmp(tree->symbolName, "=") == 0) {
        struct s_table_entry *s = find_symbol_in_table(tree->left->symbolName, resolveSyntaxTreeScope, tree->left->node_type);
        if(strcmp(tree->right->node_type, "VALUE") == 0 || strcmp(tree->right->node_type, "VARIABLE") == 0) {
          aux = generateInstruction("mov", s->id, getValueOrVariable(tree->right), NULL);
        } else if(strcmp(tree->right->node_type, "OPERATOR") == 0) {
          aux = generateAritmeticOperation(tree->right);
          aux = concat(aux, generateInstruction("mov", s->id, "$0", NULL));
        } else if(strcmp(tree->right->node_type, "CALL") == 0) {
          struct s_table_entry *s2 = find_symbol_in_table(tree->left->symbolName, resolveSyntaxTreeScope, tree->left->node_type);
          assingReturn = s2->id;
        }
      }
    } else if(strcmp(tree->node_type, "RETURN") == 0) {
      if(strcmp(resolveSyntaxTreeScope, "main") != 0) {
        if(strcmp(tree->symbolType, "void") == 0) {
          aux = generateInstruction("return", NULL, NULL, NULL);
        } else {
          if(strcmp(tree->left->node_type, "VARIABLE") == 0 || strcmp(tree->left->node_type, "VALUE") == 0){
            aux = generateInstruction("return", getValueOrVariable(tree->left), NULL, NULL);
          } else if(strcmp(tree->left->node_type, "OPERATOR") == 0) {
            aux = generateAritmeticOperation(tree->left);
            aux = concat(aux, generateInstruction("return", "$0", NULL, NULL));
          }
        }
      }
      resolveSyntaxTreeScope = "GLOBAL";
    } else if(strcmp(tree->node_type, "IO") == 0) {
      if(strcmp(tree->right->symbolName, "write") == 0) {
        if(strcmp(tree->left->node_type, "VARIABLE") == 0 || strcmp(tree->left->node_type, "VALUE") == 0) {
          if(strcmp(tree->left->symbolType, "bool") == 0) {
            char* label = getLabel();
            char* label2 = getLabel();
            aux = generateInstruction("brz", label, getValueOrVariable(tree->left), NULL);
            aux = concat(aux, generateInstruction("print", "\'t\'", NULL, NULL));
            aux = concat(aux, generateInstruction("print", "\'r\'", NULL, NULL));
            aux = concat(aux, generateInstruction("print", "\'u\'", NULL, NULL));
            aux = concat(aux, generateInstruction("print", "\'e\'", NULL, NULL));
            aux = concat(aux, generateInstruction("jump", label2, NULL, NULL));
            aux = concat(aux, label);
            aux = concat(aux, ":\n");
            aux = concat(aux, generateInstruction("print", "\'f\'", NULL, NULL));
            aux = concat(aux, generateInstruction("print", "\'a\'", NULL, NULL));
            aux = concat(aux, generateInstruction("print", "\'l\'", NULL, NULL));
            aux = concat(aux, generateInstruction("print", "\'s\'", NULL, NULL));
            aux = concat(aux, generateInstruction("print", "\'e\'", NULL, NULL));
            aux = concat(aux, label2);
            aux = concat(aux, ":\n");
            aux = concat(aux, generateInstruction("println", NULL, NULL, NULL));
          } else {
            aux = generateInstruction("println", getValueOrVariable(tree->left), NULL, NULL);
          }
        } else if(strcmp(tree->left->node_type, "OPERATOR") == 0) {
          aux = generateAritmeticOperation(tree->left);
          aux = concat(aux, generateInstruction("println", "$0", NULL, NULL));
        }
      } else if(strcmp(tree->right->symbolName, "read") == 0) {
        if(strcmp(tree->left->node_type, "VARIABLE") == 0) {
          if(strcmp(tree->left->symbolType, "int") == 0) {
            aux = generateInstruction("scani", getValueOrVariable(tree->left), NULL, NULL);
          } else if(strcmp(tree->left->symbolType, "float") == 0) {
            aux = generateInstruction("scanf", getValueOrVariable(tree->left), NULL, NULL);
          }
        }
      }
    } else if(strcmp(tree->node_type, "CALL") == 0) {
      int paramCounter = 0;
      aux = generateParmasInstruction(tree->left, "", &paramCounter);
      aux = concat(aux, generateInstruction("call", tree->symbolName, paramCounter, NULL));
      if(assingReturn != NULL) {
        aux = concat(aux, generateInstruction("pop", assingReturn, NULL, NULL));
        assingReturn = NULL;
      }
    } else if(strcmp(tree->node_type, "CONDITIONAL") == 0) {
      char* label = getLabel();
      if(strcmp(tree->left->node_type, "VARIABLE") == 0 || strcmp(tree->left->node_type, "VALUE") == 0) {
        aux = generateInstruction("brz", label, getValueOrVariable(tree->left), NULL);
        fputs(aux, tacFile);
      } else if(strcmp(tree->left->node_type, "OPERATOR") == 0) {
        aux = generateAritmeticOperation(tree->left);
        aux = concat(aux, generateInstruction("brz", label, "$0", NULL));
        fputs(aux, tacFile);
      }
      if(tree->right->right == NULL) {
        //Soh if
        resolveSyntaxTree(tacFile, tree->right->left);
        aux = concat(label, ":\n");
        aux = concat(aux, generateInstruction("println", NULL, NULL, NULL));
        fputs(aux, tacFile);
      } else {
        //if com else
        char* label2 = getLabel();
        resolveSyntaxTree(tacFile, tree->right->left);
        aux = generateInstruction("jump", label2, NULL, NULL);
        aux = concat(aux, label);
        aux = concat(aux, ":\n");
        fputs(aux, tacFile);
        resolveSyntaxTree(tacFile, tree->right->right);
        aux = concat(label2, ":\n");
        aux = concat(aux, generateInstruction("println", NULL, NULL, NULL));
        fputs(aux, tacFile);
      }
    } else if(strcmp(tree->node_type, "ITERATOR") == 0) {
      char* label = getLabel();
      char* label2 = getLabel();
      aux = concat(label, ":\n");
      if(strcmp(tree->left->node_type, "VARIABLE") == 0 || strcmp(tree->left->node_type, "VALUE") == 0) {
        aux = concat(aux, generateInstruction("brz", label2, getValueOrVariable(tree->left), NULL));
        fputs(aux, tacFile);
      } else if(strcmp(tree->left->node_type, "OPERATOR") == 0) {
        aux = concat(aux, generateAritmeticOperation(tree->left));
        aux = concat(aux, generateInstruction("brz", label2, "$0", NULL));
        fputs(aux, tacFile);
      }
      resolveSyntaxTree(tacFile, tree->right);
      aux = generateInstruction("jump", label, NULL, NULL);
      aux = concat(aux, label2);
      aux = concat(aux, ":\n");
      aux = concat(aux, generateInstruction("println", NULL, NULL, NULL));
      fputs(aux, tacFile);
    }
    if(strcmp(tree->node_type, "CONDITIONAL") != 0 && strcmp(tree->node_type, "ITERATOR") != 0) {
      if(aux != NULL){
        fputs(aux, tacFile);
      }
      resolveSyntaxTree(tacFile, tree->left);
      resolveSyntaxTree(tacFile, tree->right);
    }
  }
}

char* getLabel() {
  int digitsCounter = 0;
  int counter = labelCounter;
  if(counter == 0) {
    digitsCounter = 1;
  } else {
    while(counter != 0) {
      digitsCounter++;
      counter = counter/10;
    }
  }
  char* label = malloc(digitsCounter * sizeof(char));
  sprintf(label, "L%d", labelCounter);
  labelCounter++;
  return label;
}

char* generateOperator(char* operator) {
  if(strcmp(operator, "+") == 0) {
    return "add ";
  } else if(strcmp(operator, "-") == 0) {
    return "sub ";
  } else if(strcmp(operator, "*") == 0) {
    return "mul ";
  } else if(strcmp(operator, "/") == 0) {
    return "div ";
  } else if(strcmp(operator, "&&") == 0) {
    return "and ";
  } else if(strcmp(operator, "||") == 0) {
    return "or ";
  } else if(strcmp(operator, ">") == 0) {
    return "slt ";
  } else if(strcmp(operator, "<") == 0) {
    return "slt ";
  } else if(strcmp(operator, "==") == 0) {
    return "seq ";
  } else if(strcmp(operator, ">=") == 0) {
    return "sleq ";
  } else if(strcmp(operator, "<=") == 0) {
    return "sleq ";
  }
  return "";
}

char* getValueOrVariable(struct node* tree) {
  if(strcmp(tree->node_type, "VARIABLE") == 0) {
    struct s_table_entry *s = find_symbol_in_table(tree->symbolName, resolveSyntaxTreeScope, tree->node_type);
    return s->id;
  } else if(strcmp(tree->node_type, "VALUE") == 0){
    if(strcmp(tree->symbolType, "bool") == 0) {
      if(strcmp(tree->symbolName, "true") == 0) {
        return "1";
      } else {
        return "0";
      }
    } else {
      return tree->symbolName;
    }
  }
  return "";
}

char* generateAritmeticOperation(struct node* tree) {
  char *aux = "";
  if(strcmp(tree->left->node_type, "OPERATOR") == 0) {
    char* op = "";
    if(strcmp(tree->right->node_type, "CALL") == 0) {
      int paramCounter = 0;
      aux = concat(aux, generateParmasInstruction(tree->right->left, "", &paramCounter));
      aux = concat(aux, generateInstruction("call", tree->right->symbolName, paramCounter, NULL));
      aux = concat(aux, generateInstruction("pop", "$0", NULL, NULL));
      op = "$0";
    } else {
      op = getValueOrVariable(tree->right);
    }
    aux = concat(aux, generateAritmeticOperation(tree->left));
    aux = concat(aux, generateOperator(tree->symbolName));
    if(strcmp(tree->symbolName, "<") == 0 || strcmp(tree->symbolName, "<=") == 0) {
      aux = concat(aux, "$0, ");
      aux = concat(aux, op);
      aux = concat(aux, ", $0");
    } else {
      aux = concat(aux, "$0, $0, ");
      aux = concat(aux, op);
    }
    aux = concat(aux, "\n");
  } else {
    char* opRight = "";
    char* opLeft = "";
    if(strcmp(tree->right->node_type, "CALL") == 0) {
      int paramCounter = 0;
      aux = concat(aux, generateParmasInstruction(tree->right->left, "", &paramCounter));
      aux = concat(aux, generateInstruction("call", tree->right->symbolName, paramCounter, NULL));
      aux = concat(aux, generateInstruction("pop", "$0", NULL, NULL));
      opRight = "$0";
    } else {
      opRight = getValueOrVariable(tree->right);
    }
    if(strcmp(tree->left->node_type, "CALL") == 0) {
      int paramCounter = 0;
      aux = concat(aux, generateParmasInstruction(tree->left->left, "", &paramCounter));
      aux = concat(aux, generateInstruction("call", tree->left->symbolName, paramCounter, NULL));
      aux = concat(aux, generateInstruction("pop", "$1", NULL, NULL));
      opLeft = "$1";
    } else {
      opLeft = getValueOrVariable(tree->left);
      printf("%s\n", opLeft);
    }
    aux = concat(aux, generateOperator(tree->symbolName));
    aux = concat(aux, "$0, ");
    if(strcmp(tree->symbolName, "<") == 0 || strcmp(tree->symbolName, "<=") == 0) {
      aux = concat(aux, concat(opLeft, ", "));
      aux = concat(aux, opRight);
    } else {
      aux = concat(aux, concat(opRight, ", "));
      aux = concat(aux, opLeft);
    }
    aux = concat(aux, "\n");
  }
  return aux;
}

void generateCodeInTac(FILE *tacFile, struct node* tree) {
  fputs(".code\njump main\n", tacFile);
  resolveSyntaxTree(tacFile, tree);
}

void generateTacFile(struct node* tree, char* fileName) {
  FILE* tacFile;
  char* filePath = concat(TAC_PATH, fileName);
  tacFile = fopen(concat(filePath, ".tac"), "w");
  if(tacFile == NULL) {
    printf("Falha ao criar tac file.\n");
    exit(EXIT_FAILURE);
  }
  generateTableInTac(tacFile);
  generateCodeInTac(tacFile, tree);
  fclose(tacFile);
  printf("Arquivo .tac gerado em %s\n", filePath);
}

int main(int argc, char **argv) {
  ++argv, --argc;
  if(argc > 0)
      yyin = fopen( argv[0], "r" );
  else
      yyin = stdin;
  yyparse();
  printError();
  printf("\n\n\n");
  printf("..........ÁRVORE SINTÁTICA..........:\n");
  print_tree(syntax_tree, 0, 'n');
  printf("\n\n\n");
  print_s_table();
  print_semantic_erros();
  generateTacFile(syntax_tree, "teste");
  yylex_destroy();
  return 0;
}
