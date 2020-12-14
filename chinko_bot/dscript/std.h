#ifndef __STD__
#define __STD__

#include <unordered_map>
#include <cstdarg>
#include <vector>
#include "../../Var/Var.h"

typedef sp<IVar> (*stdf)(std::vector<sp<IVar>>);


void initstd();

void is_valid_call(std::vector<sp<IVar>> *args, int nb_params, ...);

sp<IVar> stdpow(std::vector<sp<IVar>> params);
sp<IVar> usleep(std::vector<sp<IVar>> params);
sp<IVar> stdlog(std::vector<sp<IVar>> params);
sp<IVar> randRange(std::vector<sp<IVar>> params);

sp<IVar> mapUp(std::vector<sp<IVar>> params);
sp<IVar> mapDown(std::vector<sp<IVar>> params);
sp<IVar> mapRight(std::vector<sp<IVar>> params);
sp<IVar> mapLeft(std::vector<sp<IVar>> params);

sp<IVar> collectInteractives(std::vector<sp<IVar>> params);

sp<IVar> isFull(std::vector<sp<IVar>> params);
sp<IVar> weightStatusAsString(std::vector<sp<IVar>> params);

#endif // __STD__