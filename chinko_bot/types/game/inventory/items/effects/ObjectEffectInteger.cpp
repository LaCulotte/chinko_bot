#include "ObjectEffectInteger.h"

bool ObjectEffectInteger::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!ObjectEffect::serialize(output))
		return false;

	output->writeVarInt(value);

	return true;
}

bool ObjectEffectInteger::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!ObjectEffect::deserialize(input))
		return false;

	value = input->readVarInt();

	return true;
}
