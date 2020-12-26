#include "DofusBotUnit.h"

#include "AuthentificationFrame.h"
#include "FightFrame.h"
#include "QueueFrame.h"
#include "BasicDofusBotFrame.h"
#include "APIActionsFrame.h"
#include "CommandFrame.h"

DofusBotUnit::DofusBotUnit() : MessagingUnit() {
    // Inits the PlayedCharacterManager
    characterManager = make_shared<PlayedCharacterManager>(); 
    characterManager->dofusBot = this;
}

// TODO : check si l'ordre d'ajout des frames est important dans ce cas la!!
void DofusBotUnit::initFrames() {
    MessagingUnit::initFrames();

    // Adds necessary frames
    this->addFrame(make_shared<AuthentificationFrame>());
    this->addFrame(make_shared<BasicDofusBotFrame>());

    // TODO REMOVE : 
    this->addFrame(make_shared<FightFrame>());

    this->addFrame(make_shared<QueueFrame>());

    sp<Frame> cmdFrame = make_shared<CommandFrame>();
    cmdFrame->setPriority(-1);
    this->addFrame(cmdFrame);
}

void DofusBotUnit::tick() {
    MessagingUnit::tick();

    // Resets the bot if necessary
    if(this->toReset)
        fullReset();
}

int DofusBotUnit::sendPacket(sp<ConnectionMessage> message, int connectionId) {

    if(connectionUnitId == -1) {
        // Tries to get ConnectionUnit's id 
        connectionUnitId = getMessageInterfaceOutId<ConnectionUnit>();
        if(connectionUnitId == -1) {
            // Error if there is not ConnectionUnit linked to the bot 
            Logger::write("Cannot send packet : there is no ConnectionUnit linked to the current DofusBotUnit", LOG_ERROR);
            return -1;
        }
    }

    // Builds a SendPacketRequestMessage 
    sp<SendPacketRequestMessage> sendPacketRequest(new SendPacketRequestMessage(message, connectionId));

    // Sets the packet Id
    sendPacketRequest->packetId = lastPacketId;

    // Send the request to the ConnectionUnit
    if(!sendMessage(sendPacketRequest, connectionUnitId)) {
        Logger::write("Could not send packet : could not send request to the ConnectionUnit", LOG_ERROR);
        return -1;
    }

    return lastPacketId++;
}

void DofusBotUnit::resetPlayedCharacter() {
    if(playedCharacter) {
        // Stores the character's id
        double id = playedCharacter->contextualId;

        // Resets the played character
        playedCharacter = make_shared<ActorData>();
        playedCharacter->contextualId = id;
    }
}

int DofusBotUnit::getConnectionUnitId() {
    // Gets ConnectionUnit's id
    if(connectionUnitId == -1) {
        connectionUnitId = this->getMessageInterfaceOutId<ConnectionUnit>();
        if(connectionUnitId == -1)
            Logger::write("No connectionUnit linked to dofusBotUnit.", LOG_WARNING);
    }

    return connectionUnitId;
}

int DofusBotUnit::getAPIUnitId() {
    // Gets APIUnit's id
    if(apiUnitId == -1) {
        apiUnitId = this->getMessageInterfaceOutId<APIUnit>();
        if(apiUnitId == -1)
            Logger::write("No apiUnit linked to dofusBotUnit.", LOG_WARNING);
    }

    return apiUnitId;
}

void DofusBotUnit::fullReset() {
    // Resets all from the bot 

    // TODO : hard remove de toutes les frames (ici tout ce que ca fait c'est marquer les frames comme "à remove")
    this->removeFrames(getAllFrames<Frame>());
    this->messagesToProcess.clear();

    toReset = false;
    apiUnitId = -1;
    connectionUnitId = -1;
    
    mapInfos.reset();
    playedCharacter.reset();
    
    if(gameServerInfos.connectionId != -1)
        this->sendMessage(make_shared<DisconnectRequestMessage>(vector<int>({gameServerInfos.connectionId})), this->getConnectionUnitId());
    gameServerInfos = GameServerData();

    this->initFrames();

    Logger::write("Bot has been reset!", LOG_WARNING);
}