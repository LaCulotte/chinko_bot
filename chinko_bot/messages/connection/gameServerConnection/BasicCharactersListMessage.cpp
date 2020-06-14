#include "BasicCharactersListMessage.h"

bool BasicCharactersListMessage::serialize(shared_ptr<MessageDataBuffer> output) {
	output->writeShort(characters.size());

	for(sp<CharacterBaseInformations> cbi : characters) {
		output->writeShort(cbi->getId());
		if(!cbi->serialize(output)) 
			return false;
	}

	return true;
}

bool BasicCharactersListMessage::deserialize(shared_ptr<MessageDataBuffer> input) {

	int charactersSize = input->readShort();

	for(int i = 0; i < charactersSize; i++) {
		int typeId = input->readShort();
		sp<CharacterBaseInformations> character = dynamic_pointer_cast<CharacterBaseInformations>(NetworkTypeHandler::getInstance()->getTypeById(typeId));

		if(!character) {
			Logger::write("Error on BasicCharactersListMessage deserialize : wrong character's typeId : " + to_string(typeId), LOG_ERROR);
			return false;
		}

		if(!character->deserialize(input)) {
			Logger::write("Error on BasicCharactersListMessage deserialize : wrong character's typeId.", LOG_ERROR);
			return false;
		}

		characters.push_back(character);
	}

	return true;
}
