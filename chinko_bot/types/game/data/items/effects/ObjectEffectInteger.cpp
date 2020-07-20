#include "ObjectEffectInteger.h"

bool ObjectEffectInteger::serialize(sp<MessageDataBuffer> output) {
	ObjectEffect::serialize(output);

	output->writeVarInt(value);

    return true;
}

bool ObjectEffectInteger::deserialize(sp<MessageDataBuffer> input) {
	ObjectEffect::deserialize(input);

	value = input->readVarInt();

    return true;
}
