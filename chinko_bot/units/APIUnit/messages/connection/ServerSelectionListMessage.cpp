#include "ServerSelectionListMessage.h"

bool ServerSelectionListMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeVarInt(servers.size());

    for(int i = 0; i < servers.size(); i++)
        if(!servers[i].serialize(output))
            return false;
    
    return true;
}

bool ServerSelectionListMessage::deserialize(sp<MessageDataBuffer> input) {
    int size = input->readVarInt();

    for(int i = 0; i < size; i++) {
        ServerSelectInformations server;
        if(!server.deserialize(input))
            return false;

        servers.push_back(server);
    }

    return true;
}