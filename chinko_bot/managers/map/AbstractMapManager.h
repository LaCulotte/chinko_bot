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

    // Loads map informations from the map's json file
    bool loadMapInformations(int mapId);

    // Returns the cell of cellId
    sp<Cell> getCell(int cellId) { if(isInMap(cellId)) return cells[cellId]; else return nullptr; }
    // Returns the number of cells on the map
    int getCellsCount() { return cells.size(); }
    // Returns the map's Id
    double getMapId() { return mapId; }
    // Returns true if the cells are loaded
    bool areCellsLoaded() { return cellsLoaded; };

    // Updates an actor's position
    bool updateActorPosition(double actorId, int newCellId);
    // Updates an actor's informations
    void updateActorInfos(sp<GameContextActorInformations> actorInfos);

    // Returns X coordinated from a cellId
    static int cellId_to_XPosition(int cellId);
    // Returns Y coordinated from a cellId
    static int cellId_to_YPosition(int cellId);
    // Returns cellId from coordinates
    static int position_to_cellId(int x, int y);
    
    // Returns look direction
    int getLookDirection(int fromCellId, int toCellId);
    // Returns look direction
    int getLookDirection(int fromCellX, int fromCellY, int toCellX, int toCellY);
    // Returns advanced orientation
    int getAdvancedOrientation(int fromCellId, int toCellId, bool fourDir = true);
    // Returns advanced orientation
    int getAdvancedOrientation(int fromCellX, int fromCellY, int toCellX, int toCellY, bool fourDir = true);
    // Returns distance between two orientations
    int getOrientationDist(int dir1, int dir2);

    // Returns nearest cell in direction
    int getNearestCellInDirection(int srcCellId, int dir);
    // Returns nearest free cell in direction
    int getNearestFreeCellInDirection(int srcCellId, int dir, bool allowItself = true, bool allowThroughEntity = true, bool ignoreSpeed = false, sp<vector<int>> forbiddenCells = nullptr);

    // Returns Manhattan distance between two cells 
    static int getManhattanDistance(int cellId1, int cellId2);
    // Returns Euclidian distance between two cells 
    static float getEuclidianDistance(int cellId1, int cellId2);

    // Returns true if the cellId is valid in the current map
    bool isInMap(int cellId) { return cellId < cells.size() && cellId >= 0; }
    // Returns true if the cell's coordiantes are valid in the current map
    static bool isCoordsInMap(int x, int y);
    // Translation of DataMapProvider::pointMov function from the dofus' source code
    bool canMove(int cellId, int previousCellId = -1, int endCellId = -1, bool avoidObstacles = true, bool allowThroughEntities = true);
    // Returns true if there is a blocking entity on a cell
    virtual bool isThereBlockingEntityOn(int cellId, bool allowThroughEntities = true);
    // Returns true if there is a see blocking entity on a cell
    virtual bool isThereSeeBlockingEntityOn(int cellId, bool allowThroughEntities = false);
    // Returns true if there is a change of zone between two cells
    bool isChangeZone(int cellId1, int cellId2);

    // Returns true if there is a lign of sight between two cells
    bool isThereLos(int destCellId, int referencePosition);
    // Translation of LosDetector::getCell function from the dofus' source code
    vector<int> getLosFromCells(vector<int> range, int referencePosition);

    // Adds mark 
    void addMark(GameActionMark mark);
    // Removes mark 
    void removeMark(int markId);
    // Translation of DataMapProvider::pointSpecialEffects function from the dofus' source code
    virtual int cellSpecialEffects(int x, int y);
    // Translation of DataMapProvider::setSpecialEffects function from the dofus' source code
    virtual void setCellSpecialEffects(int x, int y, int specialEffects);

    // Adds an actor to the map
    virtual void addActor(sp<GameContextActorInformations> actorInfos) = 0;
    // Gets an actor from the map
    sp<ActorData> getActor(double actorId);
    // Removes an actor from the map
    virtual void removeActor(double actorId);

    // Returns true if the bot is currently in a fight (ie. It is a FightMapManager)
    virtual bool isFight() = 0;


protected:
    // TODO : fichier de configurations où placer mapsFolder
    // Folder where all maps' data is located
    string mapsFolder = "./database/maps/json/";

    // vector<string> mapFormats = {"json", "dlm", "d2o"};
    bool loadMapCellsInformations();
    // Clears every container of the map
    virtual void clearAll();
    // Updates marks informations
    void updateMarksInformations();
    // cell1&2 are arrays of 2 elements : cellId and distance to referencePosition
    static bool sortCellDist(int* cell1, int* cell2);
    // Translation of Dofus2Line::getLine function from the dofus' source code
    vector<int> getLine(int cell1, int cell2);

    // Cells of the map
    vector<sp<Cell>> cells;
    // Marks of the map
    unordered_map<int, sp<Mark>> marks;
    // True if the cells are loaded
    bool cellsLoaded = false;

public:
    // List of the cells that allow to change to the up map
    vector<int> upChangeMapCellsId;
    // List of the cells that allow to change to the right map
    vector<int> rightChangeMapCellsId;
    // List of the cells that allow to change to the down map
    vector<int> downChangeMapCellsId;
    // List of the cells that allow to change to the left map
    vector<int> leftChangeMapCellsId;

    // Id of the right map
    double rightMapId = 0;
    // Id of the down map
    double downMapId = 0;
    // Id of the left map
    double leftMapId = 0;
    // Id of the up map
    double upMapId = 0;

// protected:
    // Map the actor's id to its instance
    unordered_map<double, sp<ActorData>> allActors;

    // Map's sub area's id
	int subAreaId = 0;
    // Map's id
	double mapId = 0;
    // True if the map has aggressive monsters
	bool hasAggressiveMonsters = false;

    // Height & width of the current map
    static const int MAP_WIDTH = 14;
    static const int MAP_HEIGHT = 20;
};

#endif