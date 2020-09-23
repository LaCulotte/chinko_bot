#include "GameActionFightKillMessage.h"

bool GameActionFightKillMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionMessage::serialize(output);

	output->writeDouble(targetId);

    return true;
}

bool GameActionFightKillMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionMessage::deserialize(input);

	targetId = input->readDouble();

    return true;
}
