#include "TempDialogFrame.h"

bool TempDialogFrame::computeMessage(sp<Message> message, int srcId) {

    sp<ChatServerMessage> csMsg;
    sp<RoleplayCharacterData> caller;
    sp<RoleplayCharacterData> player;
    sp<FighterData> fighter_caller;
    sp<ActorData> actor_caller;

    switch (message->getId())
    {
    case ChatServerMessage::protocolId:
        if(!dofusBotParent->playedCharacter) {
            Logger::write("Cannot pathfind : played character is not initialiazed", LOG_WARNING);
            break;
        }

        csMsg = dynamic_pointer_cast<ChatServerMessage>(message);
        actor_caller = dofusBotParent->mapInfos->getActor(csMsg->senderId);

        if(csMsg->content == "droite" && actor_caller)  {
            int floor = dofusBotParent->mapInfos->getCell(actor_caller->cellId)->floor;
            dofusBotParent->sendSelfMessage(make_shared<ChangeToRightMapMessage>(floor));
            Logger::write("Moving to right map.", LOG_INFO);
        } else if(csMsg->content == "gauche" && actor_caller)  {
            int floor = dofusBotParent->mapInfos->getCell(actor_caller->cellId)->floor;
            dofusBotParent->sendSelfMessage(make_shared<ChangeToLeftMapMessage>(floor));
            Logger::write("Moving to left map.", LOG_INFO);
        } else if(csMsg->content == "haut" && actor_caller)  {
            int floor = dofusBotParent->mapInfos->getCell(actor_caller->cellId)->floor;
            dofusBotParent->sendSelfMessage(make_shared<ChangeToUpMapMessage>(floor));
            Logger::write("Moving to up map.", LOG_INFO);
        } else if(csMsg->content == "bas" && actor_caller)  {
            int floor = dofusBotParent->mapInfos->getCell(actor_caller->cellId)->floor;
            dofusBotParent->sendSelfMessage(make_shared<ChangeToDownMapMessage>(floor));
            Logger::write("Moving to down map.", LOG_INFO);
        } else if (csMsg->content == "collect") {
            dofusBotParent->sendSelfMessage(make_shared<CollectInteractiveTypeIdMessage>(17));
            // dofusBotParent->sendSelfMessage(make_shared<CollectInteractiveTypeIdMessage>(17));
            Logger::write("Collecting.", LOG_INFO);
        } else if (csMsg->content == "attack" && dofusBotParent->getMapInfosAsFight()) {
            fighter_caller = dofusBotParent->getMapInfosAsFight()->getFighter(csMsg->senderId);
            if(fighter_caller) {
                int targetCell = fighter_caller->cellId;
                int spellId = 13047;
                dofusBotParent->sendSelfMessage(make_shared<CastSpellOnCellMessage>(targetCell, spellId));
            }
        } else if (csMsg->content.substr(0, 6) == "attack" && dofusBotParent->getMapInfosAsRoleplay()) {
            // dofusBotParent->getMapInfosAsRoleplay()->get
            // cout << csMsg->content.substr(7, csMsg->content.size() - 7) << endl;
            stringstream sstream(csMsg->content.substr(7, csMsg->content.size() - 7));
            double monsterGroupId;
            sstream >> monsterGroupId;

            cout << monsterGroupId << endl;

            dofusBotParent->sendSelfMessage(make_shared<AttackMonsterGroupMessage>(monsterGroupId));

        } else if (dofusBotParent->getMapInfosAsRoleplay()) {
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
            fighter_caller = dofusBotParent->getMapInfosAsFight()->getFighter(csMsg->senderId);


            // if(destCellId != 0 && fighter_caller){
            //     if(dofusBotParent->mapInfos->isThereLos(destCellId, fighter_caller->cellId))
            //         cout << "LOS" << endl;
            //     else
            //         cout << "PAS LOS" << endl;
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