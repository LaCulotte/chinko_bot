#include "CharacterBaseCharacteristic.h"

bool CharacterBaseCharacteristic::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(base);
	output->writeVarShort(additionnal);
	output->writeVarShort(objectsAndMountBonus);
	output->writeVarShort(alignGiftBonus);
	output->writeVarShort(contextModif);

    return true;
}

bool CharacterBaseCharacteristic::deserialize(sp<MessageDataBuffer> input) {
	base = input->readVarShort();
	additionnal = input->readVarShort();
	objectsAndMountBonus = input->readVarShort();
	alignGiftBonus = input->readVarShort();
	contextModif = input->readVarShort();

    return true;
}
