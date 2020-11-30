#ifndef FIGHTRESULTPLAYERLISTENTRY_H
#define FIGHTRESULTPLAYERLISTENTRY_H

#include "FightResultFighterListEntry.h"

#include "FightResultAdditionalData.h"

#include "NetworkTypeHandler.h"

class FightResultPlayerListEntry : public FightResultFighterListEntry {
public:
	// Constructor
	FightResultPlayerListEntry() {};
	// Copy constructor
	FightResultPlayerListEntry(const FightResultPlayerListEntry& other) = default;

	// Copy operator
	FightResultPlayerListEntry& operator=(const FightResultPlayerListEntry& other) = default;
	// Destructor
	~FightResultPlayerListEntry() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2386;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<sp<FightResultAdditionalData>> additional;
	int level = 0;
};

#endif