#include "CharacterBaseInformations.h"

bool CharacterBaseInformations::serialize(sp<MessageDataBuffer> output) {
	CharacterMinimalPlusLookInformations::serialize(output);

	output->writeBool(sex);

    return true;
}

bool CharacterBaseInformations::deserialize(sp<MessageDataBuffer> input) {
	CharacterMinimalPlusLookInformations::deserialize(input);

	sex = input->readBool();

    return true;
}
