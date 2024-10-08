%{
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "lex.yy.c" // Include the lexer

int yyerror(const char*);
using namespace std;

FILE* parsed_log;

// Structure to store log entries with line number and content
struct LogEntry {
    int line_number;
    string statement;
    int original_order; // To maintain relative order for identical line numbers

    LogEntry(int line, const string& stmt, int order)
        : line_number(line), statement(stmt), original_order(order) {}
};

// Vector to store all log entries
vector<LogEntry> log_entries;

// Order of the entries as they are parsed
int order_count = 0;

// Modified write_log3 function to store the logs in a vector
void write_log3(string s, int line_number) {
    log_entries.push_back(LogEntry(line_number, s, order_count++));
}

// Sorting comparator function
bool compare_logs(const LogEntry& a, const LogEntry& b) {
    if (a.line_number == b.line_number) {
        return a.original_order < b.original_order;
    }
    return a.line_number < b.line_number;
}

// Function to write sorted logs to the file
void write_sorted_logs_to_file() {
    // Sort the log entries
    sort(log_entries.begin(), log_entries.end(), compare_logs);

    // Write the sorted entries to the parsed_log file
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

%type <val> loop_block primitive_data_type


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
    ;

    setup_section
    : setup_section set_statement
    | setup_section function_declaration
    |
    ;

    set_statement
    : SET primitive_data_type data_size SEMICOLON       {
            write_log3("Set Statement", $1.line_number);
    }
    ;

    function_declaration
    : FUNC IDENTIFIER L_PAR arg_decl_list SEMICOLON return_type R_PAR LT statement_list GT      {
        write_log3("Function Declaration", $1.line_number);
    }
    ;

    arg_decl_list
    : arg_decl_list COMMA argument
    | argument
    |
    ;

    argument
    : primitive_data_type IDENTIFIER
    | L_SQ_PAR primitive_data_type R_SQ_PAR IDENTIFIER

    return_type
    : primitive_data_type
    | L_SQ_PAR primitive_data_type R_SQ_PAR
    | VOID
    ;

    primitive_data_type
    : INT       {
        $$.line_number = $1.line_number;
    }

    | FLOAT     {
        $$.line_number = $1.line_number;
    }
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
    : statement_list
    ;

    statement 
    : declaration_statement SEMICOLON
    | assignment_statement SEMICOLON
    | conditional_statement SEMICOLON
    | loop_statement
    | push_pop_statement SEMICOLON
    | return_statement SEMICOLON
    | print_statement SEMICOLON
    ;

    print_statement
    : PRINT L_PAR value R_PAR       {
        write_log3("Print Statement", $1.line_number);
    }
    ;

    return_statement
    : RETURN expression             {
        write_log3("Return Statement", $1.line_number);
    }

    | RETURN VOID                   {
        write_log3("Return Statement", $1.line_number);
    }
    ;

    push_pop_statement
    : IDENTIFIER LARROW L_SQ_PAR expression R_SQ_PAR        {
        write_log3("Push/Pop Statement", $1.line_number);
    }

    | L_SQ_PAR expression R_SQ_PAR ARROW IDENTIFIER         {
        write_log3("Push/Pop Statement", $1.line_number);
    }

    | IDENTIFIER ARROW L_SQ_PAR vector_return R_SQ_PAR      {
        write_log3("Push/Pop Statement", $1.line_number);
    }

    | L_SQ_PAR R_SQ_PAR LT GT IDENTIFIER                    {
        write_log3("Push/Pop Statement", $1.line_number);
    }
    ;

    vector_return
    : IDENTIFIER
    |
    ;

    declaration_statement
    : primitive_data_type declaration_list          {
        write_log3("Variable Declaration", $1.line_number);
    }

    | L_SQ_PAR primitive_data_type R_SQ_PAR declaration_list        {
        write_log3("Variable Declaration", $1.line_number);
    }

    | L_CUR_PAR primitive_data_type COLON mappable_value R_CUR_PAR declaration_list         {
        write_log3("Variable Declaration", $1.line_number);
    }
    ;

    declaration_list
    : declaration_list COMMA declaration
    | declaration
    ;

    declaration
    : IDENTIFIER ASSGN expression
    | IDENTIFIER
    ;

    assignment_statement
    : IDENTIFIER ASSGN expression       {
        write_log3("Assignment Statement", $1.line_number);
    }
    ;

    conditional_statement
    : LT predicate QUESTION statement_list optional_else_if optional_else_clause 
    ;

    predicate
        : expression
        |
        ;

    optional_else_if
        : optional_else_if predicate QUESTION statement_list
        | 
        ;

    optional_else_clause
        : ELSE COLON statement_list GT 
        | 
        ;

    statement_list
        : statement_list statement
        | statement
        ;



    loop_statement
    : loop_block finally_block      {
        write_log3("Loop Statement", $1.line_number);
    }
    ;

    loop_block
    : LOOP L_PAR init SEMICOLON predicate SEMICOLON update R_PAR LT statement_list GT        {
        $$.line_number = $1.line_number;
    }
    ;

    finally_block
    : FINALLY COLON LT statement_list GT
    |
    ;

    init
    : primitive_data_type IDENTIFIER ASSGN expression
    | L_SQ_PAR primitive_data_type R_SQ_PAR IDENTIFIER ASSGN expression
    |
    ;

    update
    : IDENTIFIER ASSGN expression
    |
    ;

    

    


%%

int yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}
int main(int argc, char *argv[]) {
    token_log = fopen(argv[2], "w");
    parsed_log = fopen(argv[3], "w");
    yyin = fopen(argv[1], "r");

    yyparse(); 

    // After parsing, sort and write the logs to the file
    write_sorted_logs_to_file();

    fclose(yyin);
    fclose(token_log);
    fclose(parsed_log);

    return 0;
}
