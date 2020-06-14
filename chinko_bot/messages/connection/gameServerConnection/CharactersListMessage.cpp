#include "CharactersListMessage.h"

bool CharactersListMessage::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!BasicCharactersListMessage::serialize(output))
		return false;

	output->writeBool(hasStartupActions);

	return true;
}

bool CharactersListMessage::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!BasicCharactersListMessage::deserialize(input))
		return false;

	hasStartupActions = input->readBool();

	return true;
}
