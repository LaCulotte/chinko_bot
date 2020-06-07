#include "UnknownDofusMessage.h"

UnknownDofusMessage::UnknownDofusMessage() : PrefixedMessage() {
}

UnknownDofusMessage::UnknownDofusMessage(int real_id) {
    this->real_id = real_id;
}

bool UnknownDofusMessage::serialize(sp<MessageDataBuffer> output) {
    // Returns if there is no data
    if(!data)
        return false;

    // Sets the cursor at the beginning and copies the data
    data->cursor_reset();
    
    output->write(data->getData());

    return true;
}

bool UnknownDofusMessage::deserialize(sp<MessageDataBuffer> input) {
    // Builds data if it was not done
    if(!data)
        data = make_shared<MessageDataBuffer>();

    // Clears already present data    
    data->clear();
    
    // Gets 'length' Bytes
    if(this->length > 0) 
        data->write(input->read(this->length));

    return true;
}