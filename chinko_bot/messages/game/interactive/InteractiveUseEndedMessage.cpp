#include "InteractiveUseEndedMessage.h"

bool InteractiveUseEndedMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt(elemId);
	output->writeVarShort(skillId);

    return true;
}

bool InteractiveUseEndedMessage::deserialize(sp<MessageDataBuffer> input) {
	elemId = input->readVarInt();
	skillId = input->readVarShort();

    return true;
}
