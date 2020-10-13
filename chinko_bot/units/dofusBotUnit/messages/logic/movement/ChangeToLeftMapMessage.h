#ifndef CHANGETOLEFTMAP_MESSAGE_H
#define CHANGETOLEFTMAP_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
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