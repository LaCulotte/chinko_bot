#ifndef API_CLIENT_CONNECTION_H
#define API_CLIENT_CONNECTION_H

#include "ClientConnection.h"
#include "APIConnection.h"

class APIClientConnection : public APIConnection, public ClientConnection {
public:
    APIClientConnection() : APIConnection() {};

    // Copy constructor
    APIClientConnection(const APIClientConnection& other) = default;

    // Copy operator
    APIClientConnection& operator=(const APIClientConnection& other) = default;
    // Destructor
    virtual ~APIClientConnection() = default; 

    // virtual void initHandler() override;
};

#endif