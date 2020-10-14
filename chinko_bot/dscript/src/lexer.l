%{
#include "parser.h"
#include <stdio.h>
#include <string>
#include "../includes/gramm_funcs.h"
int nline = 1;
int nvar = 0;
listvar *vars;
%}

%option noyywrap

blanks      [ \t]+
newline		\n
ifinst 		(if)
elseinst	(else)
lbrack		\{
rbrack		\}
equal		==
nequal		\!=
gteq		>=
lteq		<=
gt			>
lt			<
assign		=
plus		\+
minus		\-
mult		\*
div			\\
lparen		\(
rparen		\)
print		print
ident		[a-zA-Z_][a-zA-Z0-9_]*
real		[0-9]+\.[0-9]+
natural		[0-9]+
ptvirg		\;


%%

{blanks}	{ /* ignore */ }
{newline}	{ nline++; }
{real}		{ yylval.floatval = atof(yytext); return(REAL); }
{natural}	{ yylval.intval = atoi(yytext); return(NATURAL); }
{ifinst}	{ return(IF); }
{elseinst}	{ return(ELSE); }
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
{lparen}	{ return(LPAREN); }
{rparen}	{ return(RPAREN); }
{lbrack}	{ return(LBRACK); }
{rbrack}	{ return(RBRACK); }
{assign}	{ return(ASSIGN); }
{print}		{ return(PRINT); }
{ptvirg}	{ return(PTV); }
{ident}		{
				char *name = (char*)malloc(strlen(yytext)+1);
				strncpy(name, yytext, 128);
				yylval.nameval = name;
				// looking for yytext in the vars list
				// listvar *current = vars;
				// listvar *prev = NULL;
				// int numvar = 0;
				// while(current) {
				// 	if(!strcmp(current->varname, yytext)) {
				// 		yylval.intval = numvar;
				// 		break;
				// 	}
				// 	numvar++;
				// 	prev = current;
				// 	current = current->next;
				// }
				// if(!current) { // if not found...
				// 	yylval.intval = nvar++;
				// 	current = (listvar*)malloc(sizeof(listvar));
				// 	current->next = NULL;
				// 	current->varname = (char*)malloc(strlen(yytext)+1);
				// 	strcpy(current->varname, yytext);
				// 	if(prev)
				// 		prev->next = current;
				// 	else
				// 		vars = current;
				// }
				return(IDENT);
			}
