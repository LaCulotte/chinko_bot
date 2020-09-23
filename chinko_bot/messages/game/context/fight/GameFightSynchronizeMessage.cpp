#include "GameFightSynchronizeMessage.h"

bool GameFightSynchronizeMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(fighters.size());
	for(int i = 0; i < fighters.size(); i++) {
		output->writeShort(fighters[i]->getId());
		fighters[i]->serialize(output);
	}

    return true;
}

bool GameFightSynchronizeMessage::deserialize(sp<MessageDataBuffer> input) {
	int fighters_size = input->readShort();
	for(int i = 0; i < fighters_size; i++) {
		sp<GameFightFighterInformations> fighter(new GameFightFighterInformations());

		int fighter_TypeId = input->readShort();
		fighter = dynamic_pointer_cast<GameFightFighterInformations>(NetworkTypeHandler::getInstance()->getTypeById(fighter_TypeId));
	
		if(!fighter || !fighter->deserialize(input))
			return false;
	
		fighters.push_back(fighter);
	}

    return true;
}
