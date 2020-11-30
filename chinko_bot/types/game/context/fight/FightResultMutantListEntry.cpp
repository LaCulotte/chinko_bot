#include "FightResultMutantListEntry.h"

bool FightResultMutantListEntry::serialize(sp<MessageDataBuffer> output) {
	FightResultFighterListEntry::serialize(output);

	output->writeVarShort(level);

    return true;
}

bool FightResultMutantListEntry::deserialize(sp<MessageDataBuffer> input) {
	FightResultFighterListEntry::deserialize(input);

	level = input->readVarShort();

    return true;
}
