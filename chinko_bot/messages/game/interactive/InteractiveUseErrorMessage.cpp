#include "InteractiveUseErrorMessage.h"

bool InteractiveUseErrorMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt(elemId);
	output->writeVarInt(skillInstanceUid);

    return true;
}

bool InteractiveUseErrorMessage::deserialize(sp<MessageDataBuffer> input) {
	elemId = input->readVarInt();
	skillInstanceUid = input->readVarInt();

    return true;
}
