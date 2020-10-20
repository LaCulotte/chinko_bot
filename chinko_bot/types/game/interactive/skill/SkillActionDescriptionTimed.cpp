#include "SkillActionDescriptionTimed.h"

bool SkillActionDescriptionTimed::serialize(sp<MessageDataBuffer> output) {
	SkillActionDescription::serialize(output);

	output->writeByte(time);

    return true;
}

bool SkillActionDescriptionTimed::deserialize(sp<MessageDataBuffer> input) {
	SkillActionDescription::deserialize(input);

	time = input->readByte();

    return true;
}
