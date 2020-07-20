#include "HumanOptionTitle.h"

bool HumanOptionTitle::serialize(sp<MessageDataBuffer> output) {
	HumanOption::serialize(output);

	output->writeVarShort(titleId);
	output->writeUTF(titleParam);

    return true;
}

bool HumanOptionTitle::deserialize(sp<MessageDataBuffer> input) {
	HumanOption::deserialize(input);

	titleId = input->readVarShort();
	titleParam = input->readUTF();

    return true;
}
