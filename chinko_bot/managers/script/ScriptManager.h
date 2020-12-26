#ifndef SCRIPT_MANAGER_H
#define SCRIPT_MANAGER_H

#include "APIUnit.h"
#include "ScriptThread.h"
#include "ScriptConfig.h"


#include "BotCommand.h"
#include "BotCommandReturnValues.h"

class ScriptManager {
public:
    // Constructor
    ScriptManager() { config.interactives_to_collect.insert({1, 17, 254}); };
    // Copy Constructor
    ScriptManager(const ScriptManager& other) = default;

    // Copy operator
    ScriptManager& operator=(const ScriptManager& other) = default;
    // Destructor
    ~ScriptManager() = default;

    // Launches a script from a script file
    void launchScript(string scriptFilePath);

    // Return last command launched by a script
    sp<BotCommand> getLastCommand();
    // Sets return values to be read by a script
    void setReturnValues(sp<BotCommandReturnValues> returnValues);

private:
    ScriptThread st;
    ScriptConfig config;
};

#endif