#include "HouseGuildedInformations.h"

bool HouseGuildedInformations::serialize(sp<MessageDataBuffer> output) {
	HouseInstanceInformations::serialize(output);

	guildInfo.serialize(output);

    return true;
}

bool HouseGuildedInformations::deserialize(sp<MessageDataBuffer> input) {
	HouseInstanceInformations::deserialize(input);

	if(!guildInfo.deserialize(input))
		return false;

    return true;
}
