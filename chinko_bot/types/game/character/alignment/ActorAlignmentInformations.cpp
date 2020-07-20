#include "ActorAlignmentInformations.h"

bool ActorAlignmentInformations::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(alignmentSide);
	output->writeByte(alignmentValue);
	output->writeByte(alignmentGrade);
	output->writeDouble(characterPower);

    return true;
}

bool ActorAlignmentInformations::deserialize(sp<MessageDataBuffer> input) {
	alignmentSide = input->readByte();
	alignmentValue = input->readByte();
	alignmentGrade = input->readByte();
	characterPower = input->readDouble();

    return true;
}
