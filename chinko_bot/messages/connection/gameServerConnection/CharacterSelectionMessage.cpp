#include "CharacterSelectionMessage.h"

bool CharacterSelectionMessage::serialize(shared_ptr<MessageDataBuffer> output) {
	output->writeVarInt64(id);

	return true;
}

bool CharacterSelectionMessage::deserialize(shared_ptr<MessageDataBuffer> input) {
	id = input->readVarInt64();

	return true;
}
