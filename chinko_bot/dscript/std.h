#ifndef __STD__
#define __STD__

#include <unordered_map>
#include <cstdarg>
#include <vector>
#include "gramm_funcs.h"
#include "../../Var/Var.h"

typedef sp<IVar> (*stdf)(parser_data_t*, std::vector<sp<IVar>>, int nline);


void initstd(parser_data_t *data);

void is_valid_call(std::vector<sp<IVar>> *args, int nline, int nb_params, ...);

sp<IVar> stdpow(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> usleep(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> log(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> randRange(parser_data_t *data, std::vector<sp<IVar>> params, int nline);

sp<IVar> mapUp(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> mapDown(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> mapRight(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> mapLeft(parser_data_t *data, std::vector<sp<IVar>> params, int nline);

sp<IVar> collectInteractives(parser_data_t *data, std::vector<sp<IVar>> params, int nline);

sp<IVar> isFull(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> weightStatusAsString(parser_data_t *data, std::vector<sp<IVar>> params, int nline);

/* Standards */
sp<IVar> stdcallscript(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdprint(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdprintln(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdthrow(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdtime(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdmillis(parser_data_t *data, std::vector<sp<IVar>> params, int nline);

/* Types */
sp<IVar> stdstring(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stddouble(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdbool(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdchar(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdint(parser_data_t *data, std::vector<sp<IVar>> params, int nline);

/* Strings */
sp<IVar> stdsubstr(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdfind(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdgetchar(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdstrlen(parser_data_t *data, std::vector<sp<IVar>> params, int nline);

/* Math */
sp<IVar> stdpow(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdabs(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdmin(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdmax(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdpi(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdexp(parser_data_t *data, std::vector<sp<IVar>> params, int nline); // e^(i)
sp<IVar> stdlog(parser_data_t *data, std::vector<sp<IVar>> params, int nline); // log(num, base)
sp<IVar> stdsqrt(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdround(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdisinf(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdisNaN(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdsin(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdcos(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdtan(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdasin(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdacos(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdatan(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdrand(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdrandint(parser_data_t *data, std::vector<sp<IVar>> params, int nline);

/* I/O Files&Input */
sp<IVar> stdreadfile(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdwritefile(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdcreatefile(parser_data_t *data, std::vector<sp<IVar>> params, int nline);
sp<IVar> stdinput(parser_data_t *data, std::vector<sp<IVar>> params, int nline);

#endif // __STD__