#include "GameActionFightLifePointsLostMessage.h"

bool GameActionFightLifePointsLostMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionMessage::serialize(output);

	output->writeDouble(targetId);
	output->writeVarInt(loss);
	output->writeVarInt(permanentDamages);
	output->writeVarInt(elementId);

    return true;
}

bool GameActionFightLifePointsLostMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionMessage::deserialize(input);

	targetId = input->readDouble();
	loss = input->readVarInt();
	permanentDamages = input->readVarInt();
	elementId = input->readVarInt();

    return true;
}
