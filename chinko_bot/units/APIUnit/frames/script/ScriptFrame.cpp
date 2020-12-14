#include "ScriptFrame.h"

#include "BotCommandMessage.h"
#include "BotCommandReturnValuesMessage.h"

#include "LaunchScriptMessage.h"

bool ScriptFrame::update() {        
    sp<BotCommand> cmd = scriptManager.getLastCommand();
    if(cmd)
        apiUnitParent->sendMessage(make_shared<BotCommandMessage>(cmd), apiUnitParent->getDofusBotUnitId());

    return true;
}

bool ScriptFrame::computeMessage(sp<Message> message, int srcId) {
    sp<BotCommandReturnValuesMessage> bcrvMsg;
    sp<LaunchScriptMessage> lsMsg;

    switch (message->getId())
    {
    case BotCommandReturnValuesMessage::protocolId:
        bcrvMsg = dynamic_pointer_cast<BotCommandReturnValuesMessage>(message);
        scriptManager.setReturnValues(bcrvMsg->returnValues);
        break;
    
    case LaunchScriptMessage::protocolId:
        lsMsg = dynamic_pointer_cast<LaunchScriptMessage>(message);
        Logger::write("Launching script : " + lsMsg->scriptFilePath, LOG_DEBUG);
        scriptManager.launchScript(lsMsg->scriptFilePath);
        break;

    default:
        return false;
    }    

    return true;
}