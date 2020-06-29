#include "JobExperienceMultiUpdateMessage.h"

bool JobExperienceMultiUpdateMessage::serialize(shared_ptr<MessageDataBuffer> output) {

	output->writeShort(experiencesUpdates.size());
	for(JobExperience experienceUpdate : experiencesUpdates) {
		if(!experienceUpdate.serialize(output))
			return false;
	}

	return true;
}

bool JobExperienceMultiUpdateMessage::deserialize(shared_ptr<MessageDataBuffer> input) {

	int experiencesUpdatesLength = input->readShort();
	for(int i = 0; i < experiencesUpdatesLength; i++) {
		JobExperience experienceUpdate;
		if(experienceUpdate.deserialize(input)){
			experiencesUpdates.push_back(experienceUpdate);
		} else {
			return false;
		}
	}

	return true;
}
