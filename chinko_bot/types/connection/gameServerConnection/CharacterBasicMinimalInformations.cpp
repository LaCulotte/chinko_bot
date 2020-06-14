#include "CharacterBasicMinimalInformations.h"

bool CharacterBasicMinimalInformations::serialize(shared_ptr<MessageDataBuffer> output) {
	if(!AbstractCharacterInformation::serialize(output)) 
		return false;

	output->writeUTF(name);	

	return true;
}

bool CharacterBasicMinimalInformations::deserialize(shared_ptr<MessageDataBuffer> input) {
	if(!AbstractCharacterInformation::deserialize(input)) 
		return false;

	name = input->readUTF();

	return true;
}
