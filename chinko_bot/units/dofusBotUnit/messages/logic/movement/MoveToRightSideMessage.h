#ifndef MOVETORIGHTSIDE_MESSAGE_H
#define MOVETORIGHTSIDE_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class MoveToRightSideMessage : public Message {
public: 
	// Constructor
	MoveToRightSideMessage() {};
	// Copy constructor
	MoveToRightSideMessage(const MoveToRightSideMessage& other) = default;

	// Copy operator
	MoveToRightSideMessage& operator=(const MoveToRightSideMessage& other) = default;
	// Destructor
	~MoveToRightSideMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10059;
};

#endif