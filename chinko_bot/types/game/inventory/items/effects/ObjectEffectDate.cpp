#include "ObjectEffectDate.h"

bool ObjectEffectDate::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!ObjectEffect::serialize(output))
		return false;
	
	output->writeVarShort(year);
	output->writeByte(month);
	output->writeByte(day);
	output->writeByte(hour);
	output->writeByte(minute);

	return true;
}

bool ObjectEffectDate::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!ObjectEffect::deserialize(input))
		return false;
	
	year = input->readVarShort();
	month = input->readByte();
	day = input->readByte();
	hour = input->readByte();
	minute = input->readByte();

	return true;
}
