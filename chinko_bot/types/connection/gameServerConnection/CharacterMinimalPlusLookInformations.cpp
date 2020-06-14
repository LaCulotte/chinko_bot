#include "CharacterMinimalPlusLookInformations.h"

bool CharacterMinimalPlusLookInformations::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!CharacterMinimalInformations::serialize(output))
		return false;

	if(!entityLook.serialize(output))
		return false;

	output->writeByte(breed);

	return true;
}

bool CharacterMinimalPlusLookInformations::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!CharacterMinimalInformations::deserialize(input))
		return false;

	if(!entityLook.deserialize(input))
		return false;

	breed = input->readByte();

	return true;
}
