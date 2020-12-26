#ifndef APIUNIT_H
#define APIUNIT_H

#include "MessagingUnit.h"
#include "DofusBotUnit.h"
#include "TerminalPromptFrame.h"

#include "APIListeningServer.h"
#include "APIServerConnection.h"

#include "AddConnectionMessage.h"
#include "APIHelloMessage.h"

#define DEFAULT_API_SERVER_INCOMING_PORT 5555

class APIUnit : public MessagingUnit {
public:
    // Constructor
    APIUnit() : MessagingUnit() {};
    // Copy constructor
    APIUnit(const APIUnit& other) = default;

    // Copy operator
    APIUnit& operator=(const APIUnit& other) = default;
    // Destructor
    ~APIUnit();

    // Initialization of base frames
    void initFrames() override {};

    // Launches the server that listens for API connections
    bool launchListeningServer();

    virtual void tick() override;

    // Returns the ConnectionUnit's id
    int getConnectionUnitId();
    // Returns the DofusBotUnit's id
    int getDofusBotUnitId();
    // Returns the API connection's id
    int getAPIConnectionId() { return apiConnectionId; };
    // Sets the API's connection id
    bool setAPIConnectionId(int apiConnectionId);
    // Resets the API's connection id
    void resetAPIConnectionId() { apiConnectionId = -1; };


protected:
    // Listening server for API connection
    sp<APIListeningServer> listeningServer; 

    // Units' ids
    int connectionUnitId = -1;
    int dofusBotUnitId = -1;

    // Boolean that is true if the API unit has recevied a connection & is waiting for its id
    bool waitsForAPIConnectionId = false;
    // API connection's id
    int apiConnectionId = -1;
};

#endif