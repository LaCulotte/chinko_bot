#include "AbstractFightTeamInformations.h"

bool AbstractFightTeamInformations::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(teamId);
	output->writeDouble(leaderId);
	output->writeByte(teamSide);
	output->writeByte(teamTypeId);
	output->writeByte(nbWaves);

    return true;
}

bool AbstractFightTeamInformations::deserialize(sp<MessageDataBuffer> input) {
	teamId = input->readByte();
	leaderId = input->readDouble();
	teamSide = input->readByte();
	teamTypeId = input->readByte();
	nbWaves = input->readByte();

    return true;
}
