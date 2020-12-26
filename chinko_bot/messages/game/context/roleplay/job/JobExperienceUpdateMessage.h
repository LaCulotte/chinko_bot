#ifndef JOBEXPERIENCEUPDATEMESSAGE_MESSAGE_H
#define JOBEXPERIENCEUPDATEMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "JobExperience.h"

class JobExperienceUpdateMessage : public PrefixedMessage {
public:
	// Constructor
	JobExperienceUpdateMessage() {};
	// Copy constructor
	JobExperienceUpdateMessage(const JobExperienceUpdateMessage& other) = default;

	// Copy operator
	JobExperienceUpdateMessage& operator=(const JobExperienceUpdateMessage& other) = default;
	// Destructor
	~JobExperienceUpdateMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 1650;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	JobExperience experiencesUpdate;
};

#endif