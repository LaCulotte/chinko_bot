#ifndef __AST__
#define __AST__

#include "../gramm_funcs.h"
#include <vector>


int yylex();

int yyerror(const char *s);

void parse_params(std::vector<sp<IVar>> *dst, ast *ast);

sp<IVar> parse_expr(ast *ast);

void run(ast *ast, bool recur);

void execute(ast *x);

sp<IVar> runfunc(std::string funcname, ast *ast);

bool castable(int type1, int type2);

sp<IVar> cast_type(int type, sp<IVar> value);

void watchdog_type(int typedst, int typesrc, ast *op);


#endif // __AST__