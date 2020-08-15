#ifndef FIGHT_FRAME_H
#define FIGHT_FRAME_H

#include "PacketSendingDofusBotFrame.h"

// TO REMOVE
#include "GameRolePlayPlayerFightFriendlyRequestedMessage.h"
#include "GameRolePlayPlayerFightFriendlyAnswerMessage.h"

#include "GameFightStartingMessage.h"
#include "GameFightJoinMessage.h"
#include "GameEntitiesDispositionMessage.h"
#include "GameFightShowFighterMessage.h"
#include "GameFightUpdateTeamMessage.h"

class FightFrame : public PacketSendingDofusBotFrame {
public:
    // Constructor
    FightFrame() : PacketSendingDofusBotFrame() {}; 
    // Copy constructor
    FightFrame(const FightFrame& other) = default;

    // Copy operator
    FightFrame& operator=(const FightFrame& other) = default;
    // Destructor
    ~FightFrame() = default;

    bool computeMessage(sp<Message> message, int srcId) override;

protected:
    virtual bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    virtual bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;
};

#endif