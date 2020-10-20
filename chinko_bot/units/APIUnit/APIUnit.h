#ifndef APIUNIT_H
#define APIUNIT_H

#include "MessagingUnit.h"
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

    int botUnitId = -1;

protected:
    sp<APIListeningServer> listeningServer; 

    int connectionUnitId = -1;
};

#endif