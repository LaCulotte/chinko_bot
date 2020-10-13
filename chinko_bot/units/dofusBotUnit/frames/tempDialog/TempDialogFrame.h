#ifndef TEMPDIALOG_FRAME_H
#define TEMPDIALOG_FRAME_H

#include "PacketSendingDofusBotFrame.h"

#include "GameMapMovementRequestMessage.h"
#include "ChatServerMessage.h"
#include "Pathfinding.h"
#include "ActorData.h"

#include "MoveToCellMessage.h"
#include "ChangeToRightMapMessage.h"
#include "ChangeToLeftMapMessage.h"
#include "ChangeToUpMapMessage.h"
#include "ChangeToDownMapMessage.h"

#include "CollectInteractiveTypeIdMessage.h"

#include "CastSpellOnCellMessage.h"

#include "RoleplayMapManager.h"

// TODO : remove
#include "FightAIFrame.h"
#include "ReadyBeginTurnFightActionMessage.h"
#include "AttackMonsterGroupMessage.h"

class TempDialogFrame : public PacketSendingDofusBotFrame {
public:
    // Constructor
    TempDialogFrame() {};
    // Copy constructor
    TempDialogFrame(const TempDialogFrame& other) = default;

    // Copy operator
    TempDialogFrame& operator=(const TempDialogFrame& other) = default;
    // Destructor
    ~TempDialogFrame() = default;
    
    virtual bool computeMessage(sp<Message> message, int srcId) override;
};

#endif