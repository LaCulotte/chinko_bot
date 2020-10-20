#ifndef API_LISTENINGSERVER_H
#define API_LISTENINGSERVER_H

#include "ListeningServer.h"
#include "APIServerConnection.h"

#include "APIServerFullMessage.h"

class APIListeningServer : public ListeningServer {
public:
    APIListeningServer() : ListeningServer() {};

    // Constructor with listening port initialisation
    APIListeningServer(int listeningPort) : ListeningServer(listeningPort) {};
    // Constructor with listening port and the maximum number of connections initialisation
    APIListeningServer(int listeningPort, int maxConnections) : ListeningServer(listeningPort, maxConnections) {};
    // Copy constructor
    APIListeningServer(const APIListeningServer& other) = delete;

    // Copy operator
    virtual APIListeningServer& operator=(const APIListeningServer& other) = delete;
    // Destructor
    virtual ~APIListeningServer() = default;

protected:
    // Turns a socket into a wanted serverConnection. To implement in override in order to return an object of the wanted type
    virtual sp<ServerConnection> acceptConnection(int serverConnectionSocket);
    // Closes the connection associated to 'serverConnectionSocket'. To implement if a special action is necessary on close.
    virtual void refuseConnection(int serverConnectionSocket);
};

#endif