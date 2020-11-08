/* A Bison parser, made by GNU Bison 3.7.  */

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
#line 18 "chinko_bot/dscript/parser.y"

#include "parser.h"

#line 53 "chinko_bot/dscript/products/parser.tab.h"

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
    TBOOL = 262,                   /* TBOOL  */
    TCHAR = 263,                   /* TCHAR  */
    TINT8 = 264,                   /* TINT8  */
    TUINT8 = 265,                  /* TUINT8  */
    TINT32 = 266,                  /* TINT32  */
    TUINT32 = 267,                 /* TUINT32  */
    TDOUBLE = 268,                 /* TDOUBLE  */
    TSTR = 269,                    /* TSTR  */
    TRUE = 270,                    /* TRUE  */
    FALSE = 271,                   /* FALSE  */
    IDENT = 272,                   /* IDENT  */
    COMMA = 273,                   /* COMMA  */
    LOR = 274,                     /* LOR  */
    LAND = 275,                    /* LAND  */
    BOR = 276,                     /* BOR  */
    BXOR = 277,                    /* BXOR  */
    BAND = 278,                    /* BAND  */
    EQ = 279,                      /* EQ  */
    NEQ = 280,                     /* NEQ  */
    GT = 281,                      /* GT  */
    LT = 282,                      /* LT  */
    GTEQ = 283,                    /* GTEQ  */
    LTEQ = 284,                    /* LTEQ  */
    LSHIFT = 285,                  /* LSHIFT  */
    RSHIFT = 286,                  /* RSHIFT  */
    PLUS = 287,                    /* PLUS  */
    MINUS = 288,                   /* MINUS  */
    MULT = 289,                    /* MULT  */
    DIV = 290,                     /* DIV  */
    MOD = 291,                     /* MOD  */
    POW = 292,                     /* POW  */
    LNOT = 293,                    /* LNOT  */
    BNOT = 294,                    /* BNOT  */
    UNARY_MINUS = 295,             /* UNARY_MINUS  */
    LPAREN = 296,                  /* LPAREN  */
    RPAREN = 297,                  /* RPAREN  */
    LET = 298,                     /* LET  */
    FUNC = 299,                    /* FUNC  */
    INIT_ARGS = 300,               /* INIT_ARGS  */
    INIT_FUNC = 301,               /* INIT_FUNC  */
    IF = 302,                      /* IF  */
    ELSE = 303,                    /* ELSE  */
    LBRACK = 304,                  /* LBRACK  */
    RBRACK = 305,                  /* RBRACK  */
    PTV = 306,                     /* PTV  */
    ASSIGN = 307,                  /* ASSIGN  */
    WHILE = 308,                   /* WHILE  */
    FOR = 309,                     /* FOR  */
    TO = 310,                      /* TO  */
    IFELSE = 311,                  /* IFELSE  */
    CREATEVAR = 312,               /* CREATEVAR  */
    CREATEASSIGN = 313,            /* CREATEASSIGN  */
    TYPE = 314,                    /* TYPE  */
    PLUSASS = 315,                 /* PLUSASS  */
    MINUSASS = 316,                /* MINUSASS  */
    MULTASS = 317,                 /* MULTASS  */
    DIVASS = 318                   /* DIVASS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "chinko_bot/dscript/parser.y"

	ast *instr;
	int intval;
	double doubleval;
	char* strval;

#line 140 "chinko_bot/dscript/products/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CHINKO_BOT_DSCRIPT_PRODUCTS_PARSER_TAB_H_INCLUDED  */
