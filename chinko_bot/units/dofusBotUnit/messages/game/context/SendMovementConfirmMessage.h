#ifndef SENDMOVEMENTCONFIRM_MESSAGE_H
#define SENDMOVEMENTCONFIRM_MESSAGE_H

#include "Message.h"

// Message to send a movement confirmation message
class SendMovementConfirmMessage : public Message {
public: 
	// Constructor
	SendMovementConfirmMessage() {};
	// Copy constructor
	SendMovementConfirmMessage(const SendMovementConfirmMessage& other) = default;

	// Copy operator
	SendMovementConfirmMessage& operator=(const SendMovementConfirmMessage& other) = default;
	// Destructor
	~SendMovementConfirmMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10045;
};

#endif