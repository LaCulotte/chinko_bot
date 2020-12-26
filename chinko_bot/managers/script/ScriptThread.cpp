#include "ScriptThread.h"

void ScriptThread::launchScript() {
    // Does nothing if a script is already running
    if(currentScriptState != no_script)
        return;

    // Sets ScriptThread's state to 'running'
    currentScriptState = running;
    // If the script's thread is running, wait for it to stop
    if(scriptThread.joinable())
        scriptThread.join();
        
    // Launches the new thread
    scriptThread = thread(&ScriptThread::launchThread, this);
}

void ScriptThread::launchThread() {
    try {
        // launches the function that reads the script
        dscript(scriptFilePath.c_str(), &stop);
    } catch (string error) {
        Logger::write(error, LOG_ERROR);
    }

    // Logs and updates state when it ended
    cout << "fin script" << endl;
    currentScriptState = no_script;
}

sp<BotCommand> ScriptThread::getCurrentCommand() {
    // Must be in the correct state 
    if(currentScriptState != launching_cmd)
        return nullptr;

    // Updates state
    currentScriptState = waiting_returnValues;
    return currentCommand;
}

void ScriptThread::setReturnValues(sp<BotCommandReturnValues> returnValues) {
    // Must be waiting for the return values
    if(currentScriptState != waiting_returnValues) {
        Logger::write("Trying to set a return values while the script is not waiting for those");
        return;
    }

    // Sets return values & update state to notify the script
    currentReturnValues = returnValues;
    currentScriptState = running;
}

void ScriptThread::setScriptConfig(ScriptConfig c) {
    if(currentScriptState == no_script)
        config = c;
}