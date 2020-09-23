#include "GameActionFightExchangePositionsMessage.h"

bool GameActionFightExchangePositionsMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionMessage::serialize(output);

	output->writeDouble(targetId);
	output->writeShort(casterCellId);
	output->writeShort(targetCellId);

    return true;
}

bool GameActionFightExchangePositionsMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionMessage::deserialize(input);

	targetId = input->readDouble();
	casterCellId = input->readShort();
	targetCellId = input->readShort();

    return true;
}
