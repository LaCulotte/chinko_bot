#ifndef FIGHTACTION_FRAME_H
#define FIGHTACTION_FRAME_H

#include "PacketSendingDofusBotFrame.h"

#include "Pathfinding.h"

#include "GameFightReadyMessage.h"
#include "GameActionFightCastRequestMessage.h"
#include "GameFightTurnFinishMessage.h"
#include "GameMapMovementRequestMessage.h"

#include "TimedMessage.h"
#include "GetFightReadyMessage.h"
#include "EndTurnMessage.h"
#include "MoveToCellMessage.h"
#include "CastSpellOnCellMessage.h"
#include "FightActionFailureMessage.h"

class FightActionFrame : public PacketSendingDofusBotFrame {
public:
    // Constructor
    FightActionFrame() {};
    // Copy constructor
    FightActionFrame(const FightActionFrame& other) = default;

    // Copy operator
    FightActionFrame& operator=(const FightActionFrame& other) = default;
    // Destructor
    ~FightActionFrame() = default;
    
    virtual bool computeMessage(sp<Message> message, int srcId) override;

protected:
    virtual bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    virtual bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

    // Sends GameActionFightCastRequestMessage
    bool sendGameActionFightCastRequestMessage(int cellId, int spellId);
    // Sends GameMapMovementRequestMessage
    bool sendGameMapMovementRequestMessage(MovementPath* path);
};

#endif