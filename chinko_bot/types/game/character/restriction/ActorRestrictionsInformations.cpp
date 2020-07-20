#include "ActorRestrictionsInformations.h"

bool ActorRestrictionsInformations::serialize(sp<MessageDataBuffer> output) {
	int flags0 = (cantBeChallenged<<1) | (cantRun<<4) | (cantTrade<<2) | (cantMove<<7) | (cantBeAttackedByMutant<<3) | (cantBeAggressed<<0) | (cantMinimize<<6) | (forceSlowWalk<<5);
	output->writeByte(flags0);

	int flags1 = (cantUseObject<<6) | (cantBeMerchant<<5) | (cantChat<<4) | (cantChallenge<<1) | (cantAggress<<0) | (cantExchange<<2) | (cantUseTaxCollector<<7) | (cantAttack<<3);
	output->writeByte(flags1);

	int flags2 = (cantWalk8Directions<<4) | (cantAttackMonster<<3) | (cantSpeakToNPC<<1) | (cantChangeZone<<2) | (cantUseInteractive<<0);
	output->writeByte(flags2);


    return true;
}

bool ActorRestrictionsInformations::deserialize(sp<MessageDataBuffer> input) {
	int flags0 = input->readByte();
	cantBeChallenged = flags0 & (1 << 1);
	cantRun = flags0 & (1 << 4);
	cantTrade = flags0 & (1 << 2);
	cantMove = flags0 & (1 << 7);
	cantBeAttackedByMutant = flags0 & (1 << 3);
	cantBeAggressed = flags0 & (1 << 0);
	cantMinimize = flags0 & (1 << 6);
	forceSlowWalk = flags0 & (1 << 5);

	int flags1 = input->readByte();
	cantUseObject = flags1 & (1 << 6);
	cantBeMerchant = flags1 & (1 << 5);
	cantChat = flags1 & (1 << 4);
	cantChallenge = flags1 & (1 << 1);
	cantAggress = flags1 & (1 << 0);
	cantExchange = flags1 & (1 << 2);
	cantUseTaxCollector = flags1 & (1 << 7);
	cantAttack = flags1 & (1 << 3);

	int flags2 = input->readByte();
	cantWalk8Directions = flags2 & (1 << 4);
	cantAttackMonster = flags2 & (1 << 3);
	cantSpeakToNPC = flags2 & (1 << 1);
	cantChangeZone = flags2 & (1 << 2);
	cantUseInteractive = flags2 & (1 << 0);

    return true;
}
