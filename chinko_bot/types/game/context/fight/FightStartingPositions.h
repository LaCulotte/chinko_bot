#ifndef FIGHTSTARTINGPOSITIONS_H
#define FIGHTSTARTINGPOSITIONS_H

#include "NetworkType.h"


class FightStartingPositions : public NetworkType {
public:
	// Constructor
	FightStartingPositions() {};
	// Copy constructor
	FightStartingPositions(const FightStartingPositions& other) = default;

	// Copy operator
	FightStartingPositions& operator=(const FightStartingPositions& other) = default;
	// Destructor
	~FightStartingPositions() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 637;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<int> positionsForDefenders;
	vector<int> positionsForChallengers;
};

#endif