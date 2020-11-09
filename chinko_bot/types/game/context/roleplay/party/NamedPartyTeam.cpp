#include "NamedPartyTeam.h"

bool NamedPartyTeam::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(teamId);
	output->writeUTF(partyName);

    return true;
}

bool NamedPartyTeam::deserialize(sp<MessageDataBuffer> input) {
	teamId = input->readByte();
	partyName = input->readUTF();

    return true;
}
