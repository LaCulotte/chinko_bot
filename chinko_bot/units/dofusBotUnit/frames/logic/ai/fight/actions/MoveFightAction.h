#ifndef MOVE_FIGHTACTION_H
#define MOVE_FIGHTACTION_H

#include "AbstractFightAction.h"

// UNUSED
class MoveFightAction : public AbstactFightAction {
public:
    // Constructor
    MoveFightAction() {};
    // Constructor with destCellId initialisation
    MoveFightAction(int destCellId) { this->destCellId = destCellId; };

    int destCellId = 0;

};

#endif