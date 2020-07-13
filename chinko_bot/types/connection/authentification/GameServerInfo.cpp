#include "GameServerInfo.h"

bool GameServerInfo::serialize(sp<MessageDataBuffer> output) {
    uchar flags = isMonoAccount | (isSelectable << 1);
    output->writeByte(flags);

    output->writeVarShort(id);
    output->writeByte(type);
    output->writeByte(status);
    output->writeByte(completion);

    output->writeByte(charactersCount);
    output->writeByte(charactersSlots);

    output->writeDouble(date);

    return true;
} 

bool GameServerInfo::deserialize(sp<MessageDataBuffer> input) {
    uchar flags = input->readByte();
    isMonoAccount = flags & 1;
    isSelectable = flags & 2;

    id = input->readVarShort();
    type = input->readByte();
    status = input->readByte();
    completion = input->readByte();

    charactersCount = input->readByte();
    charactersSlots = input->readByte();

    date = input->readDouble();

    return true;
}