%error-verbose
%debug
%locations

%{
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

%}

%union {
  char *string;
  struct node *node;
}

%type <node> prog declaration declaration_list var_declaration func_declaration param params params_list
%type <node> statement_list compound_statement statement
%type <node> expression_statement conditional_statement declaration_statement io_statement iteration_statement return_statement assing_statement vector_statement
%type <node> expression var simple_expression op_expression call args arg_list
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
    check_main_not_declared_error();
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
  | var_declaration ';' {
    printf("declaration <- var_declaration\n");
    $$ = $1;
  }
;

var_declaration:
  TYPE ID {
    printf("var_declaration <- TYPE ID\n");
    $$ = add_variable_node($1, $2);
    add_to_symbol_table($2, $1, "VARIABLE", current_scope, NULL);
  }
;

func_declaration:
  TYPE ID OPEN_PARENTESES params CLOSE_PARENTESES compound_statement {
    printf("func_declaration <- TYPE ID (params) compound_statement\n");
    struct node *aux = add_function_node($1, $2, $4, $6);
    if(strcmp($1, "int") == 0 && strcmp($6->symbolType, "float") == 0) {
      add_float_to_int_node(aux, $6);
    } else if(strcmp($1, "float") == 0 && strcmp($6->symbolType, "int") == 0) {
      add_int_to_float_node(aux, $6);
    }
    check_function_return_mismatch_error($2, aux->right->symbolType, $1);
    if($4 != NULL) {
      if($4->paramsList != NULL) {
        add_to_symbol_table($2, $1, "FUNCTION", "GLOBAL", $4->paramsList);
      } else {
        add_to_symbol_table($2, $1, "FUNCTION", "GLOBAL", NULL);
      }
    } else {
      add_to_symbol_table($2, $1, "FUNCTION", "GLOBAL", NULL);
    }
    current_scope = "GLOBAL";
    $$ = aux;
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
    $$ = add_params_node($1, $3);
  }
  | param {
    printf("params_list <- param\n");
    struct param * param = (struct param*)calloc(1, sizeof(struct param));
    param->paramType = $1->symbolType;
    param->paramName = $1->symbolName;
    DL_APPEND($1->paramsList, param);
    $$ = $1;
  }
;

param:
  TYPE ID {
    printf("param <- TYPE ID\n");
    $$ = add_variable_node($1, $2);
    add_to_symbol_table($2, $1, "VARIABLE", "-", NULL);
  }
;

compound_statement:
  OPEN_CURLY statement_list return_statement CLOSE_CURLY {
    printf("compound_statement <- {statement_list return_statement }\n");
    struct node* aux = add_regular_node("COMPOUND", $2, $3);
    aux->symbolType = $3->symbolType;
    $$ = aux;
  }
;

statement_list:
  statement_list statement {
    printf("statement_list <- statement_list statement\n");
    $$ = add_regular_node("STATEMENT", $1, $2);
  }
  | {
    current_scope = "-";
    printf("statement_list <- \n");
    $$ = NULL;
  }
;

statement:
  expression_statement ';' {
    printf("statement <- expression_statement;\n");
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
  | io_statement ';' {
    printf("statement <- io_statement;\n");
    $$ = $1;
  }
  | vector_statement ';' {
    printf("statement <- vector_statement;\n");
    $$ = $1;
  }
  | assing_statement ';' {
    printf("statement <- assing_statement;\n");
    $$ = $1;
  }
  | declaration_statement ';' {
    printf("statement <- declaration_statement;\n");
    $$ = $1;
  }
;

declaration_statement:
  var_declaration {
    printf("declaration_statement <- var_declaration\n");
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
    printf("return_statement <- RETURN expression\n");
    struct node* aux = add_regular_node("RETURN", $2, NULL);
    aux->symbolType = $2->symbolType;
    $$ = aux;
  }
  | RETURN ';' {
    printf("return_statement <- RETURN\n");
    struct node* aux = add_regular_node("RETURN", NULL, NULL);
    aux->symbolType = "void";
    $$ = aux;
  }
  | {
    printf("return_statement <- \n");
    struct node* aux = add_regular_node("RETURN", NULL, NULL);
    aux->symbolType = "void";
    $$ = aux;
  }
;

io_statement:
  READ OPEN_PARENTESES var CLOSE_PARENTESES {
    printf("io_statement <- read(var)\n");
    struct node *aux = add_operator_node($1);
    $$ = add_regular_node("IO", $3, aux);
  }
  | WRITE OPEN_PARENTESES expression CLOSE_PARENTESES {
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
    $$ = add_value_node($1, "vector");
  }
;

assing_statement:
  var ASSING expression {
    printf("assing_expression <- var ASSING expression\n");
    struct node *aux = add_operator_node($2);
    aux->right = $3;
    aux->left = $1;
    printf("%s \n", $3->symbolType);
    if($3->symbolType != NULL && $1->symbolType != NULL) {
      if(strcmp($1->symbolType, "int") == 0 && strcmp($3->symbolType, "float") == 0) {
        add_float_to_int_node(aux, $3);
      } else if(strcmp($1->symbolType, "float") == 0 && strcmp($3->symbolType, "int") == 0) {
        add_int_to_float_node(aux, $3);
      }
      check_type_mismatch_error(aux->left, aux->right);
    }
    $$ = aux;
    
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
    check_symbol_not_declared_error($1);
    struct node* aux = add_variable_node(NULL, $1);
    $$ = aux;
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
  op_expression operators factor {
    printf("op_expression <- op_expression operators factor\n");
    $2->right = $3;
    $2->left = $1;
    if($3->symbolType != NULL && $1->symbolType != NULL) {
      if(strcmp($1->symbolType, "int") == 0 && strcmp($3->symbolType, "float") == 0) {
        add_float_to_int_node($2, $3);

      } else if(strcmp($1->symbolType, "float") == 0 && strcmp($3->symbolType, "int") == 0) {
        add_int_to_float_node($2, $3);
      }
      $2->symbolType = check_type_mismatch_error($2->left, $2->right);
    }
    $$ = $2;
  }
  | factor {
    printf("op_expression <- factor\n");
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
    $$ = add_value_node($1, "int");
  }
  | FLOAT {
    printf("factor <- FLOAT\n");
    $$ = add_value_node($1, "float");
  }
  | VECTOR {
    printf("factor <- VECTOR\n");
    $$ = add_value_node($1, "vector");
  }
  | BOOLEAN {
    printf("factor <- BOOLEAN\n");
    $$ = add_value_node($1, "bool");
  }
;

call:
  ID OPEN_PARENTESES args CLOSE_PARENTESES {
    printf("call <- (args)\n");
    check_symbol_not_declared_error($1);
    struct node *aux = add_function_node(NULL, $1, NULL, NULL);
    check_params_mismatch_error($1, $3->paramsList);
    $$ = add_function_call_node(aux, $3);
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
    $$ = add_params_node($1, $3);
  }
  | expression {
    printf("arg_list <- expression\n");
    struct param * param = (struct param*)calloc(1, sizeof(struct param));
    param->paramType = $1->symbolType;
    param->paramName = $1->symbolName; 
    DL_APPEND($1->paramsList, param);
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
  node->right = function_node;
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
      strcpy(aux, s->var_type);
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

void resolveSyntaxTree(FILE *tacFile, struct node* tree) {
  char *aux = NULL;
  if(tree) {
    if(strcmp(tree->node_type, "FUNCTION") == 0) {
      resolveSyntaxTreeScope = tree->symbolName;
      aux = generateInstruction(concat(tree->symbolName, ":"), NULL, NULL, NULL);
      struct param * param;
      struct s_table_entry * s = find_symbol_in_table(tree->symbolName, "GLOBAL", tree->node_type);
      LL_FOREACH(s->params_list, param) {
        char *paramId = concat("_", tree->symbolName);
        paramId = concat(paramId, "_VARIABLE");
        paramId = concat(param->paramName, paramId);
        strcat(aux, generateInstruction("pop", paramId, NULL, NULL));
      }
    } else if(strcmp(tree->node_type, "OPERATOR") == 0) {
      if(strcmp(tree->symbolName, "=") == 0) {
        struct s_table_entry *s = find_symbol_in_table(tree->left->symbolName, resolveSyntaxTreeScope, tree->left->node_type);
        if(strcmp(tree->right->node_type, "VALUE") == 0) {
          aux = generateInstruction("mov", s->id, tree->right->symbolName, NULL);
        }
      }
    } else if(strcmp(tree->node_type, "RETURN") == 0) {
      if(strcmp(tree->symbolType, "void") != 0 && strcmp(resolveSyntaxTreeScope, "main") != 0) {
        if(strcmp(tree->left->node_type, "VARIABLE") == 0){
          struct s_table_entry *s = find_symbol_in_table(tree->left->symbolName, resolveSyntaxTreeScope, tree->left->node_type);
          aux = generateInstruction("return", s->id, NULL, NULL);
        } else if(strcmp(tree->left->node_type, "VALUE") == 0){
          aux = generateInstruction("return", tree->left->symbolName, NULL, NULL);
        }
      }
      resolveSyntaxTreeScope = "GLOBAL";
    } else if(strcmp(tree->node_type, "IO") == 0) {
      if(strcmp(tree->right->symbolName, "write") == 0) {
        if(strcmp(tree->left->node_type, "VARIABLE") == 0) {
          struct s_table_entry *s = find_symbol_in_table(tree->left->symbolName, resolveSyntaxTreeScope, tree->left->node_type);
          aux = generateInstruction("println", s->id, NULL, NULL);
        } else if(strcmp(tree->left->node_type, "VALUE") == 0) {
          aux = generateInstruction("println", tree->left->symbolName, NULL, NULL);
        }
      }
    }
    if(aux != NULL){
      fputs(aux, tacFile);
    }
    resolveSyntaxTree(tacFile, tree->left);
    resolveSyntaxTree(tacFile, tree->right);
  }
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