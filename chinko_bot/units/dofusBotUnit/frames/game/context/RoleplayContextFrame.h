#ifndef ROLEPLAY_CONTEXT_FRAME_H
#define ROLEPLAY_CONTEXT_FRAME_H

#include "PacketSendingDofusBotFrame.h"

#include "TimedMessage.h"

#include "TempDialogFrame.h"
#include "MovementFrame.h"
#include "BasicActionsFrame.h"

#include "SwitchContextFrame.h"
#include "GameContextDestroyMessage.h"

#include "CurrentMapMessage.h"
#include "MapInformationsRequestMessage.h"
#include "MapComplementaryInformationsDataMessage.h"
#include "GameMapMovementMessage.h"
#include "GameMapNoMovementMessage.h"
#include "GameMapMovementConfirmMessage.h"
#include "GameContextRemoveElementMessage.h"
#include "GameRolePlayShowActorMessage.h"
#include "GameMapChangeOrientationMessage.h"
#include "SetCharacterRestrictionsMessage.h"

#include "StatedElementUpdatedMessage.h"
#include "InteractiveElementUpdatedMessage.h"
#include "InteractiveUsedMessage.h"

#include "SendMovementConfirmMessage.h"
#include "PlayerMovementEndedMessage.h"
#include "PlayerMovementErrorMessage.h"
#include "CurrentMapChangedMessage.h"

class RoleplayContextFrame : public PacketSendingDofusBotFrame {
public:
    // Constructor
    RoleplayContextFrame() : PacketSendingDofusBotFrame() {}; 
    // Copy constructor
    RoleplayContextFrame(const RoleplayContextFrame& other) = default;

    // Copy operator
    RoleplayContextFrame& operator=(const RoleplayContextFrame& other) = default;
    // Destructor
    ~RoleplayContextFrame() = default;

    bool computeMessage(sp<Message> message, int srcId) override;

protected:
    virtual bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    virtual bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

    // Sends GameMapMovementConfirmMessage
    bool sendGameMapMovementConfirmMessage();
    // Sends MapInformationsRequestMessage
    bool sendMapInformationsRequestMessage(double mapId);
};

#endif