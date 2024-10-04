%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "y.tab.h"

FILE *token_log;
int line_number = 1;
%}

%%

"set"       { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); return SET; }
"if"        { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); return IF; }
"else"      { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); return ELSE; }
"size"      { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); return SIZE; }
"loop"      { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); return LOOP; }
"finally"   { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); return FINALLY; }
"return"    { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); return RETURN; }
"func"      { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); return FUNC; }
"print"     { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); return PRINT; }

"int"       { fprintf(token_log, "%d : TYPE :  %s\n", line_number, yytext); return INT; }
"float"     { fprintf(token_log, "%d : TYPE :  %s\n", line_number, yytext); return FLOAT; }
"small"     { fprintf(token_log, "%d : TYPE :  %s\n", line_number, yytext); return SMALL; } 
"big"       { fprintf(token_log, "%d : TYPE :  %s\n", line_number, yytext); return BIG; }

"or"        { fprintf(token_log, "%d : LOGICAL OPERATOR : %s\n", line_number, yytext); return OR; }
"and"       { fprintf(token_log, "%d : LOGICAL OPERATOR : %s\n", line_number, yytext); return AND; }
"not"       { fprintf(token_log, "%d : LOGICAL OPERATOR : %s\n", line_number, yytext); return NOT; }

[a-zA-Z_][a-zA-Z0-9_]*      { fprintf(token_log, "%d : IDENTIFIER : %s\n", line_number, yytext); return IDENTIFIER; }
[0-9]*\.[0-9]+              { fprintf(token_log, "%d : FLOAT CONSTANT : %s\n", line_number, yytext); return FLOAT_CONSTANT; }
[0-9]+                      { fprintf(token_log, "%d : INT CONSTANT : %s\n", line_number, yytext); return INT_CONSTANT; }

"["         { fprintf(token_log, "%d : PUNCTUATION : ACCESS OPERATOR : %s\n", line_number, yytext); return L_SQ_PAR; }
"]"         { fprintf(token_log, "%d : PUNCTUATION : ACCESS OPERATOR : %s\n", line_number, yytext); return  R_SQ_PAR; }
"{"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); return  L_CUR_PAR; }
"}"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); return  R_CUR_PAR; }
"("         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); return  L_PAR; }
")"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); return  R_PAR; }
":"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); return COLON; }
";"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); return SEMICOLON; }
"<"         { fprintf(token_log, "%d : PUNCTUATION : COMPARISON OPERATOR : %s\n", line_number, yytext); return LT; }
">"         { fprintf(token_log, "%d : PUNCTUATION : COMPARISON OPERATOR : %s\n", line_number, yytext); return GT; }
"?"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); return QUESTION; }
"->"        { fprintf(token_log, "%d : ACCESS OPERATOR : %s\n", line_number, yytext); return ARROW; }
"<-"        { fprintf(token_log, "%d : ACCESS OPERATOR : %s\n", line_number, yytext); return LARROW; }
"+"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); return PLUS; }
"-"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); return MINUS; }
"*"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); return MUL; }
"/"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); return DIV; }
"%"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); return MOD; }
"|"         { fprintf(token_log, "%d : BITWISE OPERATOR : %s\n", line_number, yytext); return BIT_OR; }
"&"         { fprintf(token_log, "%d : BITWISE OPERATOR : %s\n", line_number, yytext); return BIT_AND; }
"^"         { fprintf(token_log, "%d : BITWISE OPERATOR : %s\n", line_number, yytext); return BIT_XOR; }
"~"         { fprintf(token_log, "%d : BITWISE OPERATOR : %s\n", line_number, yytext); return BIT_NOT; }
"<="        { fprintf(token_log, "%d : COMPARISON OPERATOR : %s\n", line_number, yytext); return LTE; }
">="        { fprintf(token_log, "%d : COMPARISON OPERATOR : %s\n", line_number, yytext); return GTE; }
"<>"        { fprintf(token_log, "%d : COMPARISON OPERATOR : %s\n", line_number, yytext); return NEQ; }

"#".*       {  /* Ignore comments */ }
\n          { line_number++; }
[ \t]+      {  /* Ignore spaces and tabs */ }
.           {  /* Ignore any other characters */ }

%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    token_log = fopen(argv[2], "w");
    yyin = fopen(argv[1], "r");

    while(yylex())
    {}

    fclose(yyin);
    fclose(token_log);

    return 0;
}
