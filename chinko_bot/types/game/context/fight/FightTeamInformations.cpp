#include "FightTeamInformations.h"

bool FightTeamInformations::serialize(sp<MessageDataBuffer> output) {
	AbstractFightTeamInformations::serialize(output);

	output->writeShort(teamMembers.size());
	for(int i = 0; i < teamMembers.size(); i++) {
		output->writeShort(teamMembers[i]->getId());
		teamMembers[i]->serialize(output);
	}

    return true;
}

bool FightTeamInformations::deserialize(sp<MessageDataBuffer> input) {
	AbstractFightTeamInformations::deserialize(input);

	int teamMembers_size = input->readShort();
	for(int i = 0; i < teamMembers_size; i++) {
		sp<FightTeamMemberInformations> teamMember(new FightTeamMemberInformations());

		int teamMember_TypeId = input->readShort();
		teamMember = dynamic_pointer_cast<FightTeamMemberInformations>(NetworkTypeHandler::getInstance()->getTypeById(teamMember_TypeId));
	
		if(!teamMember || !teamMember->deserialize(input))
			return false;
	
		teamMembers.push_back(teamMember);
	}

    return true;
}
