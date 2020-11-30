#include "ObjectAddedMessage.h"

bool ObjectAddedMessage::serialize(sp<MessageDataBuffer> output) {
	object.serialize(output);
	output->writeByte(origin);

    return true;
}

bool ObjectAddedMessage::deserialize(sp<MessageDataBuffer> input) {
	if(!object.deserialize(input))
		return false;
	origin = input->readByte();

    return true;
}
