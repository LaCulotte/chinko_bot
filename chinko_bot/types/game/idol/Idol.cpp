#include "Idol.h"

bool Idol::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(id);
	output->writeVarShort(xpBonusPercent);
	output->writeVarShort(dropBonusPercent);

    return true;
}

bool Idol::deserialize(sp<MessageDataBuffer> input) {
	id = input->readVarShort();
	xpBonusPercent = input->readVarShort();
	dropBonusPercent = input->readVarShort();

    return true;
}
