#include "ObjectDeletedMessage.h"

bool ObjectDeletedMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt(objectUID);

    return true;
}

bool ObjectDeletedMessage::deserialize(sp<MessageDataBuffer> input) {
	objectUID = input->readVarInt();

    return true;
}
