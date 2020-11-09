#include "SelectedServerRefusedMessage.h"

bool SelectedServerRefusedMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(serverId);
	output->writeByte(error);
	output->writeByte(serverStatus);

    return true;
}

bool SelectedServerRefusedMessage::deserialize(sp<MessageDataBuffer> input) {
	serverId = input->readVarShort();
	error = input->readByte();
	serverStatus = input->readByte();

    return true;
}
