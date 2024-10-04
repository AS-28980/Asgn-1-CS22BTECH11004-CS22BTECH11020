%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "y.tab.h"

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
    #define YYSTYPE char*
    # define YYSTYPE_IS_TRIVIAL 1
    # define YYSTYPE_IS_DECLARED 1
#endif

FILE *token_log;
int line_number = 1;
%}

%%

"set"       { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); yylval = yytext; return SET; }
"if"        { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); yylval = yytext; return IF; }
"else"      { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); yylval = yytext; return ELSE; }
"size"      { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); yylval = yytext; return SIZE; }
"loop"      { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); yylval = yytext; return LOOP; }
"finally"   { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); yylval = yytext; return FINALLY; }
"return"    { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); yylval = yytext; return RETURN; }
"func"      { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); yylval = yytext; return FUNC; }
"print"     { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); yylval = yytext; return PRINT; }

"int"       { fprintf(token_log, "%d : TYPE :  %s\n", line_number, yytext); yylval = yytext; return INT; }
"float"     { fprintf(token_log, "%d : TYPE :  %s\n", line_number, yytext); yylval = yytext; return FLOAT; }
"small"     { fprintf(token_log, "%d : TYPE :  %s\n", line_number, yytext); yylval = yytext; return SMALL; } 
"big"       { fprintf(token_log, "%d : TYPE :  %s\n", line_number, yytext); yylval = yytext; return BIG; }

"or"        { fprintf(token_log, "%d : LOGICAL OPERATOR : %s\n", line_number, yytext); yylval = yytext; return OR; }
"and"       { fprintf(token_log, "%d : LOGICAL OPERATOR : %s\n", line_number, yytext); yylval = yytext; return AND; }
"not"       { fprintf(token_log, "%d : LOGICAL OPERATOR : %s\n", line_number, yytext); yylval = yytext; return NOT; }

[a-zA-Z_][a-zA-Z0-9_]*      { fprintf(token_log, "%d : IDENTIFIER : %s\n", line_number, yytext); yylval = yytext; return IDENTIFIER; }
[0-9]*\.[0-9]+              { fprintf(token_log, "%d : FLOAT CONSTANT : %s\n", line_number, yytext); yylval = yytext; return FLOAT_CONSTANT; }
[0-9]+                      { fprintf(token_log, "%d : INT CONSTANT : %s\n", line_number, yytext); yylval = yytext; return INT_CONSTANT; }

"["         { fprintf(token_log, "%d : PUNCTUATION : ACCESS OPERATOR : %s\n", line_number, yytext); yylval = yytext; return L_SQ_PAR; }
"]"         { fprintf(token_log, "%d : PUNCTUATION : ACCESS OPERATOR : %s\n", line_number, yytext); yylval = yytext; return  R_SQ_PAR; }
"{"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); yylval = yytext; return  L_CUR_PAR; }
"}"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); yylval = yytext; return  R_CUR_PAR; }
"("         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); yylval = yytext; return  L_PAR; }
")"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); yylval = yytext; return  R_PAR; }
":"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); yylval = yytext; return COLON; }
";"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); yylval = yytext; return SEMICOLON; }
"<"         { fprintf(token_log, "%d : PUNCTUATION : COMPARISON OPERATOR : %s\n", line_number, yytext); yylval = yytext; return LT; }
">"         { fprintf(token_log, "%d : PUNCTUATION : COMPARISON OPERATOR : %s\n", line_number, yytext); yylval = yytext; return GT; }
"?"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); yylval = yytext; return QUESTION; }
"->"        { fprintf(token_log, "%d : ACCESS OPERATOR : %s\n", line_number, yytext); yylval = yytext; return ARROW; }
"<-"        { fprintf(token_log, "%d : ACCESS OPERATOR : %s\n", line_number, yytext); yylval = yytext; return LARROW; }
"+"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); yylval = yytext; return PLUS; }
"-"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); yylval = yytext; return MINUS; }
"*"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); yylval = yytext; return MUL; }
"/"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); yylval = yytext; return DIV; }
"%"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); yylval = yytext; return MOD; }
"|"         { fprintf(token_log, "%d : BITWISE OPERATOR : %s\n", line_number, yytext); yylval = yytext; return BIT_OR; }
"&"         { fprintf(token_log, "%d : BITWISE OPERATOR : %s\n", line_number, yytext); yylval = yytext; return BIT_AND; }
"^"         { fprintf(token_log, "%d : BITWISE OPERATOR : %s\n", line_number, yytext); yylval = yytext; return BIT_XOR; }
"~"         { fprintf(token_log, "%d : BITWISE OPERATOR : %s\n", line_number, yytext); yylval = yytext; return BIT_NOT; }
"<="        { fprintf(token_log, "%d : COMPARISON OPERATOR : %s\n", line_number, yytext); yylval = yytext; return LTE; }
">="        { fprintf(token_log, "%d : COMPARISON OPERATOR : %s\n", line_number, yytext); yylval = yytext; return GTE; }
"<>"        { fprintf(token_log, "%d : COMPARISON OPERATOR : %s\n", line_number, yytext); yylval = yytext; return NEQ; }

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
