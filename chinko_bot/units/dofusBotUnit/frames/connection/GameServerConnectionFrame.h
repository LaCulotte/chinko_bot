#ifndef GAMESERVERCONNECTION_FRAME_H
#define GAMESERVERCONNECTION_FRAME_H

// #include "Frame.h"
#include "PacketSendingDofusBotFrame.h"
#include "DofusBotUnit.h"
#include "AuthentificationManager.h"
#include "AuthentificationFrame.h"
#include "CharacterSelectionFrame.h"

#include "BeginGameServerConnectionMessage.h"
#include "BeginCharacterSelectionMessage.h"
#include "RetryAuthentificationMessage.h"

#include "SendPacketSuccessMessage.h"
#include "SendPacketFailureMessage.h"

#include "ProtocolRequiredMessage.h"
#include "HelloGameMessage.h"
#include "AuthentificationTicketMessage.h"


enum GameServerConnectionFrameState {
    gcsf_idle = 0,
    begin_GameServerConnection,
    rcv_HelloGameMessage,
    snd_AuthentificationTicketMessage,
    rcv_RawDataMessage,
    snd_CheckIntegrityMessage,
    rcv_AuthentificationTicketResponseMessage,
    end_GameServerConnection
};

class AuthentificationManager;
class GameServerConnectionFrame : public PacketSendingDofusBotFrame {
public:
    // Constructor
    GameServerConnectionFrame() : PacketSendingDofusBotFrame() {};
    // Constructor
    GameServerConnectionFrame(sp<AuthentificationManager> manager) { this->manager = manager; };
    // Copy constructor
    GameServerConnectionFrame(const GameServerConnectionFrame& other) = default;

    // Copy operator
    GameServerConnectionFrame& operator=(const GameServerConnectionFrame& other) = default;
    // Destructor
    ~GameServerConnectionFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;

protected:
    sp<AuthentificationManager> manager;

    string serverAddress;
    vector<int> serverPorts;
    int serverPorts_i = 0;

    GameServerConnectionFrameState currentState = gcsf_idle;

    bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

    bool sendAuthentificationTicketMessage();
    bool sendCheckIntegrityMessage();

    // TODO : faire des tests
    void retryAuthentification();
};

#endif