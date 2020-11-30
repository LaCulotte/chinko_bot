#include "JobsXpMessage.h"

bool JobsXpMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeShort(jobsXp.size());
    for(int i = 0; i < jobsXp.size(); i++) {
        output->writeByte(jobsXp[i].jobId);
        output->writeVarInt64(jobsXp[i].jobXp);
        output->writeVarInt64(jobsXp[i].jobXpLevelFloor);
        output->writeVarInt64(jobsXp[i].jobXpNextLevelFloor);
    }

    return true;
}

bool JobsXpMessage::deserialize(sp<MessageDataBuffer> input) {
    int size = input->readShort();
    for(int i = 0; i < size; i++) {
        JobXp jobXp;
        jobXp.jobId = input->readByte();
        jobXp.jobXp = input->readVarInt64();
        jobXp.jobXpLevelFloor = input->readVarInt64();
        jobXp.jobXpNextLevelFloor = input->readVarInt64();

        jobsXp.push_back(jobXp);
    }
    
    return true;
}