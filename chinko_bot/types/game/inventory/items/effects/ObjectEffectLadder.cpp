#include "ObjectEffectLadder.h"

bool ObjectEffectLadder::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!ObjectEffect::serialize(output))
		return false;

	output->writeVarInt(monsterCount);

	return true;
}

bool ObjectEffectLadder::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!ObjectEffect::deserialize(input))
		return false;
		
	monsterCount = input->readVarInt();

	return true;
}
