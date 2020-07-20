#include "SubEntity.h"

bool SubEntity::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(bindingPointCategory);
	output->writeByte(bindingPointIndex);
	subEntityLook = make_shared<EntityLook>();
	subEntityLook->serialize(output);

    return true;
}

bool SubEntity::deserialize(sp<MessageDataBuffer> input) {
	bindingPointCategory = input->readByte();
	bindingPointIndex = input->readByte();
	subEntityLook = make_shared<EntityLook>();
	if(!subEntityLook->deserialize(input))
		return false;

    return true;
}
