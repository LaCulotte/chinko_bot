#ifndef BOTCONNECTIONSTATUS_REQUEST_MESSAGE_H
#define BOTCONNECTIONSTATUS_REQUEST_MESSAGE_H

#include "Message.h"

class BotConnectionStatusRequestMessage : public Message {
public:
	// Constructor
	BotConnectionStatusRequestMessage() {};
	// Copy constructor
	BotConnectionStatusRequestMessage(const BotConnectionStatusRequestMessage& other) = default;

	// Copy operator
	BotConnectionStatusRequestMessage& operator=(const BotConnectionStatusRequestMessage& other) = default;
	// Destructor
	~BotConnectionStatusRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10104;
};

#endif