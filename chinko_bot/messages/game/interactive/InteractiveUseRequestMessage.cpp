#include "InteractiveUseRequestMessage.h"

bool InteractiveUseRequestMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarInt(elemId);
	output->writeVarInt(skillInstanceUid);

	for(int i = 0; i < 48; i++)
		output->writeByte(rand() % 256);


    return true;
}

bool InteractiveUseRequestMessage::deserialize(sp<MessageDataBuffer> input) {
	elemId = input->readVarInt();
	skillInstanceUid = input->readVarInt();

    return true;
}
