#ifndef PLAYERMOVEMENTERROR_MESSAGE_H
#define PLAYERMOVEMENTERROR_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
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
	static const unsigned int protocolId = 656;
};

#endif