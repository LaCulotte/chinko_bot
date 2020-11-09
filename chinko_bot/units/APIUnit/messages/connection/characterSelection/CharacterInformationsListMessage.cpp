#include "CharacterInformationsListMessage.h"

bool CharacterInformationsListMessage::serialize(sp<MessageDataBuffer> output) {
    output->writeVarInt(characters.size());

    for(int i = 0; i < characters.size(); i++)
        if(!characters[i].serialize(output))
            return false;
    
    return true;
}

bool CharacterInformationsListMessage::deserialize(sp<MessageDataBuffer> input) {
    int size = input->readVarInt();

    for(int i = 0; i < size; i++) {
        CharacterInformations character;
        if(!character.deserialize(input))
            return false;

        characters.push_back(character);
    }

    return true;
}