#ifndef GAMESERVERCONNECTION_FRAME_H
#define GAMESERVERCONNECTION_FRAME_H

#include "Frame.h"
#include "DofusBotUnit.h"
#include "AuthentificationManager.h"
#include "CharacterSelectionFrame.h"

#include "BeginGameServerConnectionMessage.h"
#include "BeginCharacterSelectionMessage.h"

#include "SendPacketSuccessMessage.h"
#include "SendPacketFailureMessage.h"

#include "ProtocolRequiredMessage.h"
#include "HelloGameMessage.h"
#include "AuthentificationTicketMessage.h"


enum GameServerConnectionFrameState {
    gcsf_idle = 0,
    rcv_HelloGameMessage,
    snd_AuthentificationTicketMessage,
    rcv_RawDataMessage,
    snd_CheckIntegrityMessage,
    rcv_AuthentificationTicketResponseMessage
};

class AuthentificationManager;
class GameServerConnectionFrame : public Frame {
public:
    // Constructor
    GameServerConnectionFrame() {};
    // Constructor
    GameServerConnectionFrame(sp<AuthentificationManager> manager) { this->manager = manager; };
    // Copy constructor
    GameServerConnectionFrame(const GameServerConnectionFrame& other) = default;

    // Copy operator
    GameServerConnectionFrame& operator=(const GameServerConnectionFrame& other) = default;
    // Destructor
    ~GameServerConnectionFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;

    virtual bool setParent(MessagingUnit* parent) override;

protected:
    sp<AuthentificationManager> manager;

    string serverAddress;
    vector<int> serverPorts;
    int serverPorts_i = 0;

    GameServerConnectionFrameState currentState = gcsf_idle;

    bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message);
    bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message);

};

#endif