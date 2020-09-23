#ifndef AUTHENTICATIONTICKETMESSAGE_MESSAGE_H
#define AUTHENTICATIONTICKETMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class AuthenticationTicketMessage : public PrefixedMessage {
public:
	// Constructor
	AuthenticationTicketMessage() {};
	// Copy constructor
	AuthenticationTicketMessage(const AuthenticationTicketMessage& other) = default;

	// Copy operator
	AuthenticationTicketMessage& operator=(const AuthenticationTicketMessage& other) = default;
	// Destructor
	~AuthenticationTicketMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 1864;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string ticket;
	string lang = "fr";
};

#endif