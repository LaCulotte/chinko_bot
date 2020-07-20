#include "ObjectEffectDuration.h"

bool ObjectEffectDuration::serialize(sp<MessageDataBuffer> output) {
	ObjectEffect::serialize(output);

	output->writeVarShort(days);
	output->writeByte(hours);
	output->writeByte(minutes);

    return true;
}

bool ObjectEffectDuration::deserialize(sp<MessageDataBuffer> input) {
	ObjectEffect::deserialize(input);

	days = input->readVarShort();
	hours = input->readByte();
	minutes = input->readByte();

    return true;
}
