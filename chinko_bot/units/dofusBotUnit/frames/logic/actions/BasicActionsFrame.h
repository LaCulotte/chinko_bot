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
    BasicActionsFrameState currentState = baf_idle;

    double changeMapId = 0;

    // int elementToCollectTypeId = 1;

    // vector<int> elementsToCollectOnMap;
    unordered_set<int> inaccessibleElements;

    int elementToCollectId = 0;
    int skillToUseId = 0;
    bool collectElementOfTypeId(int elementTypeId);
    bool collectElement(int elementId);

    bool sendInteractiveUseRequestMessage(int elementId, int skillId);

    double monsterId = 0;
    bool sendGameRolePlayAttackMonsterRequestMessage(double monsterGroupId);
};

#endif