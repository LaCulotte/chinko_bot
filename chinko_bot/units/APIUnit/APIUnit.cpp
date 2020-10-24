#include "APIUnit.h"
#include "ConnectionUnit.h"

APIUnit::~APIUnit() {
    if(listeningServer) {
        listeningServer->stop();
        listeningServer->waitThreadEnd();
    }
}

bool APIUnit::launchListeningServer() {
    connectionUnitId = this->getMessageInterfaceOutId<ConnectionUnit>();
    if(connectionUnitId == -1) {
        Logger::write("There is no ConnectionUnit linked to the APIUnit. Cannot launch listening server.", LOG_ERROR);
        return false;
    }


    listeningServer = make_shared<APIListeningServer>(DEFAULT_API_SERVER_INCOMING_PORT, 1);

    listeningServer->beginListening();
    Logger::write("Begin Listening.", LOG_DEBUG);

    return true;
}

void APIUnit::tick() {
    if(listeningServer) {
        sp<ServerConnection> incomingConnection = listeningServer->getLastConnection();
        if(dynamic_pointer_cast<APIServerConnection>(incomingConnection)) {
            if(getConnectionUnitId() != -1) {
                sendMessage(make_shared<AddConnectionMessage>(incomingConnection), connectionUnitId);
                this->waitsForAPIConnectionId = true;

                incomingConnection->sendMessage(make_shared<APIHelloMessage>());
            }
        } else if(incomingConnection) {
            incomingConnection->disconnect();
        }
    }

    MessagingUnit::tick();
}

void APIUnit::setAPIConnectionId(int apiConnectionId) {
    if(waitsForAPIConnectionId) {
        this->apiConnectionId = apiConnectionId;
        waitsForAPIConnectionId = false;
    }
}

int APIUnit::getConnectionUnitId() {
    if(connectionUnitId == -1) {
        connectionUnitId = this->getMessageInterfaceOutId<ConnectionUnit>();
        if(connectionUnitId == -1)
            Logger::write("No connectionUnit linked to APIUnit.", LOG_WARNING);
    }

    return connectionUnitId;
}

int APIUnit::getDofusBotUnitId() {
    if(dofusBotUnitId == -1) {
        dofusBotUnitId = this->getMessageInterfaceOutId<DofusBotUnit>();
        if(dofusBotUnitId == -1)
            Logger::write("No dofusBotUnit linked to APIUnit.", LOG_WARNING);
    }

    return dofusBotUnitId;
}
