#include "JobExperienceMultiUpdateMessage.h"

bool JobExperienceMultiUpdateMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(experiencesUpdate.size());
	for(int i = 0; i < experiencesUpdate.size(); i++) {
		experiencesUpdate[i].serialize(output);
	}

    return true;
}

bool JobExperienceMultiUpdateMessage::deserialize(sp<MessageDataBuffer> input) {
	int experiencesUpdate_size = input->readShort();
	for(int i = 0; i < experiencesUpdate_size; i++) {
		JobExperience experiencesUpdat;

		if(!experiencesUpdat.deserialize(input))
			return false;
		experiencesUpdate.push_back(experiencesUpdat);
	}

    return true;
}
