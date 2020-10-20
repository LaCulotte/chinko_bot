#include "SkillActionDescriptionCraft.h"

bool SkillActionDescriptionCraft::serialize(sp<MessageDataBuffer> output) {
	SkillActionDescription::serialize(output);

	output->writeByte(probability);

    return true;
}

bool SkillActionDescriptionCraft::deserialize(sp<MessageDataBuffer> input) {
	SkillActionDescription::deserialize(input);

	probability = input->readByte();

    return true;
}
