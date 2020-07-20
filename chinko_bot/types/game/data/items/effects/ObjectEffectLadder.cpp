#include "ObjectEffectLadder.h"

bool ObjectEffectLadder::serialize(sp<MessageDataBuffer> output) {
	ObjectEffectCreature::serialize(output);

	output->writeVarInt(monsterCount);

    return true;
}

bool ObjectEffectLadder::deserialize(sp<MessageDataBuffer> input) {
	ObjectEffectCreature::deserialize(input);

	monsterCount = input->readVarInt();

    return true;
}
