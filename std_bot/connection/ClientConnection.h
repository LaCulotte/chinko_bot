#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

#include "NetworkConnection.h"

class ClientConnection : public virtual NetworkConnection {
public: 
    // Constructor
    ClientConnection() : NetworkConnection() { connectionDescription = " ClientConnection "; };

    // Connects the connection to a remote server
    virtual bool connectTo(string address, int port);
    
};

#endif