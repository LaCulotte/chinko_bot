#include "GameFightStartingMessage.h"

bool GameFightStartingMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(fightType);
	output->writeVarShort(fightId);
	output->writeDouble(attackerId);
	output->writeDouble(defenderId);

    return true;
}

bool GameFightStartingMessage::deserialize(sp<MessageDataBuffer> input) {
	fightType = input->readByte();
	fightId = input->readVarShort();
	attackerId = input->readDouble();
	defenderId = input->readDouble();

    return true;
}
