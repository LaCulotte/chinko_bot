#include "ActorOrientation.h"

bool ActorOrientation::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(id);
	output->writeByte(direction);

    return true;
}

bool ActorOrientation::deserialize(sp<MessageDataBuffer> input) {
	id = input->readDouble();
	direction = input->readByte();

    return true;
}
