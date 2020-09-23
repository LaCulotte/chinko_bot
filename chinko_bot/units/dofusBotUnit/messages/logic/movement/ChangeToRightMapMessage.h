#ifndef CHANGETORIGHTMAP_MESSAGE_H
#define CHANGETORIGHTMAP_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class ChangeToRightMapMessage : public Message {
public: 
	// Constructor
	ChangeToRightMapMessage() {};
	// Copy constructor
	ChangeToRightMapMessage(const ChangeToRightMapMessage& other) = default;

	// Copy operator
	ChangeToRightMapMessage& operator=(const ChangeToRightMapMessage& other) = default;
	// Destructor
	~ChangeToRightMapMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10051;
};

#endif