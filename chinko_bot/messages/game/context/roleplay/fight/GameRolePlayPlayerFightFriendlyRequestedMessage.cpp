#include "GameRolePlayPlayerFightFriendlyRequestedMessage.h"

bool GameRolePlayPlayerFightFriendlyRequestedMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(fightId);
	output->writeVarInt64(sourceId);
	output->writeVarInt64(targetId);

    return true;
}

bool GameRolePlayPlayerFightFriendlyRequestedMessage::deserialize(sp<MessageDataBuffer> input) {
	fightId = input->readVarShort();
	sourceId = input->readVarInt64();
	targetId = input->readVarInt64();

    return true;
}
