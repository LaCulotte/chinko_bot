#ifndef API_SERVER_CONNECTION_H
#define API_SERVER_CONNECTION_H

#include "ServerConnection.h"
#include "APIConnection.h"

class APIServerConnection : public APIConnection, public ServerConnection {
public:
    APIServerConnection() : APIConnection() {};

    // Copy constructor
    APIServerConnection(const APIServerConnection& other) = default;

    // Copy operator
    APIServerConnection& operator=(const APIServerConnection& other) = default;
    // Destructor
    virtual ~APIServerConnection() = default; 

    // virtual void initHandler() override;
};

#endif