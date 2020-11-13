#ifndef BOTCONNECTIONSTATUS_MESSAGE_H
#define BOTCONNECTIONSTATUS_MESSAGE_H

#include "Message.h"

class BotConnectionStatusMessage : public Message {
public:
	// Constructor
	BotConnectionStatusMessage() {};
	// Constructor with connected initialization
	BotConnectionStatusMessage(bool connected) { this->connected = connected; };
	// Copy constructor
	BotConnectionStatusMessage(const BotConnectionStatusMessage& other) = default;

	// Copy operator
	BotConnectionStatusMessage& operator=(const BotConnectionStatusMessage& other) = default;
	// Destructor
	~BotConnectionStatusMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10105;

    bool connected = false;
};

#endif