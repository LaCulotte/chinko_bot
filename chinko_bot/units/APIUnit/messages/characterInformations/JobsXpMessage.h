#ifndef JOBS_XP_MESSAGE_H
#define JOBS_XP_MESSAGE_H

#include "PrefixedMessage.h"
#include "JobInformations.h"

struct JobXp {
	int jobId;
    uint64_t jobXp;
    uint64_t jobXpLevelFloor;
    uint64_t jobXpNextLevelFloor;
};

// Bot's character update : Updates jobs' Xp 
class JobsXpMessage : public PrefixedMessage {
public:
	// Constructor
	JobsXpMessage() {};
	// Copy constructor
	JobsXpMessage(const JobsXpMessage& other) = default;

	// Copy operator
	JobsXpMessage& operator=(const JobsXpMessage& other) = default;
	// Destructor
	~JobsXpMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11035;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<JobXp> jobsXp;

};

#endif