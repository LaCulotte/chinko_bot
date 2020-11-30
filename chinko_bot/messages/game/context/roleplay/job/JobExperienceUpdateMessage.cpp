#include "JobExperienceUpdateMessage.h"

bool JobExperienceUpdateMessage::serialize(sp<MessageDataBuffer> output) {
	experiencesUpdate.serialize(output);

    return true;
}

bool JobExperienceUpdateMessage::deserialize(sp<MessageDataBuffer> input) {
	if(!experiencesUpdate.deserialize(input))
		return false;

    return true;
}
