#include "PlayedCharacterInventoryWeightMessage.h"

bool PlayedCharacterInventoryWeightMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeVarInt(weight);   
    output->writeVarInt(maxWeight);  

    return true; 
}

bool PlayedCharacterInventoryWeightMessage::deserialize(sp<MessageDataBuffer> input) {
    weight = input->readVarInt();
    maxWeight = input->readVarInt();

    return true;
}