#include "GameRolePlayShowActorMessage.h"

bool GameRolePlayShowActorMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(informations->getId());
	informations->serialize(output);

    return true;
}

bool GameRolePlayShowActorMessage::deserialize(sp<MessageDataBuffer> input) {
	int informations_TypeId = input->readShort();
	informations = dynamic_pointer_cast<GameRolePlayActorInformations>(NetworkTypeHandler::getInstance()->getTypeById(informations_TypeId));

	if(!informations || !informations->deserialize(input))
		return false;


    return true;
}
