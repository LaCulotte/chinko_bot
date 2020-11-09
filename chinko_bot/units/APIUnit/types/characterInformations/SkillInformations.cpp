#include "SkillInformations.h"

bool SkillInformations::serialize(sp<MessageDataBuffer> output) {
    output->writeVarShort(skillId);
    output->writeVarInt(interactiveId);
    output->writeByte(range);

    return true;
}

bool SkillInformations::deserialize(sp<MessageDataBuffer> input) {
    skillId = input->readVarShort();
    interactiveId = input->readVarInt();
    range = input->readByte();

    return true;
}