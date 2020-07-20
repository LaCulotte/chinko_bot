#include "QueueStatusMessage.h"

bool QueueStatusMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(position);
	output->writeShort(total);

    return true;
}

bool QueueStatusMessage::deserialize(sp<MessageDataBuffer> input) {
	position = input->readShort();
	total = input->readShort();

    return true;
}
