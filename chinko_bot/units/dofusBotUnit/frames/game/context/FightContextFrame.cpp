#include "FightContextFrame.h"

bool FightContextFrame::computeMessage(sp<Message> message, int srcId) {

    sp<GameFightStartingMessage> gfsMsg;
    sp<GameFightShowFighterMessage> gfsfMsg;
    sp<GameEntitiesDispositionMessage> gedMsg;
    sp<GameFightUpdateTeamMessage> gfutMsg;
    sp<GameFightHumanReadyStateMessage> gfhrsMsg;

    sp<GameFightTurnReadyRequestMessage> gftrrMsg;
    sp<GameFightNewRoundMessage> gfnrMsg;
    sp<GameFightTurnStartMessage> gftsMsg;
    sp<GameFightSynchronizeMessage> gfsyncMsg;
    
    sp<GameFightRefreshFighterMessage> gfrfMsg;
    sp<GameActionFightSpellCastMessage> gafscMsg;
    sp<GameActionFightNoSpellCastMessage> gafnscMsg;
    sp<GameActionFightCloseCombatMessage> gafccMsg;
    sp<FighterStatsListMessage> fslMsg;
    sp<GameMapMovementMessage> gmmMsg;
    sp<GameMapNoMovementMessage> gmnmMsg;

    sp<GameActionFightPointsVariationMessage> gafpvMsg;
    sp<GameActionFightLifeAndShieldPointsLostMessage> gaflasplMsg;
    sp<GameActionFightLifePointsLostMessage> gaflplMsg;
    sp<GameActionFightLifePointsGainMessage> gaflpgMsg;
    sp<GameActionFightTeleportOnSameMapMessage> gaftosmMsg;
    sp<GameActionFightExchangePositionsMessage> gafepMsg;
    sp<GameActionFightSlideMessage> gafsMsg;
    sp<GameActionFightMarkCellsMessage> gafmcMsg;
    sp<GameActionFightUnmarkCellsMessage> gafucMsg;
    sp<GameActionFightDeathMessage> gafdMsg;
    sp<GameActionFightKillMessage> gafkMsg;
    sp<SequenceEndMessage> seMsg;
    

    switch (message->getId())
    {
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
    
    case GameFightStartingMessage::protocolId:
        gfsMsg = dynamic_pointer_cast<GameFightStartingMessage>(message);
        Logger::write("Fight (type : " + to_string(gfsMsg->fightType) + ") starting. Atttacker : " + to_string(gfsMsg->attackerId) + ".", LOG_INFO);
        // Save fight info?
        dofusBotParent->mapInfos = make_shared<FightMapManager>();
        break;

    case GameFightJoinMessage::protocolId:
        if(!dofusBotParent->getMapInfosAsFight())
            dofusBotParent->mapInfos = make_shared<FightMapManager>();
        
        // TODO : check si il y a pas un moyen de récupérer l'id de la current map
        dofusBotParent->mapInfos->loadMapInformations(dofusBotParent->currentMapId);

        dofusBotParent->sendSelfMessage(make_shared<TimedMessage>(make_shared<GetFightReadyMessage>(), 5000));
        break;

    case GameFightShowFighterMessage::protocolId:
        gfsfMsg = dynamic_pointer_cast<GameFightShowFighterMessage>(message);
        Logger::write("GameFightShowFighterMessage received.", LOG_INFO);

        if(!dofusBotParent->getMapInfosAsFight()) {
            Logger::write("Cannot show fighter when the map manager is not configured for a fight.", LOG_ERROR);
            this->killBot();
            break;
        }
        
        dofusBotParent->getMapInfosAsFight()->updateFighter(gfsfMsg->informations);
        if(dofusBotParent->playedCharacter && gfsfMsg->informations->contextualId == dofusBotParent->playedCharacter->contextualId) {
            sp<ActorData> playedCharacter = dofusBotParent->mapInfos->getActor(dofusBotParent->playedCharacter->contextualId);
            if(playedCharacter) {
                dofusBotParent->playedCharacter = playedCharacter;
                
                dofusBotParent->playedCharacter->canSeeThrough = true;
                dofusBotParent->playedCharacter->canWalkThrough = true;
                dofusBotParent->playedCharacter->canWalkTo = true;
            } else {
                Logger::write("Could not build played character!!", LOG_ERROR);
            }
        } 

        break;

    case GameEntitiesDispositionMessage::protocolId:
        gedMsg = dynamic_pointer_cast<GameEntitiesDispositionMessage>(message);
        Logger::write("GameEntitiesDispositionMessage received", LOG_INFO);

        for(auto disposition : gedMsg->dispositions) 
            dofusBotParent->mapInfos->updateActorPosition(disposition.id, disposition.cellId);
        break;
        
    case GameFightUpdateTeamMessage::protocolId:
        gfutMsg = dynamic_pointer_cast<GameFightUpdateTeamMessage>(message);
        Logger::write("GameFightUpdateTeamMessage received.", LOG_INFO);

        if(!dofusBotParent->getMapInfosAsFight()) {
            Logger::write("Cannot update teams when the map manager is not configured for a fight.", LOG_ERROR);
            this->killBot();
            break;
        }

        for(auto teamMember : gfutMsg->team.teamMembers) {
            dofusBotParent->getMapInfosAsFight()->updateTeamInfos(teamMember->id, gfutMsg->team.teamId);
            // TeamEnum : teamSide; TeamTypeEnum : teamTypeId
            Logger::write(to_string(teamMember->id) + " is in team " + to_string(gfutMsg->team.teamId) + " (team side : " + to_string(gfutMsg->team.teamSide) + "; team typeId : " + to_string(gfutMsg->team.teamTypeId) + ")", LOG_DEBUG);
        }
        break;

    case GameContextDestroyMessage::protocolId:
        Logger::write("Fight context destroyed.", LOG_INFO);
        dofusBotParent->addFrame(make_shared<SwitchContextFrame>());
        dofusBotParent->removeFrame(this);
        dofusBotParent->popAllFrames<FightActionFrame>();
        dofusBotParent->popAllFrames<FightAIFrame>();
        break;

    case GameFightHumanReadyStateMessage::protocolId:
        gfhrsMsg = dynamic_pointer_cast<GameFightHumanReadyStateMessage>(message);
        Logger::write(to_string(gfhrsMsg->characterId) + " is ready to fight.", LOG_INFO);
        break;

    case GameFightStartMessage::protocolId:
        Logger::write("Game fight start.", LOG_INFO);

        if(!dofusBotParent->getMapInfosAsFight()) {
            Logger::write("Cannot start fight when the map manager is not configured for a fight.", LOG_ERROR);
            this->killBot();
            break;
        }

        dofusBotParent->addFrame(make_shared<FightAIFrame>());
        break;

    case GameFightTurnListMessage::protocolId:
        Logger::write("GameFightTurnListMessage recevied.", LOG_INFO);
        break;

    case GameFightNewRoundMessage::protocolId:
        gfnrMsg = dynamic_pointer_cast<GameFightNewRoundMessage>(message);
        Logger::write("Nouveau tour. Count : " + to_string(gfnrMsg->roundNumber), LOG_INFO);
        break;

    case GameFightSynchronizeMessage::protocolId:
        gfsyncMsg = dynamic_pointer_cast<GameFightSynchronizeMessage>(message);
        if(!dofusBotParent->getMapInfosAsFight()) {
            Logger::write("Player in fight but map info is not initialized !!", LOG_ERROR);
            break;
        }
        for(auto fighter : gfsyncMsg->fighters)
            dofusBotParent->getMapInfosAsFight()->updateFighter(fighter);
        
        Logger::write("Fight synchronization done.", LOG_DEBUG);
        break;

    case GameFightTurnStartMessage::protocolId:
        gftsMsg = dynamic_pointer_cast<GameFightTurnStartMessage>(message);
        if(gftsMsg->id == dofusBotParent->playedCharacter->contextualId) {
            Logger::write("Beginning turn.", LOG_INFO);
            dofusBotParent->sendSelfMessage(make_shared<TimedMessage>(make_shared<ReadyNextFightActionMessage>(), 1000));
        }
        break;

    case GameFightTurnReadyRequestMessage::protocolId:
        // TODO : cooldown sorts
        gftrrMsg = dynamic_pointer_cast<GameFightTurnReadyRequestMessage>(message);
        Logger::write("End of the turn of entity " + to_string(gftrrMsg->id), LOG_DEBUG);     

        dofusBotParent->getMapInfosAsFight()->endFighterTurn(gftrrMsg->id);
        sendGameFightTurnReadyMessage();
        break;

    case CurrentMapMessage::protocolId:
        Logger::write("Receiving CurrentMapMessage!!!!!!!", LOG_WARNING);
        break;

    case GameFightRefreshFighterMessage::protocolId:
        gfrfMsg = dynamic_pointer_cast<GameFightRefreshFighterMessage>(message);
        Logger::write("TODO : HANDLE GameFightRefreshFighterMessage IN FightContextFrame !!!!!", LOG_ERROR);
        break;

    case GameActionFightCloseCombatMessage::protocolId:
        gafccMsg = dynamic_pointer_cast<GameActionFightCloseCombatMessage>(message);
        Logger::write("Entity " + to_string(gafccMsg->sourceId) + " is attacking with weapon of id " + to_string(gafccMsg->weaponGenericId) + ".", LOG_INFO);
        break;

    case GameActionFightSpellCastMessage::protocolId:
        gafscMsg = dynamic_pointer_cast<GameActionFightSpellCastMessage>(message);
        Logger::write("Entity " + to_string(gafscMsg->sourceId) + " is attacking with spell of id " + to_string(gafscMsg->spellId) + ".", LOG_INFO);
        break;

    case GameActionFightNoSpellCastMessage::protocolId:
        gafnscMsg = dynamic_pointer_cast<GameActionFightNoSpellCastMessage>(message);
        Logger::write("Could not cast spell of id  : " + to_string(gafnscMsg->spellLevelId), LOG_WARNING);
        dofusBotParent->sendSelfMessage(make_shared<FightActionFailureMessage>());
        break;

    case FighterStatsListMessage::protocolId:
        fslMsg = dynamic_pointer_cast<FighterStatsListMessage>(message);
        Logger::write("TODO : HANDLE FighterStatsListMessage IN FightContextFrame !!!!!", LOG_ERROR);
        fslMsg->stats;
        break;

    case GameMapMovementMessage::protocolId:
        gmmMsg = dynamic_pointer_cast<GameMapMovementMessage>(message);
        dofusBotParent->mapInfos->updateActorPosition(gmmMsg->actorId, gmmMsg->keyMovements.back() & 0xFFF);
        Logger::write(to_string(gmmMsg->actorId) + " moved from cell " + to_string(gmmMsg->keyMovements.front() & 0xFFF) + " to cell " + to_string(gmmMsg->keyMovements.back() & 0xFFF), LOG_INFO);
        break;

    case GameMapNoMovementMessage::protocolId:
        gmnmMsg = dynamic_pointer_cast<GameMapNoMovementMessage>(message);
        Logger::write("Unauthorized movement.", LOG_WARNING);
        dofusBotParent->sendSelfMessage(make_shared<FightActionFailureMessage>());
        break;

    case GameActionFightPointsVariationMessage::protocolId:
        gafpvMsg = dynamic_pointer_cast<GameActionFightPointsVariationMessage>(message);
        {
            sp<FighterData> target = dofusBotParent->getMapInfosAsFight()->getFighter(gafpvMsg->targetId);
            if(target) {
                switch (gafpvMsg->actionId)
                {
                case ActionIds::PA_LOST:
                case ActionIds::PA_USE:
                case ActionIds::PA_WIN:
                    target->stats->actionPoints += gafpvMsg->delta;
                    break;
                case ActionIds::PM_LOST:
                case ActionIds::PM_USE:
                case ActionIds::PM_WIN:
                    target->stats->movementPoints += gafpvMsg->delta;
                    break;
                }

                Logger::write(to_string(target->contextualId) + " is now at " + to_string(target->stats->actionPoints) + "/" + to_string(target->stats->maxActionPoints) + "PA and " + to_string(target->stats->movementPoints) + "/" + to_string(target->stats->maxMovementPoints) + "PM.", LOG_INFO);
            } else {
                Logger::write("Could not find target of GameActionFightPointsVariationMessage", LOG_ERROR);
            }
        }
        break;

    case GameActionFightLifeAndShieldPointsLostMessage::protocolId:
        gaflasplMsg = dynamic_pointer_cast<GameActionFightLifeAndShieldPointsLostMessage>(message);
        if(gaflasplMsg->shieldLoss != 0)
            Logger::write("TODO : HANDLE SHIELD POINTS IN FightContextFrame WHEN CHARACTER RECEIVE BUFF !!!!!", LOG_ERROR);
    case GameActionFightLifePointsLostMessage::protocolId:
        gaflplMsg = dynamic_pointer_cast<GameActionFightLifePointsLostMessage>(message);
        {
            sp<FighterData> target = dofusBotParent->getMapInfosAsFight()->getFighter(gaflplMsg->targetId);
            if(target) {
                target->stats->lifePoints = max(0, target->stats->lifePoints - gaflplMsg->loss);
                target->stats->maxLifePoints = max(1, target->stats->maxLifePoints - gaflplMsg->permanentDamages);
                Logger::write(to_string(target->contextualId) + " is now at " + to_string(target->stats->lifePoints) + "/" + to_string(target->stats->maxLifePoints) + " hp", LOG_INFO);
            } else {
                Logger::write("Could not find target of GameActionFightLifePointsLostMessage", LOG_ERROR);
            }
        }
        break;

    case GameActionFightLifePointsGainMessage::protocolId:
        gaflpgMsg = dynamic_pointer_cast<GameActionFightLifePointsGainMessage>(message);
        {
            sp<FighterData> target = dofusBotParent->getMapInfosAsFight()->getFighter(gaflpgMsg->targetId);
            if(target) {
                target->stats->lifePoints = max(0, target->stats->lifePoints + gaflpgMsg->delta);
                Logger::write(to_string(target->contextualId) + " is now at " + to_string(target->stats->lifePoints) + "/" + to_string(target->stats->maxLifePoints) + " hp", LOG_INFO);
            } else {
                Logger::write("Could not find target of GameActionFightLifePointsGainMessage", LOG_ERROR);
            }
        }
        break;

    case GameActionFightTeleportOnSameMapMessage::protocolId:
        gaftosmMsg = dynamic_pointer_cast<GameActionFightTeleportOnSameMapMessage>(message);
        Logger::write(to_string(gaftosmMsg->targetId) + " teleported on cell " + to_string(gaftosmMsg->cellId) + ".", LOG_INFO);
        dofusBotParent->mapInfos->updateActorPosition(gaftosmMsg->targetId, gaftosmMsg->cellId);
        break;

    case GameActionFightExchangePositionsMessage::protocolId:
        gafepMsg = dynamic_pointer_cast<GameActionFightExchangePositionsMessage>(message);
        Logger::write(to_string(gafepMsg->sourceId) + " exchanged positions with " + to_string(gafepMsg->targetId), LOG_INFO);
        dofusBotParent->mapInfos->updateActorPosition(gafepMsg->sourceId, gafepMsg->targetCellId);
        dofusBotParent->mapInfos->updateActorPosition(gafepMsg->targetId, gafepMsg->casterCellId);
        break;

    case GameActionFightSlideMessage::protocolId:
        gafsMsg = dynamic_pointer_cast<GameActionFightSlideMessage>(message);
        Logger::write(to_string(gafsMsg->targetId) + " slided to cell " + to_string(gafsMsg->endCellId), LOG_INFO);
        dofusBotParent->mapInfos->updateActorPosition(gafsMsg->targetId, gafsMsg->endCellId);
        break;

    case GameActionFightMarkCellsMessage::protocolId:
        gafmcMsg = dynamic_pointer_cast<GameActionFightMarkCellsMessage>(message);
        dofusBotParent->mapInfos->addMark(gafmcMsg->mark);
        Logger::write("Cells marked.", LOG_INFO);
        break;

    case GameActionFightUnmarkCellsMessage::protocolId:
        gafucMsg = dynamic_pointer_cast<GameActionFightUnmarkCellsMessage>(message);
        dofusBotParent->mapInfos->removeMark(gafucMsg->markId);
        Logger::write("Cells unmarked.", LOG_INFO);
        break;

    case GameActionFightDeathMessage::protocolId:
        gafdMsg = dynamic_pointer_cast<GameActionFightDeathMessage>(message);
        dofusBotParent->getMapInfosAsFight()->fighterDied(gafdMsg->targetId);
        
        if(gafdMsg->sourceId != gafdMsg->targetId)
            Logger::write(to_string(gafdMsg->sourceId) + " killed " + to_string(gafdMsg->targetId), LOG_INFO);
        else 
            Logger::write(to_string(gafdMsg->sourceId) + " gave up.", LOG_INFO);
            
        if(gafdMsg->targetId == dofusBotParent->playedCharacter->contextualId)
            Logger::write("You died!!", LOG_WARNING);
        break;

    case GameActionFightKillMessage::protocolId:
        Logger::write("Received GameActionFightKillMessage : find out what is different with GameActionFightDeathMessage", LOG_IMPORTANT_WARNING);
        break;

    case SequenceEndMessage::protocolId:
        seMsg = dynamic_pointer_cast<SequenceEndMessage>(message);
        if(seMsg->authorId == dofusBotParent->playedCharacter->contextualId) {
            this->sendGameActionAcknowledgementMessage(seMsg);
            dofusBotParent->sendSelfMessage(make_shared<TimedMessage>(make_shared<ReadyNextFightActionMessage>(), 3000));
        }
        break;    

    // TODO : case GameActionFightInvisibilityStateEnum::protocolId: -> change canSeeThrough & canWalkThrough 

    default:
        return false;
    }

    return true;
}

// TODO : prendre encompte FightSpellCastFrame -> change canSeeThrough & canWalkThrough 

bool FightContextFrame::handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message has been sent and changes Frame's state if needed
    switch (messageId)
    {
    case GameFightTurnReadyMessage::protocolId:
        Logger::write("GameFightTurnReadyMessage sent.", LOG_INFO);
        break;

    case GameActionAcknowledgementMessage::protocolId:
        Logger::write("GameActionAcknowledgementMessage sent.", LOG_INFO);
        break;

    default:
        Logger::write("Message of id " + to_string(messageId) + " was successfully sent.", LOG_INFO);
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool FightContextFrame::handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) {
    // Checks if the message was sent by this frame
    auto it = packetId_to_messageId.find(message->packetId);
    if(it == packetId_to_messageId.end())
        return false;

    // If so, gets the mapped message id
    int messageId = it->second;

    // Logs what message could not be sent and kills bot if needed
    switch (messageId)
    {
    case GameFightTurnReadyMessage::protocolId:
        Logger::write("Could not send GameFightTurnReadyMessage. Reason : " + message->reason, LOG_WARNING);
        break;
    
    case GameActionAcknowledgementMessage::protocolId:
        Logger::write("Could not send GameActionAcknowledgementMessage. Reason : " + message->reason, LOG_WARNING);
        break;
    
    default:
        Logger::write("Message of id " + to_string(messageId) + " was could not be sent. Reason : " + message->reason, LOG_WARNING);
        // A voir si bot kill
        break;
    }

    packetId_to_messageId.erase(it);

    return true;
}

bool FightContextFrame::sendGameFightTurnReadyMessage(bool ready) {
    sp<GameFightTurnReadyMessage> gftrMsg = make_shared<GameFightTurnReadyMessage>();

    if(!gftrMsg) {
        Logger::write("Cannot build GameFightTurnReadyMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    gftrMsg->isReady = ready;

    if(!sendPacket(gftrMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send GameFightTurnReadyMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;
}

bool FightContextFrame::sendGameActionAcknowledgementMessage(sp<SequenceEndMessage> message) {
    sp<GameActionAcknowledgementMessage> gaaMsg = make_shared<GameActionAcknowledgementMessage>();

    if(!gaaMsg) {
        Logger::write("Cannot build GameFightTurnReadyMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    gaaMsg->valid = (message->authorId == dofusBotParent->playedCharacter->contextualId);
    gaaMsg->actionId = message->actionId;

    if(!sendPacket(gaaMsg, dofusBotParent->gameServerInfos.connectionId)) {
        Logger::write("Cannot send GameFightTurnReadyMessage.", LOG_ERROR);
        this->killBot();
        return false;
    }

    return true;

}