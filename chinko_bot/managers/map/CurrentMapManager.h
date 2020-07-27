#ifndef CURRENTMAP_MANAGER_H
#define CURRENTMAP_MANAGER_H

#include "std_include.h"
#include <json/value.h>
#include <json/reader.h>
#include <fstream>

#include "MapComplementaryInformationsDataMessage.h"

#include "GameRolePlayCharacterInformations.h"
#include "GameRolePlayGroupMonsterInformations.h"
#include "GameRolePlayNpcInformations.h"
#include "GameRolePlayNpcWithQuestInformations.h"

#include <unordered_map>
#include "Cell.h"
#include "CharacterData.h"
#include "NpcWithQuestData.h"
#include "MonsterGroupData.h"

class CurrentMapManager {
public:
    // Constructor
    CurrentMapManager() {};
    // Constructor with mapsFolder initialization
    CurrentMapManager(string mapsFolder) { this->mapsFolder = mapsFolder; };
    // Copy constructor
    CurrentMapManager(const CurrentMapManager& other) = default;

    // Copy operator
    CurrentMapManager& operator=(const CurrentMapManager& other) = default;
    // Destructor
    ~CurrentMapManager() = default;

    bool loadMapInformations(int mapId);
    bool loadMapInformations(sp<MapComplementaryInformationsDataMessage> mcidMsg);

    sp<Cell> getCell(int cellId) { if(isInMap(cellId)) return cells[cellId]; else return nullptr; }
    int getCellsCount() { return cells.size(); }
    double getMapId() { return mapId; }

    bool updateActorPosition(double actorId, int newCellId);
    void updateInteractiveElement(sp<InteractiveElement> interactive);
    void updateInteractiveElement(InteractiveElement interactive);
    void updateStatedElement(StatedElement stated);

    int cellId_to_XPosition(int cellId);
    int cellId_to_YPosition(int cellId);
    int position_to_cellId(int x, int y);
    
    int getLookDirection(int fromCellId, int toCellId);
    int getLookDirection(int fromCellX, int fromCellY, int toCellX, int toCellY);

    int getManhattanDistance(int cellId1, int cellId2);
    float getEuclidianDistance(int cellId1, int cellId2);

    bool isInMap(int cellId) { return cellId < cells.size() && cellId >= 0; }
    bool isCoordsInMap(int x, int y);
    bool canMove(int cellId, int previousCellId = -1, bool avoidObstacles = true, bool allowThroughEntities = true);
    bool isThereBlockingEntityOn(int cellId);
    bool isChangeZone(int cellId1, int cellId2);

    void addActor(const sp<GameRolePlayActorInformations> actorInfos);
    sp<ActorData> getActor(double actorId);
    void removeActor(double actorID);
    sp<CharacterData> getPlayer(double playerId);
    sp<NpcData> getNpc(double npcId);
    sp<MonsterGroupData> getMonsterGroup(double monsterGroupId);

protected:
    // TODO : fichier de configurations où placer mapsFolder
    // Folder where all maps' data is located
    string mapsFolder = "./database/maps/json/";

    // vector<string> mapFormats = {"json", "dlm", "d2o"};
    bool loadMapCellsInformations();
    void clearAll();

// public:
    vector<sp<Cell>> cells;
public:
    vector<int> upChangeMapCellsId;
    vector<int> rightChangeMapCellsId;
    vector<int> downChangeMapCellsId;
    vector<int> leftChangeMapCellsId;

    double rightMapId = 0;
    double downMapId = 0;
    double leftMapId = 0;
    double upMapId = 0;

protected:
	// vector<sp<GameRolePlayActorInformations>> actors;
    unordered_map<double, sp<ActorData>> allActors;
    unordered_map<double, weak_ptr<CharacterData>> players;
    unordered_map<double, weak_ptr<MonsterGroupData>> monsterGroups;
    unordered_map<double, weak_ptr<NpcData>> npcs;

	unordered_map<int, sp<InteractiveElement>> interactiveElements;
	unordered_map<int, StatedElement> statedElements;
	int subAreaId = 0;
	double mapId = 0;
	bool hasAggressiveMonsters = false;

    const int MAP_WIDTH = 14;
    const int MAP_HEIGHT = 20;

    // List of the actors' informations' type ids that allow movement through (allowMovementThrough = true)
    // const vector<int> allowThroughActorsTypeIds = {148, 161, 467};
};

#endif