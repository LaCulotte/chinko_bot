#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include "NetworkConnection.h"

class ServerConnection : public virtual NetworkConnection {
public:
    // Constructor
    ServerConnection() : NetworkConnection() { connectionDescription = "ServerConnection"; }

    /** Function that will be called when the server connection is build
     * Here, just gets the ip address
     */
    virtual void onConnection();
};

#endif