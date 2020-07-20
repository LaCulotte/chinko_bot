#include "GameRolePlayNpcInformations.h"

bool GameRolePlayNpcInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayActorInformations::serialize(output);

	output->writeVarShort(npcId);
	output->writeBool(sex);
	output->writeVarShort(specialArtworkId);

    return true;
}

bool GameRolePlayNpcInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayActorInformations::deserialize(input);

	npcId = input->readVarShort();
	sex = input->readBool();
	specialArtworkId = input->readVarShort();

    return true;
}
