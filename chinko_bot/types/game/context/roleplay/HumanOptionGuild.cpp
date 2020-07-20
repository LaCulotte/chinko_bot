#include "HumanOptionGuild.h"

bool HumanOptionGuild::serialize(sp<MessageDataBuffer> output) {
	HumanOption::serialize(output);

	guildInformations.serialize(output);

    return true;
}

bool HumanOptionGuild::deserialize(sp<MessageDataBuffer> input) {
	HumanOption::deserialize(input);

	if(!guildInformations.deserialize(input))
		return false;

    return true;
}
