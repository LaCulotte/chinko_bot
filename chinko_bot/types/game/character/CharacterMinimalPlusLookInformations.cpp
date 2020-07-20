#include "CharacterMinimalPlusLookInformations.h"

bool CharacterMinimalPlusLookInformations::serialize(sp<MessageDataBuffer> output) {
	CharacterMinimalInformations::serialize(output);

	entityLook.serialize(output);
	output->writeByte(breed);

    return true;
}

bool CharacterMinimalPlusLookInformations::deserialize(sp<MessageDataBuffer> input) {
	CharacterMinimalInformations::deserialize(input);

	if(!entityLook.deserialize(input))
		return false;
	breed = input->readByte();

    return true;
}
