#include "GameFightFighterInformations.h"

bool GameFightFighterInformations::serialize(sp<MessageDataBuffer> output) {
	GameContextActorInformations::serialize(output);

	spawnInfo.serialize(output);
	output->writeByte(wave);
	output->writeShort(stats->getId());
	stats->serialize(output);
	output->writeShort(previousPositions.size());
	for(int i = 0; i < previousPositions.size(); i++) {
		output->writeVarShort(previousPositions[i]);
	}

    return true;
}

bool GameFightFighterInformations::deserialize(sp<MessageDataBuffer> input) {
	GameContextActorInformations::deserialize(input);

	if(!spawnInfo.deserialize(input))
		return false;
	wave = input->readByte();
	int stats_TypeId = input->readShort();
	stats = dynamic_pointer_cast<GameFightMinimalStats>(NetworkTypeHandler::getInstance()->getTypeById(stats_TypeId));

	if(!stats || !stats->deserialize(input))
		return false;

	int previousPositions_size = input->readShort();
	for(int i = 0; i < previousPositions_size; i++) {
		int previousPosition;

		previousPosition = input->readVarShort();
		previousPositions.push_back(previousPosition);
	}

    return true;
}
