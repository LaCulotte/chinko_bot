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

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 98;
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int jobId;
	int jobLevel;
	uint64_t jobXp;
	uint64_t jobXpLevelFloor;
	uint64_t jobXpNextLevelFloor;

};

#endif