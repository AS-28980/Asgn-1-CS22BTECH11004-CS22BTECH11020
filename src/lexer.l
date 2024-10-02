%{
#include <stdio.h>
FILE *token_log;
int line_number = 1;
%}

%%

"set"       { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); }
"if"        { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); }
"else"      { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); }
"size"      { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); }
"loop"      { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); }
"finally"   { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); }
"return"    { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); }
"func"      { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); }
"print"     { fprintf(token_log, "%d : RESERVED WORD : %s\n", line_number, yytext); }

"int"       { fprintf(token_log, "%d : TYPE :  %s\n", line_number, yytext); }
"float"     { fprintf(token_log, "%d : TYPE :  %s\n", line_number, yytext); }
"small"     { fprintf(token_log, "%d : TYPE :  %s\n", line_number, yytext); } 
"big"       { fprintf(token_log, "%d : TYPE :  %s\n", line_number, yytext); }

"or"        { fprintf(token_log, "%d : LOGICAL OPERATOR : %s\n", line_number, yytext); }
"and"       { fprintf(token_log, "%d : LOGICAL OPERATOR : %s\n", line_number, yytext); }
"not"       { fprintf(token_log, "%d : LOGICAL OPERATOR : %s\n", line_number, yytext); }

[a-zA-Z_][a-zA-Z0-9_]*      { fprintf(token_log, "%d : IDENTIFIER : %s\n", line_number, yytext); }
[0-9]*\.[0-9]+              { fprintf(token_log, "%d : FLOAT CONSTANT : %s\n", line_number, yytext); }
[0-9]+                      { fprintf(token_log, "%d : INT CONSTANT : %s\n", line_number, yytext); }

"["         { fprintf(token_log, "%d : PUNCTUATION : ACCESS OPERATOR : %s\n", line_number, yytext); }
"]"         { fprintf(token_log, "%d : PUNCTUATION : ACCESS OPERATOR : %s\n", line_number, yytext); }
"{"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); }
"}"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); }
"("         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); }
")"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); }
":"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); }
";"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); }
"<"         { fprintf(token_log, "%d : PUNCTUATION : COMPARISON OPERATOR : %s\n", line_number, yytext); }
">"         { fprintf(token_log, "%d : PUNCTUATION : COMPARISON OPERATOR : %s\n", line_number, yytext); }
"?"         { fprintf(token_log, "%d : PUNCTUATION : %s\n", line_number, yytext); }
"->"        { fprintf(token_log, "%d : ACCESS OPERATOR : %s\n", line_number, yytext); }
"<-"        { fprintf(token_log, "%d : ACCESS OPERATOR : %s\n", line_number, yytext); }
"+"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); }
"-"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); }
"*"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); }
"/"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); }
"%"         { fprintf(token_log, "%d : ARITHMETIC OPERATOR : %s\n", line_number, yytext); }
"|"         { fprintf(token_log, "%d : BITWISE OPERATOR : %s\n", line_number, yytext); }
"&"         { fprintf(token_log, "%d : BITWISE OPERATOR : %s\n", line_number, yytext); }
"^"         { fprintf(token_log, "%d : BITWISE OPERATOR : %s\n", line_number, yytext); }
"~"         { fprintf(token_log, "%d : BITWISE OPERATOR : %s\n", line_number, yytext); }
"<="        { fprintf(token_log, "%d : COMPARISON OPERATOR : %s\n", line_number, yytext); }
">="        { fprintf(token_log, "%d : COMPARISON OPERATOR : %s\n", line_number, yytext); }
"<>"        { fprintf(token_log, "%d : COMPARISON OPERATOR : %s\n", line_number, yytext); }
"!"         { fprintf(token_log, "%d : COMPARISON OPERATOR : %s\n", line_number, yytext); }

"#".*       {  }
\n          { line_number++; }
[ \t]*      {  }
.           {  }

%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    token_log = fopen("tokens.txt", "w");
    yyin = fopen(argv[1], "r");
    yylex();
    fclose(yyin);
    fclose(token_log);
    return 0;
}
