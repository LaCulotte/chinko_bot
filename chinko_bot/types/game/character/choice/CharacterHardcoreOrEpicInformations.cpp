#include "CharacterHardcoreOrEpicInformations.h"

bool CharacterHardcoreOrEpicInformations::serialize(sp<MessageDataBuffer> output) {
	CharacterBaseInformations::serialize(output);

	output->writeByte(deathState);
	output->writeVarShort(deathCount);
	output->writeVarShort(deathMaxLevel);

    return true;
}

bool CharacterHardcoreOrEpicInformations::deserialize(sp<MessageDataBuffer> input) {
	CharacterBaseInformations::deserialize(input);

	deathState = input->readByte();
	deathCount = input->readVarShort();
	deathMaxLevel = input->readVarShort();

    return true;
}
