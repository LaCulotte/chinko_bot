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

#include "ProtocolRequired.h"
#include "HelloGameMessage.h"
#include "RawDataMessage.h"
#include "AuthenticationTicketMessage.h"
#include "AuthenticationTicketAcceptedMessage.h"

// States that the frame can be in; Keeps track of what to do next and if every thing is going in the right order
enum GameServerConnectionFrameState {
    gcsf_idle = 0,
    begin_GameServerConnection,
    rcv_HelloGameMessage,
    snd_AuthenticationTicketMessage,
    rcv_RawDataMessage,
    snd_CheckIntegrityMessage,
    rcv_AuthenticationTicketResponseMessage,
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
    // AuthentificationManager; does many heavy operations
    sp<AuthentificationManager> manager;

    // Game server's address
    string serverAddress;
    // Game server's possibles ports
    vector<int> serverPorts;
    // Iterator throught 'serverPorts'
    int serverPorts_i = 0;

    // Current Frame's state
    GameServerConnectionFrameState currentState = gcsf_idle;

    bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

    // Sends AuthenticationTicketMessage
    bool sendAuthenticationTicketMessage();
    // Sends CheckIntegrityMessage
    bool sendCheckIntegrityMessage();

    // TODO : FAIRE DES TESTS BORDEL
    // Returns to the authentification server 'cause the Game Server connection went wrong
    void retryAuthentification();
};

#endif