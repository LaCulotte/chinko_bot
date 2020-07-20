#include "MapComplementaryInformationsDataMessage.h"

bool MapComplementaryInformationsDataMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeVarShort(subAreaId);
	output->writeDouble(mapId);
	output->writeShort(houses.size());
	for(int i = 0; i < houses.size(); i++) {
		output->writeShort(houses[i]->getId());
		houses[i]->serialize(output);
	}
	output->writeShort(actors.size());
	for(int i = 0; i < actors.size(); i++) {
		output->writeShort(actors[i]->getId());
		actors[i]->serialize(output);
	}
	output->writeShort(interactiveElements.size());
	for(int i = 0; i < interactiveElements.size(); i++) {
		output->writeShort(interactiveElements[i]->getId());
		interactiveElements[i]->serialize(output);
	}
	output->writeShort(statedElements.size());
	for(int i = 0; i < statedElements.size(); i++) {
		statedElements[i].serialize(output);
	}
	output->writeShort(obstacles.size());
	for(int i = 0; i < obstacles.size(); i++) {
		obstacles[i].serialize(output);
	}
	output->writeShort(fights.size());
	for(int i = 0; i < fights.size(); i++) {
		fights[i].serialize(output);
	}
	output->writeBool(hasAggressiveMonsters);
	fightStartPositions.serialize(output);

    return true;
}

bool MapComplementaryInformationsDataMessage::deserialize(sp<MessageDataBuffer> input) {
	subAreaId = input->readVarShort();
	mapId = input->readDouble();
	int houses_size = input->readShort();
	for(int i = 0; i < houses_size; i++) {
		sp<HouseInformations> house(new HouseInformations());

		int house_TypeId = input->readShort();
		house = dynamic_pointer_cast<HouseInformations>(NetworkTypeHandler::getInstance()->getTypeById(house_TypeId));
	
		if(!house || !house->deserialize(input))
			return false;
	
		houses.push_back(house);
	}
	int actors_size = input->readShort();
	for(int i = 0; i < actors_size; i++) {
		sp<GameRolePlayActorInformations> actor(new GameRolePlayActorInformations());

		int actor_TypeId = input->readShort();
		actor = dynamic_pointer_cast<GameRolePlayActorInformations>(NetworkTypeHandler::getInstance()->getTypeById(actor_TypeId));
	
		if(!actor || !actor->deserialize(input))
			return false;
	
		actors.push_back(actor);
	}
	int interactiveElements_size = input->readShort();
	for(int i = 0; i < interactiveElements_size; i++) {
		sp<InteractiveElement> interactiveElement(new InteractiveElement());

		int interactiveElement_TypeId = input->readShort();
		interactiveElement = dynamic_pointer_cast<InteractiveElement>(NetworkTypeHandler::getInstance()->getTypeById(interactiveElement_TypeId));
	
		if(!interactiveElement || !interactiveElement->deserialize(input))
			return false;
	
		interactiveElements.push_back(interactiveElement);
	}
	int statedElements_size = input->readShort();
	for(int i = 0; i < statedElements_size; i++) {
		StatedElement statedElement;

		if(!statedElement.deserialize(input))
			return false;
		statedElements.push_back(statedElement);
	}
	int obstacles_size = input->readShort();
	for(int i = 0; i < obstacles_size; i++) {
		MapObstacle obstacle;

		if(!obstacle.deserialize(input))
			return false;
		obstacles.push_back(obstacle);
	}
	int fights_size = input->readShort();
	for(int i = 0; i < fights_size; i++) {
		FightCommonInformations fight;

		if(!fight.deserialize(input))
			return false;
		fights.push_back(fight);
	}
	hasAggressiveMonsters = input->readBool();
	if(!fightStartPositions.deserialize(input))
		return false;

    return true;
}
