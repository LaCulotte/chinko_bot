#ifndef ACTORRESTRICTIONSINFORMATIONS_H
#define ACTORRESTRICTIONSINFORMATIONS_H

#include "NetworkType.h"


class ActorRestrictionsInformations : public NetworkType {
public:
	// Constructor
	ActorRestrictionsInformations() {};
	// Copy constructor
	ActorRestrictionsInformations(const ActorRestrictionsInformations& other) = default;

	// Copy operator
	ActorRestrictionsInformations& operator=(const ActorRestrictionsInformations& other) = default;
	// Destructor
	~ActorRestrictionsInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9470;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool cantWalk8Directions = false;
	bool cantAttackMonster = false;
	bool cantUseObject = false;
	bool cantBeMerchant = false;
	bool cantChat = false;
	bool cantBeChallenged = false;
	bool cantSpeakToNPC = false;
	bool cantRun = false;
	bool cantChangeZone = false;
	bool cantTrade = false;
	bool cantMove = false;
	bool cantChallenge = false;
	bool cantBeAttackedByMutant = false;
	bool cantBeAggressed = false;
	bool cantMinimize = false;
	bool cantUseInteractive = false;
	bool forceSlowWalk = false;
	bool cantAggress = false;
	bool cantExchange = false;
	bool cantUseTaxCollector = false;
	bool cantAttack = false;
};

#endif