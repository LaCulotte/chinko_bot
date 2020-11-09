#include "ObjectQuantityMessage.h"

bool ObjectQuantityMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt(objectUID);
	output->writeVarInt(quantity);
	output->writeByte(origin);

    return true;
}

bool ObjectQuantityMessage::deserialize(sp<MessageDataBuffer> input) {
	objectUID = input->readVarInt();
	quantity = input->readVarInt();
	origin = input->readByte();

    return true;
}
