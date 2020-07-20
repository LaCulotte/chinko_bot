#include "GuildInformations.h"

bool GuildInformations::serialize(sp<MessageDataBuffer> output) {
	BasicGuildInformations::serialize(output);

	guildEmblem.serialize(output);

    return true;
}

bool GuildInformations::deserialize(sp<MessageDataBuffer> input) {
	BasicGuildInformations::deserialize(input);

	if(!guildEmblem.deserialize(input))
		return false;

    return true;
}
