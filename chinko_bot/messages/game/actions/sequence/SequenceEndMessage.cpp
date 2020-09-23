#include "SequenceEndMessage.h"

bool SequenceEndMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(actionId);
	output->writeDouble(authorId);
	output->writeByte(sequenceType);

    return true;
}

bool SequenceEndMessage::deserialize(sp<MessageDataBuffer> input) {
	actionId = input->readVarShort();
	authorId = input->readDouble();
	sequenceType = input->readByte();

    return true;
}
