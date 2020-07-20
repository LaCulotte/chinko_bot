#include "HumanOptionSkillUse.h"

bool HumanOptionSkillUse::serialize(sp<MessageDataBuffer> output) {
	HumanOption::serialize(output);

	output->writeVarInt(elementId);
	output->writeVarShort(skillId);
	output->writeDouble(skillEndTime);

    return true;
}

bool HumanOptionSkillUse::deserialize(sp<MessageDataBuffer> input) {
	HumanOption::deserialize(input);

	elementId = input->readVarInt();
	skillId = input->readVarShort();
	skillEndTime = input->readDouble();

    return true;
}
