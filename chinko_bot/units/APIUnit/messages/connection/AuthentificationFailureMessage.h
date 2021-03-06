#ifndef AUTHENTIFICATION_FAILURE_MESSAGE_H
#define AUTHENTIFICATION_FAILURE_MESSAGE_H

#include "PrefixedMessage.h"

// Authentification was not successful
class AuthentificationFailureMessage : public PrefixedMessage {
public:
	// Constructor
	AuthentificationFailureMessage() {};
	// Constructor with reason initialization
	AuthentificationFailureMessage(string reason) { this->reason = reason; };
	// Copy constructor
	AuthentificationFailureMessage(const AuthentificationFailureMessage& other) = default;

	// Copy operator
	AuthentificationFailureMessage& operator=(const AuthentificationFailureMessage& other) = default;
	// Destructor
	~AuthentificationFailureMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11003;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override{ reason = input->readUTF(); return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override{ output->writeUTF(reason); return true; };

    string reason;

};


#endif