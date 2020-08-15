#include "GameFightMonsterInformations.h"

bool GameFightMonsterInformations::serialize(sp<MessageDataBuffer> output) {
	GameFightAIInformations::serialize(output);

	output->writeVarShort(creatureGenericId);
	output->writeByte(creatureGrade);
	output->writeShort(creatureLevel);

    return true;
}

bool GameFightMonsterInformations::deserialize(sp<MessageDataBuffer> input) {
	GameFightAIInformations::deserialize(input);

	creatureGenericId = input->readVarShort();
	creatureGrade = input->readByte();
	creatureLevel = input->readShort();

    return true;
}
