#include "ObjectEffectCreature.h"

bool ObjectEffectCreature::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!ObjectEffect::serialize(output))
		return false;

	output->writeShort(monsterFamilyId);

	return true;
}

bool ObjectEffectCreature::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!ObjectEffect::deserialize(input))
		return false;

	monsterFamilyId = input->readVarShort();

	return true;
}
