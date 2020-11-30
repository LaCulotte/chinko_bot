#include "RoleplayContextFrame.h"

bool RoleplayContextFrame::computeMessage(sp<Message> message, int srcId) {
    
    sp<CurrentMapMessage> ccMsg;
    sp<MapComplementaryInformationsDataMessage> mcidMsg;
    sp<GameMapMovementMessage> gmmMsg;
    sp<StatedElementUpdatedMessage> seuMsg;
    sp<InteractiveElementUpdatedMessage> ieuMsg;
    sp<InteractiveUsedMessage> iuMsg;
    sp<GameContextRemoveElementMessage> gcreMsg;
    sp<GameRolePlayShowActorMessage> grpsaMsg;
    sp<GameMapChangeOrientationMessage> gmcoMsg;
    sp<SetCharacterRestrictionsMessage> scrMsg;
    sp<GameMapNoMovementMessage> gmnmMsg;

    switch(message->getId()) {
    case SendPacketSuccessMessage::protocolId:
        // Handles SendPacketSuccessMessage
        if(!handleSendPacketSuccessMessage(dynamic_pointer_cast<SendPacketSuccessMessage>(message)))
            return false;
        
        break;

    case SendPacketFailureMessage::protocolId:
        // Handles SendPacketFailureMessage
        if(!handleSendPacketFailureMessage(dynamic_pointer_cast<SendPacketFailureMessage>(message)))
            return false;
        
        break;

    case CurrentMapMessage::protocolId:
        // Received current map informations
        ccMsg = dynamic_pointer_cast<CurrentMapMessage>(message);
        Logger::write("Received CurrentMapMessage.", LOG_INFO);
        Logger::write("Map id : " + to_string(ccMsg->mapId) + ". Map key : " + ccMsg->mapKey, LOG_INFO);

        // Request for more map infos
        dofusBotParent->currentMapId = ccMsg->mapId;
        sendMapInformationsRequestMessage(ccMsg->mapId);
        dofusBotParent->sendSelfMessage(make_shared<CurrentMapChangedMessage>());
        break;

    case MapComplementaryInformationsDataMessage::protocolId:
        mcidMsg = dynamic_pointer_cast<MapComplementaryInformationsDataMessage>(message);
        {
            sp<RoleplayMapManager> mapManager(new RoleplayMapManager());
            mapManager->loadMapInformations(mcidMsg);
            dofusBotParent->currentMapId = mcidMsg->mapId;

            if(dofusBotParent->playedCharacter && mapManager->getPlayer(dofusBotParent->playedCharacter->contextualId)) {
                dofusBotParent->playedCharacter = mapManager->getPlayer(dofusBotParent->playedCharacter->contextualId);
                Logger::write("Played character : " + mapManager->getPlayer(dofusBotParent->playedCharacter->contextualId)->name + ".", LOG_INFO);

                dofusBotParent->playedCharacter->canSeeThrough = true;
                dofusBotParent->playedCharacter->canWalkThrough = true;
                dofusBotParent->playedCharacter->canWalkTo = true;
            } else {
                Logger::write("Cannot locate played character.", LOG_WARNING);
            }

            dofusBotParent->mapInfos = mapManager;

            if(!dofusBotParent->getFrame<TempDialogFrame>()) {
                dofusBotParent->addFrame(make_shared<TempDialogFrame>());
            }
            if(!dofusBotParent->getFrame<MovementFrame>()) {
                sp<MovementFrame> mf(new MovementFrame());
                dofusBotParent->addFrame(mf);
            }
            if(!dofusBotParent->getFrame<BasicActionsFrame>())
                dofusBotParent->addFrame(make_shared<BasicActionsFrame>());
        }
        Logger::write("Received MapComplementaryInformationsDataMessage", LOG_INFO);
        break;

    case GameMapMovementMessage::protocolId:
        if(!dofusBotParent->getMapInfosAsRoleplay()) {
            Logger::write("Player on map but map info is not initialized !!", LOG_ERROR);
            break;
        }
        
        {    
            gmmMsg = dynamic_pointer_cast<GameMapMovementMessage>(message);
            string actorName = "";
            if (dynamic_pointer_cast<RoleplayCharacterData>(dofusBotParent->mapInfos->getActor(gmmMsg->actorId)))
                actorName = " (" + dynamic_pointer_cast<RoleplayCharacterData>(dofusBotParent->mapInfos->getActor(gmmMsg->actorId))->name + ")";
            dofusBotParent->mapInfos->updateActorPosition(gmmMsg->actorId, gmmMsg->keyMovements.back() & 0xFFF);
            Logger::write("Actor " + to_string(gmmMsg->actorId) + actorName + " moved from cell " + to_string(gmmMsg->keyMovements.front() & 0xFFF) + " to cell " + to_string(gmmMsg->keyMovements.back() & 0xFFF) + ".", LOG_DEBUG);
        }


        if(dofusBotParent->playedCharacter && gmmMsg->actorId == dofusBotParent->playedCharacter->contextualId) {
            int time = 0;
            for (int i = 0; i < gmmMsg->keyMovements.size() - 1; i++) {
                int cell1Id = gmmMsg->keyMovements[i]; 
                int cell2Id = gmmMsg->keyMovements[i + 1]; 
                time += 200 * dofusBotParent->mapInfos->getEuclidianDistance(cell1Id, cell2Id);
            }

            if(time < 1000) time = 1000;

            dofusBotParent->sendSelfMessage(make_shared<TimedMessage>(make_shared<SendMovementConfirmMessage>(), time));
        }

        break;

    case SendMovementConfirmMessage::protocolId:
        sendGameMapMovementConfirmMessage();
        dofusBotParent->sendSelfMessage(make_shared<PlayerMovementEndedMessage>());
        break;

    case GameMapNoMovementMessage::protocolId:
        gmnmMsg = dynamic_pointer_cast<GameMapNoMovementMessage>(message);
        Logger::write("No movement : (" + to_string(gmnmMsg->cellX) + "; " + to_string(gmnmMsg->cellY) + ").", LOG_WARNING);
        dofusBotParent->sendSelfMessage(make_shared<PlayerMovementErrorMessage>());
        break;

    case StatedElementUpdatedMessage::protocolId:
        seuMsg = dynamic_pointer_cast<StatedElementUpdatedMessage>(message);
        if(!dofusBotParent->getMapInfosAsRoleplay()) {
            Logger::write("Player on map but map info is not initialized !!", LOG_ERROR);
            break;
        }

        dofusBotParent->getMapInfosAsRoleplay()->updateStatedElement(seuMsg->statedElement);
        Logger::write("Stated element (" + to_string(seuMsg->statedElement.elementId) + ") updated to state " + to_string(seuMsg->statedElement.elementState) + ".", LOG_DEBUG);
        break;

    case InteractiveElementUpdatedMessage::protocolId:
        ieuMsg = dynamic_pointer_cast<InteractiveElementUpdatedMessage>(message);
        if(!dofusBotParent->getMapInfosAsRoleplay()) {
            Logger::write("Player on map but map info is not initialized !!", LOG_ERROR);
            break;
        }

        dofusBotParent->getMapInfosAsRoleplay()->updateInteractiveElement(ieuMsg->interactiveElement);
        Logger::write("Interactive element (" + to_string(ieuMsg->interactiveElement.elementId) + ") updated. Type id = " + to_string(ieuMsg->interactiveElement.elementTypeId) + ".", LOG_DEBUG);
        break;

    case InteractiveUsedMessage::protocolId:
        iuMsg = dynamic_pointer_cast<InteractiveUsedMessage>(message);
        if(!dofusBotParent->getMapInfosAsRoleplay()) {
            Logger::write("Player on map but map info is not initialized !!", LOG_ERROR);
            break;
        }

        if(dofusBotParent->getMapInfosAsRoleplay()->getPlayer(iuMsg->entityId))
            Logger::write("Player : " + dofusBotParent->getMapInfosAsRoleplay()->getPlayer(iuMsg->entityId)->name + " is using element " + to_string(iuMsg->elemId), LOG_INFO);
        else 
            Logger::write("Entity : " + to_string(iuMsg->entityId) + " is using interactive " + to_string(iuMsg->elemId), LOG_INFO);
        break;

    case GameContextRemoveElementMessage::protocolId:
        if(!dofusBotParent->getMapInfosAsRoleplay()) {
            Logger::write("Player on map but map info is not initialized !!", LOG_ERROR);
            break;
        }

        gcreMsg = dynamic_pointer_cast<GameContextRemoveElementMessage>(message);
        if(dofusBotParent->getMapInfosAsRoleplay() && dofusBotParent->getMapInfosAsRoleplay()->getPlayer(gcreMsg->id))
            Logger::write("Player : " + dofusBotParent->getMapInfosAsRoleplay()->getPlayer(gcreMsg->id)->name + " exited.", LOG_INFO);
        else 
            Logger::write("Entity : " + to_string(gcreMsg->id) + " was removed.", LOG_INFO);
        dofusBotParent->mapInfos->removeActor(gcreMsg->id);
        break;

    case GameRolePlayShowActorMessage::protocolId:
        grpsaMsg = dynamic_pointer_cast<GameRolePlayShowActorMessage>(message);
        if(!dofusBotParent->getMapInfosAsRoleplay()) {
            Logger::write("Player on map but map info is not initialized !!", LOG_ERROR);
            break;
        }

        dofusBotParent->mapInfos->addActor(grpsaMsg->informations);
        if(dofusBotParent->getMapInfosAsRoleplay() && dofusBotParent->getMapInfosAsRoleplay()->getPlayer(grpsaMsg->informations->contextualId))
            Logger::write("Added player : " + dofusBotParent->getMapInfosAsRoleplay()->getPlayer(grpsaMsg->informations->contextualId)->name, LOG_DEBUG);
        else 
            Logger::write("Added actor : " + to_string(grpsaMsg->informations->contextualId), LOG_DEBUG);

        break;

    case GameMapChangeOrientationMessage::protocolId:
        gmcoMsg = dynamic_pointer_cast<GameMapChangeOrientationMessage>(message);
        if(!dofusBotParent->getMapInfosAsRoleplay()) {
            Logger::write("Player on map but map info is not initialized !!", LOG_ERROR);
            break;
        }

        if(dofusBotParent->mapInfos->getActor(gmcoMsg->orientation.id)) {
            dofusBotParent->mapInfos->getActor(gmcoMsg->orientation.id)->direction = gmcoMsg->orientation.id;
            Logger::write("Actor : " + to_string(gmcoMsg->orientation.id) + " is now oriented to " + to_string(gmcoMsg->orientation.direction), LOG_INFO);
        }
        break;

    case SetCharacterRestrictionsMessage::protocolId:
        scrMsg = dynamic_pointer_cast<SetCharacterRestrictionsMessage>(message);
        if(!dofusBotParent->getMapInfosAsRoleplay()) {
            Logger::write("Player on map but map info is not initialized !!", LOG_ERROR);
            break;
        }

        if (dofusBotParent->getMapInfosAsRoleplay() && dofusBotParent->getMapInfosAsRoleplay()->getPlayer(scrMsg->actorId))
            dofusBotParent->getMapInfosAsRoleplay()->getPlayer(scrMsg->actorId)->restrictions = scrMsg->restrictions;
        break;

    case GameContextDestroyMessage::protocolId:
        Logger::write("Roleplay context destroyed.", LOG_INFO);
        dofusBotParent->addFrame(make_shared<SwitchContextFrame>());
        dofusBotParent->removeFrame(this);

        dofusBotParent->popAllFrames<MovementFrame>();
        dofusBotParent->popAllFrames<BasicActionsFrame>();
        dofusBotParent->popAllFrames<TempDialogFrame>();

        break;
    default:
        return false;
    }  

    return true;
}

bool RoleplayContextFrame::sendGameMapMovementConfirmMessage(){
    sp<GameMapMovementConfirmMessage> gmmcMsg(new GameMapMovementConfirmMessage());

    if(!gmmcMsg) {
        Logger::write("Cannot build GameMapMovementConfirmMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    if(!sendPacket(gmmcMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send GameMapMovementConfirmMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}

bool RoleplayContextFrame::sendMapInformationsRequestMessage(double mapId){
    sp<MapInformationsRequestMessage> mirMsg(new MapInformationsRequestMessage());

    if(!mirMsg) {
        Logger::write("Cannot build MapInformationsRequestMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }
    
    mirMsg->mapId = mapId;

    if(!sendPacket(mirMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send MapInformationRequestMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}

bool RoleplayContextFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message has been sent and changes Frame's state if needed
    switch (messageId)
    {
    case MapInformationsRequestMessage::protocolId:
        Logger::write("MapInformationsRequestMessage sent.", LOG_INFO);
        break;

    case GameMapMovementConfirmMessage::protocolId:
        Logger::write("GameMapMovementConfirmMessage sent.", LOG_INFO);
        break;
    
    default:
        Logger::write("Message of id " + to_string(messageId) + " was successfully sent.", LOG_INFO);
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool RoleplayContextFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message could not be sent and kills bot if needed
    switch (messageId)
    {
    case MapInformationsRequestMessage::protocolId:
        Logger::write("MapInformationsRequestMessage could not be sent.", LOG_WARNING);
        // A voir si bot kill
        break;
    
    case GameMapMovementConfirmMessage::protocolId:
        Logger::write("GameMapMovementConfirmMessage could not be sent.", LOG_WARNING);
        // A voir si bot kill
        break;
    
    default:
        Logger::write("Message of id " + to_string(messageId) + " was could not be sent. Reason : " + message->reason, LOG_WARNING);
        // A voir si bot kill
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}
