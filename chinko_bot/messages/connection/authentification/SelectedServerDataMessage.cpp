#include "SelectedServerDataMessage.h"

bool SelectedServerDataMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeVarShort(serverId);
    output->writeUTF(address);
    
    output->writeShort(ports.size());
    for(int port : ports)
        output->writeInt(port);

    output->writeBool(canCreateNewCharacter);

    output->writeVarInt(ticket.size());
    output->writeUTFBytes(ticket);

    return true;
}

bool SelectedServerDataMessage::deserialize(sp<MessageDataBuffer> input) {
    serverId = input->readVarShort();
    address = input->readUTF();

    int portsLen = input->readShort();
    for(int i = 0; i < portsLen; i++)
        ports.push_back(input->readVarShort());

    canCreateNewCharacter = input->readBool();

    int ticketLen = input->readVarInt();
    ticket = input->readUTFBytes(ticketLen);

    return true;
}