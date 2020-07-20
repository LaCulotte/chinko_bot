#include "ProtocolRequired.h"

bool ProtocolRequired::serialize(sp<MessageDataBuffer> output) {
	output->writeInt(requiredVersion);
	output->writeInt(currentVersion);

    return true;
}

bool ProtocolRequired::deserialize(sp<MessageDataBuffer> input) {
	requiredVersion = input->readInt();
	currentVersion = input->readInt();

    return true;
}
