#ifndef JOBLEVELUPMESSAGE_MESSAGE_H
#define JOBLEVELUPMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "JobDescription.h"

class JobLevelUpMessage : public PrefixedMessage {
public:
	// Constructor
	JobLevelUpMessage() {};
	// Copy constructor
	JobLevelUpMessage(const JobLevelUpMessage& other) = default;

	// Copy operator
	JobLevelUpMessage& operator=(const JobLevelUpMessage& other) = default;
	// Destructor
	~JobLevelUpMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 7905;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	JobDescription jobsDescription;
	int newLevel = 0;
};

#endif