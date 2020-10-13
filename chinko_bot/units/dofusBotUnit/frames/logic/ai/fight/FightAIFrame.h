#ifndef FIGHTAI_FRAME_H
#define FIGHTAI_FRAME_H

#include "DofusBotFrame.h"

#include "Pathfinding.h"

#include "CastFightAction.h"
#include "MoveFightAction.h"
#include "EndTurnFightAction.h"

#include "ReadyBeginTurnFightActionMessage.h"
#include "ReadyNextFightActionMessage.h"
#include "FightActionFailureMessage.h"
#include "CastSpellOnCellMessage.h"
#include "MoveToCellMessage.h"
#include "EndTurnMessage.h"

struct Spell {
    int id = 0;
    int range = 0;
    int pa_cost = 0;
    // Just an idea 
    int damage = 0;
};

class FightAIFrame : public DofusBotFrame {
public:
    // Constructor
    FightAIFrame() {};
    // Copy constructor
    FightAIFrame(const FightAIFrame& other) = default;

    // Copy operator
    FightAIFrame& operator=(const FightAIFrame& other) = default;
    // Destructor
    ~FightAIFrame() = default;
    
    virtual bool computeMessage(sp<Message> message, int srcId) override;

protected:
//     virtual bool handleSendPacketSuccessMessage(sp<SendPacketSuccessMessage> message) override;
//     virtual bool handleSendPacketFailureMessage(sp<SendPacketFailureMessage> message) override;

    vector<int> getReachableCells(sp<FighterData> fighter);

    void getNextAction();
    bool tryDirectAttack();
    bool tryMoveToAttack();
    bool moveTowardsEnnemy();

    int bestCastableSpell(int targetCellId);

    // sp<FighterData> tempPlayedCharacterInfos;

    // vector<sp<AbstactFightAction>> actionList;

    const vector<Spell> spells = {{13047, 8, 3, 12}};

    // bool 
};

#endif