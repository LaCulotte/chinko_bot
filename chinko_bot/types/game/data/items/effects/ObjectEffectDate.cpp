#include "ObjectEffectDate.h"

bool ObjectEffectDate::serialize(sp<MessageDataBuffer> output) {
	ObjectEffect::serialize(output);

	output->writeVarShort(year);
	output->writeByte(month);
	output->writeByte(day);
	output->writeByte(hour);
	output->writeByte(minute);

    return true;
}

bool ObjectEffectDate::deserialize(sp<MessageDataBuffer> input) {
	ObjectEffect::deserialize(input);

	year = input->readVarShort();
	month = input->readByte();
	day = input->readByte();
	hour = input->readByte();
	minute = input->readByte();

    return true;
}
