#include "GameRolePlayCharacterInformations.h"

bool GameRolePlayCharacterInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayHumanoidInformations::serialize(output);

	alignmentInfos.serialize(output);

    return true;
}

bool GameRolePlayCharacterInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayHumanoidInformations::deserialize(input);

	if(!alignmentInfos.deserialize(input))
		return false;

    return true;
}
