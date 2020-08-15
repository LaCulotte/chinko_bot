#include "GameFightMinimalStatsPreparation.h"

bool GameFightMinimalStatsPreparation::serialize(sp<MessageDataBuffer> output) {
	GameFightMinimalStats::serialize(output);

	output->writeVarInt(initiative);

    return true;
}

bool GameFightMinimalStatsPreparation::deserialize(sp<MessageDataBuffer> input) {
	GameFightMinimalStats::deserialize(input);

	initiative = input->readVarInt();

    return true;
}
