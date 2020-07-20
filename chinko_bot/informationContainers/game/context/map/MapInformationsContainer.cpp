#include "MapInformationsContainer.h"


bool MapInformationsContainer::loadMapInformations(sp<MapComplementaryInformationsDataMessage> mcidMsg) {
    actors = mcidMsg->actors;
    obstacles = mcidMsg->obstacles;
    interactiveElements = mcidMsg->interactiveElements;
    statedElements = mcidMsg->statedElements;
    subAreaId = mcidMsg->subAreaId;
    mapId = mcidMsg->mapId;
    hasAggressiveMonsters = mcidMsg->hasAggressiveMonsters;
    
    return this->loadMapCellsInformations();
}

bool MapInformationsContainer::loadMapInformations(int mapId) {
    actors.clear();
    obstacles.clear();
    interactiveElements.clear();
    statedElements.clear();

    subAreaId = 0;
    hasAggressiveMonsters = false;
    
    this->mapId = mapId;
    
    return this->loadMapCellsInformations();
}

bool MapInformationsContainer::loadMapCellsInformations() {
    ostringstream filename_strstream;
    filename_strstream.precision(0);
    filename_strstream << mapsFolder << "/" << fixed << mapId << ".json";

    ifstream mapFile_stream(filename_strstream.str(), ifstream::binary);

    if(!mapFile_stream) {
        Logger::write("Cannot open the map information file of mapId : " + to_string(mapId) + ".", LOG_ERROR);
        return false;
    }

    Json::Value mapFile_json;
    Json::Reader mapFile_reader;

    bool couldRead = mapFile_reader.parse(mapFile_stream, mapFile_json);

    if(!couldRead) {
        Logger::write("Cannot read the map information file of mapId : " + to_string(mapId) + "; it is not a correct json file.", LOG_ERROR);
        return false;
    }

    if(!mapFile_json["cells"]) {
        Logger::write("The map information file of mapId : " + to_string(mapId) + " is not a valid information file : does not contain \"cells\"", LOG_ERROR);
        return false;
    }

    for(auto cell_json : mapFile_json["cells"]) {
        sp<Cell> cell(new Cell());
        cell->mov = cell_json["mov"].asBool();
        cell->floor = cell_json["floor"].asInt();
        cell->moveZone = cell_json["moveZone"].asInt();
        cell->speed = cell_json["speed"].asInt();
        cell->mapChangeData = cell_json["mapChangeData"].asInt();
        cell->linkedZone = cell_json["_linkedZone"].asInt();
        
        cells.push_back(cell);
    }

    return false;
}