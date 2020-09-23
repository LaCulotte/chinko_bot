#include "GameActionFightUnmarkCellsMessage.h"

bool GameActionFightUnmarkCellsMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionMessage::serialize(output);

	output->writeShort(markId);

    return true;
}

bool GameActionFightUnmarkCellsMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionMessage::deserialize(input);

	markId = input->readShort();

    return true;
}
