#include "FightResultExperienceData.h"

bool FightResultExperienceData::serialize(sp<MessageDataBuffer> output) {
	FightResultAdditionalData::serialize(output);

	int flags0 = (showExperienceLevelFloor<<1) | (showExperienceNextLevelFloor<<2) | (showExperienceFightDelta<<3) | (showExperience<<0) | (showExperienceForGuild<<4) | (showExperienceForMount<<5) | (isIncarnationExperience<<6);
	output->writeByte(flags0);

	output->writeVarInt64(experience);
	output->writeVarInt64(experienceLevelFloor);
	output->writeVarInt64(experienceNextLevelFloor);
	output->writeVarInt64(experienceFightDelta);
	output->writeVarInt64(experienceForGuild);
	output->writeVarInt64(experienceForMount);
	output->writeByte(rerollExperienceMul);

    return true;
}

bool FightResultExperienceData::deserialize(sp<MessageDataBuffer> input) {
	FightResultAdditionalData::deserialize(input);

	int flags0 = input->readByte();
	showExperienceLevelFloor = flags0 & (1 << 1);
	showExperienceNextLevelFloor = flags0 & (1 << 2);
	showExperienceFightDelta = flags0 & (1 << 3);
	showExperience = flags0 & (1 << 0);
	showExperienceForGuild = flags0 & (1 << 4);
	showExperienceForMount = flags0 & (1 << 5);
	isIncarnationExperience = flags0 & (1 << 6);

	experience = input->readVarInt64();
	experienceLevelFloor = input->readVarInt64();
	experienceNextLevelFloor = input->readVarInt64();
	experienceFightDelta = input->readVarInt64();
	experienceForGuild = input->readVarInt64();
	experienceForMount = input->readVarInt64();
	rerollExperienceMul = input->readByte();

    return true;
}
