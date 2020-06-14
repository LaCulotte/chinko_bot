#ifndef AUTHENTIFICATIONTICKETACCEPTED_MESSAGE_H
#define AUTHENTIFICATIONTICKETACCEPTED_MESSAGE_H

#include "PrefixedMessage.h"

class AuthentificationTicketAcceptedMessage : public PrefixedMessage {
public: 
	// Constructor
	AuthentificationTicketAcceptedMessage() {};
	// Copy constructor
	AuthentificationTicketAcceptedMessage(const AuthentificationTicketAcceptedMessage& other) = default;

	// Copy operator
	AuthentificationTicketAcceptedMessage& operator=(const AuthentificationTicketAcceptedMessage& other) = default;
	// Destructor
	~AuthentificationTicketAcceptedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 111;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };

};

#endif