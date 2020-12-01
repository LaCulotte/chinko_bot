#ifndef __AST__
#define __AST__

#include "../gramm_funcs.h"
#include <vector>


void dscript(const char *file, bool *stop);

void dscript_cmd(const char *code, bool *stop);

void throw_exception(const std::string err, int nl);

void free_list(el_alloced_t *list);

void parse_params(parser_data_t *data, std::vector<sp<IVar>> *dst, ast *ast);

sp<IVar> parse_expr(parser_data_t *data, ast *ast);

ctx_vars_t *find_ctx(parser_data_t *data, std::string varname, int nline);

sp<IVar> run(parser_data_t *data, ast *ast, bool recur);

void execute(parser_data_t *data, ast *x);

sp<IVar> runfunc(parser_data_t *data, std::string funcname, ast *ast);

bool castable(int type1, int type2);

sp<IVar> cast_type(int type, sp<IVar> value);

void watchdog_type(int typedst, int typesrc, ast *op);


#endif // __AST__