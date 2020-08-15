#ifndef MOVETOLEFTSIDE_MESSAGE_H
#define MOVETOLEFTSIDE_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class MoveToLeftSideMessage : public Message {
public: 
	// Constructor
	MoveToLeftSideMessage() {};
	// Copy constructor
	MoveToLeftSideMessage(const MoveToLeftSideMessage& other) = default;

	// Copy operator
	MoveToLeftSideMessage& operator=(const MoveToLeftSideMessage& other) = default;
	// Destructor
	~MoveToLeftSideMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 658;
};

#endif