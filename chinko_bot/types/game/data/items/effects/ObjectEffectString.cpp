#include "ObjectEffectString.h"

bool ObjectEffectString::serialize(sp<MessageDataBuffer> output) {
	ObjectEffect::serialize(output);

	output->writeUTF(value);

    return true;
}

bool ObjectEffectString::deserialize(sp<MessageDataBuffer> input) {
	ObjectEffect::deserialize(input);

	value = input->readUTF();

    return true;
}
