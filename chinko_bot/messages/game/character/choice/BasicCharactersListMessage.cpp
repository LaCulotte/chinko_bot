#include "BasicCharactersListMessage.h"

bool BasicCharactersListMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(characters.size());
	for(int i = 0; i < characters.size(); i++) {
		output->writeShort(characters[i]->getId());
		characters[i]->serialize(output);
	}

    return true;
}

bool BasicCharactersListMessage::deserialize(sp<MessageDataBuffer> input) {
	int characters_size = input->readShort();
	for(int i = 0; i < characters_size; i++) {
		sp<CharacterBaseInformations> character(new CharacterBaseInformations());

		int character_TypeId = input->readShort();
		character = dynamic_pointer_cast<CharacterBaseInformations>(NetworkTypeHandler::getInstance()->getTypeById(character_TypeId));
	
		if(!character || !character->deserialize(input))
			return false;
	
		characters.push_back(character);
	}

    return true;
}
