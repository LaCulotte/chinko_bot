#include "GameFightMutantInformations.h"

bool GameFightMutantInformations::serialize(sp<MessageDataBuffer> output) {
	GameFightFighterNamedInformations::serialize(output);

	output->writeByte(powerLevel);

    return true;
}

bool GameFightMutantInformations::deserialize(sp<MessageDataBuffer> input) {
	GameFightFighterNamedInformations::deserialize(input);

	powerLevel = input->readByte();

    return true;
}
