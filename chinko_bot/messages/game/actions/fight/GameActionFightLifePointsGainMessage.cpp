#include "GameActionFightLifePointsGainMessage.h"

bool GameActionFightLifePointsGainMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionMessage::serialize(output);

	output->writeDouble(targetId);
	output->writeVarInt(delta);

    return true;
}

bool GameActionFightLifePointsGainMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionMessage::deserialize(input);

	targetId = input->readDouble();
	delta = input->readVarInt();

    return true;
}
