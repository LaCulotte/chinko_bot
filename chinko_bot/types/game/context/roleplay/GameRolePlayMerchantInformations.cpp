#include "GameRolePlayMerchantInformations.h"

bool GameRolePlayMerchantInformations::serialize(sp<MessageDataBuffer> output) {
	GameRolePlayNamedActorInformations::serialize(output);

	output->writeByte(sellType);
	output->writeShort(options.size());
	for(int i = 0; i < options.size(); i++) {
		output->writeShort(options[i]->getId());
		options[i]->serialize(output);
	}

    return true;
}

bool GameRolePlayMerchantInformations::deserialize(sp<MessageDataBuffer> input) {
	GameRolePlayNamedActorInformations::deserialize(input);

	sellType = input->readByte();
	int options_size = input->readShort();
	for(int i = 0; i < options_size; i++) {
		sp<HumanOption> option(new HumanOption());

		int option_TypeId = input->readShort();
		option = dynamic_pointer_cast<HumanOption>(NetworkTypeHandler::getInstance()->getTypeById(option_TypeId));
	
		if(!option || !option->deserialize(input))
			return false;
	
		options.push_back(option);
	}

    return true;
}
