#ifndef JOBDESCRIPTIONMESSAGE_MESSAGE_H
#define JOBDESCRIPTIONMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "JobDescription.h"

class JobDescriptionMessage : public PrefixedMessage {
public:
	// Constructor
	JobDescriptionMessage() {};
	// Copy constructor
	JobDescriptionMessage(const JobDescriptionMessage& other) = default;

	// Copy operator
	JobDescriptionMessage& operator=(const JobDescriptionMessage& other) = default;
	// Destructor
	~JobDescriptionMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 8854;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<JobDescription> jobsDescription;
};

#endif