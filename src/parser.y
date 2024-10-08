%{
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "lex.yy.c"

int yyerror(const char*);
using namespace std;

<<<<<<< Updated upstream
FILE* parsed_log;
=======
FILE* parsed_log, *cpp_code;
>>>>>>> Stashed changes

struct LogEntry {
    int line_number;
    string statement;
    int original_order;

    LogEntry(int line, const string& stmt, int order)
        : line_number(line), statement(stmt), original_order(order) {}
};

<<<<<<< Updated upstream
vector<LogEntry> log_entries;

int order_count = 0;
=======
vector<LogEntry> log_entries, code_entries;

int order_count2 = 0, order_count = 0;
>>>>>>> Stashed changes

void write_log3(string s, int line_number) {
    log_entries.push_back(LogEntry(line_number, s, order_count++));
}

<<<<<<< Updated upstream
=======
void write_code(string s, int line_number) {
    code_entries.push_back(LogEntry(line_number, s, order_count2++));
}

>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
%type <val> loop_block primitive_data_type
=======
%type <val> program setup_section set_statement function_declaration 
%type <val> arg_decl_list argument return_type primitive_data_type data_size 
%type <val> mappable_value unary_expression value expression function_call 
%type <val> argument_list size_value accessed_value main_section statement 
%type <val> print_statement return_statement push_pop_statement 
%type <val> declaration_statement declaration_list declaration assignment_statement 
%type <val> conditional_statement predicate optional_else_if optional_else_clause 
%type <val> statement_list loop_statement loop_block finally_block init update
>>>>>>> Stashed changes


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
<<<<<<< Updated upstream
=======
        {
            asprintf(&$$.text, "#include <iostream>\n#include <deque>\n#include <map>\nusing namespace std;\n\n%s \n\nsigned main(void){\n%s\nreturn 0;\n}\n", $1.text, $2.text);
            write_code(std::string($$.text), $1.line_number);
        }
>>>>>>> Stashed changes
    ;

    setup_section
    : setup_section set_statement
<<<<<<< Updated upstream
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
=======
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
>>>>>>> Stashed changes
    ;

    arg_decl_list
    : arg_decl_list COMMA argument
<<<<<<< Updated upstream
    | argument
    |
=======
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
>>>>>>> Stashed changes
    ;

    argument
    : primitive_data_type IDENTIFIER
<<<<<<< Updated upstream
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
=======
        {
            asprintf(&$$.text, "%s %s", $1.text, $2.text);
        }
    | L_SQ_PAR primitive_data_type R_SQ_PAR IDENTIFIER
        {
            asprintf(&$$.text, "deque <%s> %s", $2.text, $4.text);
        }

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
>>>>>>> Stashed changes
    ;

    data_size
    : SMALL
        {
            asprintf(&$$.text, "small");
        }
    | BIG
<<<<<<< Updated upstream
=======
        {
            asprintf(&$$.text, "big");
        }
>>>>>>> Stashed changes
    ;

    mappable_value
    : IDENTIFIER
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    | L_SQ_PAR IDENTIFIER R_SQ_PAR
<<<<<<< Updated upstream
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

=======
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

>>>>>>> Stashed changes
    function_call
    : IDENTIFIER L_PAR argument_list R_PAR
        {
            asprintf(&$$.text, "%s(%s)", $1.text, $3.text);
        }
    ;

    argument_list
    : argument_list COMMA expression
<<<<<<< Updated upstream
=======
        {
            asprintf(&$$.text, "%s, %s", $1.text, $3.text);
        }
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======
        {
            asprintf(&$$.text, "%s", $1.text);
        }
>>>>>>> Stashed changes
    ;

    statement 
    : declaration_statement SEMICOLON
<<<<<<< Updated upstream
    | assignment_statement SEMICOLON
    | conditional_statement 
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
=======
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
>>>>>>> Stashed changes
    ;

    declaration_list
    : declaration_list COMMA declaration
<<<<<<< Updated upstream
    | declaration
=======
        {
            asprintf(&$$.text, "%s, %s", $1.text, $3.text);
        }
    | declaration
        {
            asprintf(&$$.text, "%s", $1.text);
        }
>>>>>>> Stashed changes
    ;

    declaration
    : IDENTIFIER ASSGN expression
<<<<<<< Updated upstream
    | IDENTIFIER
    ;

    assignment_statement
    : IDENTIFIER ASSGN expression       {
        write_log3("Assignment Statement", $1.line_number);
    }
    ;

    conditional_statement
    : LT predicate QUESTION statement_list optional_else_if optional_else_clause GT         {
        write_log3("Conditional Statement", $1.line_number);
    }
=======
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
>>>>>>> Stashed changes
    ;

    predicate
        : expression
<<<<<<< Updated upstream
        |
=======
            {
                asprintf(&$$.text, "%s", $1.text);
            }
        |
            {
                asprintf(&$$.text, "");
            }
>>>>>>> Stashed changes
        ;

    optional_else_if
        : predicate QUESTION statement_list optional_else_if 
<<<<<<< Updated upstream
        | 
=======
            {
                asprintf(&$$.text, "else if (%s){\n%s\n}\n", $1.text, $3.text);
            }
        | 
            {
                asprintf(&$$.text, "");
            }
>>>>>>> Stashed changes
        ;

    optional_else_clause
        : ELSE COLON statement_list  
<<<<<<< Updated upstream
        | 
=======
            {
                asprintf(&$$.text, "else{\n%s\n}\n", $3.text);
            }
        | 
            {
                asprintf(&$$.text, "");
            }
>>>>>>> Stashed changes
        ;

    statement_list
        : statement_list statement
<<<<<<< Updated upstream
        | statement
=======
            {
                asprintf(&$$.text, "%s %s", $1.text, $2.text);
            }
        | statement
            {
                asprintf(&$$.text, "%s", $1.text);
            }
>>>>>>> Stashed changes
        ;



    loop_statement
<<<<<<< Updated upstream
    : loop_block finally_block      {
        write_log3("Loop Statement", $1.line_number);
    }
    ;

    loop_block
    : LOOP L_PAR init SEMICOLON predicate SEMICOLON update R_PAR LT statement_list GT        {
        $$.line_number = $1.line_number;
    }
=======
    : loop_block finally_block      
        {
            write_log3("Loop Statement", $1.line_number);
            asprintf(&$$.text, "%s %s", $1.text, $2.text);
        }
    ;

    loop_block
    : LOOP L_PAR init SEMICOLON predicate SEMICOLON update R_PAR LT statement_list GT        
        {
            $$.line_number = $1.line_number;
            asprintf(&$$.text, "for (%s; %s; %s){\n%s\n}\n", $3.text, $5.text, $7.text, $10.text);
        }
>>>>>>> Stashed changes
    ;

    finally_block
    : FINALLY COLON LT statement_list GT
<<<<<<< Updated upstream
    |
    ;

    init
    : primitive_data_type IDENTIFIER ASSGN expression
    | L_SQ_PAR primitive_data_type R_SQ_PAR IDENTIFIER ASSGN expression
    |
=======
        {
            asprintf(&$$.text, "%s", $4.text);
        }
    |
        {
            asprintf(&$$.text, "");
        }
    ;

    init
    : declaration_statement
        {
            asprintf(&$$.text, "%s", $1.text);
        }
    |   {
            asprintf(&$$.text, "");
        }
>>>>>>> Stashed changes
    ;

    update
    : IDENTIFIER ASSGN expression
<<<<<<< Updated upstream
    |
=======
        {
            asprintf(&$$.text, "%s = %s", $1.text, $3.text);
        }
    |   {
            asprintf(&$$.text, "");
        }
>>>>>>> Stashed changes
    ;

    

    


%%

int yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}
int main(int argc, char *argv[]) {
    token_log = fopen(argv[2], "w");
    parsed_log = fopen(argv[3], "w");
<<<<<<< Updated upstream
=======
    cpp_code = fopen(argv[4], "w");
>>>>>>> Stashed changes
    yyin = fopen(argv[1], "r");

    yyparse(); 

    write_sorted_logs_to_file();
<<<<<<< Updated upstream
=======
    for (const auto& entry : code_entries) {
        fprintf(cpp_code, "%s",entry.statement.c_str());
    }
>>>>>>> Stashed changes

    fclose(yyin);
    fclose(token_log);
    fclose(parsed_log);
<<<<<<< Updated upstream

    return 0;
}
=======
    fclose (cpp_code);

    return 0;
}
>>>>>>> Stashed changes
