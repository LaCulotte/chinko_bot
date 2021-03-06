#ifndef MOVETOBOTTOMSIDE_MESSAGE_H
#define MOVETOBOTTOMSIDE_MESSAGE_H

#include "Message.h"

// Requests to move to the bottom side of the map
class MoveToBottomSideMessage : public Message {
public: 
	// Constructor
	MoveToBottomSideMessage() {};
	// Constructor with floor initialization
	MoveToBottomSideMessage(int floor) { this->floor = floor; };
	// Copy constructor
	MoveToBottomSideMessage(const MoveToBottomSideMessage& other) = default;

	// Copy operator
	MoveToBottomSideMessage& operator=(const MoveToBottomSideMessage& other) = default;
	// Destructor
	~MoveToBottomSideMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10061;

	int floor = 0;
};

#endif