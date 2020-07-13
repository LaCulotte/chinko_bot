#include "GameContextCreateMessage.h"

bool GameContextCreateMessage::serialize(shared_ptr<MessageDataBuffer> output) {
	output->writeByte(context);

	return true;
}

bool GameContextCreateMessage::deserialize(shared_ptr<MessageDataBuffer> input) {
	context = input->readByte();

	return true;
}
