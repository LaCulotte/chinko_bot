#include "ObjectEffectMinMax.h"

bool ObjectEffectMinMax::serialize(sp<MessageDataBuffer> output) {
	ObjectEffect::serialize(output);

	output->writeVarInt(min);
	output->writeVarInt(max);

    return true;
}

bool ObjectEffectMinMax::deserialize(sp<MessageDataBuffer> input) {
	ObjectEffect::deserialize(input);

	min = input->readVarInt();
	max = input->readVarInt();

    return true;
}
