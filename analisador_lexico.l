%{
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int ERRORS_COUNT = 0;
int MAX_ERRORS = 500;
int error_cnt = 0;
int current_line = 1;
int tableSize = 0;

struct Error {
    char error_type[50];
    int line;
};

struct SymbolTableData {
    char symbol[100];
    int address;
};

struct SymbolTableData symbolTable[500];

struct Error error;

void printError(char text[]){
    printf("------ERROR %d--------\n", error_cnt+1);
    printf("Simbolo nao reconhecido: %s\n", text);
    printf("Line: %d\n", error.line);
    printf("----------------------\n");
}

int searchInTable(char symbol[]) {
    int i = 0;
    while(i < tableSize) {
        if(strcmp(symbolTable[i].symbol, symbol) == 0) {
            return symbolTable[i].address;
        }
        i++;
    }
    strcpy(symbolTable[i].symbol, symbol);
    symbolTable[i].address = i;
    tableSize++;
    return i;
}

void printTable() {
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("SYMBOL TABLE\n");
    int i = 0;
    while(i < tableSize) {
        printf("symbol (%s), endereco %d\n", symbolTable[i].symbol, symbolTable[i].address);
        i++;
    }
}

%}

%x COMMENT
%x STRING

EOL \n
SEP [,.;:]
PARENTESES [()]
CURLY [{}]
BRACKETS [\[\]]
DIGIT [0-9]
VECTOR <(" ")*{INT}(" ")*,(" ")*{INT}(" ")*>|<(" ")*{FLOAT}(" ")*,(" ")*{FLOAT}(" ")*>
INT [-]?{DIGIT}+
FLOAT [-]?{DIGIT}+"."{DIGIT}*
BOOLEAN "true"|"false"
LETTER [a-zA-Z]
TYPE "int"|"float"|"char"|"vector"|"bool"
CONDITIONAL_STMT "if"|"else"
ITERATION_STMT "while"|"for"
RETURN_STMT "return"
IO_STMT "read"|"write"
VECTOR_STMT "distance"|"normalize"
OPERATORS "+"|"-"|"*"|"/"|"="|"||"|"&&"
COMPARABLES "<="|"=="|">="|">"|"<"|"!="
ID  {LETTER}({LETTER}|{DIGIT})*

%%

{TYPE} {
    printf("TYPE (%s) SIZE %d\n", yytext, yyleng);
}

{INT} {
    printf("INT (%s) SIZE %d\n", yytext, yyleng );
}

{FLOAT} {
    printf("FLOAT (%s) SIZE %d\n", yytext, yyleng );
}

{VECTOR} {
    printf("VECTOR (%s) SIZE %d\n", yytext, yyleng );
}

{BOOLEAN} {
    printf("BOOLEAN (%s) SIZE %d\n", yytext, yyleng );
}

{CONDITIONAL_STMT} {
    printf("CONDITIONAL_STMT (%s) SIZE %d\n", yytext, yyleng );
}

{ITERATION_STMT} {
    printf("ITERATION_STMT (%s) SIZE %d\n", yytext, yyleng );
}

{RETURN_STMT} {
    printf("RETURN_STMT (%s) SIZE %d\n", yytext, yyleng );
}

{VECTOR_STMT} {
    printf("VECTOR_STMT (%s) SIZE %d\n", yytext, yyleng );
}

{IO_STMT} {
    printf("RETURN_STMT (%s) SIZE %d\n", yytext, yyleng );
}

\" {
    printf("STRING (%s)\n", yytext);
    BEGIN(STRING);
}

"/*" {
    printf("COMMENT (%s)\n", yytext);
    BEGIN(COMMENT);
}

<COMMENT>"*/" {
    printf("COMMENT (%s)\n", yytext);
    BEGIN(INITIAL);
}

<COMMENT>\n {
    current_line++;
    BEGIN(INITIAL);
}

<COMMENT>. {
    printf("COMMENT (%s)\n", yytext);
}

<STRING>\" {
    printf("STRING (%s)\n", yytext);
    BEGIN(INITIAL);
}

<STRING>\n {
    current_line++;
    BEGIN(INITIAL);
}

<STRING>\\\" {
    BEGIN(INITIAL);
}

<STRING><<EOF>> {
    ERRORS_COUNT++;
    printf("STRING (%s)\n", yytext);
    BEGIN(INITIAL);
}

<STRING>. {
    printf("STRING (%s)\n", yytext);
}

{ID} {
    int address = searchInTable(yytext);
    printf("ID (%s), SIZE %d, symbol table address %d \n", yytext, yyleng, address );
}

{OPERATORS} {
    printf("OPERATORS (%s) SIZE %d\n", yytext, yyleng );
}

{COMPARABLES} {
    printf("COMPARABLES (%s) SIZE %d\n", yytext, yyleng );
}

{PARENTESES} {
    printf("PARENTESES (%s) SIZE %d\n", yytext, yyleng);
}

{BRACKETS} {
    printf("BRACKETS (%s) SIZE %d\n", yytext, yyleng);
}

{CURLY} {
    printf("CURLY (%s) SIZE %d\n", yytext, yyleng);
}

{SEP} {

}

{EOL} {
    current_line++;
}

\t* {
}

" "* {
}

. {
    ERRORS_COUNT++;
    strcpy(error.error_type, "SIMBOL_NOT_FOUND");
    error.line = current_line;
    printError(yytext);
    error_cnt++;
}

%%

int main( int argc, char **argv ) {
    ++argv, --argc;
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    yylex();
    printTable();
}