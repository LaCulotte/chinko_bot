#include "FightMapManager.h"

void FightMapManager::addActor(sp<GameContextActorInformations> actorInfos) {
    sp<ActorData> actorData;

    sp<GameFightFighterInformations> fighterInfos = dynamic_pointer_cast<GameFightFighterInformations>(actorInfos);
    if(fighterInfos) {
        // Builds specific instance if the actor is a fighter
        sp<FighterData> fighterData(new FighterData());

        fighterData->stats = fighterInfos->stats;
        for(auto teamIt : teams) {
            if(teamIt.second.find(actorInfos->contextualId) != teamIt.second.end())
                fighterData->teamId = teamIt.first;
        }

        actorData = fighterData;
        fighters[fighterInfos->contextualId] = fighterData;
    } else {
        // Builds a regular actor
        Logger::write("Adding a non-fighter actor to a FightMapManager.", LOG_WARNING);
        actorData = make_shared<ActorData>();
    }

    // Sets actors data
    actorData->contextualId = actorInfos->contextualId;
    actorData->cellId       = actorInfos->disposition->cellId;
    actorData->direction    = actorInfos->disposition->direction;

    actorData->canWalkThrough = false;
    actorData->canWalkTo = false;
    actorData->canSeeThrough = false;

    allActors[actorData->contextualId] = actorData;
}

void FightMapManager::removeActor(double actorId) {
    // Removes actor
    AbstractMapManager::removeActor(actorId);

    // Removes fighter if it is one
    fighters.erase(actorId);
}

void FightMapManager::fighterDied(double fighterId) {
    auto fighterIt = fighters.find(fighterId);

    if(fighterIt != fighters.end() && !fighterIt->second.expired()) {
        // Translation of the dofus' source code
        fighterIt->second.lock()->alive = false;
        fighterIt->second.lock()->canSeeThrough = true;
        fighterIt->second.lock()->canWalkThrough = true;
        fighterIt->second.lock()->canWalkTo = true;

        // Kills all the summoned fighters
        for(auto otherFighterIt : fighters) {
            sp<FighterData> fighter = otherFighterIt.second.lock();
            if(fighter && fighter->stats->summoner == fighterId)
                this->fighterDied(fighter->contextualId);
        }
    }
}

void FightMapManager::updateFighter(sp<GameFightFighterInformations> fighterInfos) {
    // Gets figher
    auto fighterIt = fighters.find(fighterInfos->contextualId);
    if(fighterIt != fighters.end()) {
        if(fighterIt->second.expired()) {
            // Erase the fighter if it is not valid anymore
            fighters.erase(fighterIt);
        } else {
            // Updates fighter
            fighterIt->second.lock()->stats = fighterInfos->stats;
        }
    } else {
        // If the fighter does not exist, adds it
        this->addActor(fighterInfos);
    }
}

sp<FighterData> FightMapManager::getFighter(double fighterId) {
    // Gets fighter
    auto fighterIt = fighters.find(fighterId);
    if(fighterIt != fighters.end())
        if(!fighterIt->second.expired())
            return fighterIt->second.lock();
        else 
            // Erase the fighter if it is not valid anymore
            fighters.erase(fighterIt);

    return nullptr;
}

void FightMapManager::clearAll() {
    AbstractMapManager::clearAll();

    // Clears figther map
    fighters.clear();
}

void FightMapManager::updateTeamInfos(double fighterId, int teamId) {
    // Gets fighter
    auto fighterIt = fighters.find(fighterId);
    if(fighterIt != fighters.end()) {
        sp<FighterData> fighter = fighterIt->second.lock();
        if(!fighter) {
            // Erase the fighter if it is not valid anymore
            removeActor(fighterId);
            return;
        }

        //
        auto oldTeamIt = teams.find(fighter->teamId);
        if(oldTeamIt != teams.end()) {
            oldTeamIt->second.erase(fighterId);
            if(oldTeamIt->second.size() == 0) {
                teams.erase(oldTeamIt);
            }
        }

        fighter->teamId = teamId;
    }


    auto newTeamIt = teams.find(teamId);
    if(newTeamIt != teams.end()) {
        newTeamIt->second.insert(fighterId);
    } else {
        teams[teamId] = { fighterId };
    }
}

void FightMapManager::endFighterTurn(double fighterId) {
    // Gets fighter
    sp<FighterData> fighter = getFighter(fighterId);
    if(fighter) {
        // Resets action & movement points
        fighter->stats->actionPoints = fighter->stats->maxActionPoints;
        fighter->stats->movementPoints = fighter->stats->maxMovementPoints;
    }
}

bool FightMapManager::isThereBlockingEntityOn(int cellId, bool allowThroughEntities) {
    // Same as AbstractMapManager but takes into account if the fighter is dead or not
    for(auto actorIt : allActors) {
        sp<ActorData> actor = actorIt.second;
        if(actor->cellId == cellId && (!allowThroughEntities || !actor->allowMovementThrough) && (!dynamic_pointer_cast<FighterData>(actor) || !dynamic_pointer_cast<FighterData>(actor)->alive))
            return true;
    }

    return false;
}

bool FightMapManager::isThereSeeBlockingEntityOn(int cellId, bool allowThroughEntities) {
    // Same as AbstractMapManager but takes into account if the fighter is dead or not
    for(auto actorIt : allActors) {
        sp<ActorData> actor = actorIt.second;
        if(actor->cellId == cellId && (!allowThroughEntities || !actor->canSeeThrough) && (!dynamic_pointer_cast<FighterData>(actor) || !dynamic_pointer_cast<FighterData>(actor)->alive))
            return true;
    }

    return false;
}