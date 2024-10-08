/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "../src/parser.y"

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

#line 121 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SET = 3,                        /* SET  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_SIZE = 6,                       /* SIZE  */
  YYSYMBOL_LOOP = 7,                       /* LOOP  */
  YYSYMBOL_FINALLY = 8,                    /* FINALLY  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_FUNC = 10,                      /* FUNC  */
  YYSYMBOL_PRINT = 11,                     /* PRINT  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_INT = 13,                       /* INT  */
  YYSYMBOL_FLOAT = 14,                     /* FLOAT  */
  YYSYMBOL_SMALL = 15,                     /* SMALL  */
  YYSYMBOL_BIG = 16,                       /* BIG  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_NOT = 19,                       /* NOT  */
  YYSYMBOL_IDENTIFIER = 20,                /* IDENTIFIER  */
  YYSYMBOL_FLOAT_CONSTANT = 21,            /* FLOAT_CONSTANT  */
  YYSYMBOL_INT_CONSTANT = 22,              /* INT_CONSTANT  */
  YYSYMBOL_L_SQ_PAR = 23,                  /* L_SQ_PAR  */
  YYSYMBOL_R_SQ_PAR = 24,                  /* R_SQ_PAR  */
  YYSYMBOL_L_CUR_PAR = 25,                 /* L_CUR_PAR  */
  YYSYMBOL_R_CUR_PAR = 26,                 /* R_CUR_PAR  */
  YYSYMBOL_L_PAR = 27,                     /* L_PAR  */
  YYSYMBOL_R_PAR = 28,                     /* R_PAR  */
  YYSYMBOL_COLON = 29,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 30,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_ASSGN = 34,                     /* ASSGN  */
  YYSYMBOL_QUESTION = 35,                  /* QUESTION  */
  YYSYMBOL_ARROW = 36,                     /* ARROW  */
  YYSYMBOL_LARROW = 37,                    /* LARROW  */
  YYSYMBOL_PLUS = 38,                      /* PLUS  */
  YYSYMBOL_MINUS = 39,                     /* MINUS  */
  YYSYMBOL_MUL = 40,                       /* MUL  */
  YYSYMBOL_DIV = 41,                       /* DIV  */
  YYSYMBOL_MOD = 42,                       /* MOD  */
  YYSYMBOL_BIT_OR = 43,                    /* BIT_OR  */
  YYSYMBOL_BIT_AND = 44,                   /* BIT_AND  */
  YYSYMBOL_BIT_XOR = 45,                   /* BIT_XOR  */
  YYSYMBOL_BIT_NOT = 46,                   /* BIT_NOT  */
  YYSYMBOL_LTE = 47,                       /* LTE  */
  YYSYMBOL_GTE = 48,                       /* GTE  */
  YYSYMBOL_NEQ = 49,                       /* NEQ  */
  YYSYMBOL_EQ = 50,                        /* EQ  */
  YYSYMBOL_INVALID_TOKEN = 51,             /* INVALID_TOKEN  */
  YYSYMBOL_52_ = 52,                       /* '='  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_setup_section = 55,             /* setup_section  */
  YYSYMBOL_set_statement = 56,             /* set_statement  */
  YYSYMBOL_function_declaration = 57,      /* function_declaration  */
  YYSYMBOL_arg_decl_list = 58,             /* arg_decl_list  */
  YYSYMBOL_argument = 59,                  /* argument  */
  YYSYMBOL_return_type = 60,               /* return_type  */
  YYSYMBOL_primitive_data_type = 61,       /* primitive_data_type  */
  YYSYMBOL_data_size = 62,                 /* data_size  */
  YYSYMBOL_mappable_value = 63,            /* mappable_value  */
  YYSYMBOL_unary_expression = 64,          /* unary_expression  */
  YYSYMBOL_value = 65,                     /* value  */
  YYSYMBOL_expression = 66,                /* expression  */
  YYSYMBOL_function_call = 67,             /* function_call  */
  YYSYMBOL_argument_list = 68,             /* argument_list  */
  YYSYMBOL_size_value = 69,                /* size_value  */
  YYSYMBOL_accessed_value = 70,            /* accessed_value  */
  YYSYMBOL_main_section = 71,              /* main_section  */
  YYSYMBOL_statement = 72,                 /* statement  */
  YYSYMBOL_print_statement = 73,           /* print_statement  */
  YYSYMBOL_return_statement = 74,          /* return_statement  */
  YYSYMBOL_push_pop_statement = 75,        /* push_pop_statement  */
  YYSYMBOL_declaration_statement = 76,     /* declaration_statement  */
  YYSYMBOL_declaration_list = 77,          /* declaration_list  */
  YYSYMBOL_declaration = 78,               /* declaration  */
  YYSYMBOL_assignment_statement = 79,      /* assignment_statement  */
  YYSYMBOL_conditional_statement = 80,     /* conditional_statement  */
  YYSYMBOL_predicate = 81,                 /* predicate  */
  YYSYMBOL_optional_else_if = 82,          /* optional_else_if  */
  YYSYMBOL_optional_else_clause = 83,      /* optional_else_clause  */
  YYSYMBOL_statement_list = 84,            /* statement_list  */
  YYSYMBOL_loop_statement = 85,            /* loop_statement  */
  YYSYMBOL_loop_block = 86,                /* loop_block  */
  YYSYMBOL_finally_block = 87,             /* finally_block  */
  YYSYMBOL_init = 88,                      /* init  */
  YYSYMBOL_update = 89                     /* update  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   439

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  204

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   100,   100,   108,   112,   117,   123,   138,   146,   150,
     155,   161,   165,   171,   175,   179,   186,   192,   200,   204,
     211,   215,   222,   226,   230,   237,   241,   245,   249,   253,
     257,   264,   268,   272,   276,   280,   284,   288,   292,   296,
     300,   304,   308,   312,   316,   320,   324,   328,   332,   339,
     346,   350,   354,   360,   367,   371,   380,   387,   391,   395,
     399,   403,   407,   411,   418,   426,   432,   440,   445,   450,
     455,   460,   470,   475,   480,   488,   492,   499,   503,   510,
     518,   526,   531,   537,   542,   548,   553,   559,   563,   572,
     580,   588,   593,   599,   603,   609,   613
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SET", "IF", "ELSE",
  "SIZE", "LOOP", "FINALLY", "RETURN", "FUNC", "PRINT", "VOID", "INT",
  "FLOAT", "SMALL", "BIG", "OR", "AND", "NOT", "IDENTIFIER",
  "FLOAT_CONSTANT", "INT_CONSTANT", "L_SQ_PAR", "R_SQ_PAR", "L_CUR_PAR",
  "R_CUR_PAR", "L_PAR", "R_PAR", "COLON", "SEMICOLON", "COMMA", "LT", "GT",
  "ASSGN", "QUESTION", "ARROW", "LARROW", "PLUS", "MINUS", "MUL", "DIV",
  "MOD", "BIT_OR", "BIT_AND", "BIT_XOR", "BIT_NOT", "LTE", "GTE", "NEQ",
  "EQ", "INVALID_TOKEN", "'='", "$accept", "program", "setup_section",
  "set_statement", "function_declaration", "arg_decl_list", "argument",
  "return_type", "primitive_data_type", "data_size", "mappable_value",
  "unary_expression", "value", "expression", "function_call",
  "argument_list", "size_value", "accessed_value", "main_section",
  "statement", "print_statement", "return_statement", "push_pop_statement",
  "declaration_statement", "declaration_list", "declaration",
  "assignment_statement", "conditional_statement", "predicate",
  "optional_else_if", "optional_else_clause", "statement_list",
  "loop_statement", "loop_block", "finally_block", "init", "update", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-83)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -98,     8,   342,   -98,    42,    -2,    45,    -5,     6,   -98,
     -98,    70,   105,    42,    95,   -98,   -98,    51,   -98,   -98,
      32,    59,    62,    65,    78,   -98,   407,   -98,   102,   118,
      35,    90,   -98,    95,   -10,   -98,   -98,    95,    95,   -98,
     -98,   237,   -98,   -98,   -98,    93,    24,    95,   100,   107,
      96,   111,   150,   116,   237,   101,   114,   119,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   125,   -98,   -98,   -98,   133,
      42,   -98,   135,   146,   -98,    76,    95,   184,   -98,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    89,   127,   237,    19,    95,
     144,    51,   142,   -13,   407,    95,    51,   147,   -98,    95,
     156,   157,   160,   237,    -8,   -98,   -98,   -98,   120,   120,
     129,   129,   122,   122,   122,   256,   294,   275,   120,   120,
     120,   120,    42,   112,   -98,   165,   -98,   163,   -98,   218,
     176,   119,   183,   -98,   185,   178,    15,   237,   -98,   407,
     177,   -98,   -98,   -98,   -98,    95,   182,    40,    89,   -98,
     -98,   -98,   -98,   -98,   186,    51,   -18,   173,   204,   350,
     191,   237,   193,   -98,    42,   187,   -98,   -98,   -98,   119,
     407,   189,   181,   -98,   196,   192,   -98,   195,   205,    15,
     407,   -98,    95,   206,   -98,   407,   -98,   407,   237,   407,
     377,   392,   -98,   -98
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     0,     0,     0,    16,
      17,     0,     0,     0,    82,     3,     4,     0,     2,    88,
       0,     0,     0,     0,     0,    59,    56,    60,    92,     0,
      94,     0,    66,     0,    30,    25,    26,     0,     0,    48,
      24,    65,    29,    28,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,    78,    72,    76,    63,
      62,    61,    57,    58,    87,     0,    89,    18,    19,     0,
       0,    93,     0,     0,    23,     0,    52,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,    82,
       0,     0,     0,    51,     0,    31,    47,    46,    40,    41,
      35,    36,    32,    33,    34,    39,    37,    38,    42,    43,
      44,    45,     0,     0,     9,     0,    64,     0,    70,     0,
       0,    73,     0,    20,     0,     0,    84,    77,    75,     0,
       0,    53,    54,    55,    49,     0,     0,     0,     0,    11,
      69,    67,    71,    68,     0,     0,    30,     0,    86,     0,
      96,    50,     0,    15,     0,     0,    13,     8,    21,    74,
       0,     0,     0,    91,     0,     0,    12,     0,     0,    84,
       0,    80,     0,     0,    14,     0,    83,    85,    95,     0,
       0,     0,     7,    90
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   -98,   -98,   -98,   -98,    63,   -98,    -1,   -98,
     -98,   -98,   194,    -6,   -98,   -98,   -98,   -98,   -98,   -25,
     -98,   -98,   -98,   209,   -97,   137,   -98,   -98,   -12,    52,
     -98,   -90,   -98,   -98,   -98,   -98,   -98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    15,    16,   133,   134,   175,    17,    69,
     145,    39,    40,    54,    42,   114,    43,    44,    18,    19,
      20,    21,    22,    23,    57,    58,    24,    25,   167,   168,
     182,    26,    27,    28,    66,    72,   185
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    64,    55,    29,   141,    75,    52,   143,     3,    76,
     144,    51,    53,    75,   146,    45,    47,    76,    48,    49,
     154,    31,     5,   155,     6,    30,     8,    74,     9,    10,
      31,    77,    78,    46,    33,   166,    35,    36,    12,   137,
      13,    97,    37,   138,    34,    35,    36,    14,     9,    10,
     -82,    31,   173,     9,    10,     9,    10,    32,    70,   169,
      13,    38,    59,   174,    33,    34,    35,    36,   179,    51,
     113,    56,    37,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    60,
     189,    38,    61,   139,   135,    62,   111,   150,   112,   147,
     197,    31,     9,    10,    47,   200,    48,    49,    63,   201,
      65,    31,   132,    73,    33,    34,    35,    36,     9,    10,
      95,    64,    37,    98,    33,    34,    35,    36,   100,    50,
      99,   156,    37,    67,    68,   101,   104,    79,    80,    79,
      80,    38,   157,   158,    64,   103,    79,    80,   105,   171,
     106,    38,    81,    82,   107,   136,   176,   135,    83,    84,
      85,    86,    87,   108,    64,   109,   110,    79,    80,    85,
      86,    87,    64,   187,   102,    64,    64,   140,   142,   149,
     151,   152,    81,    82,   153,   159,   198,   160,    83,    84,
      85,    86,    87,    88,    89,    90,   162,    91,    92,    93,
      94,    79,    80,   163,   165,   164,   172,   170,   180,   181,
     178,   184,   115,   186,   191,   188,    81,    82,   190,   194,
     193,   177,    83,    84,    85,    86,    87,    88,    89,    90,
     192,    91,    92,    93,    94,    79,    80,   195,   199,    71,
      96,   196,   161,   148,     0,     0,     0,     0,     0,     0,
      81,    82,     0,     0,    79,    80,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92,    93,    94,    81,
      82,     0,     0,    79,    80,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,    81,    82,
       0,     0,    79,    80,    83,    84,    85,    86,    87,     0,
      89,    90,     0,    91,    92,    93,    94,    81,    82,     0,
       0,    79,    80,    83,    84,    85,    86,    87,     0,    89,
       0,     0,    91,    92,    93,    94,    81,    82,     0,     0,
       0,     0,    83,    84,    85,    86,    87,     0,     0,     0,
       0,    91,    92,    93,    94,     4,     0,     0,     0,     5,
       0,     6,     7,     8,     0,     9,    10,     5,     0,     6,
       0,     8,    11,     9,    10,    12,     0,    13,     0,     0,
      11,     0,     0,    12,    14,    13,     0,     0,     0,     0,
       0,     0,    14,   183,     5,     0,     6,     0,     8,     0,
       9,    10,     0,     0,     0,     0,     0,    11,     0,     5,
      12,     6,    13,     8,     0,     9,    10,     0,     0,    14,
     202,     0,    11,     0,     5,    12,     6,    13,     8,     0,
       9,    10,     0,     0,    14,   203,     0,    11,     0,     0,
      12,     0,    13,     0,     0,     0,     0,     0,     0,    14
};

static const yytype_int16 yycheck[] =
{
       6,    26,    14,     4,   101,    23,    12,    20,     0,    27,
      23,    12,    13,    23,   104,    20,    34,    27,    36,    37,
      28,     6,     7,    31,     9,    27,    11,    33,    13,    14,
       6,    37,    38,    27,    19,    20,    21,    22,    23,    20,
      25,    47,    27,    24,    20,    21,    22,    32,    13,    14,
      35,     6,    12,    13,    14,    13,    14,    12,    23,   149,
      25,    46,    30,    23,    19,    20,    21,    22,   165,    70,
      76,    20,    27,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    30,
     180,    46,    30,    99,    95,    30,    20,   109,    22,   105,
     190,     6,    13,    14,    34,   195,    36,    37,    30,   199,
       8,     6,    23,    23,    19,    20,    21,    22,    13,    14,
      27,   146,    27,    23,    19,    20,    21,    22,    32,    24,
      23,   132,    27,    15,    16,    24,    35,    17,    18,    17,
      18,    46,    30,    31,   169,    29,    17,    18,    34,   155,
      31,    46,    32,    33,    29,    28,   157,   158,    38,    39,
      40,    41,    42,    30,   189,    30,    20,    17,    18,    40,
      41,    42,   197,   174,    24,   200,   201,    33,    36,    32,
      24,    24,    32,    33,    24,    20,   192,    24,    38,    39,
      40,    41,    42,    43,    44,    45,    20,    47,    48,    49,
      50,    17,    18,    20,    26,    20,    24,    30,    35,     5,
      24,    20,    28,    20,    33,    28,    32,    33,    29,    24,
      28,   158,    38,    39,    40,    41,    42,    43,    44,    45,
      34,    47,    48,    49,    50,    17,    18,    32,    32,    30,
      46,   189,    24,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    -1,    -1,    17,    18,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    50,    32,
      33,    -1,    -1,    17,    18,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    47,    48,    49,    50,    32,    33,
      -1,    -1,    17,    18,    38,    39,    40,    41,    42,    -1,
      44,    45,    -1,    47,    48,    49,    50,    32,    33,    -1,
      -1,    17,    18,    38,    39,    40,    41,    42,    -1,    44,
      -1,    -1,    47,    48,    49,    50,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,     3,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    14,     7,    -1,     9,
      -1,    11,    20,    13,    14,    23,    -1,    25,    -1,    -1,
      20,    -1,    -1,    23,    32,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,     7,    -1,     9,    -1,    11,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    20,    -1,     7,
      23,     9,    25,    11,    -1,    13,    14,    -1,    -1,    32,
      33,    -1,    20,    -1,     7,    23,     9,    25,    11,    -1,
      13,    14,    -1,    -1,    32,    33,    -1,    20,    -1,    -1,
      23,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    54,    55,     0,     3,     7,     9,    10,    11,    13,
      14,    20,    23,    25,    32,    56,    57,    61,    71,    72,
      73,    74,    75,    76,    79,    80,    84,    85,    86,    61,
      27,     6,    12,    19,    20,    21,    22,    27,    46,    64,
      65,    66,    67,    69,    70,    20,    27,    34,    36,    37,
      24,    61,    66,    61,    66,    81,    20,    77,    78,    30,
      30,    30,    30,    30,    72,     8,    87,    15,    16,    62,
      23,    76,    88,    23,    66,    23,    27,    66,    66,    17,
      18,    32,    33,    38,    39,    40,    41,    42,    43,    44,
      45,    47,    48,    49,    50,    27,    65,    66,    23,    23,
      32,    24,    24,    29,    35,    34,    31,    29,    30,    30,
      20,    20,    22,    66,    68,    28,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    23,    58,    59,    61,    28,    20,    24,    66,
      33,    77,    36,    20,    23,    63,    84,    66,    78,    32,
      81,    24,    24,    24,    28,    31,    61,    30,    31,    20,
      24,    24,    20,    20,    20,    26,    20,    81,    82,    84,
      30,    66,    24,    12,    23,    60,    61,    59,    24,    77,
      35,     5,    83,    33,    20,    89,    20,    61,    28,    84,
      29,    33,    34,    28,    24,    32,    82,    84,    66,    32,
      84,    84,    33,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    55,    56,    57,    58,    58,
      58,    59,    59,    60,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    64,    65,    65,    65,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      68,    68,    68,    69,    70,    70,    71,    72,    72,    72,
      72,    72,    72,    72,    73,    74,    74,    75,    75,    75,
      75,    75,    76,    76,    76,    77,    77,    78,    78,    79,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      86,    87,    87,    88,    88,    89,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     4,    10,     3,     1,
       0,     2,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     4,
       3,     1,     0,     4,     4,     4,     1,     2,     2,     1,
       1,     2,     2,     2,     4,     2,     2,     5,     5,     5,
       4,     5,     2,     4,     6,     3,     1,     3,     1,     3,
       7,     1,     0,     4,     0,     3,     0,     2,     1,     2,
      11,     5,     0,     1,     0,     3,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: setup_section main_section  */
#line 101 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "#include <iostream>\n#include <deque>\n#include <map>\nusing namespace std;\n\n%s \n\nsigned main(void){\n%s\nreturn 0;\n}\n", (yyvsp[-1].val).text, (yyvsp[0].val).text);
            write_code(std::string((yyval.val).text), (yyvsp[-1].val).line_number);
        }
#line 1655 "parser.tab.c"
    break;

  case 3: /* setup_section: setup_section set_statement  */
#line 109 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s \n%s", (yyvsp[-1].val).text, (yyvsp[0].val).text);
        }
#line 1663 "parser.tab.c"
    break;

  case 4: /* setup_section: setup_section function_declaration  */
#line 113 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s \n%s", (yyvsp[-1].val).text, (yyvsp[0].val).text);
        }
#line 1671 "parser.tab.c"
    break;

  case 5: /* setup_section: %empty  */
#line 117 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "");
        }
#line 1679 "parser.tab.c"
    break;

  case 6: /* set_statement: SET primitive_data_type data_size SEMICOLON  */
#line 124 "../src/parser.y"
        {
            write_log3("Set Statement", (yyvsp[-3].val).line_number);
            if (!strcmp ((yyvsp[-2].val).text, "int")){
                if (!strcmp ((yyvsp[-1].val).text, "big")) asprintf(&(yyval.val).text, "#define int long long");
                if (!strcmp ((yyvsp[-1].val).text, "small")) asprintf(&(yyval.val).text, "#define int int");
            }
            else{
                if (!strcmp ((yyvsp[-1].val).text, "big")) asprintf(&(yyval.val).text, "#define float double");
                if (!strcmp ((yyvsp[-1].val).text, "small")) asprintf(&(yyval.val).text, "#define float float");
            }
        }
#line 1695 "parser.tab.c"
    break;

  case 7: /* function_declaration: FUNC IDENTIFIER L_PAR arg_decl_list SEMICOLON return_type R_PAR LT statement_list GT  */
#line 139 "../src/parser.y"
        {
            write_log3("Function Declaration", (yyvsp[-9].val).line_number);
            asprintf(&(yyval.val).text, "%s %s(%s){\n%s\n}", (yyvsp[-4].val).text, (yyvsp[-8].val).text, (yyvsp[-6].val).text, (yyvsp[-1].val).text);
        }
#line 1704 "parser.tab.c"
    break;

  case 8: /* arg_decl_list: arg_decl_list COMMA argument  */
#line 147 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s, %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1712 "parser.tab.c"
    break;

  case 9: /* arg_decl_list: argument  */
#line 151 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 1720 "parser.tab.c"
    break;

  case 10: /* arg_decl_list: %empty  */
#line 155 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "");
        }
#line 1728 "parser.tab.c"
    break;

  case 11: /* argument: primitive_data_type IDENTIFIER  */
#line 162 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s %s", (yyvsp[-1].val).text, (yyvsp[0].val).text);
        }
#line 1736 "parser.tab.c"
    break;

  case 12: /* argument: L_SQ_PAR primitive_data_type R_SQ_PAR IDENTIFIER  */
#line 166 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "deque <%s> %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1744 "parser.tab.c"
    break;

  case 13: /* return_type: primitive_data_type  */
#line 172 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 1752 "parser.tab.c"
    break;

  case 14: /* return_type: L_SQ_PAR primitive_data_type R_SQ_PAR  */
#line 176 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[-1].val).text);
        }
#line 1760 "parser.tab.c"
    break;

  case 15: /* return_type: VOID  */
#line 180 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "void");
        }
#line 1768 "parser.tab.c"
    break;

  case 16: /* primitive_data_type: INT  */
#line 187 "../src/parser.y"
        {
            (yyval.val).line_number = (yyvsp[0].val).line_number;
            asprintf(&(yyval.val).text, "int");
        }
#line 1777 "parser.tab.c"
    break;

  case 17: /* primitive_data_type: FLOAT  */
#line 193 "../src/parser.y"
        {
            (yyval.val).line_number = (yyvsp[0].val).line_number;
            asprintf(&(yyval.val).text, "float");
        }
#line 1786 "parser.tab.c"
    break;

  case 18: /* data_size: SMALL  */
#line 201 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "small");
        }
#line 1794 "parser.tab.c"
    break;

  case 19: /* data_size: BIG  */
#line 205 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "big");
        }
#line 1802 "parser.tab.c"
    break;

  case 20: /* mappable_value: IDENTIFIER  */
#line 212 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 1810 "parser.tab.c"
    break;

  case 21: /* mappable_value: L_SQ_PAR IDENTIFIER R_SQ_PAR  */
#line 216 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "deque <%s> ", (yyvsp[-1].val).text);
        }
#line 1818 "parser.tab.c"
    break;

  case 22: /* unary_expression: BIT_NOT expression  */
#line 223 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "~%s", (yyvsp[0].val).text);
        }
#line 1826 "parser.tab.c"
    break;

  case 23: /* unary_expression: NOT expression  */
#line 227 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "!%s", (yyvsp[0].val).text);
        }
#line 1834 "parser.tab.c"
    break;

  case 24: /* unary_expression: value  */
#line 231 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 1842 "parser.tab.c"
    break;

  case 25: /* value: FLOAT_CONSTANT  */
#line 238 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 1850 "parser.tab.c"
    break;

  case 26: /* value: INT_CONSTANT  */
#line 242 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 1858 "parser.tab.c"
    break;

  case 27: /* value: accessed_value  */
#line 246 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 1866 "parser.tab.c"
    break;

  case 28: /* value: size_value  */
#line 250 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 1874 "parser.tab.c"
    break;

  case 29: /* value: function_call  */
#line 254 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 1882 "parser.tab.c"
    break;

  case 30: /* value: IDENTIFIER  */
#line 258 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 1890 "parser.tab.c"
    break;

  case 31: /* expression: L_PAR expression R_PAR  */
#line 265 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "(%s)", (yyvsp[-1].val).text);
        }
#line 1898 "parser.tab.c"
    break;

  case 32: /* expression: expression MUL expression  */
#line 269 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s * %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1906 "parser.tab.c"
    break;

  case 33: /* expression: expression DIV expression  */
#line 273 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s / %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1914 "parser.tab.c"
    break;

  case 34: /* expression: expression MOD expression  */
#line 277 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s %% %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1922 "parser.tab.c"
    break;

  case 35: /* expression: expression PLUS expression  */
#line 281 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s + %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1930 "parser.tab.c"
    break;

  case 36: /* expression: expression MINUS expression  */
#line 285 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s - %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1938 "parser.tab.c"
    break;

  case 37: /* expression: expression BIT_AND expression  */
#line 289 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s & %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1946 "parser.tab.c"
    break;

  case 38: /* expression: expression BIT_XOR expression  */
#line 293 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s ^ %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1954 "parser.tab.c"
    break;

  case 39: /* expression: expression BIT_OR expression  */
#line 297 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s | %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1962 "parser.tab.c"
    break;

  case 40: /* expression: expression LT expression  */
#line 301 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s < %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1970 "parser.tab.c"
    break;

  case 41: /* expression: expression GT expression  */
#line 305 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s > %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1978 "parser.tab.c"
    break;

  case 42: /* expression: expression LTE expression  */
#line 309 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s <= %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1986 "parser.tab.c"
    break;

  case 43: /* expression: expression GTE expression  */
#line 313 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s >= %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 1994 "parser.tab.c"
    break;

  case 44: /* expression: expression NEQ expression  */
#line 317 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s != %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 2002 "parser.tab.c"
    break;

  case 45: /* expression: expression EQ expression  */
#line 321 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s == %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 2010 "parser.tab.c"
    break;

  case 46: /* expression: expression AND expression  */
#line 325 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s && %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 2018 "parser.tab.c"
    break;

  case 47: /* expression: expression OR expression  */
#line 329 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s || %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 2026 "parser.tab.c"
    break;

  case 48: /* expression: unary_expression  */
#line 333 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 2034 "parser.tab.c"
    break;

  case 49: /* function_call: IDENTIFIER L_PAR argument_list R_PAR  */
#line 340 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s(%s)", (yyvsp[-3].val).text, (yyvsp[-1].val).text);
        }
#line 2042 "parser.tab.c"
    break;

  case 50: /* argument_list: argument_list COMMA expression  */
#line 347 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s, %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 2050 "parser.tab.c"
    break;

  case 51: /* argument_list: expression  */
#line 351 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 2058 "parser.tab.c"
    break;

  case 52: /* argument_list: %empty  */
#line 354 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "");
        }
#line 2066 "parser.tab.c"
    break;

  case 53: /* size_value: SIZE L_SQ_PAR IDENTIFIER R_SQ_PAR  */
#line 361 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s.size()", (yyvsp[-1].val).text);
        }
#line 2074 "parser.tab.c"
    break;

  case 54: /* accessed_value: IDENTIFIER L_SQ_PAR IDENTIFIER R_SQ_PAR  */
#line 368 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s[%s]", (yyvsp[-3].val).text, (yyvsp[-1].val).text);
        }
#line 2082 "parser.tab.c"
    break;

  case 55: /* accessed_value: IDENTIFIER L_SQ_PAR INT_CONSTANT R_SQ_PAR  */
#line 372 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s[%s]", (yyvsp[-3].val).text, (yyvsp[-1].val).text);
        }
#line 2090 "parser.tab.c"
    break;

  case 56: /* main_section: statement_list  */
#line 381 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 2098 "parser.tab.c"
    break;

  case 57: /* statement: declaration_statement SEMICOLON  */
#line 388 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s;\n", (yyvsp[-1].val).text);
        }
#line 2106 "parser.tab.c"
    break;

  case 58: /* statement: assignment_statement SEMICOLON  */
#line 392 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s;\n", (yyvsp[-1].val).text);
        }
#line 2114 "parser.tab.c"
    break;

  case 59: /* statement: conditional_statement  */
#line 396 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 2122 "parser.tab.c"
    break;

  case 60: /* statement: loop_statement  */
#line 400 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 2130 "parser.tab.c"
    break;

  case 61: /* statement: push_pop_statement SEMICOLON  */
#line 404 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s;\n", (yyvsp[-1].val).text);
        }
#line 2138 "parser.tab.c"
    break;

  case 62: /* statement: return_statement SEMICOLON  */
#line 408 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s;\n", (yyvsp[-1].val).text);
        }
#line 2146 "parser.tab.c"
    break;

  case 63: /* statement: print_statement SEMICOLON  */
#line 412 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s;\n", (yyvsp[-1].val).text);
        }
#line 2154 "parser.tab.c"
    break;

  case 64: /* print_statement: PRINT L_PAR value R_PAR  */
#line 419 "../src/parser.y"
        {
            write_log3("Print Statement", (yyvsp[-3].val).line_number);
            asprintf(&(yyval.val).text, "cout << %s", (yyvsp[-1].val).text);
        }
#line 2163 "parser.tab.c"
    break;

  case 65: /* return_statement: RETURN expression  */
#line 427 "../src/parser.y"
        {
            write_log3("Return Statement", (yyvsp[-1].val).line_number);
            asprintf(&(yyval.val).text, "return %s", (yyvsp[0].val).text);
        }
#line 2172 "parser.tab.c"
    break;

  case 66: /* return_statement: RETURN VOID  */
#line 433 "../src/parser.y"
        {
            write_log3("Return Statement", (yyvsp[-1].val).line_number);
            asprintf(&(yyval.val).text, "return void");
        }
#line 2181 "parser.tab.c"
    break;

  case 67: /* push_pop_statement: IDENTIFIER LARROW L_SQ_PAR expression R_SQ_PAR  */
#line 441 "../src/parser.y"
        {
            write_log3("Push/Pop Statement", (yyvsp[-4].val).line_number);
            asprintf(&(yyval.val).text, "%s.push_back(%s)", (yyvsp[-4].val).text, (yyvsp[-1].val).text);
        }
#line 2190 "parser.tab.c"
    break;

  case 68: /* push_pop_statement: L_SQ_PAR expression R_SQ_PAR ARROW IDENTIFIER  */
#line 446 "../src/parser.y"
        {
            write_log3("Push/Pop Statement", (yyvsp[-4].val).line_number);
            asprintf(&(yyval.val).text, "%s.push_front(%s)", (yyvsp[-4].val).text, (yyvsp[-1].val).text);
        }
#line 2199 "parser.tab.c"
    break;

  case 69: /* push_pop_statement: IDENTIFIER ARROW L_SQ_PAR IDENTIFIER R_SQ_PAR  */
#line 451 "../src/parser.y"
        {
            write_log3("Push/Pop Statement", (yyvsp[-4].val).line_number);
            asprintf(&(yyval.val).text, "%s = %s.back();\n%s.pop_back()", (yyvsp[-1].val).text, (yyvsp[-4].val).text, (yyvsp[-4].val).text);
        }
#line 2208 "parser.tab.c"
    break;

  case 70: /* push_pop_statement: IDENTIFIER ARROW L_SQ_PAR R_SQ_PAR  */
#line 456 "../src/parser.y"
        {
            write_log3("Push/Pop Statement", (yyvsp[-3].val).line_number);
            asprintf(&(yyval.val).text, "%s.pop_back()", (yyvsp[-3].val).text);
        }
#line 2217 "parser.tab.c"
    break;

  case 71: /* push_pop_statement: L_SQ_PAR R_SQ_PAR LT GT IDENTIFIER  */
#line 461 "../src/parser.y"
        {
            write_log3("Push/Pop Statement", (yyvsp[-4].val).line_number);
            asprintf(&(yyval.val).text, "%s.pop_front()", (yyvsp[-4].val).text);
        }
#line 2226 "parser.tab.c"
    break;

  case 72: /* declaration_statement: primitive_data_type declaration_list  */
#line 471 "../src/parser.y"
        {
            write_log3("Variable Declaration", (yyvsp[-1].val).line_number);
            asprintf(&(yyval.val).text, "%s %s", (yyvsp[-1].val).text, (yyvsp[0].val).text);
        }
#line 2235 "parser.tab.c"
    break;

  case 73: /* declaration_statement: L_SQ_PAR primitive_data_type R_SQ_PAR declaration_list  */
#line 476 "../src/parser.y"
        {
            write_log3("Variable Declaration", (yyvsp[-3].val).line_number);
            asprintf(&(yyval.val).text, "deque <%s> %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 2244 "parser.tab.c"
    break;

  case 74: /* declaration_statement: L_CUR_PAR primitive_data_type COLON mappable_value R_CUR_PAR declaration_list  */
#line 481 "../src/parser.y"
        {
            write_log3("Variable Declaration", (yyvsp[-5].val).line_number);
            asprintf(&(yyval.val).text, "map <%s, %s> %s", (yyvsp[-4].val).text, (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 2253 "parser.tab.c"
    break;

  case 75: /* declaration_list: declaration_list COMMA declaration  */
#line 489 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s, %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 2261 "parser.tab.c"
    break;

  case 76: /* declaration_list: declaration  */
#line 493 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 2269 "parser.tab.c"
    break;

  case 77: /* declaration: IDENTIFIER ASSGN expression  */
#line 500 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s = %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 2277 "parser.tab.c"
    break;

  case 78: /* declaration: IDENTIFIER  */
#line 504 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 2285 "parser.tab.c"
    break;

  case 79: /* assignment_statement: IDENTIFIER ASSGN expression  */
#line 511 "../src/parser.y"
        {
            write_log3("Assignment Statement", (yyvsp[-2].val).line_number);
            asprintf(&(yyval.val).text, "%s = %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 2294 "parser.tab.c"
    break;

  case 80: /* conditional_statement: LT predicate QUESTION statement_list optional_else_if optional_else_clause GT  */
#line 519 "../src/parser.y"
        {
            write_log3("Conditional Statement", (yyvsp[-6].val).line_number);
            asprintf(&(yyval.val).text, "if (%s){\n%s\n}\n%s%s", (yyvsp[-5].val).text, (yyvsp[-3].val).text, (yyvsp[-2].val).text, (yyvsp[-1].val).text);
        }
#line 2303 "parser.tab.c"
    break;

  case 81: /* predicate: expression  */
#line 527 "../src/parser.y"
            {
                asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
            }
#line 2311 "parser.tab.c"
    break;

  case 82: /* predicate: %empty  */
#line 531 "../src/parser.y"
            {
                asprintf(&(yyval.val).text, "");
            }
#line 2319 "parser.tab.c"
    break;

  case 83: /* optional_else_if: predicate QUESTION statement_list optional_else_if  */
#line 538 "../src/parser.y"
            {
                asprintf(&(yyval.val).text, "else if (%s){\n%s\n}\n", (yyvsp[-3].val).text, (yyvsp[-1].val).text);
            }
#line 2327 "parser.tab.c"
    break;

  case 84: /* optional_else_if: %empty  */
#line 542 "../src/parser.y"
            {
                asprintf(&(yyval.val).text, "");
            }
#line 2335 "parser.tab.c"
    break;

  case 85: /* optional_else_clause: ELSE COLON statement_list  */
#line 549 "../src/parser.y"
            {
                asprintf(&(yyval.val).text, "else{\n%s\n}\n", (yyvsp[0].val).text);
            }
#line 2343 "parser.tab.c"
    break;

  case 86: /* optional_else_clause: %empty  */
#line 553 "../src/parser.y"
            {
                asprintf(&(yyval.val).text, "");
            }
#line 2351 "parser.tab.c"
    break;

  case 87: /* statement_list: statement_list statement  */
#line 560 "../src/parser.y"
            {
                asprintf(&(yyval.val).text, "%s %s", (yyvsp[-1].val).text, (yyvsp[0].val).text);
            }
#line 2359 "parser.tab.c"
    break;

  case 88: /* statement_list: statement  */
#line 564 "../src/parser.y"
            {
                asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
            }
#line 2367 "parser.tab.c"
    break;

  case 89: /* loop_statement: loop_block finally_block  */
#line 573 "../src/parser.y"
        {
            write_log3("Loop Statement", (yyvsp[-1].val).line_number);
            asprintf(&(yyval.val).text, "%s %s", (yyvsp[-1].val).text, (yyvsp[0].val).text);
        }
#line 2376 "parser.tab.c"
    break;

  case 90: /* loop_block: LOOP L_PAR init SEMICOLON predicate SEMICOLON update R_PAR LT statement_list GT  */
#line 581 "../src/parser.y"
        {
            (yyval.val).line_number = (yyvsp[-10].val).line_number;
            asprintf(&(yyval.val).text, "for (%s; %s; %s){\n%s\n}\n", (yyvsp[-8].val).text, (yyvsp[-6].val).text, (yyvsp[-4].val).text, (yyvsp[-1].val).text);
        }
#line 2385 "parser.tab.c"
    break;

  case 91: /* finally_block: FINALLY COLON LT statement_list GT  */
#line 589 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[-1].val).text);
        }
#line 2393 "parser.tab.c"
    break;

  case 92: /* finally_block: %empty  */
#line 593 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "");
        }
#line 2401 "parser.tab.c"
    break;

  case 93: /* init: declaration_statement  */
#line 600 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s", (yyvsp[0].val).text);
        }
#line 2409 "parser.tab.c"
    break;

  case 94: /* init: %empty  */
#line 603 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "");
        }
#line 2417 "parser.tab.c"
    break;

  case 95: /* update: IDENTIFIER ASSGN expression  */
#line 610 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "%s = %s", (yyvsp[-2].val).text, (yyvsp[0].val).text);
        }
#line 2425 "parser.tab.c"
    break;

  case 96: /* update: %empty  */
#line 613 "../src/parser.y"
        {
            asprintf(&(yyval.val).text, "");
        }
#line 2433 "parser.tab.c"
    break;


#line 2437 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 623 "../src/parser.y"


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
