#ifndef BEGINGAMECONTEXTREQUEST_MESSAGE_H
#define BEGINGAMECONTEXTREQUEST_MESSAGE_H

#include "Message.h"

class BeginGameContextRequestMessage : public Message {
public: 
	// Constructor
	BeginGameContextRequestMessage() {};
	// Copy constructor
	BeginGameContextRequestMessage(const BeginGameContextRequestMessage& other) = default;

	// Copy operator
	BeginGameContextRequestMessage& operator=(const BeginGameContextRequestMessage& other) = default;
	// Destructor
	~BeginGameContextRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 643;
};

#endif