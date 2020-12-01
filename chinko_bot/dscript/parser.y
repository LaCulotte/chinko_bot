%require "3.2"
%define api.pure full
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
%parse-param { parser_data_t *data }

%code requires{
#include "parser.h"
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

typedef union YYSTYPE YYSTYPE;
int yyerror(yyscan_t scanner, parser_data_t *data, const char *s);
extern int yylex(YYSTYPE * yylval_param , yyscan_t yyscanner);
}

%{
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
%}


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
%token RETURN UNARY_MINUS LPAREN RPAREN LET FUNC INIT_ARGS IF ELSE LBRACK RBRACK PTV ASSIGN WHILE FOR TO IFELSE CREATEVAR CREATEASSIGN TYPE PLUSASS MINUSASS MULTASS DIVASS
%type <instr> Program Sequence Instruction Expression Ops Paren Nat Real Char Bool Str Var Assignment Functions Args ArgsRec
%type <intval> NATURAL CHARACT Type
%type <strval> IDENT STR
%type <doubleval> REAL
%start Program

%%

// TODO :
//			- Enlever typage fort (donc enlever le type byte)
//			- Il n'y a pas d'analyse paresseuse des expressions booléennes...
//			- tableaux
//			- pouvoir appeler un script



Program:		Functions							{ execute(data, $1); }

Functions:		Sequence							{ $$ = $1; }
		|		Functions LET IDENT LPAREN Args RPAREN LBRACK Sequence RBRACK { declarefunc(data, $3, $5, $8); $$ = $1; }

Args:			Type Var ArgsRec					{ $$ = seq(createvar(data, $1, $2), $3); }
		|		%empty								{ $$ = NULL; }

ArgsRec:		COMMA Type Var ArgsRec				{ $$ = seq(createvar(data, $2, $3), $4); }
		|		%empty								{ $$ = NULL; }

Sequence:		Instruction Sequence				{ $$ = seq($1, $2); }
		|		Instruction							{ $$ = $1; }
		|		%empty								{ $$ = NULL; }

Instruction:	IF Expression LBRACK Sequence RBRACK{ $$ = ifinst(data, $2, $4); }
		|		IF Expression LBRACK Sequence RBRACK ELSE LBRACK Sequence RBRACK	{ $$ = ifelseinst(data, $2, $4, $8); }
		|		WHILE Expression LBRACK Sequence RBRACK								{ $$ = whileinst(data, $2, $4); }
		|		FOR Assignment TO Expression LBRACK Sequence RBRACK					{ $$ = forinst(data, $2, $4, $6); }
		|		Assignment PTV						{ $$ = $1; }
		|		IDENT LPAREN Expression RPAREN PTV	{ $$ = loadfunction(data, $1, $3); }
		|		IDENT LPAREN RPAREN PTV				{ $$ = loadfunction(data, $1, NULL); }
		|		RETURN Expression PTV				{ $$ = unary_operator(data, $2, RETURN); }

Assignment:		Var ASSIGN Expression				{ $$ = assignment(data, $1, $3); }
		|		Var PLUSASS Expression				{ $$ = binary_operator(data, $1, $3, PLUSASS); }
		|		Var MINUSASS Expression				{ $$ = binary_operator(data, $1, $3, MINUSASS); }
		|		Var MULTASS Expression				{ $$ = binary_operator(data, $1, $3, MULTASS); }
		|		Var DIVASS Expression				{ $$ = binary_operator(data, $1, $3, DIVASS); }
		|		Type Var ASSIGN Expression			{ $$ = create_assign(data, $1, $2, $4); }
		|		Type Var							{ $$ = createvar(data, $1, $2); }

Type:			TBOOL 								{ $$ = BOOL; }
		|		TCHAR								{ $$ = CHAR; }
		|		TINT8								{ $$ = INT8; }
		|		TUINT8								{ $$ = UINT8; }
		|		TINT32								{ $$ = INT32; }
		|		TUINT32								{ $$ = UINT32; }
		|		TDOUBLE								{ $$ = DOUBLE; }
		|		TSTR								{ $$ = STRING; }

Expression:		Nat | Real | Char | Bool | Str | Var | Ops | Paren	{ $$ = $1; }
Ops:			Expression EQ Expression			{ $$ = binary_operator(data, $1, $3, EQ); }
		|		Expression NEQ Expression			{ $$ = binary_operator(data, $1, $3, NEQ); }
		|		Expression GT Expression			{ $$ = binary_operator(data, $1, $3, GT); }
		|		Expression LT Expression			{ $$ = binary_operator(data, $1, $3, LT); }
		|		Expression GTEQ Expression			{ $$ = binary_operator(data, $1, $3, GTEQ); }
		|		Expression LTEQ Expression			{ $$ = binary_operator(data, $1, $3, LTEQ); }
		|		Expression PLUS Expression			{ $$ = binary_operator(data, $1, $3, PLUS); }
		|		Expression MINUS Expression			{ $$ = binary_operator(data, $1, $3, MINUS); }
		|		Expression MULT Expression			{ $$ = binary_operator(data, $1, $3, MULT); }
		|		Expression DIV Expression			{ $$ = binary_operator(data, $1, $3, DIV); }
		|		Expression MOD Expression			{ $$ = binary_operator(data, $1, $3, MOD); }
		|		Expression POW Expression			{ $$ = binary_operator(data, $1, $3, POW); }
		|		Expression LAND Expression			{ $$ = binary_operator(data, $1, $3, LAND); }
		|		Expression LOR Expression			{ $$ = binary_operator(data, $1, $3, LOR); }
		|		Expression BAND Expression			{ $$ = binary_operator(data, $1, $3, BAND); }
		|		Expression BXOR Expression			{ $$ = binary_operator(data, $1, $3, BXOR); }
		|		Expression BOR Expression			{ $$ = binary_operator(data, $1, $3, BOR); }
		|		Expression LSHIFT Expression		{ $$ = binary_operator(data, $1, $3, LSHIFT); }
		|		Expression RSHIFT Expression		{ $$ = binary_operator(data, $1, $3, RSHIFT); }
		|		Expression COMMA Expression			{ $$ = binary_operator(data, $1, $3, COMMA); }
		|		LNOT Expression						{ $$ = unary_operator(data, $2, LNOT); }
		|		BNOT Expression						{ $$ = unary_operator(data, $2, BNOT); }
		|		MINUS Expression					{ $$ = unary_operator(data, $2, UNARY_MINUS); }
		|		IDENT LPAREN Expression RPAREN		{ $$ = loadfunction(data, $1, $3); }
		|		IDENT LPAREN RPAREN					{ $$ = loadfunction(data, $1, NULL); }

Paren:			LPAREN Expression RPAREN			{ $$ = $2; }
Nat:			NATURAL								{ $$ = loadnatural(data, $1); }
Real:			REAL								{ $$ = loadreal(data, $1); }
Char:			CHARACT								{ $$ = loadnatural(data, $1); }
Bool:			TRUE								{ $$ = loadnatural(data, 1); }
		|		FALSE								{ $$ = loadnatural(data, 0); }
Str:			STR									{ $$ = loadstr(data, $1); }
Var:			IDENT								{ $$ = loadvar(data, $1); }

%%

#include "products/parser.tab.h"
#include "products/lexer.h"


void throw_exception(const string err, int nl) {
	string error;
	if(nl>0)
		error = "Error on line "+to_string(nl)+": "+err;
	else
		error = "Error: "+err;
	throw runtime_error(error);
}

int yyerror(yyscan_t scanner, parser_data_t *data, const char *s) {
	throw_exception(string(s), data->nline);
}


void dscript_cmd(const char *code, bool *stop) {
	ctx_vars_t glob_ctx = {};
	glob_ctx.variables = {};

	parser_data_t data = {};
	data.nline = 1;
	data.fst_el = NULL;
	data.ctx = &glob_ctx;
	data.stop = stop;
	initstd(&data);

	yyscan_t scanner;
	if(yylex_init(&scanner)) {
		throw runtime_error("Error while initializing the parser.");
	}
	yylex_init_extra(&data, &scanner);
	YY_BUFFER_STATE buf = yy_scan_string(code, scanner);
	try {
		yyparse(scanner, &data);
	} catch(const exception& e) {
		yy_delete_buffer(buf, scanner);
		yylex_destroy(scanner);
		free_list(data.fst_el);
		// SI TU VEUX CHANGER LA MANIÈRE DONT SONT GÉRÉES LES EXCEPTIONS C'EST ICI...
		throw runtime_error(e.what());
	}
	yy_delete_buffer(buf, scanner);
	yylex_destroy(scanner);
	free_list(data.fst_el);
}

void dscript(const char *file, bool *stop) {
	FILE *fp = fopen(file, "r");
	fseek(fp, 0L, SEEK_END);
	size_t size = ftell(fp);
	rewind(fp);
	char code[size+1];
	
	fread(code, 1, size, fp);
	code[size] = 0x0;
	try {
		dscript_cmd(code, stop);
	} catch(const exception& e) {
		fclose(fp);
		// ...ET ICI
		throw runtime_error(e.what());
	}
	
	fclose(fp);
}


void free_list(el_alloced_t *list) {
	el_alloced_t *cur = list;
	while(cur!=NULL) {
		el_alloced_t *tmp = cur->next;
		if(cur->type==0)
			free(cur->el);
		else
			delete (string*)cur->el;
		free(cur);
		cur = tmp;
	}
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


void execute(parser_data_t *data, ast *x) {
	cout << endl;
	disp_recur(x, 0);
	cout << endl;
	run(data, x, true);
}


void parse_params(parser_data_t *data, vector<sp<IVar>> *dst, ast *ast) {
	if(ast->token == COMMA) {
		dst->insert(dst->begin(), parse_expr(data, ast->fst_child->next_sibling));
		parse_params(data, dst, ast->fst_child);
	} else
		dst->insert(dst->begin(), parse_expr(data, ast));
}


sp<IVar> parse_expr(parser_data_t *data, ast *ast) {
	/* CHECKING TYPES COMPATIBILITY */
	sp<IVar> expr1;
	sp<IVar> expr2;
	if(ast->fst_child != NULL && ast->token != FUNC) {
		expr1 = parse_expr(data, ast->fst_child);
		if(ast->token != COMMA && ast->fst_child->next_sibling != NULL) {
			expr2 = parse_expr(data, ast->fst_child->next_sibling);
			watchdog_type(expr1->get_type(), expr2->get_type(), ast);
		}
	}

	switch(ast->token) {
		case COMMA:
			throw_exception("syntax error ','", ast->nline);
		case FUNC: {
			sp<IVar> ret = runfunc(data, *ast->strvalue, ast);
			if(ret==NULL)
				throw_exception("void function in expression", ast->nline);
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
			return *ZERO - *parse_expr(data, ast->fst_child);
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
			ctx_vars_t *ctx = find_ctx(data, varname, ast->nline);
			return ctx->variables.at(varname);
	}
	return 0;
}

ctx_vars_t *find_ctx(parser_data_t *data, string varname, int nline) {
	/**
	 * @returns the context structure from which varname belongs
	 * @throws an error if this context does not exist
	 */
	ctx_vars_t *cur_ctx = data->ctx;
	while(cur_ctx != NULL) {
		if(cur_ctx->variables.find(varname) != cur_ctx->variables.end())
			return cur_ctx;
		cur_ctx = cur_ctx->parent;
	}
	throw_exception("unknown variable!", nline);
}


sp<IVar> run(parser_data_t *data, ast *ast, bool recur) {
	if(data->stop != NULL)
		while(*data->stop) {}
	if(ast==NULL)
		return NULL;
	switch(ast->token) {
		case IF:
			if(parse_expr(data, ast->fst_child))
				run(data, ast->fst_child->next_sibling, true);
			break;
		case IFELSE:
			if(parse_expr(data, ast->fst_child))
				run(data, ast->fst_child->next_sibling->fst_child, true);
			else
				run(data, ast->fst_child->next_sibling->next_sibling->fst_child, true);
			break;
		case WHILE:
			while(*(bool*)(*parse_expr(data, ast->fst_child)).value)
				run(data, ast->fst_child->next_sibling, true);
			break;
		case FOR: {
			run(data, ast->fst_child, false);
			string varname = *ast->fst_child->next_sibling->fst_child->strvalue;
			const IVar ONE = Var<int>(1);
			while(*(bool*)(*parse_expr(data, ast->fst_child->next_sibling)).value) {
				run(data, ast->fst_child->next_sibling->next_sibling, true);
				data->ctx->variables.at(varname) = cast_type(data->ctx->variables.at(varname)->get_type(), *data->ctx->variables.at(varname)+ONE);
			}
			break;
		} case CREATEVAR: {
			string varname = *ast->fst_child->next_sibling->strvalue;
			if(data->ctx->variables.find(varname) != data->ctx->variables.end()) // on ne cherche que dans l'actuel contexte car s'il y a conflit, c'est la variable qui est dans le contexte le plus proche qui est utilisée
				throw_exception("variable initialized twice!", ast->nline);
			const sp<IVar> ZERO = cast_type(ast->fst_child->intvalue, make_shared<Var<int>>(0));
			data->ctx->variables.insert({varname, ZERO});
			break;
		} case CREATEASSIGN: {
			string varname = *ast->fst_child->next_sibling->strvalue;
			if(data->ctx->variables.find(varname) != data->ctx->variables.end())
				throw_exception("variable initialized twice!", ast->nline);
			sp<IVar> val = cast_type(ast->fst_child->intvalue, parse_expr(data, ast->fst_child->next_sibling->next_sibling));
			data->ctx->variables.insert({varname, val});
			break;
		} case ASSIGN: {
			string varname = *ast->fst_child->strvalue;
			ctx_vars_t *ctx = find_ctx(data, varname, ast->nline);
			sp<IVar> val = cast_type(ctx->variables.at(varname)->get_type(), parse_expr(data, ast->fst_child->next_sibling));
			ctx->variables.at(varname) = val;
			break;
		}
		case PLUSASS:
		case MINUSASS:
		case MULTASS:
		case DIVASS: {
			string varname = *ast->fst_child->strvalue;
			ctx_vars_t *ctx = find_ctx(data, varname, ast->nline);
			const sp<IVar> expr = parse_expr(data, ast->fst_child->next_sibling);
			watchdog_type(ctx->variables.at(varname)->get_type(), expr->get_type(), ast);
			sp<IVar> val;
			if(ast->token==PLUSASS)
				val = *ctx->variables.at(varname) + *expr;
			else if(ast->token==MINUSASS)
				val = *ctx->variables.at(varname) - *expr;
			else if(ast->token==MULTASS)
				val = *ctx->variables.at(varname) * *expr;
			else if(ast->token==DIVASS)
				val = *ctx->variables.at(varname) / *expr;
			
			ctx->variables.at(varname) = cast_type(ctx->variables.at(varname)->get_type(), val);
			break;
		} case FUNC: {
			runfunc(data, *ast->strvalue, ast);
			break;
		} case RETURN:
			return parse_expr(data, ast->fst_child);
			break;
		default:
			throw_exception("unrecognized token!", ast->nline);
	}
	if(recur)
		return run(data, ast->next_sibling, true);
	return NULL;
}


sp<IVar> runfunc(parser_data_t *data, string funcname, ast *node) {
	vector<sp<IVar>> params{};
	if(node->fst_child!=NULL)
		parse_params(data, &params, node->fst_child);

	if(data->stdfuncs.find(funcname) != data->stdfuncs.end())
		return data->stdfuncs[funcname](params);

	if(data->usrfuncs.find(funcname) != data->usrfuncs.end()) {
		cout << "FONCTION!!" << endl;


		ctx_vars_t child_ctx = {};
		child_ctx.variables = {};
		// Adding argument variables
		ast *curvar;
		curvar = data->usrfuncs[funcname]->fst_child;
		int i=0;
		while(curvar != NULL) {
			sp<IVar> val = cast_type(curvar->fst_child->intvalue, params[i]);
			string varname = *curvar->fst_child->next_sibling->strvalue;
			if(child_ctx.variables.find(varname) != data->ctx->variables.end())
				throw_exception("name used for two different arguments", data->usrfuncs[funcname]->nline);
			child_ctx.variables.insert({varname, val});
			curvar = curvar->next_sibling;
			i++;
		}

		// switching context
		ctx_vars_t *old_ctx = data->ctx;
		child_ctx.parent = old_ctx;
		data->ctx = &child_ctx;


		sp<IVar> retval = run(data, data->usrfuncs[funcname]->next_sibling, true);
		
		data->ctx = old_ctx;
		return retval;
	}

	throw_exception("function not found...", node->nline);
}


bool castable(int type1, int type2) {
	return (type1!=STRING && type2!=STRING) || type1==type2;
}


sp<IVar> cast_type(int type, sp<IVar> value) {
	if(!castable(type, value->get_type()))
		throw_exception("invalid types!", 0);
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
	const int nl = op->nline;
	if(typesrc==STRING && op->token!=PLUS && op->token!=PLUSASS)
		throw_exception("operation undefined for string objects.", nl);
	if((typedst==STRING && typesrc!=STRING) || (typedst!=STRING && typesrc==STRING))
		throw_exception("cannot convert STRING to a canonical type!", nl);
}
