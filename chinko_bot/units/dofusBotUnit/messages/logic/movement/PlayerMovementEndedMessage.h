#ifndef PLAYERMOVEMENTENDED_MESSAGE_H
#define PLAYERMOVEMENTENDED_MESSAGE_H

#include "Message.h"

// Notify that the character finished movement
class PlayerMovementEndedMessage : public Message {
public: 
	// Constructor
	PlayerMovementEndedMessage() {};
	// Copy constructor
	PlayerMovementEndedMessage(const PlayerMovementEndedMessage& other) = default;

	// Copy operator
	PlayerMovementEndedMessage& operator=(const PlayerMovementEndedMessage& other) = default;
	// Destructor
	~PlayerMovementEndedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10055;
};

#endif