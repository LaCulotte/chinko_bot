/*
	Fonctions directement liées à la création du code asm
	utilisées dans la grammaire de base.y
*/

#include "../includes/gramm_funcs.h"
#include "../products/parser.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
extern int yyerror(const char *s);
extern int error;

extern std::unordered_map<std::string, void*> variables;


ast *seq(ast *inst, ast *seq) {
	printf("SEQ ");
	inst->next_sibling = seq;
	return inst;
}


ast *ifinst(ast *expr, ast *seq) {
	ast *new_ast = new_ast_entry(IF, NULL, expr);
	expr->next_sibling = seq;
	return new_ast;
}


ast *ifelseinst(ast *expr, ast *seq1, ast *seq2) {
	printf("IFELSE ");
	ast *else_ast = new_ast_entry(ELSE, NULL, seq2);
	ast *if_ast = new_ast_entry(IF, else_ast, expr);
	expr->next_sibling = seq1;
	return if_ast;
}


ast *whileinst(ast *expr, ast *seq) {
	return NULL;
}


ast *assignment(ast *var, ast *expr) {
	return NULL;
}


ast *print(ast *expr) {
	printf("PRINT ");
	ast *new_ast = new_ast_entry(PRINT, NULL, expr);
	return new_ast;
}


/*********** EXPRESSIONS *************/

ast *binary_operator(ast *expr1, ast *expr2, int token) {
	ast *new_ast = new_ast_entry(token, NULL, expr1);
	expr1->next_sibling = expr2;
	return new_ast;
}


ast *loadnatural(int natural) {
	printf("NAT ");
	ast *new_ast = new_ast_entry(NATURAL, NULL, NULL);
	new_ast->intvalue = natural;
	return new_ast;
}


ast *loadvar(char *varname) {
	printf("VAR ");
	ast *new_ast = new_ast_entry(IDENT, NULL, NULL);
	new_ast->addrvalue = variables.at(varname);
	return new_ast;
}

ast *storevar(char * varname, void *value) {
	return NULL;
}

ast *new_ast_entry(int token, ast *sibling, ast *child) {
	ast *new_ast = (ast*)malloc(sizeof(ast));
	new_ast->token = token;
	new_ast->next_sibling = sibling;
	new_ast->fst_child = child;
	return new_ast;
}
