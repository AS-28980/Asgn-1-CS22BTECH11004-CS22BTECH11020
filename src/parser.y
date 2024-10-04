%{
#include <stdio.h>
#include "lex.yy.c" // Include the lexer
int yyerror(const char*);
%}

%define parse.error verbose

%start program
%token SET IF ELSE SIZE LOOP FINALLY RETURN FUNC PRINT
%token INT FLOAT SMALL BIG
%token OR AND NOT
%token IDENTIFIER FLOAT_CONSTANT INT_CONSTANT
%token L_SQ_PAR R_SQ_PAR L_CUR_PAR R_CUR_PAR L_PAR R_PAR
%token COLON SEMICOLON LT GT 
%token QUESTION ARROW LARROW
%token PLUS MINUS MUL DIV MOD
%token BIT_OR BIT_AND BIT_XOR BIT_NOT
%token LTE GTE NEQ

%%
    program:
    ;

%% // Ensure you include proper grammar rules here

int yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}
