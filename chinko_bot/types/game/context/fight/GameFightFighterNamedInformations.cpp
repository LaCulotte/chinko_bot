#include "GameFightFighterNamedInformations.h"

bool GameFightFighterNamedInformations::serialize(sp<MessageDataBuffer> output) {
	GameFightFighterInformations::serialize(output);

	output->writeUTF(name);
	status.serialize(output);
	output->writeVarShort(leagueId);
	output->writeInt(ladderPosition);
	output->writeBool(hiddenInPrefight);

    return true;
}

bool GameFightFighterNamedInformations::deserialize(sp<MessageDataBuffer> input) {
	GameFightFighterInformations::deserialize(input);

	name = input->readUTF();
	if(!status.deserialize(input))
		return false;
	leagueId = input->readVarShort();
	ladderPosition = input->readInt();
	hiddenInPrefight = input->readBool();

    return true;
}
