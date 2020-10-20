#include "APIListeningServer.h"

sp<ServerConnection> APIListeningServer::acceptConnection(int serverConnectionSocket) {
    // Builds new connection
    sp<APIServerConnection> newConnection = make_shared<APIServerConnection>();
    // Sets connection's socket
    newConnection->setSocket(serverConnectionSocket);

    // Returns connection
    return newConnection;
}

void APIListeningServer::refuseConnection(int serverConnectionSocket) {
    // Builds connection
    sp<APIServerConnection> refusedConnection = make_shared<APIServerConnection>();
    // Set's connection's socket
    refusedConnection->setSocket(serverConnectionSocket);

    // Retreive address
    refusedConnection->onConnection();
    // Sends message to indicate that the API's server is full
    refusedConnection->sendMessage(make_shared<APIServerFullMessage>());

    Logger::write(refusedConnection->getConnectedAddress() + " was refused : listening server full.", LOG_WARNING);

    // Disconnects from the refused connection
    refusedConnection->disconnect();
}