#include "RawDataMessage.h"

bool RawDataMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeVarInt(content.size());
    for(char c : content)
        output->writeByte(c);

    return true;
}

bool RawDataMessage::deserialize(sp<MessageDataBuffer> input) {
    int contentSize = input->readVarInt();
    for(int i = 0; i < contentSize; i++) 
        content.push_back(input->readByte());

    return true;
}