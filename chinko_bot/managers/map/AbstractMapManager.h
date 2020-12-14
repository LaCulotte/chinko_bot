#ifndef ABSTRACT_MAP_MANAGER_H
#define ABSTRACT_MAP_MANAGER_H

#include "std_include.h"
#include <json/value.h>
#include <json/reader.h>
#include <fstream>

#include "MapComplementaryInformationsDataMessage.h"
#include "GameContextActorInformations.h"
#include "GameActionMark.h"

#include <unordered_map>
#include "Cell.h"
#include "ActorData.h"
#include "Mark.h"
#include "ZoneBuilder.h"

class AbstractMapManager {
public:
    // Constructor
    AbstractMapManager() {};
    // Constructor with mapsFolder initialization
    AbstractMapManager(string mapsFolder) { this->mapsFolder = mapsFolder; };
    // Copy constructor
    AbstractMapManager(const AbstractMapManager& other) = default;

    // Copy operator
    AbstractMapManager& operator=(const AbstractMapManager& other) = default;
    // Destructor
    ~AbstractMapManager() = default;

    bool loadMapInformations(int mapId);
    // bool loadMapInformations(sp<MapComplementaryInformationsDataMessage> mcidMsg);

    sp<Cell> getCell(int cellId) { if(isInMap(cellId)) return cells[cellId]; else return nullptr; }
    int getCellsCount() { return cells.size(); }
    double getMapId() { return mapId; }
    bool areCellsLoaded() { return cellsLoaded; };

    bool updateActorPosition(double actorId, int newCellId);
    void updateActorInfos(sp<GameContextActorInformations> actorInfos);
    // void updateInteractiveElement(sp<InteractiveElement> interactive);
    // void updateInteractiveElement(InteractiveElement interactive);
    // void updateStatedElement(StatedElement stated);

    static int cellId_to_XPosition(int cellId);
    static int cellId_to_YPosition(int cellId);
    static int position_to_cellId(int x, int y);
    
    int getLookDirection(int fromCellId, int toCellId);
    int getLookDirection(int fromCellX, int fromCellY, int toCellX, int toCellY);

    static int getManhattanDistance(int cellId1, int cellId2);
    static float getEuclidianDistance(int cellId1, int cellId2);

    bool isInMap(int cellId) { return cellId < cells.size() && cellId >= 0; }
    static bool isCoordsInMap(int x, int y);
    bool canMove(int cellId, int previousCellId = -1, int endCellId = -1, bool avoidObstacles = true, bool allowThroughEntities = true);
    virtual bool isThereBlockingEntityOn(int cellId, bool allowThroughEntities = true);
    virtual bool isThereSeeBlockingEntityOn(int cellId, bool allowThroughEntities = false);
    bool isChangeZone(int cellId1, int cellId2);

    bool isThereLos(int destCellId, int referencePosition);
    vector<int> getLosFromCells(vector<int> range, int referencePosition);

    void addMark(GameActionMark mark);
    void removeMark(int markId);
    virtual int cellSpecialEffects(int x, int y);
    virtual void setCellSpecialEffects(int x, int y, int specialEffects);

    virtual void addActor(sp<GameContextActorInformations> actorInfos) = 0;
    sp<ActorData> getActor(double actorId);
    virtual void removeActor(double actorId);
    // sp<RoleplayCharacterData> getPlayer(double playerId);
    // sp<RoleplayNpcData> getNpc(double npcId);
    // sp<RoleplayMonsterGroupData> getMonsterGroup(double monsterGroupId);

    virtual bool isFight() = 0;


protected:
    // TODO : fichier de configurations où placer mapsFolder
    // Folder where all maps' data is located
    string mapsFolder = "./database/maps/json/";

    // vector<string> mapFormats = {"json", "dlm", "d2o"};
    bool loadMapCellsInformations();
    virtual void clearAll();
    void updateMarksInformations();
    // cell1&2 are arrays of 2 elements : cellId and distance to referencePosition
    static bool sortCellDist(int* cell1, int* cell2);
    vector<int> getLine(int cell1, int cell2);

// public:
    vector<sp<Cell>> cells;
    unordered_map<int, sp<Mark>> marks;
    bool cellsLoaded = false;

public:
    vector<int> upChangeMapCellsId;
    vector<int> rightChangeMapCellsId;
    vector<int> downChangeMapCellsId;
    vector<int> leftChangeMapCellsId;

    double rightMapId = 0;
    double downMapId = 0;
    double leftMapId = 0;
    double upMapId = 0;

// protected:
	// vector<sp<GameRolePlayActorInformations>> actors;
    unordered_map<double, sp<ActorData>> allActors;
    // unordered_map<double, weak_ptr<RoleplayCharacterData>> players;
    // unordered_map<double, weak_ptr<RoleplayMonsterGroupData>> monsterGroups;
    // unordered_map<double, weak_ptr<RoleplayNpcData>> npcs;

	// unordered_map<int, sp<InteractiveElement>> interactiveElements;
	// unordered_map<int, StatedElement> statedElements;

	int subAreaId = 0;
	double mapId = 0;
	bool hasAggressiveMonsters = false;

    static const int MAP_WIDTH = 14;
    static const int MAP_HEIGHT = 20;
};

#endif