#include "CharacterHardcoreOrEpicInformations.h"

bool CharacterHardcoreOrEpicInformations::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!CharacterBaseInformations::serialize(output))
		return false;

	output->writeByte(deathState);
	output->writeVarShort(deathCount);
	output->writeVarShort(deathMaxLevel);

	return true;
}

bool CharacterHardcoreOrEpicInformations::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!CharacterBaseInformations::deserialize(input))
		return false;

	deathState = input->readByte();
	deathCount = input->readVarShort();
	deathMaxLevel = input->readVarShort();

	return true;
}
