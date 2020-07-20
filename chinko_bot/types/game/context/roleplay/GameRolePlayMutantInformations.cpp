#include "GameRolePlayMutantInformations.h"

bool GameRolePlayMutantInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayHumanoidInformations::serialize(output);

	output->writeVarShort(monsterId);
	output->writeByte(powerLevel);

    return true;
}

bool GameRolePlayMutantInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayHumanoidInformations::deserialize(input);

	monsterId = input->readVarShort();
	powerLevel = input->readByte();

    return true;
}
