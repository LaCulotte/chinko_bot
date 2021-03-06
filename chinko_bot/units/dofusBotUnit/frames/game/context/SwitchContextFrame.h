#ifndef CONTEXT_FRAME_H
#define CONTEXT_FRAME_H

#include "PacketSendingDofusBotFrame.h"

// #include "TempDialogFrame.h"
// #include "MovementFrame.h"
// #include "BasicActionsFrame.h"

#include "RoleplayContextFrame.h"
#include "FightContextFrame.h"
#include "FightActionFrame.h"
#include "FightAIFrame.h"

#include "RoleplayCharacterData.h"

#include "BeginGameContextRequestMessage.h"

#include "GameContextCreateRequestMessage.h"
#include "GameContextCreateMessage.h"
#include "GameContextDestroyMessage.h"

// TODO : faire des fichiers séparés pour chaque enum
enum GameContextEnum {
    Roleplay = 1,
    Fight = 2
};

class SwitchContextFrame : public PacketSendingDofusBotFrame {
public:
    // Constructor
    SwitchContextFrame() : PacketSendingDofusBotFrame() {}; 
    // Copy constructor
    SwitchContextFrame(const SwitchContextFrame& other) = default;

    // Copy operator
    SwitchContextFrame& operator=(const SwitchContextFrame& other) = default;
    // Destructor
    ~SwitchContextFrame() = default;

    bool computeMessage(sp<Message> message, int srcId) override;

protected:
    virtual bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    virtual bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

    // Sends GameContextCreateRequestMessage
    bool sendGameContextCreateRequestMessage();
};

#endif