#include "TempDialogFrame.h"

bool TempDialogFrame::computeMessage(sp<Message> message, int srcId) {

    sp<ChatServerMessage> csMsg;
    sp<RoleplayCharacterData> caller;
    sp<RoleplayCharacterData> player;

    switch (message->getId())
    {
    case ChatServerMessage::protocolId:
        if(!dofusBotParent->playedCharacter) {
            Logger::write("Cannot pathfind : played character is not initialiazed", LOG_WARNING);
            break;
        }

        csMsg = dynamic_pointer_cast<ChatServerMessage>(message);

        if(csMsg->content == "droite")  {
            dofusBotParent->sendSelfMessage(make_shared<ChangeToRightMapMessage>());
            Logger::write("Moving to right map.", LOG_INFO);
        } else if(csMsg->content == "gauche")  {
            dofusBotParent->sendSelfMessage(make_shared<ChangeToLeftMapMessage>());
            Logger::write("Moving to left map.", LOG_INFO);
        } else if(csMsg->content == "haut")  {
            dofusBotParent->sendSelfMessage(make_shared<ChangeToUpMapMessage>());
            Logger::write("Moving to up map.", LOG_INFO);
        } else if(csMsg->content == "bas")  {
            dofusBotParent->sendSelfMessage(make_shared<ChangeToDownMapMessage>());
            Logger::write("Moving to down map.", LOG_INFO);
        } else if (csMsg->content == "collect") {
            dofusBotParent->sendSelfMessage(make_shared<CollectInteractiveTypeIdMessage>(17));
            // dofusBotParent->sendSelfMessage(make_shared<CollectInteractiveTypeIdMessage>(17));
            Logger::write("Collecting.", LOG_INFO);
        } else if(dofusBotParent->getMapInfosAsRoleplay()) {
            caller = dofusBotParent->getMapInfosAsRoleplay()->getPlayer(csMsg->senderId);
            // player = dofusBotParent->mapInfos.getPlayer(dofusBotParent->playedCharacter->contextualId);

            Logger::write("[Chat][Channel " + to_string(csMsg->channel) + "] " + csMsg->senderName + " : " + csMsg->content, LOG_INFO);
            if(caller && dofusBotParent->playedCharacter) {
                Logger::write(caller->name + " called.", LOG_INFO);
                dofusBotParent->sendSelfMessage(make_shared<MoveToCellMessage>(caller->cellId));
            } 
        } else {
            stringstream sstream(csMsg->content);
            int destCellId;
            sstream >> destCellId;


            if(destCellId != 0) {
                cout << "To cell " << destCellId << endl;
                dofusBotParent->sendSelfMessage(make_shared<MoveToCellMessage>(destCellId));
            }
        }
        break;
    
    default:
        return false;
    }

    return true;
}