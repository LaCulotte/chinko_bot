#include "CharacterBasicMinimalInformations.h"

bool CharacterBasicMinimalInformations::serialize(sp<MessageDataBuffer> output) {
	AbstractCharacterInformation::serialize(output);

	output->writeUTF(name);

    return true;
}

bool CharacterBasicMinimalInformations::deserialize(sp<MessageDataBuffer> input) {
	AbstractCharacterInformation::deserialize(input);

	name = input->readUTF();

    return true;
}
