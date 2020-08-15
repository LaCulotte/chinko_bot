#include "GameFightMonsterWithAlignmentInformations.h"

bool GameFightMonsterWithAlignmentInformations::serialize(sp<MessageDataBuffer> output) {
	GameFightMonsterInformations::serialize(output);

	alignmentInfos.serialize(output);

    return true;
}

bool GameFightMonsterWithAlignmentInformations::deserialize(sp<MessageDataBuffer> input) {
	GameFightMonsterInformations::deserialize(input);

	if(!alignmentInfos.deserialize(input))
		return false;

    return true;
}
