#include "GameFightEntityInformation.h"

bool GameFightEntityInformation::serialize(sp<MessageDataBuffer> output) {
	GameFightFighterInformations::serialize(output);

	output->writeByte(entityModelId);
	output->writeVarShort(level);
	output->writeDouble(masterId);

    return true;
}

bool GameFightEntityInformation::deserialize(sp<MessageDataBuffer> input) {
	GameFightFighterInformations::deserialize(input);

	entityModelId = input->readByte();
	level = input->readVarShort();
	masterId = input->readDouble();

    return true;
}
