#ifndef JOBS_INFORMATIONS_MESSAGE_H
#define JOBS_INFORMATIONS_MESSAGE_H

#include "PrefixedMessage.h"
#include "JobInformations.h"

class JobsInformationsMessage : public PrefixedMessage {
public:
	// Constructor
	JobsInformationsMessage() {};
	// Constructor with items initialization
	JobsInformationsMessage(vector<JobInformations> jobs) { this->jobs = jobs; };
	// Copy constructor
	JobsInformationsMessage(const JobsInformationsMessage& other) = default;

	// Copy operator
	JobsInformationsMessage& operator=(const JobsInformationsMessage& other) = default;
	// Destructor
	~JobsInformationsMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11034;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<JobInformations> jobs;

};

#endif