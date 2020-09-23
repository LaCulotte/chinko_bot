#include "GameFightTurnStartMessage.h"

bool GameFightTurnStartMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(id);
	output->writeVarInt(waitTime);

    return true;
}

bool GameFightTurnStartMessage::deserialize(sp<MessageDataBuffer> input) {
	id = input->readDouble();
	waitTime = input->readVarInt();

    return true;
}
