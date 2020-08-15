#include "GameFightJoinMessage.h"

bool GameFightJoinMessage::serialize(sp<MessageDataBuffer> output) {
	int flags0 = (isFightStarted<<3) | (canSayReady<<2) | (canBeCancelled<<1) | (isTeamPhase<<0);
	output->writeByte(flags0);

	output->writeShort(timeMaxBeforeFightStart);
	output->writeByte(fightType);

    return true;
}

bool GameFightJoinMessage::deserialize(sp<MessageDataBuffer> input) {
	int flags0 = input->readByte();
	isFightStarted = flags0 & (1 << 3);
	canSayReady = flags0 & (1 << 2);
	canBeCancelled = flags0 & (1 << 1);
	isTeamPhase = flags0 & (1 << 0);

	timeMaxBeforeFightStart = input->readShort();
	fightType = input->readByte();

    return true;
}
