#include "GameFightTurnReadyMessage.h"

bool GameFightTurnReadyMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeBool(isReady);

    return true;
}

bool GameFightTurnReadyMessage::deserialize(sp<MessageDataBuffer> input) {
	isReady = input->readBool();

    return true;
}
