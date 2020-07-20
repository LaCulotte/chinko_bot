#ifndef MAP_INFORMATIONSCONTAINER_H
#define MAP_INFORMATIONSCONTAINER_H

#include "std_include.h"
#include <json/value.h>
#include <json/reader.h>
#include <fstream>

#include "Cell.h"

#include "MapComplementaryInformationsDataMessage.h"

class MapInformationsContainer {
public:
    // Constructor
    MapInformationsContainer() {};
    // Constructor with mapsFolder initialization
    MapInformationsContainer(string mapsFolder) { this->mapsFolder = mapsFolder; };
    // Copy constructor
    MapInformationsContainer(const MapInformationsContainer& other) = default;

    // Copy operator
    MapInformationsContainer& operator=(const MapInformationsContainer& other) = default;
    // Destructor
    ~MapInformationsContainer() = default;

    bool loadMapInformations(int mapId);
    bool loadMapInformations(sp<MapComplementaryInformationsDataMessage> mcidMsg);


protected:
    // TODO : fichier de configurations où placer mapsFolder
    // Folder where all maps' data is located
    string mapsFolder = "./database/maps/json/";

    // vector<string> mapFormats = {"json", "dlm", "d2o"};

    bool loadMapCellsInformations();
    vector<sp<Cell>> cells;

	vector<sp<GameRolePlayActorInformations>> actors;
	vector<MapObstacle> obstacles;
	vector<sp<InteractiveElement>> interactiveElements;
	vector<StatedElement> statedElements;
	int subAreaId = 0;
	double mapId = 0;
	bool hasAggressiveMonsters = false;
};

#endif