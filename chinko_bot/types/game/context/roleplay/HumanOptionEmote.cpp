#include "HumanOptionEmote.h"

bool HumanOptionEmote::serialize(sp<MessageDataBuffer> output) {
	HumanOption::serialize(output);

	output->writeByte(emoteId);
	output->writeDouble(emoteStartTime);

    return true;
}

bool HumanOptionEmote::deserialize(sp<MessageDataBuffer> input) {
	HumanOption::deserialize(input);

	emoteId = input->readByte();
	emoteStartTime = input->readDouble();

    return true;
}
