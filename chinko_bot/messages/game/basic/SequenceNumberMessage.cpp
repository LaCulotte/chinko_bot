#include "SequenceNumberMessage.h"

bool SequenceNumberMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(number);

    return true;
}

bool SequenceNumberMessage::deserialize(sp<MessageDataBuffer> input) {
	number = input->readShort();

    return true;
}
