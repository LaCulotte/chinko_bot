#include "ScriptManager.h"
#include "LogBotCommand.h"
#include "NoReturnValue.h"

void ScriptManager::launchScript(string scriptFilePath) {  
    // Launches ScriptThread  
    st.setScriptPath(scriptFilePath);
    st.setScriptConfig(this->config);
    st.launchScript();
}

sp<BotCommand> ScriptManager::getLastCommand() {
    // Gets command
    sp<BotCommand> cmd = st.getCurrentCommand();

    // Checks if it is a log command
    sp<LogBotCommand> logCmd = dynamic_pointer_cast<LogBotCommand>(cmd);
    if(logCmd) {
        // Logs content
        Logger::write(logCmd->log, LOG_INFO);

        // Returns no value to the script
        sp<NoReturnValue> ret = make_shared<NoReturnValue>();
        ret->commmandNumber = cmd->commandNumber;
        st.setReturnValues(ret);

        return nullptr;
    }

    // else, return the command 
    return cmd;
}

void ScriptManager::setReturnValues(sp<BotCommandReturnValues> returnValues) {
    // Sets ScriptThread's return values
    st.setReturnValues(returnValues);
}