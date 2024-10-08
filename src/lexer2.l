%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "parser2.tab.h"

FILE *token_log;
int line_number = 1;

void write_log1(const char* s1, const char* s2)
{
    fprintf(token_log, "%d : %s : %s\n", line_number, s1, s2);
}

void write_log2(const char* s1, const char* s2, const char* s3)
{
    fprintf(token_log, "%d : %s : %s : %s\n", line_number, s1, s2, s3);
}

%}

%%

"set"       { 
    write_log1("RESERVED WORD", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return SET; 
}

"if"        { 
    write_log1("RESERVED WORD", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return IF; 
}

"else"      { 
    write_log1("RESERVED WORD", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return ELSE; 
}

"size"      { 
    write_log1("RESERVED WORD", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return SIZE; 
}

"loop"      { 
    write_log1("RESERVED WORD", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return LOOP; 
}

"finally"   { 
    write_log1("RESERVED WORD", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return FINALLY; 
}

"return"    { 
    write_log1("RESERVED WORD", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return RETURN; 
}

"func"      { 
    write_log1("RESERVED WORD", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return FUNC; 
}
    
"print"     { 
    write_log1("RESERVED WORD", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return PRINT; 
}

"void"      {
    write_log1("RESERVED WORD", yytext);
    yylval.val.text = strdup(yytext);
    yylval.val.line_number = line_number;
    return VOID;
}



"int"       { 
    write_log1("TYPE", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return INT; 
}

"float"     { 
    write_log1("TYPE", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return FLOAT; 
}

"small"     { 
    write_log1("TYPE", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return SMALL; 
}

"big"       { 
    write_log1("TYPE", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return BIG; 
}



"or"        { 
    write_log1("LOGICAL OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return OR; 
}

"and"       { 
    write_log1("LOGICAL OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return AND; 
}

"not"       { 
    write_log1("LOGICAL OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return NOT; 
}



[a-zA-Z_][a-zA-Z0-9_]*      { 
    write_log1("IDENTIFIER", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return IDENTIFIER; 
}

[0-9]*\.[0-9]+              { 
    write_log1("FLOAT CONSTANT", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return FLOAT_CONSTANT; 
}

[0-9]+                      { 
    write_log1("INT CONSTANT", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return INT_CONSTANT; 
}



"["         { 
    write_log2("PUNCTUATION", "ACCESS OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return L_SQ_PAR; 
}

"]"         { 
    write_log2("PUNCTUATION", "ACCESS OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return  R_SQ_PAR; 
}

"{"         { 
    write_log1("PUNCTUATION", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return  L_CUR_PAR; 
}

"}"         { 
    write_log1("PUNCTUATION", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return  R_CUR_PAR; 
}

"("         { 
    write_log1("PUNCTUATION", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return  L_PAR; 
}

")"         { 
    write_log1("PUNCTUATION", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return  R_PAR; 
}

":"         { 
    write_log1("PUNCTUATION", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return  COLON; 
}

";"         { 
    write_log1("PUNCTUATION", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return  SEMICOLON; 
}

","         {
    write_log1("PUNCTUATION", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return  COMMA; 
}

"="         {
    write_log1("PUNCTUATION", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return  ASSGN; 
}

"<"         { 
    write_log2("PUNCTUATION", "COMPARISON OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return LT; 
}

">"         { 
    write_log2("PUNCTUATION", "COMPARISON OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return GT; 
}

"?"         { 
    write_log1("PUNCTUATION", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return QUESTION; 
}

"->"        { 
    write_log1("ACCESS OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return ARROW; 
}

"<-"        { 
    write_log1("ACCESS OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return LARROW; 
}

"+"         { 
    write_log1("ARITHMETIC OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return PLUS; 
}

"-"         { 
    write_log1("ARITHMETIC OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return MINUS; 
}
    
"*"         { 
    write_log1("ARITHMETIC OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return MUL; 
}
    
"/"         { 
    write_log1("ARITHMETIC OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return DIV; 
}
    
"%"         { 
    write_log1("ARITHMETIC OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return MOD; 
}
    
"|"         { 
    write_log1("BITWISE OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return BIT_OR; 
}
    
"&"         { 
    write_log1("BITWISE OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return BIT_AND; 
}
    
"^"         { 
    write_log1("BITWISE OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return BIT_XOR; 
}
    
"~"         { 
    write_log1("BITWISE OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return BIT_NOT; 
}
    
"<="        { 
    write_log1("COMPARISON OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return LTE; 
}

">="        { 
    write_log1("COMPARISON OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return GTE; 
}

"<>"        { 
    write_log1("COMPARISON OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return NEQ; 
}

"=="        { 
    write_log1("COMPARISON OPERATOR", yytext); 
    yylval.val.text = strdup(yytext); 
    yylval.val.line_number = line_number; 
    return EQ; 
}

"#".*       {  /* Ignore comments */ }
\n          { line_number++; }
[ \t]+      {  /* Ignore spaces and tabs */ }
.           { 
    write_log1("INVALID SYMBOL", yytext);
    yylval.val.text = strdup(yytext);
    yylval.val.line_number = line_number;
    return INVALID_TOKEN; 
}

%%

int yywrap() {
    return 1;
}
