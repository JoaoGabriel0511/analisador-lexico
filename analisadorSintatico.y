%error-verbose
%debug
%locations

%{
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

%}

%union {
  char *string;
  struct node *node;
}

%type <node> prog declaration declaration_list var_declaration func_declaration param params params_list
%type <node> local_declarations statement_list compound_statement statement
%type <node> expression_statement conditional_statement io_statement iteration_statement return_statement assing_statement vector_statement
%type <node> expression var simple_expression op_expression term call args arg_list
%type <node> vector_param relop operators factor

%token <string> ID
%token <string> TYPE
%token <string> WHILE IF ELSE RETURN WRITE READ
%token <string> STRING INT FLOAT VECTOR
%token <string> DISTANCE NORMALIZE
%token <string> BOOLEAN
%token <string> OPEN_PARENTESES CLOSE_PARENTESES OPEN_BRACKETS CLOSE_BRACKETS OPEN_CURLY CLOSE_CURLY
%token <string> QUOTES
%right <string> ASSING
%left <string> COMPARABLES
%left <string> ADD SUB TIMES DIV OR AND

%%

prog:
  declaration_list {
    printf("prog <- declaration_list\n");
    syntax_tree = $1;
  }
;

declaration_list:
  declaration_list declaration {
    printf("declaration_list <- declaration_list declation\n");
    $$ = add_regular_node("DECLARATION", $1, $2);
  }
  | declaration {
    printf("declaration_list <- declaration\n");
    $$ = $1;
  }
;

declaration:
  func_declaration {
    printf("declaration <- func_declaration\n");
    $$ = $1;
  }
  | var_declaration {
    printf("declaration <- var_declaration\n");
    $$ = $1;
  }
;

var_declaration:
  TYPE ID ';' {
    printf("var_declaration <- TYPE ID;\n");
    $$ = add_variable_node($1, $2);
    add_to_symbol_table($2, $1, "VARIABLE", current_scope);
  }
;

func_declaration:
  TYPE ID OPEN_PARENTESES params CLOSE_PARENTESES compound_statement {
    printf("func_declaration <- TYPE ID (params) compound_statement;\n");
    $$ = add_function_node($1, $2, $4, $6);
    add_to_symbol_table($2, $1, "FUNCTION", "GLOBAL");
    current_scope = "GLOBAL";
  }
;

params:
  params_list {
    printf("params <- params_list\n");
    $$ = $1;
  }
  | {
    printf("params <- \n");
    $$ = NULL;
  }
;

params_list:
  params_list ',' param {
    printf("params_list <- params_list, param\n");
    $$ = add_regular_node("PARAMS", $1, $3);
  }
  | param {
    printf("params_list <- param\n");
    $$ = $1;
  }
;

param:
  TYPE ID {
    printf("param <- TYPE ID\n");
    $$ = add_variable_node($1, $2);
    add_to_symbol_table($2, $1, "VARIABLE", "-");
  }
;

compound_statement:
  OPEN_CURLY local_declarations statement_list CLOSE_CURLY {
    printf("compound_statement <- { local_declarations statement_list}\n");
    $$ = add_regular_node("STATEMENT", $2, $3);
  }
;

local_declarations:
  local_declarations var_declaration {
    printf("local_declarations <- local_declarations var_declaration\n");
    $$ = add_regular_node("DECLARATION", $1, $2);
  }
  | {
    current_scope = "-";
    printf("local_declarations <- \n");
    $$ = NULL;
  }
;

statement_list:
  statement_list statement {
    printf("statement_list <- statement_list statement\n");
    $$ = add_regular_node("STATEMENT", $1, $2);
  }
  | {
    printf("statement_list <- \n");
    $$ = NULL;
  }
;

statement:
  expression_statement {
    printf("statement <- expression_statement\n");
    $$ = $1;
  }
  | conditional_statement {
    printf("statement <- conditional_statement\n");
    $$ = $1;
  }
  | iteration_statement {
    printf("statement <- iteration_statement\n");
    $$ = $1;
  }
  | return_statement {
    printf("statement <- return_statement\n");
    $$ = $1;
  }
  | io_statement {
    printf("statement <- io_statement\n");
    $$ = $1;
  }
  | vector_statement {
    printf("statement <- vector_statement\n");
    $$ = $1;
  }
  | assing_statement {
    printf("statement <- assing_statement\n");
    $$ = $1;
  }
  | local_declarations {
    printf("statement <- local_declaration\n");
    $$ = $1;
  }
;

expression_statement:
  simple_expression {
   printf("expression_statement <- simple_expression\n");
   $$ = $1;
  }
;

conditional_statement:
  IF OPEN_PARENTESES simple_expression CLOSE_PARENTESES compound_statement {
    printf("conditional_statement <- if(expression)compound_statement\n");
    struct node *aux = add_regular_node("STATEMENT", $5, NULL);
    $$ = add_regular_node("CONDITIONAL", $3, aux);
  }
  | IF OPEN_PARENTESES simple_expression CLOSE_PARENTESES compound_statement ELSE compound_statement {
    printf("conditional_statement <- if(expression)compound_statement eles compund_statement\n");
    struct node *aux = add_regular_node("STATEMENT", $5, $7);
    $$ = add_regular_node("CONDITIONAL", $3, aux);
  }
;

iteration_statement:
  WHILE OPEN_PARENTESES simple_expression CLOSE_PARENTESES compound_statement {
    printf("iteration_statement <- while(expression)compound_statement\n");
    $$ = add_regular_node("ITERATOR", $3, $5);
  }
;

return_statement:
  RETURN expression ';' {
    printf("return_statement <- RETURN expression;\n");
    $$ = add_regular_node("RETURN", $2, NULL);
  }
  | RETURN ';' {
    printf("return_statement <- RETURN ;\n");
    $$ = add_regular_node("RETURN", NULL, NULL);
  }
;

io_statement:
  READ OPEN_PARENTESES var CLOSE_PARENTESES ';' {
    printf("io_statement <- read(var)\n");
    struct node *aux = add_operator_node($1);
    $$ = add_regular_node("IO", $3, aux);
  }
  | WRITE OPEN_PARENTESES var CLOSE_PARENTESES ';' {
    printf("io_statement <- write(var)\n");
    printf("io_statement <- read(var)\n");
    struct node *aux = add_operator_node($1);
    $$ = add_regular_node("IO", $3, aux);
  }
;

vector_statement:
  NORMALIZE OPEN_PARENTESES vector_param CLOSE_PARENTESES {
    printf("vector_statement <- normallize(vector_param)\n");
    struct node *aux = add_operator_node($1);
    $$ = add_regular_node("VECTOR", $3, aux);
  }
  | DISTANCE OPEN_PARENTESES vector_param ',' vector_param CLOSE_PARENTESES {
    printf("vector_statement <- distance(vector_param, vector_param)\n");
    struct node *aux = add_operator_node($1);
    struct node *aux2 = add_regular_node("VECTOR", $3, $5);
    $$ = add_regular_node("VECTOR", aux2, aux);
  }
;

vector_param:
  var {
    printf("vector_param <- var\n");
    $$ = $1;
  }
  | VECTOR {
    printf("vector_param <- vector\n");
    $$ = add_value_node($1);
  }
;

assing_statement:
  var ASSING expression ';' {
    struct node *aux = add_operator_node($2);
    struct node *aux2 = add_regular_node("STATEMENT", aux, $3);
    $$ = add_regular_node("STATEMENT", $1, aux2);
    printf("assing_expression <- var ASSING expression\n");
  }
;

expression:
  op_expression {
    printf("expression <- op_expression\n");
    $$ = $1;
  }
;

var:
  ID {
    printf("var <- ID\n");
    $$ = add_variable_node(NULL, $1);
  }
;

simple_expression:
  op_expression relop op_expression {
    printf("simple_expression <- op_expression relop op_expression\n");
    struct node *aux = add_regular_node("EXPRESSION", $2, $3);
    $$ = add_regular_node("EXPRESSION", $1, aux);
  }
  | op_expression {
    printf("simple_expression <- op_expression\n");
    $$ = $1;
  }
;

relop:
  COMPARABLES {
    printf("relop <- comparables\n");
    $$ = add_operator_node($1);
  }
;

op_expression:
  op_expression operators term {
    printf("op_expression <- op_expression operators term\n");
    struct node* aux = add_regular_node("EXPRESSION", $2, $3);
    $$ = add_regular_node("EXPRESSION", $1, aux);
  }
  | term {
    printf("op_expression <- term\n");
    $$ = $1;
  }
;

operators:
  ADD {
    printf("operators <- add\n");
    $$ = add_operator_node($1);
  }
  | SUB {
    printf("operators <- sub\n");
    $$ = add_operator_node($1);
  }
  | TIMES {
    printf("operators <- times\n");
    $$ = add_operator_node($1);
  }
  | DIV {
    printf("operators <- div\n");
    $$ = add_operator_node($1);
  }
  | OR {
    printf("operators <- or\n");
    $$ = add_operator_node($1);
  }
  | AND {
    printf("operators <- and\n");
    $$ = add_operator_node($1);
  }
;

term:
  term factor {
    printf("term <- term factor\n");
    $$ = add_regular_node("TERM", $1, $2);
  }
  | factor {
    printf("term <- factor\n");
    $$ = $1;
  }
;

factor:
  OPEN_PARENTESES expression CLOSE_PARENTESES {
    printf("factor <- (expression)\n");
    $$ = $2;
  }
  | var {
    printf("factor <- var\n");
    $$ = $1;
  }
  | call {
    printf("factor <- call\n");
    $$ = $1;
  }
  | INT {
    printf("factor <- INT\n");
    $$ = add_value_node($1);
  }
  | FLOAT {
    printf("factor <- FLOAT\n");
    $$ = add_value_node($1);
  }
  | VECTOR {
    printf("factor <- VECTOR\n");
    $$ = add_value_node($1);
  }
  | BOOLEAN {
    printf("factor <- BOOLEAN\n");
    $$ = add_value_node($1);
  }
;

call:
  ID OPEN_PARENTESES args CLOSE_PARENTESES ';' {
    printf("call <- (args)\n");
    struct node *aux = add_function_node(NULL, $1, NULL, NULL);
    $$ = add_regular_node("CALL", aux, $3);
  }
;

args:
  arg_list {
    printf("args <- arg_list\n");
    $$ = $1;
  }
  | {
    printf("args <- \n");
    $$ = NULL;
  }
;

arg_list:
  arg_list ',' expression {
    printf("arg_list <- arg_list , expression\n");
    $$ = add_regular_node("ARG", $1, $3);
  }
  | expression {
    printf("arg_list <- expression\n");
    $$ = $1;
  }
;
%%

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