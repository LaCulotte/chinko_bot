#include "InteractiveElementSkill.h"

bool InteractiveElementSkill::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt(skillId);
	output->writeInt(skillInstanceUid);

    return true;
}

bool InteractiveElementSkill::deserialize(sp<MessageDataBuffer> input) {
	skillId = input->readVarInt();
	skillInstanceUid = input->readInt();

    return true;
}
