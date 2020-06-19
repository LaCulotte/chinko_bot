#ifndef GAMESERVER_INFORMATIONCONTAINER_H
#define GAMESERVER_INFORMATIONCONTAINER_H

#include "std_include.h"

class GameServerInformationContainer {
public:
    // Constructor
    GameServerInformationContainer() {};
    // Copy constructor
    GameServerInformationContainer(const GameServerInformationContainer& other) = default;

    // Copy operator
    GameServerInformationContainer& operator=(const GameServerInformationContainer& other) = default;
    // Destructor
    ~GameServerInformationContainer() = default;

    std::string adress;
    int connectionId;

    // bool isMonoAccount;
    // bool isSelectable;
    
};

#endif