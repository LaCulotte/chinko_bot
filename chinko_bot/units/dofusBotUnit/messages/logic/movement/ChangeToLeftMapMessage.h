#ifndef CHANGETOLEFTMAP_MESSAGE_H
#define CHANGETOLEFTMAP_MESSAGE_H

#include "Message.h"

// Requests the change to the left map
class ChangeToLeftMapMessage : public Message {
public: 
	// Constructor
	ChangeToLeftMapMessage() {};
	// Constructor with floor initialization
	ChangeToLeftMapMessage(int floor) { this->floor = floor; };
	// Copy constructor
	ChangeToLeftMapMessage(const ChangeToLeftMapMessage& other) = default;

	// Copy operator
	ChangeToLeftMapMessage& operator=(const ChangeToLeftMapMessage& other) = default;
	// Destructor
	~ChangeToLeftMapMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10053;

	int floor = 0;
};

#endif