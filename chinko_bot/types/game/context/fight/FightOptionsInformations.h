#ifndef FIGHTOPTIONSINFORMATIONS_H
#define FIGHTOPTIONSINFORMATIONS_H

#include "NetworkType.h"


class FightOptionsInformations : public NetworkType {
public:
	// Constructor
	FightOptionsInformations() {};
	// Copy constructor
	FightOptionsInformations(const FightOptionsInformations& other) = default;

	// Copy operator
	FightOptionsInformations& operator=(const FightOptionsInformations& other) = default;
	// Destructor
	~FightOptionsInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 20;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool isAskingForHelp = false;
	bool isClosed = false;
	bool isRestrictedToPartyOnly = false;
	bool isSecret = false;
};

#endif