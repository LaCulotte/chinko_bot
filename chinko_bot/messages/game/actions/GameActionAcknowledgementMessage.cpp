#include "GameActionAcknowledgementMessage.h"

bool GameActionAcknowledgementMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeBool(valid);
	output->writeByte(actionId);

    return true;
}

bool GameActionAcknowledgementMessage::deserialize(sp<MessageDataBuffer> input) {
	valid = input->readBool();
	actionId = input->readByte();

    return true;
}
