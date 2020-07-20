#include "GameContextCreateMessage.h"

bool GameContextCreateMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(context);

    return true;
}

bool GameContextCreateMessage::deserialize(sp<MessageDataBuffer> input) {
	context = input->readByte();

    return true;
}
