#ifndef FIGHTLOOT_H
#define FIGHTLOOT_H

#include "NetworkType.h"


class FightLoot : public NetworkType {
public:
	// Constructor
	FightLoot() {};
	// Copy constructor
	FightLoot(const FightLoot& other) = default;

	// Copy operator
	FightLoot& operator=(const FightLoot& other) = default;
	// Destructor
	~FightLoot() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 4390;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t kamas = 0;
	vector<int> objects;
};

#endif