#include "SkillActionDescription.h"

bool SkillActionDescription::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(skillId);

    return true;
}

bool SkillActionDescription::deserialize(sp<MessageDataBuffer> input) {
	skillId = input->readVarShort();

    return true;
}
