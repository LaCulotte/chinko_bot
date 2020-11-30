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

    bool launchListeningServer();

    virtual void tick() override;

    int getConnectionUnitId();
    int getDofusBotUnitId();
    int getAPIConnectionId() { return apiConnectionId; };
    bool setAPIConnectionId(int apiConnectionId);
    void resetAPIConnectionId() { apiConnectionId = -1; };


protected:
    sp<APIListeningServer> listeningServer; 

    int connectionUnitId = -1;
    int dofusBotUnitId = -1;

    bool waitsForAPIConnectionId = false;
    int apiConnectionId = -1;
};

#endif