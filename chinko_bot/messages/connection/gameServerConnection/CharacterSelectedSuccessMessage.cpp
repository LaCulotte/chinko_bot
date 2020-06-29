#include "CharacterSelectedSuccessMessage.h"

bool CharacterSelectedSuccessMessage::serialize(shared_ptr<MessageDataBuffer> output) {

	infos.serialize(output);
	output->writeBool(isCollectionStats);

	return true;
}

bool CharacterSelectedSuccessMessage::deserialize(shared_ptr<MessageDataBuffer> input) {

	infos.deserialize(input);
	isCollectionStats = input->readBool();

	return true;
}
