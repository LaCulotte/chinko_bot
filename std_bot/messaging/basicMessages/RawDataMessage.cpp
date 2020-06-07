#include "RawDataMessage.h"

// Basically copy object's data to the output buffer.
bool RawDataMessage::serialize(sp<MessageDataBuffer> output) {
    if(!output)
        return false;
    
    data.cursor_reset();
    
    while(data.remainingDataSize() > 0){
        output->write(data.read());
    }

    return true;
}

// Basically get object's data from the input buffer.
bool RawDataMessage::deserialize(sp<MessageDataBuffer> intput) {
    if(!intput)
        return false;

    data.clear();

    while(intput->remainingDataSize() > 0){
        data.write(intput->read());
    }

    return true;
}