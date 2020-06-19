#include "QueueStatusMessage.h"

bool QueueStatusMessage::serialize(shared_ptr<MessageDataBuffer> output) {

	output->writeShort(position);
	output->writeShort(total);

	return true;
}

bool QueueStatusMessage::deserialize(shared_ptr<MessageDataBuffer> input) {

	position = input->readShort();
	total = input->readShort();

	return true;
}
