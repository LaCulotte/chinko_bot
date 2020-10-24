#include "ServerSelectInformations.h"

bool ServerSelectInformations::serialize(sp<MessageDataBuffer> output) {
    output->writeVarShort(id);
    output->writeUTF(name);
    output->writeVarShort(charactersCount);
    output->writeVarShort(slotsCount);
    output->writeByte(status);
    output->writeBool(isSelectable);

    return true;
}

bool ServerSelectInformations::deserialize(sp<MessageDataBuffer> input) {
    id = input->readVarShort();
    name = input->readUTF();
    charactersCount = input->readVarShort();
    slotsCount = input->readVarShort();
    status = input->readByte();
    isSelectable = input->readBool();

    return true;
}