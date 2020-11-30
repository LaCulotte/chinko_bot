#include "FightResultFighterListEntry.h"

bool FightResultFighterListEntry::serialize(sp<MessageDataBuffer> output) {
	FightResultListEntry::serialize(output);

	output->writeDouble(id);
	output->writeBool(alive);

    return true;
}

bool FightResultFighterListEntry::deserialize(sp<MessageDataBuffer> input) {
	FightResultListEntry::deserialize(input);

	id = input->readDouble();
	alive = input->readBool();

    return true;
}
