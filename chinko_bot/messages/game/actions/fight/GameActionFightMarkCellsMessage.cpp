#include "GameActionFightMarkCellsMessage.h"

bool GameActionFightMarkCellsMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionMessage::serialize(output);

	mark.serialize(output);

    return true;
}

bool GameActionFightMarkCellsMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionMessage::deserialize(input);

	if(!mark.deserialize(input))
		return false;

    return true;
}
