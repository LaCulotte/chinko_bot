#ifndef SCRIPT_CONFIG_H
#define SCRIPT_CONFIG_H

#include "std_include.h"
#include <unordered_set>
struct ScriptConfig {
    // Set of the interactive that the bot should collect on every map
    unordered_set<int> interactives_to_collect;
};

#endif