#include "BasicConnectionUnitFrame.h"

bool BasicConnectionUnitFrame::setParent(MessagingUnit *parent) {
    // The parent must be a ConnectionUnit
    if(dynamic_cast<ConnectionUnit *>(parent))
        return Frame::setParent(parent);

    return false;
}

bool BasicConnectionUnitFrame::computeMessage(sp<Message> message, int srcId) {
    ConnectionUnit *connectionParent = dynamic_cast<ConnectionUnit *>(parent);     

    // The parent must be a ConnectionUnit
    if(!connectionParent)
        return false;

    // Variables for casting the message
    sp<SendPacketRequestMessage> sprMsg;
    sp<GetConnectionFocusRequestMessage> gcfrMsg;
    sp<ConnectionRequestMessage> crMsg;
    sp<ConnectionIdGetMessage> cigMsg;
    sp<ConnectionIdMessage> ciMsg;
    sp<DisconnectRequestMessage> drMsg;

    switch (message->getId())
    {
    case SendPacketRequestMessage::protocolId:
        // The source wants to send a message through a connection 
        sprMsg = dynamic_pointer_cast<SendPacketRequestMessage>(message);
        
        // Tries to send a message and sends a response message according to the success of the send
        if(connectionParent->sendConnectionMessage(sprMsg->message, sprMsg->connectionId, srcId)){
            connectionParent->sendMessage(make_shared<SendPacketSuccessMessage>(), srcId);
        } else {
            connectionParent->sendMessage(make_shared<SendPacketFailureMessage>(), srcId);
        }
        
        return true;

    case GetConnectionFocusRequestMessage::protocolId:
        // The source wants to receive the messages of some connections
        gcfrMsg = dynamic_pointer_cast<GetConnectionFocusRequestMessage>(message);

        if(gcfrMsg->connectionIds.size()) {
            // The connections are specified with their id
            
            // Ids of the connections of which the focus has be changed
            vector<int> successIds;
            for(int id : gcfrMsg->connectionIds){
                if(connectionParent->changeConnectionDestination(id, srcId)){
                    successIds.push_back(id);
                }
            }

            // Sends response according to the success of the operation
            if(!successIds.size()){
                connectionParent->sendMessage(make_shared<GetConnectionFocusFailureMessage>("All failed"), srcId);
            } else {
                connectionParent->sendMessage(make_shared<GetConnectionFocusSuccessMessage>(successIds), srcId);
            }

        } else if(gcfrMsg->filter) {
            // The connections are specified with a filter

            // Ids of the connections of which the focus could be changed
            vector<int> ids;
            // Ids of the connections of which the focus has be changed
            vector<int> successIds;
            // Gets the connections ids with the filter
            if(gcfrMsg->all){
                ids = connectionParent->getAllConnectionIds<Connection>(gcfrMsg->filter);
            } else {
                ids = connectionParent->getConnectionIds<Connection>(gcfrMsg->n, gcfrMsg->filter);
            }

            // Tries to change the focus of the connections
            for(int id : ids){
                if(connectionParent->changeConnectionDestination(id, srcId)){
                    successIds.push_back(id);
                }
            }

            // Sends response according to the success of the operation
            if(!successIds.size()){
                connectionParent->sendMessage(make_shared<GetConnectionFocusFailureMessage>("No match"), srcId);
            } else {
                connectionParent->sendMessage(make_shared<GetConnectionFocusSuccessMessage>(successIds), srcId);
            }
        }

        return true;

    case ConnectionRequestMessage::protocolId:
        // The source wants to make a new connection
        crMsg = dynamic_pointer_cast<ConnectionRequestMessage>(message);

        if(crMsg->toConnect){
            // If the connection is sent by the source

            // Tries to connect it
            int conn_id = connectionParent->connectToServer(crMsg->toConnect, crMsg->address, crMsg->port, srcId);
            // Sends response according to the success of the connection
            if(conn_id != -1){
                connectionParent->sendMessage(make_shared<ConnectionSuccessMessage>(conn_id), srcId);
            } else {
                connectionParent->sendMessage(make_shared<ConnectionFailureMessage>("Connection fail"), srcId);
            }
        } else if(crMsg->connectionBuilder) {
            // If the connection must be built

            // Tries to build the connection
            sp<ClientConnection> toConnect = crMsg->connectionBuilder();

            if(toConnect){
                // Tries to connect the built connection
                int conn_id = connectionParent->connectToServer(toConnect, crMsg->address, crMsg->port, srcId);

                // Sends a message according to the success of the connection
                if(conn_id != -1){
                    connectionParent->sendMessage(make_shared<ConnectionSuccessMessage>(conn_id), srcId);
                } else {
                    connectionParent->sendMessage(make_shared<ConnectionFailureMessage>("Connection fail"), srcId);
                }
            } else {
                // The connection could not be built
                connectionParent->sendMessage(make_shared<ConnectionFailureMessage>("Build fail"), srcId);
            }
        } else {
            // No connection was specified
            connectionParent->sendMessage(make_shared<ConnectionFailureMessage>("No connection to"), srcId);
        }
        return true;

    case ConnectionIdGetMessage::protocolId:
        // The source wants to know the id of some connections
        cigMsg = dynamic_pointer_cast<ConnectionIdGetMessage>(message);

        // Builds the reponse message
        ciMsg = make_shared<ConnectionIdMessage>();
        // Gets the ids
        if(cigMsg->all){
            ciMsg->ids = connectionParent->getAllConnectionIds<Connection>(cigMsg->filter);
        } else {
            ciMsg->ids = connectionParent->getConnectionIds<Connection>(cigMsg->n, cigMsg->filter);
        }
        // Sends the response
        connectionParent->sendMessage(ciMsg, srcId);

        return true;
    
    case DisconnectRequestMessage::protocolId:
        // The source wants to disconnect some connections
        drMsg = dynamic_pointer_cast<DisconnectRequestMessage>(message);
        
        if(drMsg->connectionIds.size()){
            // If the ids are specified, disonnect them
            for(int id : drMsg->connectionIds){
                connectionParent->disconnect(id);
            }

            // Sends that the connections has been disconnected
            parent->sendMessage(make_shared<DisconnectedMessage>(drMsg->connectionIds), srcId);
        } else {
            // Ids of the connections that will be disconnected
            vector<int> disconnectIds;

            // Gets the ids
            if(drMsg->all){
                disconnectIds = connectionParent->getAllConnectionIds<Connection>(drMsg->filter);
            } else {
                disconnectIds = connectionParent->getConnectionIds<Connection>(drMsg->n, drMsg->filter);
            }

            // Disconnects
            for(int id : disconnectIds)
                connectionParent->disconnect(id);

            // Sends the disconnected connections
            parent->sendMessage(make_shared<DisconnectedMessage>(disconnectIds), srcId);
        }

        return true;
    }

    return false;
}