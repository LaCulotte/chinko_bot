#ifndef SCRIPT_THREAD
#define SCRIPT_THREAD

#include "parser.h"
#include "std_include.h"
#include "thread_include.h"
#include "Logger.h"

#include "ScriptConfig.h"

#include "BotCommand.h"
#include "BotCommandReturnValues.h"

int dscript(const char*);

enum ScriptState {
    no_script,
    running,
    launching_cmd,
    waiting_returnValues
};

extern ScriptConfig config;
extern ScriptState currentScriptState;
extern sp<BotCommand> currentCommand;
extern sp<BotCommandReturnValues> currentReturnValues;

class ScriptThread {
public:
    // Constructor
    ScriptThread() {};
    // Constructor with scriptFilePath initialization
    ScriptThread(string scriptFilePath) {this->scriptFilePath = scriptFilePath;};
    // Copy constructor
    ScriptThread(const ScriptThread& other) = delete;

    // Copy operator
    ScriptThread& operator=(const ScriptThread& other) = delete;
    // Destructor
    ~ScriptThread() = default;

    // true if the script should be stopped
    bool stop = false;

// Asynchronus methods
public:
    // Launches the script
    void launchScript();
    // /!\ Careful -> will be called asynchronusly 
    void stopScript() { stop = true; };

    // Sets script file's path
    void setScriptPath(string scriptFilePath) { this->scriptFilePath = scriptFilePath; }
    // Sets script config
    void setScriptConfig(ScriptConfig config);

    // Returns the last command launched by the script
    sp<BotCommand> getCurrentCommand();
    // Sets a command return values to be read by the script 
    void setReturnValues(sp<BotCommandReturnValues> returnValues);

protected:
    // Launches a script thread
    void launchThread();

    // Path to the script's file
    string scriptFilePath;
    // Script's thread
    thread scriptThread;
};

#endif