#include "SelectedServerDataExtendedMessage.h"

bool SelectedServerDataExtendedMessage::serialize(sp<MessageDataBuffer> output) {
    SelectedServerDataMessage::serialize(output);

    output->writeShort(servers.size());
    for(int i = 0; i < servers.size(); i++)
        servers[i].serialize(output);

    return true;
}

bool SelectedServerDataExtendedMessage::deserialize(sp<MessageDataBuffer> input) {
    if (!SelectedServerDataMessage::deserialize(input))
        return false;

    int serversLen = input->readShort();
    for(int i = 0; i < serversLen; i++){
        GameServerInfo gsi;
        gsi.deserialize(input);
        servers.push_back(gsi);
    }

    return true;
}