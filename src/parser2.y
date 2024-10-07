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
%token COLON SEMICOLON COMMA LT GT ASSGN
%token QUESTION ARROW LARROW
%token PLUS MINUS MUL DIV MOD
%token BIT_OR BIT_AND BIT_XOR BIT_NOT
%token LTE GTE NEQ EQ
%token INVALID_TOKEN


%right '='
%left BIT_OR
%left BIT_XOR
%left BIT_AND
%left LT GT LTE GTE NEQ EQ
%left PLUS MINUS
%left MUL DIV MOD
%left AND OR
%right NOT
%right BIT_NOT
%nonassoc L_PAR R_PAR



%%
    program
    : set_section main_section
    ;

    set_section
    : set_section set_statement
    |
    ;

    set_statement
    : SET primitive_data_type data_size SEMICOLON
    ;

    primitive_data_type
    : INT
    | FLOAT
    ;

    data_size
    : SMALL
    | BIG
    ;

    mappable_value
    : IDENTIFIER
    | L_SQ_PAR IDENTIFIER R_SQ_PAR
    ;

    unary_expression
    : BIT_NOT expression
    | NOT expression
    | value
    ;

    value
    : FLOAT_CONSTANT
    | INT_CONSTANT
    | accessed_value
    | size_value
    | function_call
    | IDENTIFIER
    ;

    expression
    : L_PAR expression R_PAR
    | expression MUL expression
    | expression DIV expression
    | expression MOD expression
    | expression PLUS expression
    | expression MINUS expression
    | expression BIT_AND expression
    | expression BIT_XOR expression
    | expression BIT_OR expression
    | expression LT expression
    | expression GT expression
    | expression LTE expression
    | expression GTE expression
    | expression NEQ expression
    | expression EQ expression
    | expression AND expression
    | expression OR expression
    | unary_expression
    ;

    function_call
    : IDENTIFIER L_PAR argument_list R_PAR
    ;

    argument_list
    : argument_list COMMA expression
    | expression
    |
    ;

    size_value
    : SIZE L_SQ_PAR IDENTIFIER R_SQ_PAR
    ;
    
    accessed_value
    : IDENTIFIER L_SQ_PAR IDENTIFIER R_SQ_PAR
    | IDENTIFIER L_SQ_PAR INT_CONSTANT R_SQ_PAR
    ;



    main_section
    : main_section statement
    | statement
    ;

    statement 
    : declaration_statement SEMICOLON
    | assignment_statement SEMICOLON
    | conditional_statement SEMICOLON
    ;

    declaration_statement
    : primitive_data_type declaration_list
    | L_SQ_PAR primitive_data_type R_SQ_PAR declaration_list
    | L_CUR_PAR primitive_data_type COLON mappable_value R_CUR_PAR declaration_list
    ;

    declaration_list
    : declaration_list COMMA declaration
    | declaration
    ;

    declaration
    : IDENTIFIER
    | assignment_statement
    ;

    assignment_statement
    : IDENTIFIER ASSGN expression
    ;

    conditional_statement
    : if_eq else_if_eq else_eq
	;

    if_eq
    : LT expression QUESTION statement
    ;

    else_if_eq
    : expression QUESTION statement
    | 
    ;

    else_eq
    : ELSE COLON statement GT
    | 
    ;



    

    

    


%%

int yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}

int main(int argc, char *argv[]) {
    token_log = fopen(argv[2], "w");
    yyin = fopen(argv[1], "r");

    yyparse(); // Call the parser instead of yylex directly

    fclose(yyin);
    fclose(token_log);

    return 0;
}
