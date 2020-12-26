#ifndef FIGHT_MAP_MANAGER_H
#define FIGHT_MAP_MANAGER_H

#include "AbstractMapManager.h"

#include "FighterData.h"
#include "GameFightFighterInformations.h"

#include <unordered_set>

class FightMapManager : public AbstractMapManager {
public:
    // Constructor
    FightMapManager() : AbstractMapManager() {};
    // Constructor with mapsFolder initialization
    FightMapManager(string mapsFolder) : AbstractMapManager(mapsFolder) {};
    // Copy constructor
    FightMapManager(const FightMapManager& other) = default;

    // Copy operator
    FightMapManager& operator=(const FightMapManager& other) = default;
    // Destructor
    ~FightMapManager() = default;

    // Adds an actor to the map
    virtual void addActor(sp<GameContextActorInformations> actorInfos) override;
    // Removes an actor from the map
    virtual void removeActor(double actorId) override;
    // 'Kills' a fighter
    void fighterDied(double fighter);
    // Returns fighter from Id
    sp<FighterData> getFighter(double fighterId);
    // Updates (or add) a fighter from GameFightFighterInformations
    void updateFighter(sp<GameFightFighterInformations> fighterInfos);

    // Returns true if the bot is currently in a fight (ie. It is a FightMapManager) (here true)
    virtual bool isFight() override { return true; };

    // Updates fighter's team
    void updateTeamInfos(double fighterId, int teamId);
    // Ends the turn of a fighter
    void endFighterTurn(double fighterId);

    // Returns true if there is a blocking entity on a cell
    virtual bool isThereBlockingEntityOn(int cellId, bool allowThroughEntities = true) override;
    // Returns true if there is a see blocking entity on a cell
    virtual bool isThereSeeBlockingEntityOn(int cellId, bool allowThroughEntities = false) override;

    // TODO : virtual int cellSpecialEffects(int x, int y) override;

protected:
    // Clears every container of the map
    virtual void clearAll() override;

public:
// protected:

    // Maps the fighterId to its fighter
    unordered_map<double, weak_ptr<FighterData>> fighters;

    // Map teamId to a set of fighters' id 
    unordered_map<int, unordered_set<double>> teams;
};

#endif