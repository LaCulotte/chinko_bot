#include "HumanInformations.h"

bool HumanInformations::serialize(sp<MessageDataBuffer> output) {
	restrictions.serialize(output);
	output->writeBool(sex);
	output->writeShort(options.size());
	for(int i = 0; i < options.size(); i++) {
		output->writeShort(options[i]->getId());
		options[i]->serialize(output);
	}

    return true;
}

bool HumanInformations::deserialize(sp<MessageDataBuffer> input) {
	if(!restrictions.deserialize(input))
		return false;
	sex = input->readBool();
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
