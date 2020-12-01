/*
	Fonctions directement liées à la création du code asm
	utilisées dans la grammaire de base.y
*/

#ifndef GRAMM_FUNCS_I
#define GRAMM_FUNCS_I

#include <string>
#include <memory>
#include <unordered_map>
#include <vector>
#include "../../Var/Var.h"

typedef sp<IVar> (*stdf)(std::vector<sp<IVar>>);


typedef struct _ast {
	int token;
	uint32_t intvalue;
	double doublevalue;
	std::string *strvalue;
	struct _ast *next_sibling;
	struct _ast *fst_child;
	int nline;
} ast;

typedef struct el_alloced {
	int type; // 0=malloced 1=newed
	void *el;
	struct el_alloced *next;
} el_alloced_t;

typedef struct ctx_vars {
	std::unordered_map<std::string, sp<IVar>> variables;
	struct ctx_vars *parent;
} ctx_vars_t;

typedef struct parser_data {
	int nline;
	bool *stop;
	el_alloced_t *fst_el;
	ctx_vars_t *ctx;
	std::unordered_map<std::string, stdf> stdfuncs;
	std::unordered_map<std::string, ast*> usrfuncs;
} parser_data_t;


ast *seq(ast *inst, ast *seq);

ast *ifinst(parser_data_t *data, ast *expr, ast *seq);

ast *ifelseinst(parser_data_t *data, ast *expr, ast *seq1, ast *seq2);

ast *whileinst(parser_data_t *data, ast *expr, ast *seq);

ast *forinst(parser_data_t *data, ast *assignment, ast *exprf, ast *seq);

ast *assignment(parser_data_t *data, ast *var, ast *expr);

ast *binary_operator(parser_data_t *data, ast *expr1, ast *expr2, int token);

ast *unary_operator(parser_data_t *data, ast *expr, int token);

ast *loadfunction(parser_data_t *data, char *funcname, ast *expr);

void declarefunc(parser_data_t *data, char *funcname, ast *inits , ast *seq);

ast *loadnatural(parser_data_t *data, int natural);

ast *loadreal(parser_data_t *data, double real);

ast *loadstr(parser_data_t *data, char *str);

ast *loadvar(parser_data_t *data, char *varname);

ast *loadtype(parser_data_t *data, int token);

ast *createvar(parser_data_t *data, int vartype, ast *var);

ast *create_assign(parser_data_t *data, int vartype, ast *var, ast *expr);

ast *new_ast_entry(parser_data_t *data, int token, ast *sibling, ast *child);

ast *ast_cpy(parser_data_t *data, ast *ast);

void push_freelist(parser_data_t *data, void *el, int type);


#endif // GRAM_FUNCS_I
