#ifndef FIGHTRESULTTAXCOLLECTORLISTENTRY_H
#define FIGHTRESULTTAXCOLLECTORLISTENTRY_H

#include "FightResultFighterListEntry.h"

#include "BasicGuildInformations.h"

class FightResultTaxCollectorListEntry : public FightResultFighterListEntry {
public:
	// Constructor
	FightResultTaxCollectorListEntry() {};
	// Copy constructor
	FightResultTaxCollectorListEntry(const FightResultTaxCollectorListEntry& other) = default;

	// Copy operator
	FightResultTaxCollectorListEntry& operator=(const FightResultTaxCollectorListEntry& other) = default;
	// Destructor
	~FightResultTaxCollectorListEntry() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 1061;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int experienceForGuild = 0;
	BasicGuildInformations guildInfo;
	int level = 0;
};

#endif