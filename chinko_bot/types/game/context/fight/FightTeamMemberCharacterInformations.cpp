#include "FightTeamMemberCharacterInformations.h"

bool FightTeamMemberCharacterInformations::serialize(sp<MessageDataBuffer> output) {
	FightTeamMemberInformations::serialize(output);

	output->writeUTF(name);
	output->writeVarShort(level);

    return true;
}

bool FightTeamMemberCharacterInformations::deserialize(sp<MessageDataBuffer> input) {
	FightTeamMemberInformations::deserialize(input);

	name = input->readUTF();
	level = input->readVarShort();

    return true;
}
