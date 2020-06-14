#include "CharacterMinimalInformations.h"

bool CharacterMinimalInformations::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!CharacterBasicMinimalInformations::serialize(output))
		return false;

	output->writeVarShort(id);

	return true;
}

bool CharacterMinimalInformations::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!CharacterBasicMinimalInformations::deserialize(input))
		return false;

	level = input->readVarShort();

	return true;
}
