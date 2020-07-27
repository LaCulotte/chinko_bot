#ifndef CHANGETODOWNMAP_MESSAGE_H
#define CHANGETODOWNMAP_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class ChangeToDownMapMessage : public Message {
public: 
	// Constructor
	ChangeToDownMapMessage() {};
	// Copy constructor
	ChangeToDownMapMessage(const ChangeToDownMapMessage& other) = default;

	// Copy operator
	ChangeToDownMapMessage& operator=(const ChangeToDownMapMessage& other) = default;
	// Destructor
	~ChangeToDownMapMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 652;
};

#endif