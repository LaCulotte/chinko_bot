#include "FightTeamMemberEntityInformation.h"

bool FightTeamMemberEntityInformation::serialize(sp<MessageDataBuffer> output) {
	FightTeamMemberInformations::serialize(output);

	output->writeByte(entityModelId);
	output->writeVarShort(level);
	output->writeDouble(masterId);

    return true;
}

bool FightTeamMemberEntityInformation::deserialize(sp<MessageDataBuffer> input) {
	FightTeamMemberInformations::deserialize(input);

	entityModelId = input->readByte();
	level = input->readVarShort();
	masterId = input->readDouble();

    return true;
}
