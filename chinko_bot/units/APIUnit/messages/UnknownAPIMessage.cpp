#include "UnknownAPIMessage.h"

bool UnknownAPIMessage::serialize(sp<MessageDataBuffer> output) {
    if(!data)
        return false;

    data->cursor_reset();

    output->write(data->getData());

    return true;
}

bool UnknownAPIMessage::deserialize(sp<MessageDataBuffer> input) {
    if(!data) 
        data = make_shared<MessageDataBuffer>();

    data->clear();

    data->write(input->read(this->length));

    return true;
}