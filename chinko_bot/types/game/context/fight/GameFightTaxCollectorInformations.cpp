#include "GameFightTaxCollectorInformations.h"

bool GameFightTaxCollectorInformations::serialize(sp<MessageDataBuffer> output) {
	GameFightAIInformations::serialize(output);

	output->writeVarShort(firstNameId);
	output->writeVarShort(lastNameId);
	output->writeByte(level);

    return true;
}

bool GameFightTaxCollectorInformations::deserialize(sp<MessageDataBuffer> input) {
	GameFightAIInformations::deserialize(input);

	firstNameId = input->readVarShort();
	lastNameId = input->readVarShort();
	level = input->readByte();

    return true;
}
