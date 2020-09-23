#include "GameFightHumanReadyStateMessage.h"

bool GameFightHumanReadyStateMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt64(characterId);
	output->writeBool(isReady);

    return true;
}

bool GameFightHumanReadyStateMessage::deserialize(sp<MessageDataBuffer> input) {
	characterId = input->readVarInt64();
	isReady = input->readBool();

    return true;
}
