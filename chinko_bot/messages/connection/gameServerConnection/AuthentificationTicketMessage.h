#ifndef AUTHENTIFICATIONTICKET_MESSAGE_H
#define AUTHENTIFICATIONTICKET_MESSAGE_H

#include "PrefixedMessage.h"

class AuthentificationTicketMessage : public PrefixedMessage {
public: 
	// Constructor
	AuthentificationTicketMessage() {};
	// Constructor with ticket initialization
	AuthentificationTicketMessage(string ticket) { this->ticket = ticket; };
	// Copy constructor
	AuthentificationTicketMessage(const AuthentificationTicketMessage& other) = default;

	// Copy operator
	AuthentificationTicketMessage& operator=(const AuthentificationTicketMessage& other) = default;
	// Destructor
	~AuthentificationTicketMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 110;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string lang = "fr";
	string ticket;

};

#endif