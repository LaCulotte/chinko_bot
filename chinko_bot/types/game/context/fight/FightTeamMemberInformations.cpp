#include "FightTeamMemberInformations.h"

bool FightTeamMemberInformations::serialize(sp<MessageDataBuffer> output) {
	output->writeDouble(id);

    return true;
}

bool FightTeamMemberInformations::deserialize(sp<MessageDataBuffer> input) {
	id = input->readDouble();

    return true;
}
