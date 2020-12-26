#ifndef FIGHTRESULTPVPDATA_H
#define FIGHTRESULTPVPDATA_H

#include "FightResultAdditionalData.h"


class FightResultPvpData : public FightResultAdditionalData {
public:
	// Constructor
	FightResultPvpData() {};
	// Copy constructor
	FightResultPvpData(const FightResultPvpData& other) = default;

	// Copy operator
	FightResultPvpData& operator=(const FightResultPvpData& other) = default;
	// Destructor
	~FightResultPvpData() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 9936;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int honorDelta = 0;
	int honor = 0;
	int maxHonorForGrade = 0;
	int minHonorForGrade = 0;
	int grade = 0;
};

#endif