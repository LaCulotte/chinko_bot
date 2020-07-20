#ifndef IDENTIFICATIONSUCCESSMESSAGE_MESSAGE_H
#define IDENTIFICATIONSUCCESSMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class IdentificationSuccessMessage : public PrefixedMessage {
public:
	// Constructor
	IdentificationSuccessMessage() {};
	// Copy constructor
	IdentificationSuccessMessage(const IdentificationSuccessMessage& other) = default;

	// Copy operator
	IdentificationSuccessMessage& operator=(const IdentificationSuccessMessage& other) = default;
	// Destructor
	~IdentificationSuccessMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 22;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int havenbagAvailableRoom = 0;
	double subscriptionEndDate = 0;
	string secretQuestion;
	bool hasConsoleRight = false;
	bool wasAlreadyConnected = false;
	bool hasRights = false;
	double subscriptionElapsedDuration = 0;
	int communityId = 0;
	double accountCreation = 0;
	int accountId = 0;
	string nickname;
	string login;
};

#endif