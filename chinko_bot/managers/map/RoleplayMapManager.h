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

    // Loads map informations from the map's json file
    bool loadMapInformations(sp<MapComplementaryInformationsDataMessage> mcidMsg);

    // Adds an actor to the map
    virtual void addActor(sp<GameContextActorInformations> actorInfos) override;
    // Removes an actor from the map
    virtual void removeActor(double actorId) override;
    // Updates/add an interactive element
    void updateInteractiveElement(sp<InteractiveElement> interactive);
    // Updates/add an interactive element
    void updateInteractiveElement(InteractiveElement interactive);
    // Updates/add an stated element
    void updateStatedElement(StatedElement stated);

    // Return a player
    sp<RoleplayCharacterData> getPlayer(double playerId);
    // Return a NPC
    sp<RoleplayNpcData> getNpc(double npcId);
    // Return a monster group
    sp<RoleplayMonsterGroupData> getMonsterGroup(double monsterGroupId);

    // Returns true if the bot is currently in a fight (ie. It is a FightMapManager) (here false)
    virtual bool isFight() override { return false; };

protected:

    // Clears every container of the map
    virtual void clearAll() override;

public:
// protected:

    // Map player's id to player 
    unordered_map<double, weak_ptr<RoleplayCharacterData>> players;
    // Map monster group's id to monster group 
    unordered_map<double, weak_ptr<RoleplayMonsterGroupData>> monsterGroups;
    // Map npc's id to npc 
    unordered_map<double, weak_ptr<RoleplayNpcData>> npcs;

    // Map interactive element's id to interactive element
	unordered_map<int, sp<InteractiveElement>> interactiveElements;
    // Map stated element's id to stated element
	unordered_map<int, StatedElement> statedElements;
};

#endif