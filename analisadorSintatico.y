%error-verbose
%debug
%locations

%{
  #include <stdlib.h>
  #include <stdio.h>

  int yylex();
  void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
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

  struct node* syntax_tree = NULL;
  struct node* add_ast_node(char * node_type, struct node *left, struct node *right);
  struct node* add_symbol_node(char * node_type, char * symbolType, char * symbolName);
  void gen_table_symbol(char * type, char * name);
  void print_tree(struct node * tree, int prof);

%}

%union {
  char *string;
  struct node *node;
}

%type <node> prog declaration declaration_list var_declaration func_declaration param params
%type <node> local_declarations statement_list compound_statement statement
%type <node> expression_statement conditional_statement iteration_statement return_statement assing_statement vector_statement
%type <node> expression var simple_expression op_expression term call args arg_list string
%type <node> vector_param relop

%token <string> ID
%token <string> TYPE
%token <string> WHILE IF ELSE RETURN WRITE READ FOR
%token <string> STRING INT FLOAT VECTOR
%token <string> COMPARABLES
%token <string> ADD SUB TIMES DIV OR AND ASSING
%token <string> DISTANCE NORMALIZE
%token <string> BOOLEAN
%token <string> OPEN_PARENTESES CLOSE_PARENTESES OPEN_BRACKETS CLOSE_BRACKETS OPEN_CURLY CLOSE_CURLY
%token <string> QUOTES

%right ASSING
%left CEQ CNE CLT CLE CGT CGE
%left '*' '/'
%left '+' '-'

%%

prog:
  declaration_list {
    printf("prog <- declaration_list\n");
    //syntax_tree = $1;
  }
;

declaration_list:
  declaration_list declaration {
    printf("declaration_list <- declaration_list declation\n");
    //$$ = add_ast_node("A", $1, $2);
  }
  | declaration {
    printf("declaration_list <- declaration\n");
    //$$ = $1;
  }
;

declaration:
  func_declaration {
    printf("declaration <- func_declaration\n");
    //$$ = $1;
  }
  | var_declaration {
    printf("declaration <- var_declaration\n");
    //$$ = $1;
  }
;

var_declaration:
  TYPE ID ';' {
    printf("var_declaration <- TYPE ID;\n");
    //$$ = add_symbol_node("V", $1, $2);
  }
;

func_declaration:
  TYPE ID OPEN_PARENTESES params CLOSE_PARENTESES compound_statement {
    printf("func_declaration <- TYPE ID (params) compound_statement;\n");
    //add_symbol_node("F", $1, $2);
  }
;

params:
  params_list {printf("params <- params_list\n");}
  | {printf("params <- \n");}
;

params_list:
  params_list ',' param {printf("params_list <- params_list, param\n");}
  | param {printf("params_list <- param\n");}
;

param:
  TYPE ID {printf("param <- TYPE ID\n");}
;

compound_statement:
  OPEN_CURLY local_declarations statement_list CLOSE_CURLY {printf("compound_statement <- { local_declarations statement_list}\n");}
;

local_declarations:
  local_declarations var_declaration {printf("local_declarations <- local_declarations var_declaration\n");}
  | {printf("local_declarations <- \n");}
;

statement_list:
  statement_list statement {printf("statement_list <- statement_list statement\n");}
  | statement {printf("statement_list <- statement\n");}
;

statement:
  expression_statement {printf("statement <- expression_statement\n");}
  | conditional_statement {printf("statement <- conditional_statement\n");}
  | iteration_statement {printf("statement <- iteration_statement\n");}
  | return_statement {printf("statement <- return_statement\n");}
  | io_statement {printf("statement <- io_statement\n");}
  | vector_statement {printf("statement <- vector_statement\n");}
  | assing_statement {printf("statement <- assing_statement\n");}
;

expression_statement:
 expression {printf("expression_statement <- expression\n");}
 | simple_expression {printf("expression_statement <- simple_expression\n");}
;

conditional_statement:
  IF OPEN_PARENTESES simple_expression CLOSE_PARENTESES compound_statement {printf("conditional_statement <- if(expression)compound_statement\n");}
  | IF OPEN_PARENTESES simple_expression CLOSE_PARENTESES compound_statement ELSE compound_statement {printf("conditional_statement <- if(expression)compound_statement eles compund_statement\n");}
;

iteration_statement:
  WHILE OPEN_PARENTESES simple_expression CLOSE_PARENTESES compound_statement {printf("iteration_statement <- while(expression)compound_statement\n");}
;

return_statement:
  RETURN expression ';' {printf("return_statement <- RETURN expression;\n");}
  | RETURN ';' {printf("return_statement <- RETURN ;\n");}
;

io_statement:
  READ OPEN_PARENTESES var CLOSE_PARENTESES ';' {printf("io_statement <- read(var)\n");}
  | WRITE OPEN_PARENTESES var CLOSE_PARENTESES ';' {printf("io_statement <- write(var)\n");}
  | WRITE OPEN_PARENTESES QUOTES string QUOTES CLOSE_PARENTESES ';' {printf("io_statement <- write(quotes string quotes)\n");}
;

string:
  string STRING {printf("string <- string STRING\n");}
  | {} {printf("string <- \n");}
;

vector_statement:
  NORMALIZE OPEN_PARENTESES vector_param CLOSE_PARENTESES {printf("vector_statement <- normallize(vector_param)\n");}
  | DISTANCE OPEN_PARENTESES vector_param ',' vector_param CLOSE_PARENTESES {printf("vector_statement <- distance(vector_param, vector_param)\n");}
;

vector_param:
  var {printf("vector_param <- var\n");}
  | VECTOR {printf("vector_param <- vector\n");}
;

assing_statement:
  var ASSING expression ';' {printf("assing_expression <- var ASSING expression\n");}
;

expression:
  op_expression {printf("expression <- op_expression\n");}
;

var:
  ID {printf("var <- ID\n");}
;

simple_expression:
  op_expression relop op_expression {printf("simple_expression <- op_expression relop op_expression\n");}
  | op_expression {printf("simple_expression <- op_expression\n");}
;

relop:
  COMPARABLES {printf("relop <- comparables\n");}
;

op_expression:
  op_expression operators term {printf("op_expression <- op_expression operators term\n");}
  | term {printf("op_expression <- term\n");}
;

operators:
  ADD {printf("operators <- add\n");}
  | SUB {printf("operators <- sub\n");}
  | TIMES {printf("operators <- times\n");}
  | DIV {printf("operators <- div\n");}
  | OR {printf("operators <- or\n");}
  | AND {printf("operators <- and\n");}
;

term:
  term factor {printf("term <- term factor\n");}
  | factor {printf("term <- factor\n");}
;

factor:
  OPEN_PARENTESES expression CLOSE_PARENTESES {printf("factor <- (expression)\n");}
  | var {printf("factor <- var\n");}
  | call {printf("factor <- call\n");}
  | INT {printf("factor <- INT\n");}
  | FLOAT {printf("factor <- FLOAT\n");}
  | VECTOR {printf("factor <- VECTOR\n");}
  | BOOLEAN {printf("factor <- BOOLEAN\n");}
;

call:
  ID OPEN_PARENTESES args CLOSE_PARENTESES {printf("call <- (args)\n");}
;

args:
  arg_list {printf("args <- arg_list\n");}
  | {printf("args <- \n");}
;

arg_list:
  arg_list ',' expression {printf("arg_list <- arg_list , expression\n");}
  | expression {printf("arg_list <- expression\n");}
;
%%

struct node * add_ast_node(char * node_type, struct node *left, struct node *right){
  printf("nao symbol\n");
  struct node* node = (struct node*)calloc(1, sizeof(node));
  node->node_type = node_type;
  node->left = left;
  node->right = right;
  node->symbolName = NULL;
  node->symbolType = NULL;
  return node;
}

struct node* add_symbol_node(char * node_type, char * symbolType, char * symbolName) {
  struct node* node = (struct node*)calloc(1, sizeof(node));
  node->node_type = node_type;
  node->symbolName = symbolName;
  node->symbolType = symbolType;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void print_tree(struct node *tree, int prof) {
  //printf("AQUI3\n");
  int j;
  for(j=0;j<prof;j++){
    printf("  ");
  }
  //printf("aquia %s\n", tree);
  //printf("AQUI4\n");
  if (tree) {
    printf("AQUI6\n");
    printf("| node_type: %s  |symbolName: %s | symbolType: %s |\n", tree->node_type, tree->symbolName, tree->symbolType);
    print_tree(tree->left, prof+1);
    print_tree(tree->right, prof+1);
  } else {
    //printf("AQUI5\n");
  }
  //printf("AQUI 7\n");
}

int main(int argc, char **argv) {
  ++argv, --argc;
  if(argc > 0)
      yyin = fopen( argv[0], "r" );
  else
      yyin = stdin;
  yyparse();
  //printf("AQUI1\n");
  print_tree(syntax_tree, 0);
  //printf("AQUI2\n");
  yylex_destroy();
  return 0;
}