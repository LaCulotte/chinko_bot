#ifndef GETFIGHTREADY_MESSAGE_H
#define GETFIGHTREADY_MESSAGE_H

#include "Message.h"

// Requests for the bot to get ready in a fight
class GetFightReadyMessage : public Message {
public: 
	// Constructor
	GetFightReadyMessage() {};
	// Copy constructor
	GetFightReadyMessage(const GetFightReadyMessage& other) = default;

	// Copy operator
	GetFightReadyMessage& operator=(const GetFightReadyMessage& other) = default;
	// Destructor
	~GetFightReadyMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10063;
};

#endif