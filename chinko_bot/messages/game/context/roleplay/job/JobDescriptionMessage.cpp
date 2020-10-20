#include "JobDescriptionMessage.h"

bool JobDescriptionMessage::serialize(sp<MessageDataBuffer> output) {
	output->writeShort(jobsDescription.size());
	for(int i = 0; i < jobsDescription.size(); i++) {
		jobsDescription[i].serialize(output);
	}

    return true;
}

bool JobDescriptionMessage::deserialize(sp<MessageDataBuffer> input) {
	int jobsDescription_size = input->readShort();
	for(int i = 0; i < jobsDescription_size; i++) {
		JobDescription jobsDescriptio;

		if(!jobsDescriptio.deserialize(input))
			return false;
		jobsDescription.push_back(jobsDescriptio);
	}

    return true;
}
