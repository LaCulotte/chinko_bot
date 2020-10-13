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
// #include "TimedMessage.h"

// #include "SendMovementConfirmMessage.h"
// #include "PlayerMovementEndedMessage.h"
// #include "PlayerMovementErrorMessage.h"
// #include "CurrentMapChangedMessage.h"

#include "GameContextCreateRequestMessage.h"
#include "GameContextCreateMessage.h"
#include "GameContextDestroyMessage.h"
// #include "CurrentMapMessage.h"
// #include "MapInformationsRequestMessage.h"
// #include "MapComplementaryInformationsDataMessage.h"
// #include "GameMapMovementMessage.h"
// #include "GameMapNoMovementMessage.h"
// #include "GameMapMovementConfirmMessage.h"
// #include "GameContextRemoveElementMessage.h"
// #include "GameRolePlayShowActorMessage.h"
// #include "GameMapChangeOrientationMessage.h"
// #include "SetCharacterRestrictionsMessage.h"

// #include "StatedElementUpdatedMessage.h"
// #include "InteractiveElementUpdatedMessage.h"
// #include "InteractiveUsedMessage.h"

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