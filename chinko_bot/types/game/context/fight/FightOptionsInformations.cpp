#include "FightOptionsInformations.h"

bool FightOptionsInformations::serialize(sp<MessageDataBuffer> output) {
	int flags0 = (isAskingForHelp<<3) | (isClosed<<2) | (isRestrictedToPartyOnly<<1) | (isSecret<<0);
	output->writeByte(flags0);


    return true;
}

bool FightOptionsInformations::deserialize(sp<MessageDataBuffer> input) {
	int flags0 = input->readByte();
	isAskingForHelp = flags0 & (1 << 3);
	isClosed = flags0 & (1 << 2);
	isRestrictedToPartyOnly = flags0 & (1 << 1);
	isSecret = flags0 & (1 << 0);

    return true;
}
