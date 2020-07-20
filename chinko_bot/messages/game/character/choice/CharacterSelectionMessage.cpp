#include "CharacterSelectionMessage.h"

bool CharacterSelectionMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt64(id);

    return true;
}

bool CharacterSelectionMessage::deserialize(sp<MessageDataBuffer> input) {
	id = input->readVarInt64();

    return true;
}
