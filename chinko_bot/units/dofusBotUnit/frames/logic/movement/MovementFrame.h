#ifndef MOVEMENT_FRAME_H
#define MOVEMENT_FRAME_H

#include "PacketSendingDofusBotFrame.h"

#include "Pathfinding.h"
#include "MovementManager.h"

#include "MoveToCellMessage.h"
#include "ChangeToMapMessage.h"
#include "PlayerMovementEndedMessage.h"
#include "PlayerMovementErrorMessage.h"

#include "MoveToRightSideMessage.h"
#include "MoveToLeftSideMessage.h"
#include "MoveToTopSideMessage.h"
#include "MoveToBottomSideMessage.h"

#include "GameMapMovementRequestMessage.h" 
#include "GameMapNoMovementMessage.h"
#include "InteractiveUseRequestMessage.h"
#include "InteractiveUseEndedMessage.h"


#include "ChangeMapMessage.h"
#include "GameMapNoMovementMessage.h"

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

    bool sendGameMapMovementRequestMessage(MovementPath* path);
    bool sendChangeMapMessage(double mapId);

    sp<MovementManager> manager;

    bool moveToRandomCellInVector(vector<int> cells);

 };

#endif