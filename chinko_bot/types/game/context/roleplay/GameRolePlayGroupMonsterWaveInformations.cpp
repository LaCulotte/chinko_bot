#include "GameRolePlayGroupMonsterWaveInformations.h"

bool GameRolePlayGroupMonsterWaveInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayGroupMonsterInformations::serialize(output);

	output->writeByte(nbWaves);
	output->writeShort(alternatives.size());
	for(int i = 0; i < alternatives.size(); i++) {
		output->writeShort(alternatives[i]->getId());
		alternatives[i]->serialize(output);
	}

    return true;
}

bool GameRolePlayGroupMonsterWaveInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayGroupMonsterInformations::deserialize(input);

	nbWaves = input->readByte();
	int alternatives_size = input->readShort();
	for(int i = 0; i < alternatives_size; i++) {
		sp<GroupMonsterStaticInformations> alternative(new GroupMonsterStaticInformations());

		int alternative_TypeId = input->readShort();
		alternative = dynamic_pointer_cast<GroupMonsterStaticInformations>(NetworkTypeHandler::getInstance()->getTypeById(alternative_TypeId));
	
		if(!alternative || !alternative->deserialize(input))
			return false;
	
		alternatives.push_back(alternative);
	}

    return true;
}
