#include "InteractiveElementNamedSkill.h"

bool InteractiveElementNamedSkill::serialize(sp<MessageDataBuffer> output) {
	InteractiveElementSkill::serialize(output);

	output->writeVarInt(nameId);

    return true;
}

bool InteractiveElementNamedSkill::deserialize(sp<MessageDataBuffer> input) {
	InteractiveElementSkill::deserialize(input);

	nameId = input->readVarInt();

    return true;
}
