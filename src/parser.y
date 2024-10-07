%{
#include <stdio.h>
#include "lex.yy.c" // Include the lexer
int yyerror(const char*);


%}

%define parse.error verbose

%union{
	struct s{
      char* text;
      int line_number;
   }val;
}


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
%token INVALID_TOKEN


%%
    program: set_section main_section
    ;

    set_section
    : SET primitive_data_type data_size ';'
    ;

    data_type
    : primitive_data_type
    | data_size
    ;

    primitive_data_type
    : INT
    | FLOAT
    ;

    data_size
    : SMALL
    | BIG
    ;

    main_section
    : main_section statement
    | statement
    ;

    statement 
    : declaration_statement
    ;

    declaration_statement
    : primitive_data_type declaration_list
    | L_SQ_PAR primitive_data_type R_SQ_PAR IDENTIFIER
    | L_CUR_PAR primitive_data_type COLON mappable_value R_CUR_PAR IDENTIFIER
    ;

    mappable_value
    : IDENTIFIER
    | L_SQ_PAR IDENTIFIER R_SQ_PAR
    ;

    declaration_list
    : declaration_list ',' declaration
    | declaration
    ;

    declaration
    : IDENTIFIER '=' expression
    | IDENTIFIER
    ;

    expression
    : data_type PLUS data_type
    ;

%%

int yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}