#include "ScriptThread.h"

void ScriptThread::launchScript() {
    if(currentScriptState != no_script)
        return;

    currentScriptState = running;
    if(scriptThread.joinable())
        scriptThread.join();
        
    scriptThread = thread(&ScriptThread::launchThread, this);
}

void ScriptThread::launchThread() {
    try {
        dscript(scriptFilePath.c_str());
    } catch (string error) {
        Logger::write(error, LOG_ERROR);
    }

    cout << "fin script" << endl;
    currentScriptState = no_script;
}

sp<BotCommand> ScriptThread::getCurrentCommand() {
    if(currentScriptState != launching_cmd)
        return nullptr;

    currentScriptState = waiting_returnValues;
    return currentCommand;
}

void ScriptThread::setReturnValues(sp<BotCommandReturnValues> returnValues) {
    if(currentScriptState != waiting_returnValues) {
        Logger::write("Trying to set a return values while the script is not waiting for those");
        return;
    }

    currentReturnValues = returnValues;
    currentScriptState = running;
}

void ScriptThread::setScriptConfig(ScriptConfig c) {
    if(currentScriptState == no_script)
        config = c;
}