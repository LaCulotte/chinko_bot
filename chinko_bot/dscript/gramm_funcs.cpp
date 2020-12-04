/*
	Fonctions directement liées à la création du code asm
	utilisées dans la grammaire de base.y
*/

#include "gramm_funcs.h"
#include "products/parser.tab.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
#include "../../Var/Var.h"
using namespace std;

void throw_exception(const std::string err, int nl);


ast *seq(ast *inst, ast *seq) {
	inst->next_sibling = seq;
	return inst;
}


ast *ifinst(parser_data_t *data, ast *expr, ast *seq) {
	ast *new_ast = new_ast_entry(data, IF, NULL, expr);
	expr->next_sibling = seq;
	return new_ast;
}


ast *ifelseinst(parser_data_t *data, ast *expr, ast *seq1, ast *seq2) {
	ast *else_ast = new_ast_entry(data, ELSE, NULL, seq2);
	ast *if_ast = new_ast_entry(data, IF, else_ast, seq1);
	ast *ifelse_ast = new_ast_entry(data, IFELSE, NULL, expr);
	expr->next_sibling = if_ast;
	return ifelse_ast;
}


ast *whileinst(parser_data_t *data, ast *expr, ast *seq) {
	ast *while_ast = new_ast_entry(data, WHILE, NULL, expr);
	expr->next_sibling = seq;
	return while_ast;
}


ast *forinst(parser_data_t *data, ast *assignment, ast *exprf, ast *seq) {
	ast *var;
	if(assignment->token==CREATEASSIGN)
		var = ast_cpy(data, assignment->fst_child->next_sibling);
	else if(assignment->token==ASSIGN)
		var = ast_cpy(data, assignment->fst_child);
	else
		throw_exception("bad use of for loop!", data->nline);

	ast *for_ast = new_ast_entry(data, FOR, NULL, assignment);
	for_ast->fst_child->next_sibling = binary_operator(data, var, exprf, LT);
	for_ast->fst_child->next_sibling->next_sibling = seq;
	return for_ast;
}


ast *assignment(parser_data_t *data, ast *var, ast *expr) {
	ast *assign_ast = new_ast_entry(data, ASSIGN, NULL, var);
	var->next_sibling = expr;
	return assign_ast;
}



/*********** EXPRESSIONS *************/

ast *binary_operator(parser_data_t *data, ast *expr1, ast *expr2, int token) {
	ast *new_ast = new_ast_entry(data, token, NULL, expr1);
	expr1->next_sibling = expr2;
	return new_ast;
}


ast *unary_operator(parser_data_t *data, ast *expr, int token) {
	ast *new_ast = new_ast_entry(data, token, NULL, expr);
	return new_ast;
}

void disp_recur(ast *x, int nbsp);
void declarefunc(parser_data_t *data, char *funcname, ast *inits , ast *seq) {
	ast *ast_inits = new_ast_entry(data, INIT_ARGS, seq, inits);
	if(data->usrfuncs.find(string(funcname)) != data->usrfuncs.end()) {
		string err = "redefinition of "+string(funcname)+" function.\n";
		throw_exception(err, data->nline);
	}
	data->usrfuncs.insert({string(funcname), ast_inits});

	cout << funcname << " : " << endl;
	disp_recur(ast_inits, 0);
	
	free(funcname);
}


ast *loadfunction(parser_data_t *data, char *funcname, ast *expr) {
	ast *ast_func = new_ast_entry(data, FUNC, NULL, expr);
	ast_func->strvalue = new string(funcname);
	push_freelist(data, ast_func->strvalue, 1);
	free(funcname);
	return ast_func;
}


ast *loadnatural(parser_data_t *data, int natural) {
	ast *new_ast = new_ast_entry(data, NATURAL, NULL, NULL);
	new_ast->intvalue = (int32_t)natural;
	return new_ast;
}


ast *loadchar(parser_data_t *data, char charact) {
	ast *new_ast = new_ast_entry(data, CHARACT, NULL, NULL);
	new_ast->charvalue = (char)charact;
	return new_ast;
}


ast *loadreal(parser_data_t *data, double real) {
	ast *new_ast = new_ast_entry(data, REAL, NULL, NULL);
	new_ast->doublevalue = real;
	return new_ast;
}


ast *loadstr(parser_data_t *data, char *str) {
	string nstr = string(str).substr(1, strlen(str)-2);
	ast *new_ast = new_ast_entry(data, STR, NULL, NULL);
	new_ast->strvalue = new string(nstr);
	push_freelist(data, new_ast->strvalue, 1);
	free(str);
	return new_ast;
}


ast *loadvar(parser_data_t *data, char *varname) {
	ast *new_ast = new_ast_entry(data, IDENT, NULL, NULL);
	new_ast->strvalue = new string(varname);
	push_freelist(data, new_ast->strvalue, 1);
	free(varname);
	return new_ast;
}


ast *new_ast_entry(parser_data_t *data, int token, ast *sibling, ast *child) {
	ast *new_ast = (ast*)malloc(sizeof(ast));
	new_ast->token = token;
	new_ast->next_sibling = sibling;
	new_ast->fst_child = child;
	new_ast->nline = data->nline;

	push_freelist(data, new_ast, 0);
	return new_ast;
}

ast *ast_cpy(parser_data_t *data, ast *atome) {
	ast *new_ast = (ast*)malloc(sizeof(ast));
	memcpy(new_ast, atome, sizeof(ast));

	push_freelist(data, new_ast, 0);
	return new_ast;
}

void push_freelist(parser_data_t *data, void *el, int type) {
	el_alloced_t *strct = (el_alloced_t*)malloc(sizeof(el_alloced_t));
	strct->type = type;
	strct->el = el;
	strct->next = data->fst_el;
	data->fst_el = strct;
}
