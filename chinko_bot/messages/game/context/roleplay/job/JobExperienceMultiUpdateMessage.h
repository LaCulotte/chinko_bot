#ifndef JOBEXPERIENCEMULTIUPDATEMESSAGE_MESSAGE_H
#define JOBEXPERIENCEMULTIUPDATEMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "JobExperience.h"

class JobExperienceMultiUpdateMessage : public PrefixedMessage {
public:
	// Constructor
	JobExperienceMultiUpdateMessage() {};
	// Copy constructor
	JobExperienceMultiUpdateMessage(const JobExperienceMultiUpdateMessage& other) = default;

	// Copy operator
	JobExperienceMultiUpdateMessage& operator=(const JobExperienceMultiUpdateMessage& other) = default;
	// Destructor
	~JobExperienceMultiUpdateMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 2837;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<JobExperience> experiencesUpdate;
};

#endif