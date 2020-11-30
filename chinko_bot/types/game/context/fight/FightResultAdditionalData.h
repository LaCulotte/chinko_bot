#ifndef FIGHTRESULTADDITIONALDATA_H
#define FIGHTRESULTADDITIONALDATA_H

#include "NetworkType.h"


class FightResultAdditionalData : public NetworkType {
public:
	// Constructor
	FightResultAdditionalData() {};
	// Copy constructor
	FightResultAdditionalData(const FightResultAdditionalData& other) = default;

	// Copy operator
	FightResultAdditionalData& operator=(const FightResultAdditionalData& other) = default;
	// Destructor
	~FightResultAdditionalData() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 6509;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };

};

#endif