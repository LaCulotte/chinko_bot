#include "CharacterMinimalInformations.h"

bool CharacterMinimalInformations::serialize(sp<MessageDataBuffer> output) {
	CharacterBasicMinimalInformations::serialize(output);

	output->writeVarShort(level);

    return true;
}

bool CharacterMinimalInformations::deserialize(sp<MessageDataBuffer> input) {
	CharacterBasicMinimalInformations::deserialize(input);

	level = input->readVarShort();

    return true;
}
