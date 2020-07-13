#ifndef IDENTIFICATIONSUCCESS_MESSAGE_H
#define IDENTIFICATIONSUCCESS_MESSAGE_H

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

	bool hasRights = false;
	bool hasConsoleRights = false;
	bool wasAlreadyConnected = false;
	
	string username;
	string nickname;
	
	int accountId;
	int communityId;
	
	string secretQuestion;
	
	double accountCreation;
	double subscriptionElapsedDuration;
	double subscriptionEndDate;

	int havenBagAvailableRoom;

};

#endif