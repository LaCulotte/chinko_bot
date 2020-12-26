#ifndef CHANGETODOWNMAP_MESSAGE_H
#define CHANGETODOWNMAP_MESSAGE_H

#include "Message.h"

// Requests the change to the down map
class ChangeToDownMapMessage : public Message {
public: 
	// Constructor
	ChangeToDownMapMessage() {};
	// Constructor with floor initialization
	ChangeToDownMapMessage(int floor) { this->floor = floor; };
	// Copy constructor
	ChangeToDownMapMessage(const ChangeToDownMapMessage& other) = default;

	// Copy operator
	ChangeToDownMapMessage& operator=(const ChangeToDownMapMessage& other) = default;
	// Destructor
	~ChangeToDownMapMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10052;

	int floor = 0;
};

#endif