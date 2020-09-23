#include "GameActionFightPointsVariationMessage.h"

bool GameActionFightPointsVariationMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionMessage::serialize(output);

	output->writeDouble(targetId);
	output->writeShort(delta);

    return true;
}

bool GameActionFightPointsVariationMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionMessage::deserialize(input);

	targetId = input->readDouble();
	delta = input->readShort();

    return true;
}
