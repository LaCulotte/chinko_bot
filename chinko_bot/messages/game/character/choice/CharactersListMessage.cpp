#include "CharactersListMessage.h"

bool CharactersListMessage::serialize(sp<MessageDataBuffer> output) {
	BasicCharactersListMessage::serialize(output);

	output->writeBool(hasStartupActions);

    return true;
}

bool CharactersListMessage::deserialize(sp<MessageDataBuffer> input) {
	BasicCharactersListMessage::deserialize(input);

	hasStartupActions = input->readBool();

    return true;
}
