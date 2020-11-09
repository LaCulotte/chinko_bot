#include "PlayedCharacterInformations.h"

bool PlayedCharacterInformations::serialize(sp<MessageDataBuffer> output) {
    output->writeDouble(id);
    output->writeUTF(name);
    output->writeByte(breedId);
    output->writeBool(sex);

    output->writeByte(level);
    output->writeVarInt64(xp);
    output->writeVarInt64(xpLevelFloor);
    output->writeVarInt64(xpNextLevelFloor);

    output->writeVarInt64(kamas);
    output->writeVarInt(weight);
    output->writeVarInt(maxWeight);

    output->writeShort(inventory.size());
    for(auto itemIt : inventory)
        itemIt.second.serialize(output);

    output->writeShort(jobs.size());
    for(auto jobIt : jobs)
        jobIt.second.serialize(output);

    return true;
}

bool PlayedCharacterInformations::deserialize(sp<MessageDataBuffer> input) {
    id = input->readDouble();
    name = input->readUTF();
    breedId = input->readByte();
    sex = input->readBool();

    level = input->readByte();
    xp = input->readVarInt64();
    xpLevelFloor = input->readVarInt64();
    xpNextLevelFloor = input->readVarInt64();

    kamas = input->readVarInt64();
    weight = input->readVarInt();
    maxWeight = input->readVarInt();

    int size = input->readShort();
    for(int i = 0; i < size; i++) {
        ItemInformations item;
        item.deserialize(input);
        inventory[item.itemUID] = item;
    }

    size = input->readShort();
    for(int i = 0; i < size; i++) {
        JobInformations job;
        job.deserialize(input);
        jobs[job.jobId] =  job;
    }

    return true;
}