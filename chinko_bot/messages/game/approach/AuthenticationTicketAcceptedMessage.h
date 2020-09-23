#ifndef AUTHENTICATIONTICKETACCEPTEDMESSAGE_MESSAGE_H
#define AUTHENTICATIONTICKETACCEPTEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class AuthenticationTicketAcceptedMessage : public PrefixedMessage {
public:
	// Constructor
	AuthenticationTicketAcceptedMessage() {};
	// Copy constructor
	AuthenticationTicketAcceptedMessage(const AuthenticationTicketAcceptedMessage& other) = default;

	// Copy operator
	AuthenticationTicketAcceptedMessage& operator=(const AuthenticationTicketAcceptedMessage& other) = default;
	// Destructor
	~AuthenticationTicketAcceptedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9026;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override{ return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override{ return true; };

};

#endif