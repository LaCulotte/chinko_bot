#include "CharacterStatsListMessage.h"

bool CharacterStatsListMessage::serialize(sp<MessageDataBuffer> output) {
	stats.serialize(output);

    return true;
}

bool CharacterStatsListMessage::deserialize(sp<MessageDataBuffer> input) {
	if(!stats.deserialize(input))
		return false;

    return true;
}
