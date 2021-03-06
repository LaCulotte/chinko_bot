#ifndef MOVETORIGHTSIDE_MESSAGE_H
#define MOVETORIGHTSIDE_MESSAGE_H

#include "Message.h"

// Requests to move to the right side of the map
class MoveToRightSideMessage : public Message {
public: 
	// Constructor
	MoveToRightSideMessage() {};
	// Constructor with floor initialization
	MoveToRightSideMessage(int floor) { this->floor = floor; };
	// Copy constructor
	MoveToRightSideMessage(const MoveToRightSideMessage& other) = default;

	// Copy operator
	MoveToRightSideMessage& operator=(const MoveToRightSideMessage& other) = default;
	// Destructor
	~MoveToRightSideMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10059;

	int floor = 0;
};

#endif