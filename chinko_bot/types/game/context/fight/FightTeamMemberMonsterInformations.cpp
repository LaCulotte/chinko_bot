#include "FightTeamMemberMonsterInformations.h"

bool FightTeamMemberMonsterInformations::serialize(sp<MessageDataBuffer> output) {
	FightTeamMemberInformations::serialize(output);

	output->writeInt(monsterId);
	output->writeByte(grade);

    return true;
}

bool FightTeamMemberMonsterInformations::deserialize(sp<MessageDataBuffer> input) {
	FightTeamMemberInformations::deserialize(input);

	monsterId = input->readInt();
	grade = input->readByte();

    return true;
}
