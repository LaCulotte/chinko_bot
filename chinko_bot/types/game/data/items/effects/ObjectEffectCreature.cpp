#include "ObjectEffectCreature.h"

bool ObjectEffectCreature::serialize(sp<MessageDataBuffer> output) {
	ObjectEffect::serialize(output);

	output->writeVarShort(monsterFamilyId);

    return true;
}

bool ObjectEffectCreature::deserialize(sp<MessageDataBuffer> input) {
	ObjectEffect::deserialize(input);

	monsterFamilyId = input->readVarShort();

    return true;
}
