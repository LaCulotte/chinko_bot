#include "PlayedCharacterXpMessage.h"

bool PlayedCharacterXpMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeVarInt64(xp);
    output->writeVarInt64(xpLevelFloor);
    output->writeVarInt64(xpNextLevelFloor);

    return true;
}

bool PlayedCharacterXpMessage::deserialize(sp<MessageDataBuffer> input) {
    xp = input->readVarInt64();
    xpLevelFloor = input->readVarInt64();
    xpNextLevelFloor = input->readVarInt64();
    
    return true;
}
