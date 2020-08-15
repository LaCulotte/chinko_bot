#include "GameRolePlayPlayerFightFriendlyAnswerMessage.h"

bool GameRolePlayPlayerFightFriendlyAnswerMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(fightId);
	output->writeBool(accept);

    return true;
}

bool GameRolePlayPlayerFightFriendlyAnswerMessage::deserialize(sp<MessageDataBuffer> input) {
	fightId = input->readVarShort();
	accept = input->readBool();

    return true;
}
