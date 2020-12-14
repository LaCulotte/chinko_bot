#include "ScriptManager.h"
#include "LogBotCommand.h"
#include "NoReturnValue.h"

void ScriptManager::launchScript(string scriptFilePath) {    
    st.setScriptPath(scriptFilePath);
    st.setScriptConfig(this->config);
    st.launchScript();
}

sp<BotCommand> ScriptManager::getLastCommand() {
    sp<BotCommand> cmd = st.getCurrentCommand();

    sp<LogBotCommand> logCmd = dynamic_pointer_cast<LogBotCommand>(cmd);
    if(logCmd) {
        Logger::write(logCmd->log, LOG_INFO);
        sp<NoReturnValue> ret = make_shared<NoReturnValue>();
        ret->commmandNumber = cmd->commandNumber;
        st.setReturnValues(ret);
        return nullptr;
    }

    return cmd;
}

void ScriptManager::setReturnValues(sp<BotCommandReturnValues> returnValues) {
    st.setReturnValues(returnValues);
}