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

// Spell structure (here only attacking spells)
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
    // Returns all the cells that can be accessed by the fighter
    vector<int> getReachableCells(sp<FighterData> fighter);

    // Does the next action
    void getNextAction();
    // Tries a direct attack to an enemy
    bool tryDirectAttack();
    // Tries a move in order to attack an enemy
    bool tryMoveToAttack();
    // Tries a move towards an enemy
    bool moveTowardsEnnemy();

    // Return index of the best castable spell (the one that does the most damages in this one instance)
    int bestCastableSpell(int targetCellId);

    // Spells that can be used
    const vector<Spell> spells = {{13047, 8, 3, 12}};
};

#endif