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

// Asynchronus methods
public:
    void launchScript();
    // Careful -> will be called asynchronusly 
    void stopScript() { cout << "---- TODO!!!!!!! : voir avec Mathis pour stopper un script en cours d'éxecution ----" << endl; };

    // sp<Command> getCurrentCommand();
    // bool setCommandReturnValue(sp<CommandReturnValue> return);

    void setScriptPath(string scriptFilePath) { this->scriptFilePath = scriptFilePath; }
    void setScriptConfig(ScriptConfig config);

    sp<BotCommand> getCurrentCommand();
    void setReturnValues(sp<BotCommandReturnValues> returnValues);

protected:
    void launchThread();

    string scriptFilePath;
    thread scriptThread;
};

#endif