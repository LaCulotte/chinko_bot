#ifndef __STD__
#define __STD__

#include <unordered_map>
#include <cstdarg>
#include <vector>
#include "gramm_funcs.h"
#include "../../Var/Var.h"

typedef sp<IVar> (*stdf)(std::vector<sp<IVar>>);


void initstd(parser_data_t *data);

void is_valid_call(std::vector<sp<IVar>> *args, int nb_params, ...);

sp<IVar> stdprint(std::vector<sp<IVar>> params);
sp<IVar> stdpow(std::vector<sp<IVar>> params);
sp<IVar> test(std::vector<sp<IVar>> params);

#endif // __STD__