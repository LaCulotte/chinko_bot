#include "GameContextActorInformations.h"

bool GameContextActorInformations::serialize(sp<MessageDataBuffer> output) {
	GameContextActorPositionInformations::serialize(output);

	look.serialize(output);

    return true;
}

bool GameContextActorInformations::deserialize(sp<MessageDataBuffer> input) {
	GameContextActorPositionInformations::deserialize(input);

	if(!look.deserialize(input))
		return false;

    return true;
}
