/*
	Fonctions directement liées à la création du code asm
	utilisées dans la grammaire de base.y
*/

#ifndef GRAMM_FUNCS_I
#define GRAMM_FUNCS_I

#include <string>
#include <memory>
#include "../../Var/Var.h"


typedef struct _ast {
	int token;
	uint32_t intvalue;
	double doublevalue;
	std::shared_ptr<std::string> strvalue;
	struct _ast *next_sibling;
	struct _ast *fst_child;
	int nline;
} ast;


// Fonction permettant de faire la jointure entre deux séquences d'instructions
ast *seq(ast *inst, ast *seq);
// Génère un if asm
ast *ifinst(ast *expr, ast *seq);
//
ast *ifelseinst(ast *expr, ast *seq1, ast *seq2);
//
ast *whileinst(ast *expr, ast *seq);

ast *forinst(ast *assignment, ast *exprf, ast *seq);
// Stocke une valeur dans pixelshadow+x
ast *assignment(ast *var, ast *expr);
// affiche la variable (_dispHL ou _dispOP1a)
ast *binary_operator(ast *expr1, ast *expr2, int token);

ast *unary_operator(ast *expr, int token);

ast *loadfunction(char *funcname, ast *expr);

ast *declarefunc(char *funcname, ast *inits , ast *seq);
//
ast *loadnatural(int natural);

ast *loadreal(double real);

ast *loadstr(char *str);
//
ast *loadvar(char *varname);

ast *loadtype(int token);

ast *createvar(int vartype, ast *var);

ast *create_assign(int vartype, ast *var, ast *expr);

ast *new_ast_entry(int token, ast *sibling, ast *child);

ast *ast_cpy(ast *ast);

#endif // GRAM_FUNCS_I
