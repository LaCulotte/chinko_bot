#include "FightResultTaxCollectorListEntry.h"

bool FightResultTaxCollectorListEntry::serialize(sp<MessageDataBuffer> output) {
	FightResultFighterListEntry::serialize(output);

	output->writeByte(level);
	guildInfo.serialize(output);
	output->writeInt(experienceForGuild);

    return true;
}

bool FightResultTaxCollectorListEntry::deserialize(sp<MessageDataBuffer> input) {
	FightResultFighterListEntry::deserialize(input);

	level = input->readByte();
	if(!guildInfo.deserialize(input))
		return false;
	experienceForGuild = input->readInt();

    return true;
}
