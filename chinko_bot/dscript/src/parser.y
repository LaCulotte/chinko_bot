// c'est plus compliqué que prevu parce que je dois faire un ast et ensuite le parcourir au lieu de juste utiliser bison/flex
// du coup je suis en train de faire les variables là, à voir si je store un ID (int) ou leur nom complet (std::string ou String) ?
// d'ailleurs quid de la différence entre std::string et String ? Ce mélange de C et C++ est n'importe quoi
// bref bon courage



%require "3.2"
%{
#include <unordered_map>
#include <stdio.h>
#include <iostream>
#include <string>
extern std::unordered_map<std::string, void*> variables;
int yylex();
int yyerror(const char *s);
int error;
extern int nline;
extern int nvar;
%}

%code requires{
#include "../includes/gramm_funcs.h"
extern listvar *vars;
void execute(ast *x);
}

%union {
	ast *instr;
	int intval;
	float floatval;
	char *nameval;
}

%token NATURAL REAL
%left EQ NEQ GT LT GTEQ LTEQ
%left PLUS MINUS
%left MULT DIV
%token LPAREN RPAREN IF ELSE LBRACK RBRACK IDENT PTV PRINT ASSIGN
%type <instr> Program Sequence Instruction Expression Ops Paren Nat Var
%type <intval> NATURAL
%type <nameval> IDENT
%type <floatval> REAL
%start Program

%%

Program:		Sequence							{ execute($1); }

Sequence:		Instruction Sequence				{ $$ = seq($1, $2); }
		|		Instruction							{ $$ = $1; }

Instruction:	IF Expression LBRACK Sequence RBRACK{ $$ = ifinst($2, $4); }
		|		IF Expression LBRACK Sequence RBRACK ELSE LBRACK Sequence RBRACK	{ $$ = ifelseinst($2, $4, $8); }
		|		Var ASSIGN Expression PTV			{ $$ = assignment($1, $3); }
		|		PRINT Expression PTV				{ $$ = print($2); }

Expression:		Nat | Var | Ops | Paren				{ $$ = $1; }
Ops:			Expression EQ Expression			{ $$ = binary_operator($1, $3, EQ); }
		|		Expression NEQ Expression			{ $$ = binary_operator($1, $3, NEQ); }
		|		Expression GT Expression			{ $$ = binary_operator($1, $3, GT); }
		|		Expression LT Expression			{ $$ = binary_operator($1, $3, LT); }
		|		Expression GTEQ Expression			{ $$ = binary_operator($1, $3, GTEQ); }
		|		Expression LTEQ Expression			{ $$ = binary_operator($1, $3, LTEQ); }
		|		Expression PLUS Expression			{ $$ = binary_operator($1, $3, PLUS); }
		|		Expression MINUS Expression			{ $$ = binary_operator($1, $3, MINUS); }
		|		Expression MULT Expression			{ $$ = binary_operator($1, $3, MULT); }
		|		Expression DIV Expression			{ $$ = binary_operator($1, $3, DIV); }
Paren:			LPAREN Expression RPAREN			{ $$ = $2; }
Nat:			NATURAL								{ $$ = loadnatural($1); }
Var:			IDENT								{ $$ = loadvar($1); }

%%

int yyerror(const char *s) {
    printf("Error on line %d : %s\n", nline, s);
    return 0;
}

int dscript(const char *file) {
	std::unordered_map<std::string, sp<IVar>> variables{{"x", 42}, {"test", 9}, {"var", 3}};
	// std::shared_ptr<Var<double>> variable1 = std::make_shared<Var<int>>(8);
	// std::shared_ptr<Var<int>> variable2 = std::make_shared<Var<int>>(4);
	// vérifier que deux var n'ont pas le même nom.
	// variables.insert({{"namevar1", variable1}, {"namevar2", variable2}});
	// variables.find("namevar1");
	// variable1->getType()==INT8 (un enum à check sur IVar.h);
	// l'addition de 2 *sp est un sp.




	freopen(file, "r", stdin);
	error = 0;
	vars = NULL;
    yyparse();
    listvar *current = vars;
    listvar *nextv = NULL;
    while(current) {
    	nextv = current->next;
    	free(current->varname);
    	free(current);
    	current = nextv;
    }
    return error;
}

void execute(ast *x) {
	printf("\n  %u\n", x->token);
	if(x->fst_child) {
		printf("CHD : ");
		execute(x->fst_child);
		printf(" RET");
	}
	if(x->next_sibling) {
		printf("SIB : ");
		execute(x->next_sibling);
		printf(" RET");
	}
}
