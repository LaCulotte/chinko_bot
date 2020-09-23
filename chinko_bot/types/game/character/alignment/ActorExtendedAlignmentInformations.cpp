#include "ActorExtendedAlignmentInformations.h"

bool ActorExtendedAlignmentInformations::serialize(sp<MessageDataBuffer> output) {
	ActorAlignmentInformations::serialize(output);

	output->writeVarShort(honor);
	output->writeVarShort(honorGradeFloor);
	output->writeVarShort(honorNextGradeFloor);
	output->writeByte(aggressable);

    return true;
}

bool ActorExtendedAlignmentInformations::deserialize(sp<MessageDataBuffer> input) {
	ActorAlignmentInformations::deserialize(input);

	honor = input->readVarShort();
	honorGradeFloor = input->readVarShort();
	honorNextGradeFloor = input->readVarShort();
	aggressable = input->readByte();

    return true;
}
