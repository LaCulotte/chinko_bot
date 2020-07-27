#ifndef MOVEMENT_FRAME_H
#define MOVEMENT_FRAME_H

#include "PacketSendingDofusBotFrame.h"

#include "Pathfinding.h"
#include "MovementManager.h"

#include "MoveToCellMessage.h"
#include "PlayerMoved.h"

#include "GameMapMovementRequestMessage.h" 
#include "ChangeToRightMapMessage.h"
#include "ChangeToLeftMapMessage.h"
#include "ChangeToUpMapMessage.h"
#include "ChangeToDownMapMessage.h"

#include "ChangeMapMessage.h"
#include "GameMapNoMovementMessage.h"

enum MovementFrameState {
    mfs_idle,
    mfs_changingmap
};

class MovementFrame : public PacketSendingDofusBotFrame {
public:
    // Constructor
    MovementFrame() : PacketSendingDofusBotFrame() {};
    // Copy constructor
    MovementFrame(const MovementFrame& other) = default;

    // Copy constructor
    MovementFrame& operator=(const MovementFrame& other) = default;
    // Constructor
    ~MovementFrame() = default;

    bool computeMessage(sp<Message> message, int srcId) override;

    virtual bool setParent(MessagingUnit* parent) override;

protected:
    virtual bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    virtual bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

    sp<MovementManager> manager;

    MovementFrameState currentState = mfs_idle;
    double newMapId = 0;
};

#endif