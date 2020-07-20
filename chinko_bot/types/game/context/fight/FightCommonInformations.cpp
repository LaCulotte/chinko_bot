#include "FightCommonInformations.h"

bool FightCommonInformations::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(fightId);
	output->writeByte(fightType);
	output->writeShort(fightTeams.size());
	for(int i = 0; i < fightTeams.size(); i++) {
		output->writeShort(fightTeams[i]->getId());
		fightTeams[i]->serialize(output);
	}
	output->writeShort(fightTeamsPositions.size());
	for(int i = 0; i < fightTeamsPositions.size(); i++) {
		output->writeVarShort(fightTeamsPositions[i]);
	}
	output->writeShort(fightTeamsOptions.size());
	for(int i = 0; i < fightTeamsOptions.size(); i++) {
		fightTeamsOptions[i].serialize(output);
	}

    return true;
}

bool FightCommonInformations::deserialize(sp<MessageDataBuffer> input) {
	fightId = input->readVarShort();
	fightType = input->readByte();
	int fightTeams_size = input->readShort();
	for(int i = 0; i < fightTeams_size; i++) {
		sp<FightTeamInformations> fightTeam(new FightTeamInformations());

		int fightTeam_TypeId = input->readShort();
		fightTeam = dynamic_pointer_cast<FightTeamInformations>(NetworkTypeHandler::getInstance()->getTypeById(fightTeam_TypeId));
	
		if(!fightTeam || !fightTeam->deserialize(input))
			return false;
	
		fightTeams.push_back(fightTeam);
	}
	int fightTeamsPositions_size = input->readShort();
	for(int i = 0; i < fightTeamsPositions_size; i++) {
		int fightTeamsPosition;

		fightTeamsPosition = input->readVarShort();
		fightTeamsPositions.push_back(fightTeamsPosition);
	}
	int fightTeamsOptions_size = input->readShort();
	for(int i = 0; i < fightTeamsOptions_size; i++) {
		FightOptionsInformations fightTeamsOption;

		if(!fightTeamsOption.deserialize(input))
			return false;
		fightTeamsOptions.push_back(fightTeamsOption);
	}

    return true;
}
