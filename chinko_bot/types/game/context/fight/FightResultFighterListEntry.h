#ifndef FIGHTRESULTFIGHTERLISTENTRY_H
#define FIGHTRESULTFIGHTERLISTENTRY_H

#include "FightResultListEntry.h"


class FightResultFighterListEntry : public FightResultListEntry {
public:
	// Constructor
	FightResultFighterListEntry() {};
	// Copy constructor
	FightResultFighterListEntry(const FightResultFighterListEntry& other) = default;

	// Copy operator
	FightResultFighterListEntry& operator=(const FightResultFighterListEntry& other) = default;
	// Destructor
	~FightResultFighterListEntry() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 1126;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool alive = false;
	double id = 0;
};

#endif