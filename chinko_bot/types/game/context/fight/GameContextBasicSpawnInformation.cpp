#include "GameContextBasicSpawnInformation.h"

bool GameContextBasicSpawnInformation::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(teamId);
	output->writeBool(alive);
	output->writeShort(informations->getId());
	informations->serialize(output);

    return true;
}

bool GameContextBasicSpawnInformation::deserialize(sp<MessageDataBuffer> input) {
	teamId = input->readByte();
	alive = input->readBool();
	int informations_TypeId = input->readShort();
	informations = dynamic_pointer_cast<GameContextActorPositionInformations>(NetworkTypeHandler::getInstance()->getTypeById(informations_TypeId));

	if(!informations || !informations->deserialize(input))
		return false;


    return true;
}
