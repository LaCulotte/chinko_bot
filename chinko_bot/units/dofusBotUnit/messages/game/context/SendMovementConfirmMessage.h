#ifndef SENDMOVEMENTCONFIRM_MESSAGE_H
#define SENDMOVEMENTCONFIRM_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the GameContext building
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
	static const unsigned int protocolId = 644;
};

#endif