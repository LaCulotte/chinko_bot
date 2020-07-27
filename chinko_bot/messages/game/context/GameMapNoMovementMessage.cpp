#include "GameMapNoMovementMessage.h"

bool GameMapNoMovementMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(cellX);
	output->writeShort(cellY);

    return true;
}

bool GameMapNoMovementMessage::deserialize(sp<MessageDataBuffer> input) {
	cellX = input->readShort();
	cellY = input->readShort();

    return true;
}
