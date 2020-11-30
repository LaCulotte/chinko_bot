#include "ItemInformations.h"

bool ItemInformations::serialize(sp<MessageDataBuffer> output) {
    output->writeVarShort(itemGID);
    output->writeVarInt(itemUID);
    output->writeVarInt(quantity);
    
    return true;
}

bool ItemInformations::deserialize(sp<MessageDataBuffer> input) {
    itemGID = input->readVarShort();
    itemUID = input->readVarInt();
    quantity = input->readVarInt();

    return true;
}