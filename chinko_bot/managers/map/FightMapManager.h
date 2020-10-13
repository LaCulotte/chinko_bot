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

    virtual void addActor(sp<GameContextActorInformations> actorInfos) override;
    virtual void removeActor(double actorId) override;
    virtual void fighterDied(double fighter);
    sp<FighterData> getFighter(double fighterId);
    void updateFighter(sp<GameFightFighterInformations> fighterInfos);
    // void updateFighter(int fighterId, );

    virtual bool isFight() override { return true; };

    void updateTeamInfos(double fighterId, int teamId);
    void endFighterTurn(double fighterId);

    virtual bool isThereBlockingEntityOn(int cellId, bool allowThroughEntities = true) override;
    virtual bool isThereSeeBlockingEntityOn(int cellId, bool allowThroughEntities = false) override;

    // TODO : virtual int cellSpecialEffects(int x, int y) override;

protected:
    virtual void clearAll() override;

public:
// protected:

    unordered_map<double, weak_ptr<FighterData>> fighters;

    unordered_map<int, unordered_set<double>> teams;
};

#endif