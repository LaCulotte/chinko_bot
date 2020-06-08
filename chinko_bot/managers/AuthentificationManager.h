#ifndef AUTHENTIFICATION_MANAGER_H
#define AUTHENTIFICATION_MANAGER_H

#include "AuthentificationFrame.h"
#include "DofusBotUnit.h"

#include "DofusClientConnection.h"
#include "ConnectionUnit.h"
#include "ConnectionRequestMessage.h"

// enum State_AuthentificationManager {
//     state_none = 0,
//     state_connected,
//     state_authentified
// };

class DofusBotUnit;
class AuthentificationManager {
public:
    // Constructor
    AuthentificationManager();
    // Constructor with username and password initialization
    AuthentificationManager(string username, string password);
    // Copy constructor
    AuthentificationManager(const AuthentificationManager& other) = default;

    // Copy operator
    AuthentificationManager& operator=(const AuthentificationManager& other) = default;
    // Destructor
    ~AuthentificationManager() = default;

    void setCredentials(string username, string password);
    void setBot(DofusBotUnit *bot) { this->bot = bot; };

    bool beginAuthentification(string server, int port);

    // void resetState();
    // void setState(State_AuthentificationManager new_state);

    void setDofusConnectionId(int id) { dofusConnectionId = id; };

protected:
    string username;
    string password;

    int dofusConnectionId;

    DofusBotUnit *bot = nullptr;

    // State_AuthentificationManager current_state = state_none;
};

#endif