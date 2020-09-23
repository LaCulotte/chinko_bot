#include "FighterStatsListMessage.h"

bool FighterStatsListMessage::serialize(sp<MessageDataBuffer> output) {
	stats.serialize(output);

    return true;
}

bool FighterStatsListMessage::deserialize(sp<MessageDataBuffer> input) {
	if(!stats.deserialize(input))
		return false;

    return true;
}
