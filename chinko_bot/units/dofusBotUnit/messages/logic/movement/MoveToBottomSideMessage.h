#ifndef MOVETOBOTTOMSIDE_MESSAGE_H
#define MOVETOBOTTOMSIDE_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class MoveToBottomSideMessage : public Message {
public: 
	// Constructor
	MoveToBottomSideMessage() {};
	// Copy constructor
	MoveToBottomSideMessage(const MoveToBottomSideMessage& other) = default;

	// Copy operator
	MoveToBottomSideMessage& operator=(const MoveToBottomSideMessage& other) = default;
	// Destructor
	~MoveToBottomSideMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 661;
};

#endif