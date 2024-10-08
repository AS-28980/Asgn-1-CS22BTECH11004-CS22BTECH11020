/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SET = 258,                     /* SET  */
    IF = 259,                      /* IF  */
    ELSE = 260,                    /* ELSE  */
    SIZE = 261,                    /* SIZE  */
    LOOP = 262,                    /* LOOP  */
    FINALLY = 263,                 /* FINALLY  */
    RETURN = 264,                  /* RETURN  */
    FUNC = 265,                    /* FUNC  */
    PRINT = 266,                   /* PRINT  */
    VOID = 267,                    /* VOID  */
    INT = 268,                     /* INT  */
    FLOAT = 269,                   /* FLOAT  */
    SMALL = 270,                   /* SMALL  */
    BIG = 271,                     /* BIG  */
    OR = 272,                      /* OR  */
    AND = 273,                     /* AND  */
    NOT = 274,                     /* NOT  */
    IDENTIFIER = 275,              /* IDENTIFIER  */
    FLOAT_CONSTANT = 276,          /* FLOAT_CONSTANT  */
    INT_CONSTANT = 277,            /* INT_CONSTANT  */
    L_SQ_PAR = 278,                /* L_SQ_PAR  */
    R_SQ_PAR = 279,                /* R_SQ_PAR  */
    L_CUR_PAR = 280,               /* L_CUR_PAR  */
    R_CUR_PAR = 281,               /* R_CUR_PAR  */
    L_PAR = 282,                   /* L_PAR  */
    R_PAR = 283,                   /* R_PAR  */
    COLON = 284,                   /* COLON  */
    SEMICOLON = 285,               /* SEMICOLON  */
    COMMA = 286,                   /* COMMA  */
    LT = 287,                      /* LT  */
    GT = 288,                      /* GT  */
    ASSGN = 289,                   /* ASSGN  */
    QUESTION = 290,                /* QUESTION  */
    ARROW = 291,                   /* ARROW  */
    LARROW = 292,                  /* LARROW  */
    PLUS = 293,                    /* PLUS  */
    MINUS = 294,                   /* MINUS  */
    MUL = 295,                     /* MUL  */
    DIV = 296,                     /* DIV  */
    MOD = 297,                     /* MOD  */
    BIT_OR = 298,                  /* BIT_OR  */
    BIT_AND = 299,                 /* BIT_AND  */
    BIT_XOR = 300,                 /* BIT_XOR  */
    BIT_NOT = 301,                 /* BIT_NOT  */
    LTE = 302,                     /* LTE  */
    GTE = 303,                     /* GTE  */
    NEQ = 304,                     /* NEQ  */
    EQ = 305,                      /* EQ  */
    INVALID_TOKEN = 306            /* INVALID_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "../src/parser.y"

	struct s{
      char* text;
      int line_number;
   }val;

#line 122 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
