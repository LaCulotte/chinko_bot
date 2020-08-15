#include "GameFightUpdateTeamMessage.h"

bool GameFightUpdateTeamMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(fightId);
	team.serialize(output);

    return true;
}

bool GameFightUpdateTeamMessage::deserialize(sp<MessageDataBuffer> input) {
	fightId = input->readVarShort();
	if(!team.deserialize(input))
		return false;

    return true;
}
