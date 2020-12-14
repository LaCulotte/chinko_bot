#ifndef SENDUSEREQUEST_MESSAGE_H
#define SENDUSEREQUEST_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class SendUseRequestMessage : public Message {
public: 
	// Constructor
	SendUseRequestMessage() {};
	// Copy constructor
	SendUseRequestMessage(const SendUseRequestMessage& other) = default;

	// Copy operator
	SendUseRequestMessage& operator=(const SendUseRequestMessage& other) = default;
	// Destructor
	~SendUseRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10085;
};

#endif