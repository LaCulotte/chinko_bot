#include "GameActionFightLifeAndShieldPointsLostMessage.h"

bool GameActionFightLifeAndShieldPointsLostMessage::serialize(sp<MessageDataBuffer> output) {
	GameActionFightLifePointsLostMessage::serialize(output);

	output->writeVarShort(shieldLoss);

    return true;
}

bool GameActionFightLifeAndShieldPointsLostMessage::deserialize(sp<MessageDataBuffer> input) {
	GameActionFightLifePointsLostMessage::deserialize(input);

	shieldLoss = input->readVarShort();

    return true;
}
