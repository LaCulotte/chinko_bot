#include "FightAllianceTeamInformations.h"

bool FightAllianceTeamInformations::serialize(sp<MessageDataBuffer> output) {
	FightTeamInformations::serialize(output);

	output->writeByte(relation);

    return true;
}

bool FightAllianceTeamInformations::deserialize(sp<MessageDataBuffer> input) {
	FightTeamInformations::deserialize(input);

	relation = input->readByte();

    return true;
}
