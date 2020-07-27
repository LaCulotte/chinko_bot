#ifndef GAMESERVER_INFORMATIONCONTAINER_H
#define GAMESERVER_INFORMATIONCONTAINER_H

#include "std_include.h"

class GameServerData {
public:
    // Constructor
    GameServerData() {};
    // Copy constructor
    GameServerData(const GameServerData& other) = default;

    // Copy operator
    GameServerData& operator=(const GameServerData& other) = default;
    // Destructor
    ~GameServerData() = default;

    // Game Server Informations

    // Server address
    std::string adress;
    // Game Server connection Id
    int connectionId;

    // Miscallenious informations
    // bool isMonoAccount;
    // bool isSelectable;
    
};

#endif