#ifndef FIGHTRESULTLISTENTRY_H
#define FIGHTRESULTLISTENTRY_H

#include "NetworkType.h"

#include "FightLoot.h"

class FightResultListEntry : public NetworkType {
public:
	// Constructor
	FightResultListEntry() {};
	// Copy constructor
	FightResultListEntry(const FightResultListEntry& other) = default;

	// Copy operator
	FightResultListEntry& operator=(const FightResultListEntry& other) = default;
	// Destructor
	~FightResultListEntry() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9494;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	FightLoot rewards;
	int wave = 0;
	int outcome = 0;
};

#endif