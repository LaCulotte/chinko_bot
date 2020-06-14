#include "AbstractCharacterInformation.h"

bool AbstractCharacterInformation::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt64(id);

	return true;
}

bool AbstractCharacterInformation::deserialize(sp<MessageDataBuffer> input) {
	id = input->readVarInt64();

	return true;
}
