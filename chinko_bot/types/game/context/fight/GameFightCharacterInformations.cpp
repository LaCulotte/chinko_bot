#include "GameFightCharacterInformations.h"

bool GameFightCharacterInformations::serialize(sp<MessageDataBuffer> output) {
	GameFightFighterNamedInformations::serialize(output);

	output->writeVarShort(level);
	alignmentInfos.serialize(output);
	output->writeByte(breed);
	output->writeBool(sex);

    return true;
}

bool GameFightCharacterInformations::deserialize(sp<MessageDataBuffer> input) {
	GameFightFighterNamedInformations::deserialize(input);

	level = input->readVarShort();
	if(!alignmentInfos.deserialize(input))
		return false;
	breed = input->readByte();
	sex = input->readBool();

    return true;
}
