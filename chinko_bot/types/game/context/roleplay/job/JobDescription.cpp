#include "JobDescription.h"

bool JobDescription::serialize(sp<MessageDataBuffer> output) {
	output->writeByte(jobId);
	output->writeShort(skills.size());
	for(int i = 0; i < skills.size(); i++) {
		output->writeShort(skills[i]->getId());
		skills[i]->serialize(output);
	}

    return true;
}

bool JobDescription::deserialize(sp<MessageDataBuffer> input) {
	jobId = input->readByte();
	int skills_size = input->readShort();
	for(int i = 0; i < skills_size; i++) {
		sp<SkillActionDescription> skill(new SkillActionDescription());

		int skill_TypeId = input->readShort();
		skill = dynamic_pointer_cast<SkillActionDescription>(NetworkTypeHandler::getInstance()->getTypeById(skill_TypeId));
	
		if(!skill || !skill->deserialize(input))
			return false;
	
		skills.push_back(skill);
	}

    return true;
}
