#include "NamedPartyTeamWithOutcome.h"

bool NamedPartyTeamWithOutcome::serialize(sp<MessageDataBuffer> output) {
	team.serialize(output);
	output->writeVarShort(outcome);

    return true;
}

bool NamedPartyTeamWithOutcome::deserialize(sp<MessageDataBuffer> input) {
	if(!team.deserialize(input))
		return false;
	outcome = input->readVarShort();

    return true;
}
