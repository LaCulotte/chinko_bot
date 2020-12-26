#ifndef PLAYERMOVEMENTERROR_MESSAGE_H
#define PLAYERMOVEMENTERROR_MESSAGE_H

#include "Message.h"

// Notify that the character movement was a failure
class PlayerMovementErrorMessage : public Message {
public: 
	// Constructor
	PlayerMovementErrorMessage() {};
	// Copy constructor
	PlayerMovementErrorMessage(const PlayerMovementErrorMessage& other) = default;

	// Copy operator
	PlayerMovementErrorMessage& operator=(const PlayerMovementErrorMessage& other) = default;
	// Destructor
	~PlayerMovementErrorMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10056;
};

#endif