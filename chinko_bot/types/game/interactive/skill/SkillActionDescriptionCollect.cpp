#include "SkillActionDescriptionCollect.h"

bool SkillActionDescriptionCollect::serialize(sp<MessageDataBuffer> output) {
	SkillActionDescriptionTimed::serialize(output);

	output->writeVarShort(min);
	output->writeVarShort(max);

    return true;
}

bool SkillActionDescriptionCollect::deserialize(sp<MessageDataBuffer> input) {
	SkillActionDescriptionTimed::deserialize(input);

	min = input->readVarShort();
	max = input->readVarShort();

    return true;
}
