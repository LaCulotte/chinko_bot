#include "ProtocolRequired.h"

bool ProtocolRequired::serialize(sp<MessageDataBuffer> output) {
	output->writeUTF(version);

    return true;
}

bool ProtocolRequired::deserialize(sp<MessageDataBuffer> input) {
	version = input->readUTF();
	
    return true;
}
