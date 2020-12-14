#ifndef SCRIPT_CONFIG_H
#define SCRIPT_CONFIG_H

#include "std_include.h"
#include <unordered_set>
struct ScriptConfig {
    unordered_set<int> interactives_to_collect;
};

#endif