#include "InteractiveElement.h"

bool InteractiveElement::serialize(sp<MessageDataBuffer> output) {
	output->writeInt(elementId);
	output->writeInt(elementTypeId);
	output->writeShort(enabledSkills.size());
	for(int i = 0; i < enabledSkills.size(); i++) {
		output->writeShort(enabledSkills[i]->getId());
		enabledSkills[i]->serialize(output);
	}
	output->writeShort(disabledSkills.size());
	for(int i = 0; i < disabledSkills.size(); i++) {
		output->writeShort(disabledSkills[i]->getId());
		disabledSkills[i]->serialize(output);
	}
	output->writeBool(onCurrentMap);

    return true;
}

bool InteractiveElement::deserialize(sp<MessageDataBuffer> input) {
	elementId = input->readInt();
	elementTypeId = input->readInt();
	int enabledSkills_size = input->readShort();
	for(int i = 0; i < enabledSkills_size; i++) {
		sp<InteractiveElementSkill> enabledSkill(new InteractiveElementSkill());

		int enabledSkill_TypeId = input->readShort();
		enabledSkill = dynamic_pointer_cast<InteractiveElementSkill>(NetworkTypeHandler::getInstance()->getTypeById(enabledSkill_TypeId));
	
		if(!enabledSkill || !enabledSkill->deserialize(input))
			return false;
	
		enabledSkills.push_back(enabledSkill);
	}
	int disabledSkills_size = input->readShort();
	for(int i = 0; i < disabledSkills_size; i++) {
		sp<InteractiveElementSkill> disabledSkill(new InteractiveElementSkill());

		int disabledSkill_TypeId = input->readShort();
		disabledSkill = dynamic_pointer_cast<InteractiveElementSkill>(NetworkTypeHandler::getInstance()->getTypeById(disabledSkill_TypeId));
	
		if(!disabledSkill || !disabledSkill->deserialize(input))
			return false;
	
		disabledSkills.push_back(disabledSkill);
	}
	onCurrentMap = input->readBool();

    return true;
}
