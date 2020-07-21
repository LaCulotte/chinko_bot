#include "IdentificationFailedMessage.h"

bool IdentificationFailedMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(reason);

    return true;
}

bool IdentificationFailedMessage::deserialize(sp<MessageDataBuffer> input) {
	reason = input->readByte();

    return true;
}
