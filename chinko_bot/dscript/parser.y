%require "3.2"
%{
#include <unordered_map>
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include "std.h"
#include "../../../Var/Var.h"

using namespace std; 
int error;
extern int nline;
extern unordered_map<string, stdf> stdfuncs;
unordered_map<string, sp<IVar>> variables;
%}

%code requires{
#include "parser.h"
}

%union {
	ast *instr;
	int intval;
	double doubleval;
	char* strval;
}

%token NATURAL REAL CHARACT STR TBOOL TCHAR TINT8 TUINT8 TINT32 TUINT32 TDOUBLE TSTR TRUE FALSE IDENT
%left COMMA
%left LOR
%left LAND
%left BOR
%left BXOR
%left BAND
%left EQ NEQ
%left GT LT GTEQ LTEQ
%left LSHIFT RSHIFT
%left PLUS MINUS
%left MULT DIV MOD
%right POW
%token LNOT BNOT
%token UNARY_MINUS LPAREN RPAREN LET FUNC INIT_ARGS INIT_FUNC IF ELSE LBRACK RBRACK PTV ASSIGN WHILE FOR TO IFELSE CREATEVAR CREATEASSIGN TYPE PLUSASS MINUSASS MULTASS DIVASS
%type <instr> Program Sequence Instruction Expression Ops Paren Nat Real Char Bool Str Var Assignment Functions Args ArgsRec
%type <intval> NATURAL CHARACT Type
%type <strval> IDENT STR
%type <doubleval> REAL
%start Program

%%

// TODO : 	- Fonctions personnelles ?
//			- Demander à Chriggz de faire en sorte que char+int = char (dans un print par exemple) : quioque, je crois que c'est juste qu'un char est mal affiché dans un print
//			- Discuter avec Chriggz du fait de ne garder que 1 type de var parmi (u)int8_t et (u)int32_t
//					-> en effet ce qu'on veut faire un langage haut niveau très simple, et ça simplifierait le langage
//			- Changer les malloc en make_shared (notamment dans new_ast())
//			- Il n'y a pas d'analyse paresseuse des expressions booléennes...


// CURRENT : NORMALEMENT ÇA DEVRAIT MARCHER MAIS LES FONCTIONS ACCEPTANT STRCIT PLUS DE 2 ARGS FONT PLANTER


Program:		Functions							{ execute($1); }

Functions:		Sequence							{ $$ = $1; }
		|		Functions LET IDENT LPAREN Args RPAREN LBRACK Sequence RBRACK { $$ = declarefunc($3, $5, $8); }

Args:			ArgsRec Type Var					{ $$ = seq(createvar($2, $3), $1); }
		|		%empty								{ $$ = NULL; }

ArgsRec:		ArgsRec Type Var COMMA				{ $$ = seq(createvar($2, $3), $1); }
		|		%empty								{ $$ = NULL; }

Sequence:		Instruction Sequence				{ $$ = seq($1, $2); }
		|		Instruction							{ $$ = $1; }
		|		%empty								{ $$ = NULL; }

Instruction:	IF Expression LBRACK Sequence RBRACK{ $$ = ifinst($2, $4); }
		|		IF Expression LBRACK Sequence RBRACK ELSE LBRACK Sequence RBRACK	{ $$ = ifelseinst($2, $4, $8); }
		|		WHILE Expression LBRACK Sequence RBRACK								{ $$ = whileinst($2, $4); }
		|		FOR Assignment TO Expression LBRACK Sequence RBRACK					{ $$ = forinst($2, $4, $6); }
		|		Assignment PTV						{ $$ = $1; }
		|		Expression PTV						{ /* Do nothing */ }

Assignment:		Var ASSIGN Expression				{ $$ = assignment($1, $3); }
		|		Var PLUSASS Expression				{ $$ = binary_operator($1, $3, PLUSASS); }
		|		Var MINUSASS Expression				{ $$ = binary_operator($1, $3, MINUSASS); }
		|		Var MULTASS Expression				{ $$ = binary_operator($1, $3, MULTASS); }
		|		Var DIVASS Expression				{ $$ = binary_operator($1, $3, DIVASS); }
		|		Type Var ASSIGN Expression			{ $$ = create_assign($1, $2, $4); }
		|		Type Var							{ $$ = createvar($1, $2); }

Type:			TBOOL 								{ $$ = BOOL; }
		|		TCHAR								{ $$ = CHAR; }
		|		TINT8								{ $$ = INT8; }
		|		TUINT8								{ $$ = UINT8; }
		|		TINT32								{ $$ = INT32; }
		|		TUINT32								{ $$ = UINT32; }
		|		TDOUBLE								{ $$ = DOUBLE; }
		|		TSTR								{ $$ = STRING; }

Expression:		Nat | Real | Char | Bool | Str | Var | Ops | Paren	{ $$ = $1; }
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
		|		Expression MOD Expression			{ $$ = binary_operator($1, $3, MOD); }
		|		Expression POW Expression			{ $$ = binary_operator($1, $3, POW); }
		|		Expression LAND Expression			{ $$ = binary_operator($1, $3, LAND); }
		|		Expression LOR Expression			{ $$ = binary_operator($1, $3, LOR); }
		|		Expression BAND Expression			{ $$ = binary_operator($1, $3, BAND); }
		|		Expression BXOR Expression			{ $$ = binary_operator($1, $3, BXOR); }
		|		Expression BOR Expression			{ $$ = binary_operator($1, $3, BOR); }
		|		Expression LSHIFT Expression		{ $$ = binary_operator($1, $3, LSHIFT); }
		|		Expression RSHIFT Expression		{ $$ = binary_operator($1, $3, RSHIFT); }
		|		Expression COMMA Expression			{ $$ = binary_operator($1, $3, COMMA); }
		|		LNOT Expression						{ $$ = unary_operator($2, LNOT); }
		|		BNOT Expression						{ $$ = unary_operator($2, BNOT); }
		|		MINUS Expression					{ $$ = unary_operator($2, UNARY_MINUS); }
		|		IDENT LPAREN Expression RPAREN		{ $$ = loadfunction($1, $3); }
		|		IDENT LPAREN RPAREN					{ $$ = loadfunction($1, NULL); }

Paren:			LPAREN Expression RPAREN			{ $$ = $2; }
Nat:			NATURAL								{ $$ = loadnatural($1); }
Real:			REAL								{ $$ = loadreal($1); }
Char:			CHARACT								{ $$ = loadnatural($1); }
Bool:			TRUE								{ $$ = loadnatural(1); }
		|		FALSE								{ $$ = loadnatural(0); }
Str:			STR									{ $$ = loadstr($1); }
Var:			IDENT								{ $$ = loadvar($1); }

%%

int yyerror(const char *s) {
	printf("Error on line %d : %s\n", nline, s);
	return 0;
}


int dscript(const char *file) {
	//unordered_map<string, sp<IVar>> variables{{"x", 42}, {"test", 9}, {"var", 3}};
	// std::shared_ptr<Var<double>> variable1 = std::make_shared<Var<int>>(8);
	// std::shared_ptr<Var<int>> variable2 = std::make_shared<Var<int>>(4);
	// vérifier que deux var n'ont pas le même nom.
	// variables.insert({{"namevar1", variable1}, {"namevar2", variable2}});
	// variables.find("namevar1");
	// variable1->getType()==INT8 (un enum à check sur IVar.h);
	// l'addition de 2 *sp est un sp.

	variables = {};
	initstd();
	freopen(file, "r", stdin);
	error = 0;
	yyparse();
	return error;
}


void disp_recur(ast *x, int nbsp) {
	for(int i=0; i<nbsp; i++)
		printf(" ");
	switch(x->token) {
		case COMMA:
			printf(",\n");
			break;
		case IFELSE:
			printf("IFELSE\n");
			break;
		case IF:
			printf("IF\n");
			break;
		case ELSE:
			printf("ELSE\n");
			break;
		case WHILE:
			printf("WHILE\n");
			break;
		case FOR:
			printf("FOR\n");
			break;
		case NATURAL:
			cout << x->intvalue << endl;
			break;
		case REAL:
			cout << x->doublevalue << endl;
			break;
		case MULT:
			printf("*\n");
			break;
		case DIV:
			printf("/\n");
			break;
		case EQ:
			printf("==\n");
			break;
		case LT:
			printf("<\n");
			break;
		case ASSIGN:
			printf("=\n");
			break;
		case PLUS:
			printf("+\n");
			break;
		case MINUS:
		case UNARY_MINUS:
			printf("-\n");
			break;
		case FUNC:
			cout << "f ";
		case IDENT:
			cout << *x->strvalue << endl;
			break;
		default:
			printf("%d\n", x->token);

	}
	if(x->fst_child)
		disp_recur(x->fst_child, nbsp+2);
	if(x->next_sibling)
		disp_recur(x->next_sibling, nbsp);
}


void execute(ast *x) {
	printf("\n");
	disp_recur(x, 0);
	printf("\n");
	run(x, true);
}


void parse_params(vector<sp<IVar>> *dst, ast *ast) {
	if(ast->token == COMMA) {
		dst->insert(dst->begin(), parse_expr(ast->fst_child->next_sibling));
		parse_params(dst, ast->fst_child);
	} else
		dst->insert(dst->begin(), parse_expr(ast));
}


sp<IVar> parse_expr(ast *ast) {
	/* CHECKING TYPES COMPATIBILITY */
	sp<IVar> expr1;
	sp<IVar> expr2;
	if(ast->fst_child != NULL && ast->token != FUNC) {
		expr1 = parse_expr(ast->fst_child);
		if(ast->token != COMMA && ast->fst_child->next_sibling != NULL) {
			expr2 = parse_expr(ast->fst_child->next_sibling);
			watchdog_type(expr1->get_type(), expr2->get_type(), ast);
		}
	}

	switch(ast->token) {
		case COMMA:
			printf("Error on line %d : syntax error ','\n", ast->nline);
			exit(-1);
		case FUNC: {
			sp<IVar> ret = runfunc(*ast->strvalue, ast);
			if(ret==NULL) {
				printf("Error on line %d : void function in expression\n", ast->nline);
				exit(-1);
			}
			return ret;
		} case PLUS:
			return *expr1+(*expr2);
		case MINUS:
			return *expr1-(*expr2);
		case MULT:
			return *expr1*(*expr2);
		case DIV:
			return *expr1/(*expr2);
		case MOD:
			return *expr1%(*expr2);
		case POW: {
			vector<sp<IVar>> args = {expr1, expr2};
			return stdpow(args);
		} case UNARY_MINUS: {
			const sp<IVar> ZERO = make_shared<Var<int>>(0);
			return *ZERO - *parse_expr(ast->fst_child);
		} case EQ:
			return make_shared<Var<bool>>(*expr1==(*expr2));
		case LT:
			return make_shared<Var<bool>>(*expr1<(*expr2));
		case GT:
			return make_shared<Var<bool>>(*expr1>(*expr2));
		case LTEQ:
			return make_shared<Var<bool>>(*expr1<=(*expr2));
		case GTEQ:
			return make_shared<Var<bool>>(*expr1>=(*expr2));
		//case LAND:
		//	return *expr1 && (*expr2);
		//case LOR:
		//	return *expr1 || (*expr2);
		//case LNOT:
		//	return !*expr1;
		case BAND:
			return *expr1 & (*expr2);
		case BXOR:
			return *expr1 ^ (*expr2);
		case BOR:
			return *expr1 | (*expr2);
		//case BNOT:
		//	return ~ *expr1;
		case NATURAL:
			return make_shared<Var<uint32_t>>(ast->intvalue);
		case REAL:
			return make_shared<Var<double>>(ast->doublevalue);
		case STR:
			return make_shared<Var<string>>(*ast->strvalue);
		case IDENT:
			string varname = *ast->strvalue;
			if(variables.find(varname) == variables.end()) {
				printf("ERROR ON LINE %d : Unknown variable!\n", ast->nline);
				exit(-1);
			}
			return variables.at(varname);
	}
	return 0;
}


void run(ast *ast, bool recur) {
	if(ast==NULL)
		return;
	switch(ast->token) {
		case IF:
			if(parse_expr(ast->fst_child))
				run(ast->fst_child->next_sibling, true);
			break;
		case IFELSE:
			if(parse_expr(ast->fst_child))
				run(ast->fst_child->next_sibling->fst_child, true);
			else
				run(ast->fst_child->next_sibling->next_sibling->fst_child, true);
			break;
		case WHILE:
			while(*(bool*)(*parse_expr(ast->fst_child)).value)
				run(ast->fst_child->next_sibling, true);
			break;
		case FOR: {
			run(ast->fst_child, false);
			string varname = *ast->fst_child->next_sibling->fst_child->strvalue;
			const IVar ONE = Var<int>(1);
			while(*(bool*)(*parse_expr(ast->fst_child->next_sibling)).value) {
				run(ast->fst_child->next_sibling->next_sibling, true);
				variables.at(varname) = cast_type(variables.at(varname)->get_type(), *variables.at(varname)+ONE);
			}
			break;
		} case CREATEVAR: {
			string varname = *ast->fst_child->next_sibling->strvalue;
			if(variables.find(varname) != variables.end()) {
				printf("ERROR ON LINE %d : Variable initialized twice!\n", ast->nline);
				exit(-1);
			}
			const sp<IVar> ZERO = cast_type(ast->fst_child->intvalue, make_shared<Var<int>>(0));
			variables.insert({varname, ZERO});
			break;
		} case CREATEASSIGN: {
			string varname = *ast->fst_child->next_sibling->strvalue;
			if(variables.find(varname) != variables.end()) {
				printf("ERROR ON LINE %d : Variable initialized twice!\n", ast->nline);
				exit(-1);
			}
			sp<IVar> val = cast_type(ast->fst_child->intvalue, parse_expr(ast->fst_child->next_sibling->next_sibling));
			variables.insert({varname, val});
			break;
		} case ASSIGN: {
			string varname = *ast->fst_child->strvalue;
			if(variables.find(varname) == variables.end()) {
				printf("ERROR ON LINE %d : Unknown variable!\n", ast->nline);
				exit(-1);
			}
			sp<IVar> val = cast_type(variables.at(varname)->get_type(), parse_expr(ast->fst_child->next_sibling));
			variables.at(varname) = val;
			break;
		}
		case PLUSASS:
		case MINUSASS:
		case MULTASS:
		case DIVASS: {
			string varname = *ast->fst_child->strvalue;
			if(variables.find(varname) == variables.end()) {
				printf("ERROR ON LINE %d : Unknown variable!\n", ast->nline);
				exit(-1);
			}
			const sp<IVar> expr = parse_expr(ast->fst_child->next_sibling);
			watchdog_type(variables.at(varname)->get_type(), expr->get_type(), ast);
			sp<IVar> val;
			if(ast->token==PLUSASS)
				val = *variables.at(varname) + *expr;
			else if(ast->token==MINUSASS)
				val = *variables.at(varname) - *expr;
			else if(ast->token==MULTASS)
				val = *variables.at(varname) * *expr;
			else if(ast->token==DIVASS)
				val = *variables.at(varname) / *expr;
			
			variables.at(varname) = cast_type(variables.at(varname)->get_type(), val);
			break;
		} case FUNC: {
			runfunc(*ast->strvalue, ast);
			break;
		} default:
			printf("Unrecognized token %d\n", ast->token);
			break;
	}
	if(recur)
		run(ast->next_sibling, true);
}


sp<IVar> runfunc(string funcname, ast *ast) {
	vector<sp<IVar>> params{};
	if(ast->fst_child!=NULL)
		parse_params(&params, ast->fst_child);

	// for(int i=0; i<params.size(); i++)
	// 	cout << "PARAM: " << *params[i] << endl;

	return stdfuncs[funcname](params);
}


bool castable(int type1, int type2) {
	return (type1!=STRING && type2!=STRING) || type1==type2;
}


sp<IVar> cast_type(int type, sp<IVar> value) {
	if(!castable(type, value->get_type())) {
		cout << "ERR: Conversion from number to string" << endl;
		exit(-1);
	}
	switch(type) {
		case BOOL:
			return make_shared<Var<bool>>(*value);
		case CHAR:
			return make_shared<Var<char>>(*value);
		case INT8:
			return make_shared<Var<int8_t>>(*value);
		case UINT8:
			return make_shared<Var<uint8_t>>(*value);
		case INT32:
			return make_shared<Var<int32_t>>(*value);
		case UINT32:
			return make_shared<Var<uint32_t>>(*value);
		case DOUBLE:
			return make_shared<Var<double>>(*value);
		case STRING:
			return make_shared<Var<string>>(*value);
	}
	return NULL;
}


void watchdog_type(int typedst, int typesrc, ast *op) {
	const int nline = op->nline;
	if(typesrc==STRING && op->token!=PLUS && op->token!=PLUSASS) {
		cout << "ERROR ON LINE " << nline << ": Operation undefined for string objects." << endl;
		exit(-1);
	}
	if((typedst==STRING && typesrc!=STRING) || (typedst!=STRING && typesrc==STRING)) {
		cout << "ERROR ON LINE " << nline << ": Cannont convert STRING to a canonical type!" << endl;
		exit(-1);
	}
}
