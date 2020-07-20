#include "BasicTimeMessage.h"

bool BasicTimeMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(timestamp);
	output->writeShort(timezoneOffset);

    return true;
}

bool BasicTimeMessage::deserialize(sp<MessageDataBuffer> input) {
	timestamp = input->readDouble();
	timezoneOffset = input->readShort();

    return true;
}
