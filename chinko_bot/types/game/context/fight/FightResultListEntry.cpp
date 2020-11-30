#include "FightResultListEntry.h"

bool FightResultListEntry::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(outcome);
	output->writeByte(wave);
	rewards.serialize(output);

    return true;
}

bool FightResultListEntry::deserialize(sp<MessageDataBuffer> input) {
	outcome = input->readVarShort();
	wave = input->readByte();
	if(!rewards.deserialize(input))
		return false;

    return true;
}
