#include "APIUnit.h"
#include "ConnectionUnit.h"

#include "APINoBotMessage.h"
#include "BotConnectionStatusRequestMessage.h"

APIUnit::~APIUnit() {
    // Stops the listening server
    if(listeningServer) {
        listeningServer->stop();
        listeningServer->waitThreadEnd();
    }
}

bool APIUnit::launchListeningServer() {
    // Gets connection unit's Id
    connectionUnitId = this->getMessageInterfaceOutId<ConnectionUnit>();
    if(connectionUnitId == -1) {
        Logger::write("There is no ConnectionUnit linked to the APIUnit. Cannot launch listening server.", LOG_ERROR);
        return false;
    }

    // Builds the listening server
    listeningServer = make_shared<APIListeningServer>(DEFAULT_API_SERVER_INCOMING_PORT, 1);

    // Launches the listening server
    listeningServer->beginListening();
    Logger::write("Begin Listening.", LOG_DEBUG);

    return true;
}

void APIUnit::tick() {
    if(listeningServer) {
        // Checks if there is an incoming connection
        sp<ServerConnection> incomingConnection = listeningServer->getLastConnection();
        if(dynamic_pointer_cast<APIServerConnection>(incomingConnection)) {
            if(getConnectionUnitId() != -1) {
                if(this->getDofusBotUnitId() != -1) {
                    // If there is, adds the connection to the connectionUnit 
                    sendMessage(make_shared<AddConnectionMessage>(incomingConnection), connectionUnitId);
                    // Wait for the id
                    this->waitsForAPIConnectionId = true;

                    // Sends a hello message to the client
                    incomingConnection->sendMessage(make_shared<APIHelloMessage>());
                } else {
                    // If there is not BotUnit, cannot take an API unit
                    incomingConnection->sendMessage(make_shared<APINoBotMessage>());
                    incomingConnection->disconnect();
                }
            }
        } else if(incomingConnection) {
            // If the incomingConnection is not an APIConnection, disconnects.
            incomingConnection->disconnect();
        }
    }

    // Regular tick
    MessagingUnit::tick();
}

bool APIUnit::setAPIConnectionId(int apiConnectionId) {
    // If the unit is waiting for the connection Id, sets it
    if(waitsForAPIConnectionId) {
        this->apiConnectionId = apiConnectionId;
        waitsForAPIConnectionId = false;

        return true;
    }

    return false;
}

int APIUnit::getConnectionUnitId() {
    // Gets ConnectionUnit's id
    if(connectionUnitId == -1) {
        connectionUnitId = this->getMessageInterfaceOutId<ConnectionUnit>();
        if(connectionUnitId == -1)
            Logger::write("No connectionUnit linked to APIUnit.", LOG_WARNING);
    }

    return connectionUnitId;
}

int APIUnit::getDofusBotUnitId() {
    // Gets DofusBotUnit's id
    if(dofusBotUnitId == -1) {
        dofusBotUnitId = this->getMessageInterfaceOutId<DofusBotUnit>();
        if(dofusBotUnitId == -1)
            Logger::write("No dofusBotUnit linked to APIUnit.", LOG_WARNING);
    }

    return dofusBotUnitId;
}
