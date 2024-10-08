%{
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "lex.yy.c"

int yyerror(const char*);
using namespace std;

FILE* parsed_log, *cpp_code;

struct LogEntry {
    int line_number;
    string statement;
    int original_order;

    LogEntry(int line, const string& stmt, int order)
        : line_number(line), statement(stmt), original_order(order) {}
};

vector<LogEntry> log_entries, code_entries;

int order_count2 = 0, order_count = 0;

void write_log3(string s, int line_number) {
    log_entries.push_back(LogEntry(line_number, s, order_count++));
}

void write_code(string s, int line_number) {
    code_entries.push_back(LogEntry(line_number, s, order_count2++));
}

bool compare_logs(const LogEntry& a, const LogEntry& b) {
    if (a.line_number == b.line_number) {
        return a.original_order < b.original_order;
    }
    return a.line_number < b.line_number;
}

void write_sorted_logs_to_file() {
    sort(log_entries.begin(), log_entries.end(), compare_logs);

    for (const auto& entry : log_entries) {
        fprintf(parsed_log, "%d : %s\n", entry.line_number, entry.statement.c_str());
    }
}
%}

%define parse.error verbose

%union{
	struct s{
      char* text;
      int line_number;
   }val;
}

%start program
%token <val> SET IF ELSE SIZE LOOP FINALLY RETURN FUNC PRINT VOID
%token <val> INT FLOAT SMALL BIG
%token <val> OR AND NOT
%token <val> IDENTIFIER FLOAT_CONSTANT INT_CONSTANT
%token <val> L_SQ_PAR R_SQ_PAR L_CUR_PAR R_CUR_PAR L_PAR R_PAR
%token <val> COLON SEMICOLON COMMA LT GT ASSGN
%token <val> QUESTION ARROW LARROW
%token <val> PLUS MINUS MUL DIV MOD
%token <val> BIT_OR BIT_AND BIT_XOR BIT_NOT
%token <val> LTE GTE NEQ EQ
%token <val> INVALID_TOKEN

%type <val> program setup_section set_statement function_declaration 
%type <val> arg_decl_list argument return_type primitive_data_type data_size 
%type <val> mappable_value unary_expression value expression function_call 
%type <val> argument_list size_value accessed_value main_section statement 
%type <val> print_statement return_statement push_pop_statement 
%type <val> declaration_statement declaration_list declaration assignment_statement 
%type <val> conditional_statement predicate optional_else_if optional_else_clause 
%type <val> statement_list loop_statement loop_block finally_block init update


%right '='
%left BIT_OR
%left BIT_XOR
%left BIT_AND
%left LTE GTE NEQ EQ
%right LT GT
%left PLUS MINUS
%left MUL DIV MOD
%left AND OR
%right NOT
%right BIT_NOT
%nonassoc L_PAR R_PAR



%%
    program
    : setup_section main_section
        {
            asprintf(&$$.text, "#include <iostream>\n#include <deque>\n#include <map>\nusing namespace std;\n\n%s \n\nsigned main(void){\n%s\nreturn 0;\n}\n", $1.text, $2.text);
            write_code(std::string($$.text), $1.line_number);
        }
    ;

    setup_section
    : setup_section set_statement
        {
            asprintf(&$$.text, "%s \n%s", $1.text, $2.text);
        }
    | setup_section function_declaration
        {
            asprintf(&$$.text, "%s \n%s", $1.text, $2.text);
        }
    |   
        {
            asprintf(&$$.text, "");
        }
    ;

    set_statement
    : SET primitive_data_type data_size SEMICOLON
        {
            write_log3("Set Statement", $1.line_number);
            if (!strcmp ($2.text, "int")){
                if (!strcmp ($3.text, "big")) asprintf(&$$.text, "#define int long long");
                if (!strcmp ($3.text, "small")) asprintf(&$$.text, "#define int int");
            }
            else{
                if (!strcmp ($3.text, "big")) asprintf(&$$.text, "#define float double");
                if (!strcmp ($3.text, "small")) asprintf(&$$.text, "#define float float");
            }
        }
    ;

    function_declaration
    : FUNC IDENTIFIER L_PAR arg_decl_list SEMICOLON return_type R_PAR LT statement_list GT      
        {
            write_log3("Function Declaration", $1.line_number);
            asprintf(&$$.text, "%s %s(%s){\n%s\n}", $6.text, $2.text, $4.text, $9.text);
        }
    ;

    arg_decl_list
    : arg_decl_list COMMA argument
        {
            asprintf(&$$.text, "%s, %s", $1.text, $3.text);
        }
    | argument
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    |
        {
            asprintf(&$$.text, "");
        }
    ;

    argument
    : primitive_data_type IDENTIFIER
        {
            asprintf(&$$.text, "%s %s", $1.text, $2.text);
        }
    | L_SQ_PAR primitive_data_type R_SQ_PAR IDENTIFIER
        {
            asprintf(&$$.text, "deque <%s> %s", $2.text, $4.text);
        }
    | L_CUR_PAR primitive_data_type COLON mappable_value R_CUR_PAR IDENTIFIER    
        {
            asprintf(&$$.text, "map <%s, %s> %s", $2.text, $4.text, $6.text);
        }
    ;

    return_type
    : primitive_data_type
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    | L_SQ_PAR primitive_data_type R_SQ_PAR
        {
            asprintf(&$$.text, "%s", $2.text);
        }
    | VOID
        {
            asprintf(&$$.text, "void");
        }
    ;

    primitive_data_type
    : INT       
        {
            $$.line_number = $1.line_number;
            asprintf(&$$.text, "int");
        }

    | FLOAT     
        {
            $$.line_number = $1.line_number;
            asprintf(&$$.text, "float");
        }
    ;

    data_size
    : SMALL
        {
            asprintf(&$$.text, "small");
        }
    | BIG
        {
            asprintf(&$$.text, "big");
        }
    ;

    mappable_value
    : primitive_data_type
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    | L_SQ_PAR primitive_data_type R_SQ_PAR
        {
            asprintf(&$$.text, "deque <%s> ", $2.text);
        }
    ;

    unary_expression
    : BIT_NOT expression
        {
            asprintf(&$$.text, "~%s", $2.text);
        }
    | NOT expression
        {
            asprintf(&$$.text, "!%s", $2.text);
        }
    | value
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    ;

    value
    : FLOAT_CONSTANT
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    | INT_CONSTANT
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    | accessed_value
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    | size_value
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    | function_call
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    | IDENTIFIER
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    ;

    expression
    : L_PAR expression R_PAR
        {
            asprintf(&$$.text, "(%s)", $2.text);
        }
    | expression MUL expression
        {
            asprintf(&$$.text, "%s * %s", $1.text, $3.text);
        }
    | expression DIV expression
        {
            asprintf(&$$.text, "%s / %s", $1.text, $3.text);
        }
    | expression MOD expression
        {
            asprintf(&$$.text, "%s %% %s", $1.text, $3.text);
        }
    | expression PLUS expression
        {
            asprintf(&$$.text, "%s + %s", $1.text, $3.text);
        }
    | expression MINUS expression
        {
            asprintf(&$$.text, "%s - %s", $1.text, $3.text);
        }
    | expression BIT_AND expression
        {
            asprintf(&$$.text, "%s & %s", $1.text, $3.text);
        }
    | expression BIT_XOR expression
        {
            asprintf(&$$.text, "%s ^ %s", $1.text, $3.text);
        }
    | expression BIT_OR expression
        {
            asprintf(&$$.text, "%s | %s", $1.text, $3.text);
        }
    | expression LT expression
        {
            asprintf(&$$.text, "%s < %s", $1.text, $3.text);
        }
    | expression GT expression
        {
            asprintf(&$$.text, "%s > %s", $1.text, $3.text);
        }
    | expression LTE expression
        {
            asprintf(&$$.text, "%s <= %s", $1.text, $3.text);
        }
    | expression GTE expression
        {
            asprintf(&$$.text, "%s >= %s", $1.text, $3.text);
        }
    | expression NEQ expression
        {
            asprintf(&$$.text, "%s != %s", $1.text, $3.text);
        }
    | expression EQ expression
        {
            asprintf(&$$.text, "%s == %s", $1.text, $3.text);
        }
    | expression AND expression
        {
            asprintf(&$$.text, "%s && %s", $1.text, $3.text);
        }
    | expression OR expression
        {
            asprintf(&$$.text, "%s || %s", $1.text, $3.text);
        }
    | unary_expression
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    ;

    function_call
    : IDENTIFIER L_PAR argument_list R_PAR
        {
            asprintf(&$$.text, "%s(%s)", $1.text, $3.text);
        }
    ;

    argument_list
    : argument_list COMMA expression
        {
            asprintf(&$$.text, "%s, %s", $1.text, $3.text);
        }
    | expression
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    |   {
            asprintf(&$$.text, "");
        }
    ;

    size_value
    : SIZE L_SQ_PAR IDENTIFIER R_SQ_PAR
        {
            asprintf(&$$.text, "%s.size()", $3.text);
        }
    ;
    
    accessed_value
    : IDENTIFIER L_SQ_PAR IDENTIFIER R_SQ_PAR
        {
            asprintf(&$$.text, "%s[%s]", $1.text, $3.text);
        }
    | IDENTIFIER L_SQ_PAR INT_CONSTANT R_SQ_PAR
        {
            asprintf(&$$.text, "%s[%s]", $1.text, $3.text);
        }
    ;



    main_section
    : statement_list
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    ;

    statement 
    : declaration_statement SEMICOLON
        {
            asprintf(&$$.text, "%s;\n", $1.text);
        }
    | assignment_statement SEMICOLON
        {
            asprintf(&$$.text, "%s;\n", $1.text);
        }
    | conditional_statement 
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    | loop_statement
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    | push_pop_statement SEMICOLON
        {
            asprintf(&$$.text, "%s;\n", $1.text);
        }
    | return_statement SEMICOLON
        {
            asprintf(&$$.text, "%s;\n", $1.text);
        }
    | print_statement SEMICOLON
        {
            asprintf(&$$.text, "%s;\n", $1.text);
        }
    ;

    print_statement
    : PRINT L_PAR value R_PAR       
        {
            write_log3("Print Statement", $1.line_number);
            asprintf(&$$.text, "cout << %s", $3.text);
        }
    ;

    return_statement
    : RETURN expression             
        {
            write_log3("Return Statement", $1.line_number);
            asprintf(&$$.text, "return %s", $2.text);
        }

    | RETURN VOID                   
        {
            write_log3("Return Statement", $1.line_number);
            asprintf(&$$.text, "return void");
        }
    ;

    push_pop_statement
    : IDENTIFIER LARROW L_SQ_PAR expression R_SQ_PAR        
        {
            write_log3("Push/Pop Statement", $1.line_number);
            asprintf(&$$.text, "%s.push_back(%s)", $1.text, $4.text);
        }
    | L_SQ_PAR expression R_SQ_PAR ARROW IDENTIFIER         
        {
            write_log3("Push/Pop Statement", $1.line_number);
            asprintf(&$$.text, "%s.push_front(%s)", $1.text, $4.text);
        }
    | IDENTIFIER ARROW L_SQ_PAR IDENTIFIER R_SQ_PAR      
        {
            write_log3("Push/Pop Statement", $1.line_number);
            asprintf(&$$.text, "%s = %s.back();\n%s.pop_back()", $4.text, $1.text, $1.text);
        }
    | IDENTIFIER ARROW L_SQ_PAR R_SQ_PAR      
        {
            write_log3("Push/Pop Statement", $1.line_number);
            asprintf(&$$.text, "%s.pop_back()", $1.text);
        }
    | L_SQ_PAR R_SQ_PAR LT GT IDENTIFIER                    
        {
            write_log3("Push/Pop Statement", $1.line_number);
            asprintf(&$$.text, "%s.pop_front()", $1.text);
        }
    ;

    

    declaration_statement
    : primitive_data_type declaration_list          
        {
            write_log3("Variable Declaration", $1.line_number);
            asprintf(&$$.text, "%s %s", $1.text, $2.text);
        }
    | L_SQ_PAR primitive_data_type R_SQ_PAR declaration_list        
        {
            write_log3("Variable Declaration", $1.line_number);
            asprintf(&$$.text, "deque <%s> %s", $2.text, $4.text);
        }
    | L_CUR_PAR primitive_data_type COLON mappable_value R_CUR_PAR declaration_list         
        {
            write_log3("Variable Declaration", $1.line_number);
            asprintf(&$$.text, "map <%s, %s> %s", $2.text, $4.text, $6.text);
        }
    ;

    declaration_list
    : declaration_list COMMA declaration
        {
            asprintf(&$$.text, "%s, %s", $1.text, $3.text);
        }
    | declaration
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    ;

    declaration
    : IDENTIFIER ASSGN expression
        {
            asprintf(&$$.text, "%s = %s", $1.text, $3.text);
        }
    | IDENTIFIER
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    ;

    assignment_statement
    : IDENTIFIER ASSGN expression       
        {
            write_log3("Assignment Statement", $1.line_number);
            asprintf(&$$.text, "%s = %s", $1.text, $3.text);
        }
    ;

    conditional_statement
    : LT predicate QUESTION statement_list optional_else_if optional_else_clause GT         
        {
            write_log3("Conditional Statement", $1.line_number);
            asprintf(&$$.text, "if (%s){\n%s\n}\n%s%s", $2.text, $4.text, $5.text, $6.text);
        }
    ;

    predicate
        : expression
            {
                asprintf(&$$.text, "%s", $1.text);
            }
        |
            {
                asprintf(&$$.text, "");
            }
        ;

    optional_else_if
        : predicate QUESTION statement_list optional_else_if 
            {
                asprintf(&$$.text, "else if (%s){\n%s\n}\n", $1.text, $3.text);
            }
        | 
            {
                asprintf(&$$.text, "");
            }
        ;

    optional_else_clause
        : ELSE COLON statement_list  
            {
                asprintf(&$$.text, "else{\n%s\n}\n", $3.text);
            }
        | 
            {
                asprintf(&$$.text, "");
            }
        ;

    statement_list
        : statement_list statement
            {
                asprintf(&$$.text, "%s %s", $1.text, $2.text);
            }
        | statement
            {
                asprintf(&$$.text, "%s", $1.text);
            }
        ;



    loop_statement
    : loop_block finally_block      
        {
            write_log3("Loop Statement", $1.line_number);
            asprintf(&$$.text, "%s %s", $1.text, $2.text);
        }
    ;

    loop_block
    : LOOP L_PAR init SEMICOLON predicate SEMICOLON update R_PAR COLON LT statement_list GT        
        {
            $$.line_number = $1.line_number;
            asprintf(&$$.text, "for (%s; %s; %s){\n%s\n}\n", $3.text, $5.text, $7.text, $11.text);
        }
    ;

    finally_block
    : FINALLY COLON LT statement_list GT
        {
            asprintf(&$$.text, "%s", $4.text);
        }
    |
        {
            asprintf(&$$.text, "");
        }
    ;

    init
    : primitive_data_type declaration_list          
        {
            asprintf(&$$.text, "%s %s", $1.text, $2.text);
        }
    | L_SQ_PAR primitive_data_type R_SQ_PAR declaration_list        
        {
            asprintf(&$$.text, "deque <%s> %s", $2.text, $4.text);
        }
    | L_CUR_PAR primitive_data_type COLON mappable_value R_CUR_PAR declaration_list         
        {
            asprintf(&$$.text, "map <%s, %s> %s", $2.text, $4.text, $6.text);
        }
    |   {
            asprintf(&$$.text, "");
        }
    ;

    update
    : IDENTIFIER ASSGN expression
        {
            asprintf(&$$.text, "%s = %s", $1.text, $3.text);
        }
    |   {
            asprintf(&$$.text, "");
        }
    ;


%%

int yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}
int main(int argc, char *argv[]) {
    token_log = fopen(argv[2], "w");
    parsed_log = fopen(argv[3], "w");
    cpp_code = fopen(argv[4], "w");
    yyin = fopen(argv[1], "r");

    yyparse(); 

    write_sorted_logs_to_file();
    for (const auto& entry : code_entries) {
        fprintf(cpp_code, "%s",entry.statement.c_str());
    }

    fclose(yyin);
    fclose(token_log);
    fclose(parsed_log);
    fclose (cpp_code);

    return 0;
}
