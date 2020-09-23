#include "GameActionFightSlideMessage.h"

bool GameActionFightSlideMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionMessage::serialize(output);

	output->writeDouble(targetId);
	output->writeShort(startCellId);
	output->writeShort(endCellId);

    return true;
}

bool GameActionFightSlideMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionMessage::deserialize(input);

	targetId = input->readDouble();
	startCellId = input->readShort();
	endCellId = input->readShort();

    return true;
}
