#ifndef FIGHTRESULTMUTANTLISTENTRY_H
#define FIGHTRESULTMUTANTLISTENTRY_H

#include "FightResultFighterListEntry.h"


class FightResultMutantListEntry : public FightResultFighterListEntry {
public:
	// Constructor
	FightResultMutantListEntry() {};
	// Copy constructor
	FightResultMutantListEntry(const FightResultMutantListEntry& other) = default;

	// Copy operator
	FightResultMutantListEntry& operator=(const FightResultMutantListEntry& other) = default;
	// Destructor
	~FightResultMutantListEntry() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 3438;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int level = 0;
};

#endif