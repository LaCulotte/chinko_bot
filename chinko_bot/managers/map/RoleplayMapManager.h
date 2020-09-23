#ifndef ROLEPLAY_MAP_MANAGER_H
#define ROLEPLAY_MAP_MANAGER_H

#include "AbstractMapManager.h"

#include "GameRolePlayCharacterInformations.h"
#include "GameRolePlayGroupMonsterInformations.h"
#include "GameRolePlayNpcInformations.h"
#include "GameRolePlayNpcWithQuestInformations.h"
#include "GameRolePlayTaxCollectorInformations.h"
#include "GameRolePlayPrismInformations.h"
#include "GameRolePlayPortalInformations.h"

#include "RoleplayCharacterData.h"
#include "RoleplayNpcWithQuestData.h"
#include "RoleplayMonsterGroupData.h"

class RoleplayMapManager : public AbstractMapManager {
public:
    // Constructor
    RoleplayMapManager() : AbstractMapManager() {};
    // Constructor with mapsFolder initialization
    RoleplayMapManager(string mapsFolder) : AbstractMapManager(mapsFolder) {};
    // Copy constructor
    RoleplayMapManager(const RoleplayMapManager& other) = default;

    // Copy operator
    RoleplayMapManager& operator=(const RoleplayMapManager& other) = default;
    // Destructor
    ~RoleplayMapManager() = default;

    bool loadMapInformations(sp<MapComplementaryInformationsDataMessage> mcidMsg);

    virtual void addActor(sp<GameContextActorInformations> actorInfos) override;
    virtual void removeActor(double actorId) override;
    void updateInteractiveElement(sp<InteractiveElement> interactive);
    void updateInteractiveElement(InteractiveElement interactive);
    void updateStatedElement(StatedElement stated);


    sp<RoleplayCharacterData> getPlayer(double playerId);
    sp<RoleplayNpcData> getNpc(double npcId);
    sp<RoleplayMonsterGroupData> getMonsterGroup(double monsterGroupId);

    virtual bool isFight() override { return false; };

protected:

    virtual void clearAll() override;

public:
// protected:

    unordered_map<double, weak_ptr<RoleplayCharacterData>> players;
    unordered_map<double, weak_ptr<RoleplayMonsterGroupData>> monsterGroups;
    unordered_map<double, weak_ptr<RoleplayNpcData>> npcs;

	unordered_map<int, sp<InteractiveElement>> interactiveElements;
	unordered_map<int, StatedElement> statedElements;
};

#endif