/*
	Fonctions directement liées à la création du code asm
	utilisées dans la grammaire de base.y
*/

#ifndef GRAMM_FUNCS_I
#define GRAMM_FUNCS_I


typedef struct _ast {
	int token;
	int intvalue;
	void *addrvalue;
	struct _ast *next_sibling;
	struct _ast *fst_child;
} ast;

typedef struct _listvar {
	char *varname;
	struct _listvar *next;
} listvar;


// Fonction permettant de faire la jointure entre deux séquences d'instructions
ast *seq(ast *inst, ast *seq);
// Génère un if asm
ast *ifinst(ast *expr, ast *seq);
//
ast *ifelseinst(ast *expr, ast *seq1, ast *seq2);
//
ast *whileinst(ast *expr, ast *seq);
// Stocke une valeur dans pixelshadow+x
ast *assignment(ast *var, ast *expr);
// affiche la variable (_dispHL ou _dispOP1a)
ast *print(ast *expr);
//
ast *binary_operator(ast *expr1, ast *expr2, int token);
//
ast *loadnatural(int natural);
//
ast *loadvar(char *varname);

ast *storevar(char *varname, int value);

ast *new_ast_entry(int token, ast *sibling, ast *child);

#endif // GRAM_FUNCS_I
