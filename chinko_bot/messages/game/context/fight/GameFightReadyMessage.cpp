#include "GameFightReadyMessage.h"

bool GameFightReadyMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeBool(isReady);

    return true;
}

bool GameFightReadyMessage::deserialize(sp<MessageDataBuffer> input) {
	isReady = input->readBool();

    return true;
}
