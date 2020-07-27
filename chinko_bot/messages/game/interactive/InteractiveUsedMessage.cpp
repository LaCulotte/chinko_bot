#include "InteractiveUsedMessage.h"

bool InteractiveUsedMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt64(entityId);
	output->writeVarInt(elemId);
	output->writeVarShort(skillId);
	output->writeVarShort(duration);
	output->writeBool(canMove);

    return true;
}

bool InteractiveUsedMessage::deserialize(sp<MessageDataBuffer> input) {
	entityId = input->readVarInt64();
	elemId = input->readVarInt();
	skillId = input->readVarShort();
	duration = input->readVarShort();
	canMove = input->readBool();

    return true;
}
