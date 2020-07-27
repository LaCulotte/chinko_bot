#ifndef PLAYERMOVEMENTENDED_MESSAGE_H
#define PLAYERMOVEMENTENDED_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class PlayerMoved : public Message {
public: 
	// Constructor
	PlayerMoved() {};
	// Copy constructor
	PlayerMoved(const PlayerMoved& other) = default;

	// Copy operator
	PlayerMoved& operator=(const PlayerMoved& other) = default;
	// Destructor
	~PlayerMoved() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 655;
};

#endif