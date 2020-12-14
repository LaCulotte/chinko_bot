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

extern int nline;


ast *seq(ast *inst, ast *seq) {
	inst->next_sibling = seq;
	return inst;
}


ast *ifinst(ast *expr, ast *seq) {
	ast *new_ast = new_ast_entry(IF, NULL, expr);
	expr->next_sibling = seq;
	return new_ast;
}


ast *ifelseinst(ast *expr, ast *seq1, ast *seq2) {
	ast *else_ast = new_ast_entry(ELSE, NULL, seq2);
	ast *if_ast = new_ast_entry(IF, else_ast, seq1);
	ast *ifelse_ast = new_ast_entry(IFELSE, NULL, expr);
	expr->next_sibling = if_ast;
	return ifelse_ast;
}


ast *whileinst(ast *expr, ast *seq) {
	ast *while_ast = new_ast_entry(WHILE, NULL, expr);
	expr->next_sibling = seq;
	return while_ast;
}


ast *forinst(ast *assignment, ast *exprf, ast *seq) {
	ast *var;
	if(assignment->token==CREATEASSIGN)
		var = ast_cpy(assignment->fst_child->next_sibling);
	else if(assignment->token==ASSIGN)
		var = ast_cpy(assignment->fst_child);
	else {
		cout << "ERROR: Bad use of For loop on line " << nline << endl;
		exit(-1); 
	}
	ast *for_ast = new_ast_entry(FOR, NULL, assignment);
	for_ast->fst_child->next_sibling = binary_operator(var, exprf, LT);
	for_ast->fst_child->next_sibling->next_sibling = seq;
	return for_ast;
}


ast *assignment(ast *var, ast *expr) {
	ast *assign_ast = new_ast_entry(ASSIGN, NULL, var);
	var->next_sibling = expr;
	return assign_ast;
}



/*********** EXPRESSIONS *************/

ast *binary_operator(ast *expr1, ast *expr2, int token) {
	ast *new_ast = new_ast_entry(token, NULL, expr1);
	expr1->next_sibling = expr2;
	return new_ast;
}


ast *unary_operator(ast *expr, int token) {
	ast *new_ast = new_ast_entry(token, NULL, expr);
	return new_ast;
}


ast *declarefunc(char *funcname, ast *inits , ast *seq) {
	ast *ast_inits = new_ast_entry(INIT_ARGS, seq, inits);
	ast *ast_func = new_ast_entry(INIT_FUNC, NULL, ast_inits);
	return ast_inits;
}


ast *loadfunction(char *funcname, ast *expr) {
	ast *ast_func = new_ast_entry(FUNC, NULL, expr);
	ast_func->strvalue = make_shared<string>(funcname);
	free(funcname);
	return ast_func;
}


ast *loadnatural(int natural) {
	ast *new_ast = new_ast_entry(NATURAL, NULL, NULL);
	new_ast->intvalue = (uint32_t)natural; // pour l'instant je stocke dans le plus grand type qu'on puisse avoir
	return new_ast;
}


ast *loadreal(double real) {
	ast *new_ast = new_ast_entry(REAL, NULL, NULL);
	new_ast->doublevalue = real;
	return new_ast;
}


ast *loadstr(char *str) {
	cout << "STR " << str << endl;
	string nstr = string(str).substr(1, strlen(str)-2);
	ast *new_ast = new_ast_entry(STR, NULL, NULL);
	sp<string> s = make_shared<string>(nstr);
	new_ast->strvalue = s;
	free(str);
	return new_ast;
}


ast *loadvar(char *varname) {
	ast *new_ast = new_ast_entry(IDENT, NULL, NULL);
	new_ast->strvalue = make_shared<string>(varname);
	free(varname);
	return new_ast;
}


ast *createvar(int vartype, ast *var) {
	ast *type_ast = new_ast_entry(TYPE, var, NULL);
	type_ast->intvalue = vartype;
	ast *new_ast = new_ast_entry(CREATEVAR, NULL, type_ast);
	return new_ast;
}


ast *create_assign(int vartype, ast *var, ast *expr) {
	ast *type_ast = new_ast_entry(TYPE, var, NULL);
	type_ast->intvalue = vartype;
	ast *new_ast = new_ast_entry(CREATEASSIGN, NULL, type_ast);
	var->next_sibling = expr;
	return new_ast;
}



ast *new_ast_entry(int token, ast *sibling, ast *child) {
	ast *new_ast = (ast*)malloc(sizeof(ast));
	new_ast->token = token;
	new_ast->next_sibling = sibling;
	new_ast->fst_child = child;
	new_ast->nline = nline;
	return new_ast;
}

ast *ast_cpy(ast *atome) {
	ast *new_ast = (ast*)malloc(sizeof(ast));
	memcpy(new_ast, atome, sizeof(ast));
	return new_ast;
}
