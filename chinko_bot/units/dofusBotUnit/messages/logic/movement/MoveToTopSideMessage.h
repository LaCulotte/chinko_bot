#ifndef MOVETOTOPSIDE_MESSAGE_H
#define MOVETOTOPSIDE_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class MoveToTopSideMessage : public Message {
public: 
	// Constructor
	MoveToTopSideMessage() {};
	// Constructor with floor initialization
	MoveToTopSideMessage(int floor) { this->floor = floor; };
	// Copy constructor
	MoveToTopSideMessage(const MoveToTopSideMessage& other) = default;

	// Copy operator
	MoveToTopSideMessage& operator=(const MoveToTopSideMessage& other) = default;
	// Destructor
	~MoveToTopSideMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10060;

	int floor = 0;
};

#endif