#include "LoginQueueStatusMessage.h"

bool LoginQueueStatusMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(position);
	output->writeShort(total);

    return true;
}

bool LoginQueueStatusMessage::deserialize(sp<MessageDataBuffer> input) {
	position = input->readShort();
	total = input->readShort();

    return true;
}
