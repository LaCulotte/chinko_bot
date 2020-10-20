#include "ServerSelectionMessage.h"

bool ServerSelectionMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(serverId);

    return true;
}

bool ServerSelectionMessage::deserialize(sp<MessageDataBuffer> input) {
	serverId = input->readVarShort();

    return true;
}
