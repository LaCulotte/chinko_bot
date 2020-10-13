#include "GameRolePlayAttackMonsterRequestMessage.h"

bool GameRolePlayAttackMonsterRequestMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(monsterGroupId);

    return true;
}

bool GameRolePlayAttackMonsterRequestMessage::deserialize(sp<MessageDataBuffer> input) {
	monsterGroupId = input->readDouble();

    return true;
}
