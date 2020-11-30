#include "ItemsAddMessage.h"

bool ItemsAddMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeShort(items.size());
    for(int i = 0; i < items.size(); i++)
        if(!items[i].serialize(output))
            return false;

    return true;
}

bool ItemsAddMessage::deserialize(sp<MessageDataBuffer> input) {
    int size = input->readShort();
    for(int i = 0; i < size; i++) {
        ItemInformations item;
        if(!item.deserialize(input))
            return false;

        items.push_back(item);
    }
    
    return true;
}
