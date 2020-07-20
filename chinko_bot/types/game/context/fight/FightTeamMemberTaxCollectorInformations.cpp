#include "FightTeamMemberTaxCollectorInformations.h"

bool FightTeamMemberTaxCollectorInformations::serialize(sp<MessageDataBuffer> output) {
	FightTeamMemberInformations::serialize(output);

	output->writeVarShort(firstNameId);
	output->writeVarShort(lastNameId);
	output->writeByte(level);
	output->writeVarInt(guildId);
	output->writeDouble(uid);

    return true;
}

bool FightTeamMemberTaxCollectorInformations::deserialize(sp<MessageDataBuffer> input) {
	FightTeamMemberInformations::deserialize(input);

	firstNameId = input->readVarShort();
	lastNameId = input->readVarShort();
	level = input->readByte();
	guildId = input->readVarInt();
	uid = input->readDouble();

    return true;
}
