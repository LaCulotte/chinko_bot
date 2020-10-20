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
            if(connectionUnitId != -1) {
                sendMessage(make_shared<AddConnectionMessage>(incomingConnection), connectionUnitId);

                incomingConnection->sendMessage(make_shared<APIHelloMessage>());
            }
        } else if(incomingConnection) {
            incomingConnection->disconnect();
        }
    }

    MessagingUnit::tick();
}
