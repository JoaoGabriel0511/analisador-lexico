%{
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "analisadorSintatico.tab.h"

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
OPEN_PARENTESES [(]
CLOSE_PARENTESES [)]
OPEN_CURLY [{]
CLOSE_CURLY [}]
OPEN_BRACKETS [\[]
CLOSE_BRACKETS [\]]
DIGIT [0-9]
VECTOR <(" ")*{INT}(" ")*,(" ")*{INT}(" ")*>|<(" ")*{FLOAT}(" ")*,(" ")*{FLOAT}(" ")*>
INT [-]?{DIGIT}+
FLOAT [-]?{DIGIT}+"."{DIGIT}*
BOOLEAN "true"|"false"
LETTER [a-zA-Z]
TYPE "int"|"float"|"char"|"vector"|"bool"|"void"
IF "if"
ELSE "else"
WHILE "while"
FOR "for"
RETURN "return"
READ "read"
WRITE "write"
DISTANCE "distance"
NORMALIZE "normalize"
ADD "+"
SUB "-"
TIMES "*"
DIV "/"
ASSING "="
OR "||"
AND "&&"
QUOTES ["]
COMPARABLES "<="|"=="|">="|">"|"<"|"!="
ID  {LETTER}({LETTER}|{DIGIT})*

%%

{TYPE} {
    //printf("TYPE (%s) SIZE %d\n", yytext, yyleng);
    yylval.string = (char *) strdup(yytext);
    return TYPE;
}

{INT} {
    //printf("INT (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return INT;
}

{FLOAT} {
    //printf("FLOAT (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return FLOAT;
}

{VECTOR} {
    //printf("VECTOR (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return VECTOR;
}

{BOOLEAN} {
    //printf("BOOLEAN (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return BOOLEAN;
}

{IF} {
    //printf("IF (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return IF;
}

{ELSE} {
    //printf("ELSE (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return ELSE;
}

{WHILE} {
    //printf("WHILE (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return WHILE;
}

{FOR} {
    //printf("FOR (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return FOR;
}

{RETURN} {
    //printf("RETURN (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return RETURN;
}

{DISTANCE} {
    //printf("DISTANCE (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return DISTANCE;
}

{NORMALIZE} {
    //printf("NORMALIZE (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return NORMALIZE;
}

{WRITE} {
    //printf("WRITE (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return WRITE;
}

{READ} {
    //printf("READ (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return READ;
}

{QUOTES} {
    //printf("QUOTES (%s)\n", yytext);
    BEGIN(STRING);
    return QUOTES;
}

"/*" {
    //printf("COMMENT (%s)\n", yytext);
    BEGIN(COMMENT);
}

<COMMENT>"*/" {
    //printf("COMMENT (%s)\n", yytext);
    BEGIN(INITIAL);
}

<COMMENT>\n {
    current_line++;
    BEGIN(INITIAL);
}

<COMMENT>. {
    //printf("COMMENT (%s)\n", yytext);
}

<STRING>\" {
    //printf("STRING (%s)\n", yytext);
    BEGIN(INITIAL);
    return STRING;
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
    //printf("STRING (%s)\n", yytext);
    BEGIN(INITIAL);
    return STRING;
}

<STRING>. {
    //printf("STRING (%s)\n", yytext);
    return STRING;
}

{ID} {
    int address = searchInTable(yytext);
    //printf("ID (%s), SIZE %d, symbol table address %d \n", yytext, yyleng, address );
    yylval.string = (char *) strdup(yytext);
    return ID;
}

{ADD} {
    //printf("ADD (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return ADD;
}

{SUB} {
    //printf("SUB (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return SUB;
}

{TIMES} {
    //printf("TIMES (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return TIMES;
}

{DIV} {
    //printf("DIV (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return DIV;
}

{ASSING} {
    //printf("ASSING (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return ASSING;
}

{OR} {
    //printf("OR (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return OR;
}

{AND} {
    //printf("AND (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return AND;
}

{COMPARABLES} {
    //printf("COMPARABLES (%s) SIZE %d\n", yytext, yyleng );
    yylval.string = (char *) strdup(yytext);
    return COMPARABLES;
}

{OPEN_PARENTESES} {
    //printf("OPEN_PARENTESES (%s) SIZE %d\n", yytext, yyleng);
    yylval.string = (char *) strdup(yytext);
    return OPEN_PARENTESES;
}

{CLOSE_PARENTESES} {
    //printf("CLOSE_PARENTESES (%s) SIZE %d\n", yytext, yyleng);
    yylval.string = (char *) strdup(yytext);
    return CLOSE_PARENTESES;
}

{OPEN_BRACKETS} {
    //printf("OPEN_BRACKETS (%s) SIZE %d\n", yytext, yyleng);
    yylval.string = (char *) strdup(yytext);
    return OPEN_BRACKETS;
}

{CLOSE_BRACKETS} {
    //printf("CLOSE_BRACKETS (%s) SIZE %d\n", yytext, yyleng);
    yylval.string = (char *) strdup(yytext);
    return CLOSE_BRACKETS;
}

{OPEN_CURLY} {
    //printf("OPEN_CURLY (%s) SIZE %d\n", yytext, yyleng);
    yylval.string = (char *) strdup(yytext);
    return OPEN_CURLY;
}

{CLOSE_CURLY} {
    //printf("CLOSE_CURLY (%s) SIZE %d\n", yytext, yyleng);
    yylval.string = (char *) strdup(yytext);
    return CLOSE_CURLY;
}

{EOL} {
    current_line++;
}

\t* {
}

" "* {
}

. {
    return yytext[0];
}

%%