#include "GameActionFightDeathMessage.h"

bool GameActionFightDeathMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionMessage::serialize(output);

	output->writeDouble(targetId);

    return true;
}

bool GameActionFightDeathMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionMessage::deserialize(input);

	targetId = input->readDouble();

    return true;
}
