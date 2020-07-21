#ifndef AUTHENTIFICATION_FRAME_H
#define AUTHENTIFICATION_FRAME_H

#include "PacketSendingDofusBotFrame.h"
#include "DofusBotUnit.h"
#include "AuthentificationManager.h"
#include "GameServerConnectionFrame.h"

#include "BeginAuthentificationMessage.h"
#include "RetryAuthentificationMessage.h"
#include "ConnectionSuccessMessage.h"
#include "ConnectionFailureMessage.h"
#include "BeginGameServerConnectionMessage.h"

#include "SelectedServerDataExtendedMessage.h"
#include "CredentialsAcknowledgementMessage.h"
#include "IdentificationSuccessMessage.h"
#include "IdentificationFailedForBadVersionMessage.h"

#include "ProtocolRequired.h"
#include "HelloConnectMessage.h"
#include "ClientKeyMessage.h"

// States that the frame can be in; Keeps track of what to do next and if every thing is going in the right order
enum AuthentificationFrameState {
    af_idle,
    begin_authentification,
    rcv_HelloConnectMessage,
    snd_IdentificationMessage,
    rcv_CredentialAknowledgmentMessage,
    rcv_IdentificationResponseMessage,
    end_authentification
};

class AuthentificationManager;
class AuthentificationFrame : public PacketSendingDofusBotFrame {
public :
    // Constructor
    AuthentificationFrame();
    // Constructor with AuthentificationManager initialization
    AuthentificationFrame(sp<AuthentificationManager> manager) { this->manager = manager; };
    // Copy constructor
    AuthentificationFrame(const AuthentificationFrame& other) = default;

    // Copy operator
    AuthentificationFrame& operator=(const AuthentificationFrame& other) = default;
    // Destructor
    ~AuthentificationFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;

    virtual bool setParent(MessagingUnit* parent) override;

protected:
    // AuthentificationManager; does many heavy operations
    sp<AuthentificationManager> manager;

    virtual bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    virtual bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

    // Connection's id to the authentification server
    int authentificationServerConnectionId = -1;

    // Current Frame's state
    AuthentificationFrameState currentState = af_idle;  

    // Sends IdentificationMessage
    bool sendIdentificationMessage(sp<HelloConnectMessage> hcMsg);
    // Sends ClientKeyMessage
    bool sendClientKeyMessage();
};

#endif