#include "SequenceNumberMessage.h"

bool SequenceNumberMessage::serialize(shared_ptr<MessageDataBuffer> output) {

	output->writeShort(sequenceNumber);

	return true;
}

bool SequenceNumberMessage::deserialize(shared_ptr<MessageDataBuffer> input) {

	sequenceNumber = input->readShort();

	return true;
}
