%option header-file = "chinko_bot/dscript/products/lexer.h"
%option outfile     = "chinko_bot/dscript/products/lexer.cpp"
%option reentrant
%option bison-bridge
%option extra-type="parser_data_t*"
%option noyywrap nounput noinput
%{
#include "parser.tab.h"
#include <stdio.h>
#include <string>
#include "../gramm_funcs.h"
#include "../../../Var/Var.h"
using namespace std;
%}


%option noyywrap

/* SEPARATORS */
blanks      [ \t]+
newline		\n
comment		#.*\n
/* INSTRUCTIONS */
ifinst 		if
elseinst	else
whileinst	while
forinst		for
to			to
ret			return
lbrack		\{
rbrack		\}
ptvirg		\;
assign		=
plusass		\+=
minusass	\-=
multass		\*=
divass		\/=
/* TYPES */
tbool		bool
tchar		char
tint8		(byte|int8)
tuint8		(ubyte|uint8)
tint32		(int32|int)
tuint32		(uint32|uint)
tdouble		(double|fp)
tstr		string
let			let
/* EXPRESSIONS */
equal		==
nequal		\!=
gteq		>=
lteq		<=
gt			>
lt			<
plus		\+
minus		\-
mult		\*
div			\/
mod			%
pow			\*\*
lparen		\(
rparen		\)
land		&&
lor			\|\|
lnot		!
bnot		~	
band		&
bor			\|
bxor		\^
lshift		<<
rshift		>>
comma		,
/* IDENTITIES */
ident		[a-zA-Z_][a-zA-Z0-9_]*
real		[0-9]+((\.[0-9]+f?)|f)
naturaldec	[0-9]+
naturalhex	0x[0-9A-Fa-f]+
naturalbin	0b[01]+
charv		'.'
truev		true
falsev		false
strv		\"[^\"]*\"


%%

{blanks}	{ /* ignore */ }
{newline}	{ yyextra->nline++; }
{comment}	{ yyextra->nline++; }
{real}		{ yylval->doubleval = atof(yytext); return(REAL); }
{naturaldec} { yylval->intval = atoi(yytext); return(NATURAL); }
{naturalhex} { yylval->intval = strtol(yytext+2, NULL, 16); return(NATURAL); }
{naturalbin} { yylval->intval = strtol(yytext+2, NULL, 2); return(NATURAL); }
{charv}		{ yylval->intval = *((char*)yytext+1); return(CHARACT); }
{strv}		{ yylval->strval = (char*)malloc(strlen(yytext)+1); strcpy(yylval->strval, yytext); return(STR); }
{truev}		{ return(TRUE); }
{falsev}	{ return(FALSE); }
{ifinst}	{ return(IF); }
{elseinst}	{ return(ELSE); }
{whileinst}	{ return(WHILE); }
{forinst}	{ return(FOR); }
{to}		{ return(TO); }
{ret}		{ return(RETURN); }
{let}		{ return(LET); }
{tbool}		{ return(TBOOL); }
{tchar}		{ return(TCHAR); }
{tint8}		{ return(TINT8); }
{tuint8}	{ return(TUINT8); }
{tint32}	{ return(TINT32); }
{tuint32}	{ return(TUINT32); }
{tdouble}	{ return(TDOUBLE); }
{tstr}		{ return(TSTR); }
{equal}		{ return(EQ); }
{nequal}	{ return(NEQ); }
{gt}		{ return(GT); }
{lt}		{ return(LT); }
{gteq}		{ return(GTEQ); }
{lteq}		{ return(LTEQ); }
{plus}		{ return(PLUS); }
{minus}		{ return(MINUS); }
{mult}		{ return(MULT); }
{div}		{ return(DIV); }
{mod}		{ return(MOD); }
{pow}		{ return(POW); }
{lparen}	{ return(LPAREN); }
{rparen}	{ return(RPAREN); }
{land}		{ return(LAND); }
{lor}		{ return(LOR); }
{lnot}		{ return(LNOT); }
{bnot}		{ return(BNOT); }
{band}		{ return(BAND); }
{bor}		{ return(BOR); }
{bxor}		{ return(BXOR); }
{lshift}	{ return(LSHIFT); }
{rshift}	{ return(RSHIFT); }
{lbrack}	{ return(LBRACK); }
{rbrack}	{ return(RBRACK); }
{assign}	{ return(ASSIGN); }
{plusass}	{ return(PLUSASS); }
{minusass}	{ return(MINUSASS); }
{multass}	{ return(MULTASS); }
{divass}	{ return(DIVASS); }
{ptvirg}	{ return(PTV); }
{comma}		{ return(COMMA); }
{ident}		{ yylval->strval = (char*)malloc(strlen(yytext)+1); strcpy(yylval->strval, yytext); return(IDENT); }
