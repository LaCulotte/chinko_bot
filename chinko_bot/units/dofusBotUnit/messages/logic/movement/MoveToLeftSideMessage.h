#ifndef MOVETOLEFTSIDE_MESSAGE_H
#define MOVETOLEFTSIDE_MESSAGE_H

#include "Message.h"

// Requests to move to the left side of the map
class MoveToLeftSideMessage : public Message {
public: 
	// Constructor
	MoveToLeftSideMessage() {};
	// Constructor with floor initialization
	MoveToLeftSideMessage(int floor) { this->floor = floor; };
	// Copy constructor
	MoveToLeftSideMessage(const MoveToLeftSideMessage& other) = default;

	// Copy operator
	MoveToLeftSideMessage& operator=(const MoveToLeftSideMessage& other) = default;
	// Destructor
	~MoveToLeftSideMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10058;

	int floor = 0;
};

#endif