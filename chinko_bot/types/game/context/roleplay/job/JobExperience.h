#ifndef JOBEXPERIENCE_H
#define JOBEXPERIENCE_H

#include "NetworkType.h"


class JobExperience : public NetworkType {
public:
	// Constructor
	JobExperience() {};
	// Copy constructor
	JobExperience(const JobExperience& other) = default;

	// Copy operator
	JobExperience& operator=(const JobExperience& other) = default;
	// Destructor
	~JobExperience() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 7912;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t jobXpNextLevelFloor = 0;
	uint64_t jobXpLevelFloor = 0;
	uint64_t jobXP = 0;
	int jobLevel = 0;
	int jobId = 0;
};

#endif