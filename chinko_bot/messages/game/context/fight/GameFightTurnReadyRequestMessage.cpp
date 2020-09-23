#include "GameFightTurnReadyRequestMessage.h"

bool GameFightTurnReadyRequestMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(id);

    return true;
}

bool GameFightTurnReadyRequestMessage::deserialize(sp<MessageDataBuffer> input) {
	id = input->readDouble();

    return true;
}
