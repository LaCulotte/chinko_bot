#ifndef FIGHT_CONTEXT_FRAME_H
#define FIGHT_CONTEXT_FRAME_H

#include "PacketSendingDofusBotFrame.h"

#include "SwitchContextFrame.h"
#include "FightActionFrame.h"
#include "FightAIFrame.h"

#include "GameContextDestroyMessage.h"
#include "GameFightStartingMessage.h"
#include "GameFightJoinMessage.h"
#include "GameEntitiesDispositionMessage.h"
#include "GameFightShowFighterMessage.h"
#include "GameFightUpdateTeamMessage.h"
#include "GameFightHumanReadyStateMessage.h"

#include "GameFightTurnReadyMessage.h"
#include "GameFightTurnStartMessage.h"
#include "GameFightTurnReadyRequestMessage.h"

#include "GameFightStartMessage.h"
#include "GetFightReadyMessage.h"
#include "GameFightNewRoundMessage.h"
#include "GameFightSynchronizeMessage.h"
#include "GameFightTurnListMessage.h"
#include "GameFightEndMessage.h"

#include "GameFightRefreshFighterMessage.h"
#include "FighterStatsListMessage.h"
#include "AbstractGameActionMessage.h"
#include "AbstractGameActionFightTargetedAbilityMessage.h"
#include "GameActionFightCloseCombatMessage.h"
#include "GameActionFightSpellCastMessage.h"
#include "GameActionFightNoSpellCastMessage.h"

#include "GameActionFightPointsVariationMessage.h"
#include "GameActionFightLifeAndShieldPointsLostMessage.h"
#include "GameActionFightLifePointsLostMessage.h"
#include "GameActionFightLifePointsGainMessage.h"
#include "GameActionFightTeleportOnSameMapMessage.h"
#include "GameActionFightExchangePositionsMessage.h"
#include "GameActionFightSlideMessage.h"
#include "GameActionFightMarkCellsMessage.h"
#include "GameActionFightUnmarkCellsMessage.h"
#include "GameActionFightDeathMessage.h"
#include "GameActionFightKillMessage.h"
#include "GameActionAcknowledgementMessage.h"

#include "ReadyBeginTurnFightActionMessage.h"
#include "ReadyNextFightActionMessage.h"
#include "FightActionFailureMessage.h"

#include "GameMapNoMovementMessage.h"
#include "SequenceEndMessage.h"

namespace ActionIds {
    enum ActionIds {
        PA_LOST = 101,
        PA_USE = 102,
        PA_WIN = 120,
        PM_LOST = 127,
        PM_USE = 129,
        PM_WIN = 78
    };
};

class FightContextFrame : public PacketSendingDofusBotFrame {
public:
    // Constructor
    FightContextFrame() : PacketSendingDofusBotFrame() {}; 
    // Copy constructor
    FightContextFrame(const FightContextFrame& other) = default;

    // Copy operator
    FightContextFrame& operator=(const FightContextFrame& other) = default;
    // Destructor
    ~FightContextFrame() = default;

    bool computeMessage(sp<Message> message, int srcId) override;

protected:
    virtual bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
    virtual bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

    bool sendGameFightTurnReadyMessage(bool ready = true);
    bool sendGameActionAcknowledgementMessage(sp<SequenceEndMessage> message);
};

#endif