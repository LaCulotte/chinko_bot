#ifndef CAST_FIGHTACTION_H
#define CAST_FIGHTACTION_H

#include "AbstractFightAction.h"

class CastFightAction : public AbstactFightAction {
public:
    // Constructor
    CastFightAction() {};
    // Constructor with targetCellId initialisation
    CastFightAction(int spellId, int targetCellId) { this->targetCellId = targetCellId; this->spellId =spellId; };

    int spellId = 0;
    int targetCellId = 0;

};

#endif