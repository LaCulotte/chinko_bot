#ifndef BASICACTIONS_FRAME_H
#define BASICACTIONS_FRAME_H

#include "PacketSendingDofusBotFrame.h"

#include "PlayerMovementEndedMessage.h"
#include "PlayerMovementErrorMessage.h"
#include "CurrentMapChangedMessage.h"
#include "CollectInteractiveTypeIdMessage.h"

#include "MoveToCellMessage.h"
#include "ChangeToMapMessage.h"
#include "ChangeToRightMapMessage.h"
#include "ChangeToLeftMapMessage.h"
#include "ChangeToUpMapMessage.h"
#include "ChangeToDownMapMessage.h"
#include "MoveToRightSideMessage.h"
#include "MoveToLeftSideMessage.h"
#include "MoveToTopSideMessage.h"
#include "MoveToBottomSideMessage.h"

#include "InteractiveUseRequestMessage.h"
#include "InteractiveUseEndedMessage.h"
#include "CurrentMapMessage.h"

#include "AttackMonsterGroupMessage.h"
#include "GameRolePlayAttackMonsterRequestMessage.h"

#include "Pathfinding.h"

#include <unordered_set>

enum BasicActionsFrameState {
    baf_idle,
    baf_pathfindToSide,
    baf_changeMap,
    baf_pathfindToCollect,
    baf_pathfindToMonster,
    baf_collect
};

class BasicActionsFrame : public PacketSendingDofusBotFrame {
public: 
    // Constructor
    BasicActionsFrame() { this->priority = -1; };
    // Copy constructor
    BasicActionsFrame(const BasicActionsFrame& other) = default;

    // Copy operator
    BasicActionsFrame& operator=(const BasicActionsFrame& other) = default;
    // Destructor
    ~BasicActionsFrame() = default;
    
    virtual bool computeMessage(sp<Message> message, int srcId) override;

protected:
    // Frame's state
    BasicActionsFrameState currentState = baf_idle;

    // Id of the map to change to
    double changeMapId = 0;

    // Elements that cannot be accessed by the bot
    unordered_set<int> inaccessibleElements;

    // Id of the next interactive element to collect
    int elementToCollectId = 0;
    // Id of the skill used to collect the next interactive element to collect
    int skillToUseId = 0;
    // Collect an element of a specified typeId 
    bool collectElementOfTypeId(int elementTypeId);
    // Collect specific interacitve element with a specific skill 
    bool collectElement(int elementId, int skillId, int skillUID);

    // Id of the monster group to attack
    double monsterId = 0;
    // Sends GameRolePlayAttackMonsterRequestMessage
    bool sendGameRolePlayAttackMonsterRequestMessage(double monsterGroupId);
    // Sends InteractiveUseRequestMessage
    bool sendInteractiveUseRequestMessage(int elementId, int skillId);
};

#endif