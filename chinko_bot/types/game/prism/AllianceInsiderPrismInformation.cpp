#include "AllianceInsiderPrismInformation.h"

bool AllianceInsiderPrismInformation::serialize(sp<MessageDataBuffer> output) {
	PrismInformation::serialize(output);

	output->writeInt(lastTimeSlotModificationDate);
	output->writeVarInt(lastTimeSlotModificationAuthorGuildId);
	output->writeVarInt64(lastTimeSlotModificationAuthorId);
	output->writeUTF(lastTimeSlotModificationAuthorName);
	output->writeShort(modulesObjects.size());
	for(int i = 0; i < modulesObjects.size(); i++) {
		modulesObjects[i].serialize(output);
	}

    return true;
}

bool AllianceInsiderPrismInformation::deserialize(sp<MessageDataBuffer> input) {
	PrismInformation::deserialize(input);

	lastTimeSlotModificationDate = input->readInt();
	lastTimeSlotModificationAuthorGuildId = input->readVarInt();
	lastTimeSlotModificationAuthorId = input->readVarInt64();
	lastTimeSlotModificationAuthorName = input->readUTF();
	int modulesObjects_size = input->readShort();
	for(int i = 0; i < modulesObjects_size; i++) {
		ObjectItem modulesObject;

		if(!modulesObject.deserialize(input))
			return false;
		modulesObjects.push_back(modulesObject);
	}

    return true;
}
