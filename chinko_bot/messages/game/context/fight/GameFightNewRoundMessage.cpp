#include "GameFightNewRoundMessage.h"

bool GameFightNewRoundMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt(roundNumber);

    return true;
}

bool GameFightNewRoundMessage::deserialize(sp<MessageDataBuffer> input) {
	roundNumber = input->readVarInt();

    return true;
}
