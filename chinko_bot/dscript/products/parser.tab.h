/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_CHINKO_BOT_DSCRIPT_PRODUCTS_PARSER_TAB_H_INCLUDED
# define YY_YY_CHINKO_BOT_DSCRIPT_PRODUCTS_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 7 "chinko_bot/dscript/parser.y"

#include "parser.h"
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

void fatal_error(const char* msg, yyscan_t yyscanner);
#define YY_FATAL_ERROR(msg) fatal_error(msg, yyscanner)

#line 60 "chinko_bot/dscript/products/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NATURAL = 258,                 /* NATURAL  */
    REAL = 259,                    /* REAL  */
    CHARACT = 260,                 /* CHARACT  */
    STR = 261,                     /* STR  */
    TRUE = 262,                    /* TRUE  */
    FALSE = 263,                   /* FALSE  */
    IDENT = 264,                   /* IDENT  */
    COMMA = 265,                   /* COMMA  */
    LOR = 266,                     /* LOR  */
    LAND = 267,                    /* LAND  */
    BOR = 268,                     /* BOR  */
    BXOR = 269,                    /* BXOR  */
    BAND = 270,                    /* BAND  */
    EQ = 271,                      /* EQ  */
    NEQ = 272,                     /* NEQ  */
    GT = 273,                      /* GT  */
    LT = 274,                      /* LT  */
    GTEQ = 275,                    /* GTEQ  */
    LTEQ = 276,                    /* LTEQ  */
    LSHIFT = 277,                  /* LSHIFT  */
    RSHIFT = 278,                  /* RSHIFT  */
    PLUS = 279,                    /* PLUS  */
    MINUS = 280,                   /* MINUS  */
    MULT = 281,                    /* MULT  */
    DIV = 282,                     /* DIV  */
    MOD = 283,                     /* MOD  */
    POW = 284,                     /* POW  */
    LNOT = 285,                    /* LNOT  */
    GLOBAL = 286,                  /* GLOBAL  */
    RETURN = 287,                  /* RETURN  */
    UNARY_MINUS = 288,             /* UNARY_MINUS  */
    LPAREN = 289,                  /* LPAREN  */
    RPAREN = 290,                  /* RPAREN  */
    LET = 291,                     /* LET  */
    FUNC = 292,                    /* FUNC  */
    INIT_ARGS = 293,               /* INIT_ARGS  */
    INIT_VAR = 294,                /* INIT_VAR  */
    IF = 295,                      /* IF  */
    ELSE = 296,                    /* ELSE  */
    LBRACK = 297,                  /* LBRACK  */
    RBRACK = 298,                  /* RBRACK  */
    PTV = 299,                     /* PTV  */
    ASSIGN = 300,                  /* ASSIGN  */
    WHILE = 301,                   /* WHILE  */
    FOR = 302,                     /* FOR  */
    TO = 303,                      /* TO  */
    IFELSE = 304,                  /* IFELSE  */
    CREATEVAR = 305,               /* CREATEVAR  */
    CREATEASSIGN = 306,            /* CREATEASSIGN  */
    TYPE = 307,                    /* TYPE  */
    PLUSASS = 308,                 /* PLUSASS  */
    MINUSASS = 309,                /* MINUSASS  */
    MULTASS = 310,                 /* MULTASS  */
    DIVASS = 311                   /* DIVASS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "chinko_bot/dscript/parser.y"

	ast *instr;
	int intval;
	char charval;
	double doubleval;
	char* strval;

#line 141 "chinko_bot/dscript/products/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (yyscan_t scanner, parser_data_t *data);
/* "%code provides" blocks.  */
#line 18 "chinko_bot/dscript/parser.y"

#include <unordered_map>
#include <stdexcept>
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include "std.h"
#include "../../../Var/Var.h"
#include "gramm_funcs.h"

using namespace std;

int yyerror(yyscan_t scanner, parser_data_t *data, const char *s);
extern int yylex(YYSTYPE * yylval_param , yyscan_t yyscanner);

#line 170 "chinko_bot/dscript/products/parser.tab.h"

#endif /* !YY_YY_CHINKO_BOT_DSCRIPT_PRODUCTS_PARSER_TAB_H_INCLUDED  */
