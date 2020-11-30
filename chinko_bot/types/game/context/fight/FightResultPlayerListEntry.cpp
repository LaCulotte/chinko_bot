#include "FightResultPlayerListEntry.h"

bool FightResultPlayerListEntry::serialize(sp<MessageDataBuffer> output) {
	FightResultFighterListEntry::serialize(output);

	output->writeVarShort(level);
	output->writeShort(additional.size());
	for(int i = 0; i < additional.size(); i++) {
		output->writeShort(additional[i]->getId());
		additional[i]->serialize(output);
	}

    return true;
}

bool FightResultPlayerListEntry::deserialize(sp<MessageDataBuffer> input) {
	FightResultFighterListEntry::deserialize(input);

	level = input->readVarShort();
	int additional_size = input->readShort();
	for(int i = 0; i < additional_size; i++) {
		sp<FightResultAdditionalData> additiona(new FightResultAdditionalData());

		int additiona_TypeId = input->readShort();
		additiona = dynamic_pointer_cast<FightResultAdditionalData>(NetworkTypeHandler::getInstance()->getTypeById(additiona_TypeId));
	
		if(!additiona || !additiona->deserialize(input))
			return false;
	
		additional.push_back(additiona);
	}

    return true;
}
