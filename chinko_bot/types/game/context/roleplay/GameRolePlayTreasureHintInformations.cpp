#include "GameRolePlayTreasureHintInformations.h"

bool GameRolePlayTreasureHintInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayActorInformations::serialize(output);

	output->writeVarShort(npcId);

    return true;
}

bool GameRolePlayTreasureHintInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayActorInformations::deserialize(input);

	npcId = input->readVarShort();

    return true;
}
