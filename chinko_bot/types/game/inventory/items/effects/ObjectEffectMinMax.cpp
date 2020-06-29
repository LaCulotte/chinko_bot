#include "ObjectEffectMinMax.h"

bool ObjectEffectMinMax::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!ObjectEffect::serialize(output))
		return false;

	output->writeVarInt(min);
	output->writeVarInt(max);

	return true;
}

bool ObjectEffectMinMax::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!ObjectEffect::deserialize(input))
		return false;

	min = input->readVarInt();
	max = input->readVarInt();

	return true;
}
