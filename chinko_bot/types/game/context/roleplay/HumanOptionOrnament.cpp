#include "HumanOptionOrnament.h"

bool HumanOptionOrnament::serialize(sp<MessageDataBuffer> output) {
	HumanOption::serialize(output);

	output->writeVarShort(ornamentId);
	output->writeVarShort(level);
	output->writeVarShort(leagueId);
	output->writeInt(ladderPosition);

    return true;
}

bool HumanOptionOrnament::deserialize(sp<MessageDataBuffer> input) {
	HumanOption::deserialize(input);

	ornamentId = input->readVarShort();
	level = input->readVarShort();
	leagueId = input->readVarShort();
	ladderPosition = input->readInt();

    return true;
}
