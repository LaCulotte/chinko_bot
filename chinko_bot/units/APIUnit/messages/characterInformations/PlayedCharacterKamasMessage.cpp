#include "PlayedCharacterKamasMessage.h"

bool PlayedCharacterKamasMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeVarInt64(kamas);
    
    return true;
}

bool PlayedCharacterKamasMessage::deserialize(sp<MessageDataBuffer> input) {
    kamas = input->readVarInt64();

    return true;
}