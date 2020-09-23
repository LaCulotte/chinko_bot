#include "GameFightTurnFinishMessage.h"

bool GameFightTurnFinishMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeBool(isAfk);

    return true;
}

bool GameFightTurnFinishMessage::deserialize(sp<MessageDataBuffer> input) {
	isAfk = input->readBool();

    return true;
}
