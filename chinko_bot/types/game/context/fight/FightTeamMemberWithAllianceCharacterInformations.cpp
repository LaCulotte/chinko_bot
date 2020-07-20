#include "FightTeamMemberWithAllianceCharacterInformations.h"

bool FightTeamMemberWithAllianceCharacterInformations::serialize(sp<MessageDataBuffer> output) {
	FightTeamMemberCharacterInformations::serialize(output);

	allianceInfos.serialize(output);

    return true;
}

bool FightTeamMemberWithAllianceCharacterInformations::deserialize(sp<MessageDataBuffer> input) {
	FightTeamMemberCharacterInformations::deserialize(input);

	if(!allianceInfos.deserialize(input))
		return false;

    return true;
}
