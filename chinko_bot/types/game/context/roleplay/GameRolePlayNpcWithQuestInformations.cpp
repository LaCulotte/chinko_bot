#include "GameRolePlayNpcWithQuestInformations.h"

bool GameRolePlayNpcWithQuestInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayNpcInformations::serialize(output);

	questFlag.serialize(output);

    return true;
}

bool GameRolePlayNpcWithQuestInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayNpcInformations::deserialize(input);

	if(!questFlag.deserialize(input))
		return false;

    return true;
}
