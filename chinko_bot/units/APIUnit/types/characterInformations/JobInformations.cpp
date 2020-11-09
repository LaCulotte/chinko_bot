#include "JobInformations.h"

bool JobInformations::serialize(sp<MessageDataBuffer> output) {
    output->writeVarShort(jobId);
    output->writeByte(level);
    output->writeInt64(xp);
    output->writeInt64(xpLevelFloor);
    output->writeInt64(xpNextLevelFloor);

    output->writeVarShort(skills.size());
    for(auto skillIt = skills.begin(); skillIt != skills.end(); skillIt++) {
        skillIt->second.serialize(output);
    }

    return true;
}

bool JobInformations::deserialize(sp<MessageDataBuffer> input) {
    jobId = input->readVarShort();
    level = input->readByte();
    xp = input->readInt64();
    xpLevelFloor = input->readInt64();
    xpNextLevelFloor = input->readInt64();

    int size = input->readVarShort();
    for(int i = 0; i < size; i++) {
        SkillInformations skill;
        skill.deserialize(input);
        skills.insert({skill.skillId, skill});
    }
    
    return true;
}