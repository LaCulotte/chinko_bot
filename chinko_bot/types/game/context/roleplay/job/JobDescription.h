#ifndef JOBDESCRIPTION_H
#define JOBDESCRIPTION_H

#include "NetworkType.h"

#include "SkillActionDescription.h"

#include "NetworkTypeHandler.h"

class JobDescription : public NetworkType {
public:
	// Constructor
	JobDescription() {};
	// Copy constructor
	JobDescription(const JobDescription& other) = default;

	// Copy operator
	JobDescription& operator=(const JobDescription& other) = default;
	// Destructor
	~JobDescription() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 8519;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<sp<SkillActionDescription>> skills;
	int jobId = 0;
};

#endif