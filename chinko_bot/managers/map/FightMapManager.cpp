#include "FightMapManager.h"

void FightMapManager::addActor(sp<GameContextActorInformations> actorInfos) {
    sp<ActorData> actorData;

    sp<GameFightFighterInformations> fighterInfos = dynamic_pointer_cast<GameFightFighterInformations>(actorInfos);
    if(fighterInfos) {
        sp<FighterData> fighterData(new FighterData());

        fighterData->stats = fighterInfos->stats;
        for(auto teamIt : teams) {
            if(teamIt.second.find(actorInfos->contextualId) != teamIt.second.end())
                fighterData->teamId = teamIt.first;
        }

        actorData = fighterData;
        fighters[fighterInfos->contextualId] = fighterData;
    } else {
        Logger::write("Adding a non-fighter actor to a FightMapManager.", LOG_WARNING);
        actorData = make_shared<ActorData>();
    }

    actorData->contextualId = actorInfos->contextualId;
    actorData->cellId       = actorInfos->disposition->cellId;
    actorData->direction    = actorInfos->disposition->direction;

    actorData->canWalkThrough = false;
    actorData->canWalkTo = false;
    actorData->canSeeThrough = false;

    allActors[actorData->contextualId] = actorData;
}

void FightMapManager::removeActor(double actorId) {
    AbstractMapManager::removeActor(actorId);

    fighters.erase(actorId);
}

void FightMapManager::fighterDied(double fighterId) {
    auto fighterIt = fighters.find(fighterId);

    if(fighterIt != fighters.end() && !fighterIt->second.expired()) {
        fighterIt->second.lock()->alive = false;
        fighterIt->second.lock()->canSeeThrough = true;
        fighterIt->second.lock()->canWalkThrough = true;
        fighterIt->second.lock()->canWalkTo = true;

        // this->removeActor(fighterId);

        for(auto otherFighterIt : fighters) {
            sp<FighterData> fighter = otherFighterIt.second.lock();
            if(fighter && fighter->stats->summoner == fighterId)
                this->fighterDied(fighter->contextualId);
        }
    }
}

void FightMapManager::updateFighter(sp<GameFightFighterInformations> fighterInfos) {
    auto fighterIt = fighters.find(fighterInfos->contextualId);
    if(fighterIt != fighters.end()) {
        if(fighterIt->second.expired()) {
            fighters.erase(fighterIt);
        } else {
            fighterIt->second.lock()->stats = fighterInfos->stats;
        }
    } else {
        this->addActor(fighterInfos);
    }
}

sp<FighterData> FightMapManager::getFighter(double fighterId) {
    auto fighterIt = fighters.find(fighterId);
    if(fighterIt != fighters.end())
        if(!fighterIt->second.expired())
            return fighterIt->second.lock();
        else 
            fighters.erase(fighterIt);

    return nullptr;
}

void FightMapManager::clearAll() {
    AbstractMapManager::clearAll();

    fighters.clear();
}

void FightMapManager::updateTeamInfos(double fighterId, int teamId) {
    auto fighterIt = fighters.find(fighterId);
    if(fighterIt != fighters.end()) {
        sp<FighterData> fighter = fighterIt->second.lock();
        if(!fighter) {
            removeActor(fighterId);
            return;
        }

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
    sp<FighterData> fighter = getFighter(fighterId);
    if(fighter) {
        fighter->stats->actionPoints = fighter->stats->maxActionPoints;
        fighter->stats->movementPoints = fighter->stats->maxMovementPoints;
    }
}

bool FightMapManager::isThereBlockingEntityOn(int cellId, bool allowThroughEntities) {
    for(auto actorIt : allActors) {
        sp<ActorData> actor = actorIt.second;
        if(actor->cellId == cellId && (!allowThroughEntities || !actor->allowMovementThrough) && (!dynamic_pointer_cast<FighterData>(actor) || !dynamic_pointer_cast<FighterData>(actor)->alive))
            return true;
    }

    return false;
}

bool FightMapManager::isThereSeeBlockingEntityOn(int cellId, bool allowThroughEntities) {
    for(auto actorIt : allActors) {
        sp<ActorData> actor = actorIt.second;
        if(actor->cellId == cellId && (!allowThroughEntities || !actor->canSeeThrough) && (!dynamic_pointer_cast<FighterData>(actor) || !dynamic_pointer_cast<FighterData>(actor)->alive))
            return true;
    }

    return false;
}