#include "CharacterBaseInformations.h"

bool CharacterBaseInformations::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!CharacterMinimalPlusLookInformations::serialize(output))
		return false;

	output->writeBool(sex);

	return true;
}

bool CharacterBaseInformations::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!CharacterMinimalPlusLookInformations::deserialize(input))
		return false;

	sex = input->readBool();

	return true;
}
