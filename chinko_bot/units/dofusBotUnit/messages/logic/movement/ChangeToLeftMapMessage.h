#ifndef CHANGETOLEFTMAP_MESSAGE_H
#define CHANGETOLEFTMAP_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class ChangeToLeftMapMessage : public Message {
public: 
	// Constructor
	ChangeToLeftMapMessage() {};
	// Copy constructor
	ChangeToLeftMapMessage(const ChangeToLeftMapMessage& other) = default;

	// Copy operator
	ChangeToLeftMapMessage& operator=(const ChangeToLeftMapMessage& other) = default;
	// Destructor
	~ChangeToLeftMapMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 653;
};

#endif