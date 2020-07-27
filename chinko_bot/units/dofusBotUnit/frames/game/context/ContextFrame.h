#ifndef CONTEXT_FRAME_H
#define CONTEXT_FRAME_H

#include "PacketSendingDofusBotFrame.h"

#include "TempDialogFrame.h"
#include "MovementFrame.h"
#include "CharacterData.h"

#include "BeginGameContextRequestMessage.h"
#include "TimedMessage.h"

#include "GameContextCreateRequestMessage.h"
#include "GameContextCreateMessage.h"
#include "CurrentMapMessage.h"
#include "MapInformationsRequestMessage.h"
#include "MapComplementaryInformationsDataMessage.h"
#include "GameMapMovementMessage.h"
#include "GameMapMovementConfirmMessage.h"
#include "GameContextRemoveElementMessage.h"
#include "GameRolePlayShowActorMessage.h"
#include "GameMapChangeOrientationMessage.h"
#include "SetCharacterRestrictionsMessage.h"

#include "StatedElementUpdatedMessage.h"
#include "InteractiveElementUpdatedMessage.h"
#include "InteractiveUsedMessage.h"

class ContextFrame : public PacketSendingDofusBotFrame {
public:
    // Constructor
    ContextFrame() : PacketSendingDofusBotFrame() {}; 
    // Copy constructor
    ContextFrame(const ContextFrame& other) = default;

    // Copy operator
    ContextFrame& operator=(const ContextFrame& other) = default;
    // Destructor
    ~ContextFrame() = default;

    bool computeMessage(sp<Message> message, int srcId) override;

protected:
    virtual bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    virtual bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

    // Sends GameContextCreateRequestMessage
    bool sendGameContextCreateRequestMessage();
    // Sends GameMapMovementConfirmMessage
    bool sendGameMapMovementConfirmMessage();
    // Sends MapInformationsRequestMessage
    bool sendMapInformationsRequestMessage(double mapId);
};

#endif