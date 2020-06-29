#include "ObjectEffectString.h"

bool ObjectEffectString::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!ObjectEffect::serialize(output))
		return false;

	output->writeUTF(value);	

	return true;
}

bool ObjectEffectString::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!ObjectEffect::deserialize(input))
		return false;

	value = input->readUTF();

	return true;
}
