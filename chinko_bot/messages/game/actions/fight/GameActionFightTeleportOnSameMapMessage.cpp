#include "GameActionFightTeleportOnSameMapMessage.h"

bool GameActionFightTeleportOnSameMapMessage::serialize(sp<MessageDataBuffer> output) {
	AbstractGameActionMessage::serialize(output);

	output->writeDouble(targetId);
	output->writeShort(cellId);

    return true;
}

bool GameActionFightTeleportOnSameMapMessage::deserialize(sp<MessageDataBuffer> input) {
	AbstractGameActionMessage::deserialize(input);

	targetId = input->readDouble();
	cellId = input->readShort();

    return true;
}
