#include "FightResultPvpData.h"

bool FightResultPvpData::serialize(sp<MessageDataBuffer> output) {
	FightResultAdditionalData::serialize(output);

	output->writeByte(grade);
	output->writeVarShort(minHonorForGrade);
	output->writeVarShort(maxHonorForGrade);
	output->writeVarShort(honor);
	output->writeVarShort(honorDelta);

    return true;
}

bool FightResultPvpData::deserialize(sp<MessageDataBuffer> input) {
	FightResultAdditionalData::deserialize(input);

	grade = input->readByte();
	minHonorForGrade = input->readVarShort();
	maxHonorForGrade = input->readVarShort();
	honor = input->readVarShort();
	honorDelta = input->readVarShort();

    return true;
}
