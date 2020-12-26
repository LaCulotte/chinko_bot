#include "FightAIFrame.h"

bool FightAIFrame::computeMessage(sp<Message> message, int srcId) {
    
    switch (message->getId())
    {
    case ReadyBeginTurnFightActionMessage::protocolId:
    case ReadyNextFightActionMessage::protocolId:
        // Gets action
        getNextAction();
        break;

    case FightActionFailureMessage::protocolId:
        // If there is an action that results into an error, ends the players turn
        dofusBotParent->sendSelfMessage(make_shared<EndTurnMessage>());
        break;
    
    default:
        return false;
    }

    return true;
}

vector<int> FightAIFrame::getReachableCells(sp<FighterData> fighter) {
    // Basically a Dyxtra algorithm
    unordered_set<int> accessibleCells;
    vector<pair<int, int>> toCheckCells = { pair<int, int>(fighter->cellId, 0) };

    while(toCheckCells.size() > 0) {
        // While some cells can lead to others
        auto currentPair = toCheckCells[0];
        toCheckCells.erase(toCheckCells.begin());

        // If the current cell is not too far away ...
        if(currentPair.second <= fighter->stats->movementPoints) {
            int currentCellId = currentPair.first;
            int currentCellX = dofusBotParent->mapInfos->cellId_to_XPosition(currentCellId);
            int currentCellY = dofusBotParent->mapInfos->cellId_to_YPosition(currentCellId);
            for(int dx = -1; dx < 2; dx++) {
                for(int dy = -1; dy < 2; dy++) {
                    // Loops on direct neighboors 
                    if(dx + dy == 1 || dx + dy == -1) {
                        int nextCellX = currentCellX + dx;
                        int nextCellY = currentCellY + dy;

                        if(!dofusBotParent->mapInfos->isCoordsInMap(nextCellX, nextCellY))
                            continue;

                        int nextCellId = dofusBotParent->mapInfos->position_to_cellId(nextCellX, nextCellY);

                        sp<Cell> nextCell = dofusBotParent->mapInfos->getCell(nextCellId);

                        // If it is a valid cell, adds it to the cells to check
                        if(nextCell && nextCell->mov && !nextCell->nonWalkableDuringFight && !nextCell->isBlockedByObstacle && !dofusBotParent->mapInfos->isThereBlockingEntityOn(nextCellId))
                            toCheckCells.push_back(pair(nextCellId, currentPair.second + 1));
                    }
                }
            }

            // Adds current cells to the set of accessible cells
            accessibleCells.insert(currentPair.first);
        }

    }

    // Turns the set into a vector
    vector<int> ret;
    ret.insert(ret.end(), accessibleCells.begin(), accessibleCells.end());

    return ret;
}

void FightAIFrame::getNextAction() {   
    if(!dofusBotParent->playedCharacter || !dofusBotParent->getMapInfosAsFight())
        return;

    // Tries first to attack
    if(!tryDirectAttack()) {
        // Then to move
        if(!tryMoveToAttack() && !moveTowardsEnnemy())
            // If nothing works, ends turn
            dofusBotParent->sendSelfMessage(make_shared<EndTurnMessage>());
    }
}

bool FightAIFrame::tryDirectAttack() {
    sp<FighterData> playedFighter = dynamic_pointer_cast<FighterData>(dofusBotParent->playedCharacter);

    sp<FighterData> bestTarget = nullptr;
    int spellToCast = -1;

    bool couldCastSpell = false;

    // Loops through all the enemies fighters
    for(auto fighterIt : dofusBotParent->getMapInfosAsFight()->fighters) {
        sp<FighterData> fighter = fighterIt.second.lock();
        if(!fighter || fighter->teamId == playedFighter->teamId || !fighter->alive)
            continue;

        // Check for lign of sight betwenn player and enemy 
        if(dofusBotParent->mapInfos->isThereLos(fighter->cellId, playedFighter->cellId)) {

            int dist = AbstractMapManager::getManhattanDistance(playedFighter->cellId, fighter->cellId);
            int bestSpellId = -1;
            int bestSpellDamage = -1;

            // Gets the best valid spell to attack to enemy 
            for(Spell spell : spells) {
                if(dist <= spell.range) {
                    if(playedFighter->stats->actionPoints >= spell.pa_cost && spell.damage > bestSpellDamage) {
                        bestSpellId = spell.id;
                        bestSpellDamage = spell.damage;
                    }
                    couldCastSpell = true;
                }
            }

            if(bestSpellId != -1 && (!bestTarget || fighter->stats->lifePoints < bestTarget->stats->lifePoints)) {
                bestTarget = fighter;
                spellToCast = bestSpellId;
            }
        }
    }

    // If there is one, casts it
    if(bestTarget && spellToCast != -1) {
        dofusBotParent->sendSelfMessage(make_shared<CastSpellOnCellMessage>(bestTarget->cellId, spellToCast));
        Logger::write("Attacked " + to_string(bestTarget->contextualId) + " with spell " + to_string(spellToCast), LOG_DEBUG);
        return true;
    } else if(couldCastSpell) {
        // Checks for a error on a spell
        dofusBotParent->sendSelfMessage(make_shared<EndTurnMessage>());
        return true;
    }

    return false;
}

bool FightAIFrame::tryMoveToAttack() {
    sp<FighterData> playedFighter = dynamic_pointer_cast<FighterData>(dofusBotParent->playedCharacter);

    if(playedFighter->stats->movementPoints <= 0)
        return false;

    // Gets reachable cells
    vector<int> reachableCells = this->getReachableCells(playedFighter);
    
    int destCellId = -1;
    int bestDist = 1000;
    double targetId = 0;

    // Loops through all the enemy fighters
    for(auto fighterIt : dofusBotParent->getMapInfosAsFight()->fighters) {
        sp<FighterData> fighter = fighterIt.second.lock();
        if(!fighter || fighter->teamId == playedFighter->teamId || !fighter->alive)
            continue;

        // Gets all cells that are accessible and that are in LOS of the enemy
        vector<int> cellsWithLos = dofusBotParent->mapInfos->getLosFromCells(reachableCells, fighter->cellId);

        // Gets the nearest cell
        for(int cellId : cellsWithLos) {
            if(AbstractMapManager::getManhattanDistance(fighter->cellId, cellId) < bestDist) {
                destCellId = cellId;
                bestDist = AbstractMapManager::getManhattanDistance(fighter->cellId, cellId);
                targetId = fighter->contextualId;
            }
        }
    }

    // If there is a cell to move to, sends movement message
    if(destCellId != -1 && destCellId != playedFighter->cellId) {
        dofusBotParent->sendSelfMessage(make_shared<MoveToCellMessage>(destCellId));
        Logger::write("Moving to cell " + to_string(destCellId) + " to attack target " + to_string(targetId), LOG_DEBUG);
        return true;
    }

    return false;
}

bool FightAIFrame::moveTowardsEnnemy() {
    sp<FighterData> playedFighter = dynamic_pointer_cast<FighterData>(dofusBotParent->playedCharacter);
    int destCellId = -1;
    int minDist = 10000;
    double targetId = 0;

    if(playedFighter->stats->movementPoints <= 0)
        return false;

    // Loops through all the enemy fighters
    for(auto fighterIt : dofusBotParent->getMapInfosAsFight()->fighters) {
        sp<FighterData> fighter = fighterIt.second.lock();
        if(!fighter || fighter->teamId == playedFighter->teamId || !fighter->alive)
            continue;

        //Pathfinds to the enemy
        MovementPath movPath = PathFinding::findPath(dofusBotParent->mapInfos, playedFighter->cellId, fighter->cellId, false, true, false);

        // Gets the destination from the shortest path.
        if(movPath.path.size() < minDist && movPath.path.size() > 1) {
            minDist = movPath.path.size();
            destCellId = movPath.getNthTile(fighter->stats->movementPoints);
            targetId = fighter->contextualId;
        }
    }

    // If there is a cell to move to, sends movement message (there should always be the case)
    if(destCellId != -1 && destCellId != playedFighter->cellId) {
        dofusBotParent->sendSelfMessage(make_shared<MoveToCellMessage>(destCellId));
        Logger::write("Moves to cell " + to_string(destCellId) + " towards " + to_string(targetId), LOG_DEBUG);
        return true;
    }

    return false;
}

// Unused
int FightAIFrame::bestCastableSpell(int targetCellId) {
    sp<FighterData> playedFighter = dynamic_pointer_cast<FighterData>(dofusBotParent->playedCharacter);
    int dist = AbstractMapManager::getManhattanDistance(playedFighter->cellId, targetCellId);
    
    int bestSpellId = -1;
    int bestSpellDamage = -1;

    for(Spell spell : spells) {
        if(playedFighter->stats->actionPoints >= spell.pa_cost && dist <= spell.range && spell.damage > bestSpellDamage) {
            bestSpellId = spell.id;
            bestSpellDamage = spell.damage;
        }
    }

    return bestSpellId;
}