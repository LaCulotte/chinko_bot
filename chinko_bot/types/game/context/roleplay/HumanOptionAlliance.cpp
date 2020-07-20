#include "HumanOptionAlliance.h"

bool HumanOptionAlliance::serialize(sp<MessageDataBuffer> output) {
	HumanOption::serialize(output);

	allianceInformations.serialize(output);
	output->writeByte(aggressable);

    return true;
}

bool HumanOptionAlliance::deserialize(sp<MessageDataBuffer> input) {
	HumanOption::deserialize(input);

	if(!allianceInformations.deserialize(input))
		return false;
	aggressable = input->readByte();

    return true;
}
