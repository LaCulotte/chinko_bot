#ifndef GAMESERVER_INFORMATIONCONTAINER_H
#define GAMESERVER_INFORMATIONCONTAINER_H

#include "std_include.h"

class GameServerInformationsContainer {
public:
    // Constructor
    GameServerInformationsContainer() {};
    // Copy constructor
    GameServerInformationsContainer(const GameServerInformationsContainer& other) = default;

    // Copy operator
    GameServerInformationsContainer& operator=(const GameServerInformationsContainer& other) = default;
    // Destructor
    ~GameServerInformationsContainer() = default;

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