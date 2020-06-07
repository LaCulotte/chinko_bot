#include "ConnectionUnit.h"

ConnectionUnit::ConnectionUnit() : MessagingUnit() {
    messagingUnitDescription = "ConnectionUnit";
}

void ConnectionUnit::initFrames(){
    addFrame(make_shared<BasicConnectionUnitFrame>());
}

int ConnectionUnit::connectToServer(sp<ClientConnection> toConnect, string address, int port, int sourceInterfaceId){
    // Returns if toConnect is nullptr
    if(!toConnect)
        return -1;

    // Tries to establish the connection
    if(toConnect->connectTo(address, port)){
        // If it succeeds, returns the id of the newly added connection.
        return addConnection(toConnect, sourceInterfaceId);
    } else {
        // Returns -1 to indicate that the connection could not be made
        return -1;
    }
}

int ConnectionUnit::addConnection(sp<Connection> connection, int sourceInterfaceId){
    // Checks if the connection is valid
    if(!connection)
        return -1;
    
    // Insert the new connection
    connections.insert(pair<int, sp<Connection>>(lastConnectionId++, connection));

    // Changes the connection's destination and the source's preffered destination connection 
    if(sourceInterfaceId != -1 && msgInterfaces.find(sourceInterfaceId) != msgInterfaces.end()) {
        
        connectionId_to_interfaceId.insert(pair(lastConnectionId - 1, sourceInterfaceId));
        interfaceId_to_preferredConnectionId[sourceInterfaceId] = lastConnectionId - 1;
    }

    return lastConnectionId - 1;
}

bool ConnectionUnit::sendConnectionMessage(sp<ConnectionMessage> message, int destConnectionId, int sourceInterfaceId) {
    // Tries to find the destination with 'destConnectionId'
    if(connections.find(destConnectionId) != connections.end()){
        sp<Connection> connection = connections.at(destConnectionId);

        // Changes the source's preffered destination connection
        if(msgInterfaces.find(sourceInterfaceId) != msgInterfaces.end())
            interfaceId_to_preferredConnectionId[sourceInterfaceId] = destConnectionId;

        // Sends the message
        return connection->sendMessage(message);
    } else if(interfaceId_to_preferredConnectionId.find(sourceInterfaceId) != interfaceId_to_preferredConnectionId.end()){
        // If the destination id is invalid, sends the message to the source's preffered destination connection
        int connectionId = interfaceId_to_preferredConnectionId.at(sourceInterfaceId);

        if(connections.find(connectionId) != connections.end())
            return connections.at(connectionId)->sendMessage(message);
    }

    return false;
}

bool ConnectionUnit::changeConnectionDestination(int connectionId, int newDestinationId) {
    // Checks if the connectionId and the newDestinationId are valid 
    if(connections.find(connectionId) != connections.end() && msgInterfaces.find(newDestinationId) != msgInterfaces.end()){

        // Change occurs
        connectionId_to_interfaceId[connectionId] = newDestinationId;
        interfaceId_to_preferredConnectionId[newDestinationId] = connectionId;

        return true;
    }

    return false;
}

void ConnectionUnit::disconnect(int connectionId){
    // Finds the connection
    auto connectionIt = connections.find(connectionId);
    if(connectionIt != connections.end()){
        // Disconnects
        connectionIt->second->disconnect();

        // Removes the connection
        connections.erase(connectionIt);
        if(connectionId_to_interfaceId.find(connectionId) != connectionId_to_interfaceId.end())
            connectionId_to_interfaceId.erase(connectionId); 
        
        //Removes the connection from the prefferred destination connections
        for(auto it = interfaceId_to_preferredConnectionId.begin(); it != interfaceId_to_preferredConnectionId.end(); it++){
            if(it->second = connectionId)
                interfaceId_to_preferredConnectionId.erase(it);
        }
    }
}

void ConnectionUnit::tick(){
    // Before anything, retreives one message from every connections and send them to the correct destination
    for(auto it = connections.begin(); it != connections.end(); it++){
        sp<ConnectionMessage> message = it->second->readMessage();
        if(!message)
            continue;
        
        message->sourceConnectionId = it->first;

        if(connectionId_to_interfaceId.find(it->first) != connectionId_to_interfaceId.end()){

            int destId = connectionId_to_interfaceId.at(it->first);
            if(msgInterfaces.find(destId) != msgInterfaces.end()){
                sp<MessageInterface> dest = msgInterfaces.at(destId)[1];
                dest->send(message);
            } else {
                connectionId_to_interfaceId.erase(it->first);
            }
        }
    }

    // Proceeds to the usual MessagingUnit's tick
    MessagingUnit::tick();
}

bool ConnectionUnit::removeMessageInterface(int interfaceId) {

    if(MessagingUnit::removeMessageInterface(interfaceId)) {

        // If the MessagingUnit was successfully removes, removes it from the preferred connection destination map 
        auto it = interfaceId_to_preferredConnectionId.find(interfaceId);
        if(it != interfaceId_to_preferredConnectionId.end()){
            interfaceId_to_preferredConnectionId.erase(it);
        }

        return true;
    }

    return false;
}

bool ConnectionUnit::removeMessageInterface(map<int, sp<MessageInterface>*>::iterator interfaceIt) {
    if(MessagingUnit::removeMessageInterface(interfaceIt)) {
    
        // If the MessagingUnit was successfully removes, removes it from the preferred connection destination map 
        auto it = interfaceId_to_preferredConnectionId.find(interfaceIt->first);
        if(it != interfaceId_to_preferredConnectionId.end()){
            interfaceId_to_preferredConnectionId.erase(it);
        }

        return true;
    }

    return false;
}