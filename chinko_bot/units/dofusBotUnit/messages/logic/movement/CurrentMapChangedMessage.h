#ifndef CURRENTMAPCHANGED_MESSAGE_H
#define CURRENTMAPCHANGED_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class CurrentMapChangedMessage : public Message {
public: 
	// Constructor
	CurrentMapChangedMessage() {};
	// Copy constructor
	CurrentMapChangedMessage(const CurrentMapChangedMessage& other) = default;

	// Copy operator
	CurrentMapChangedMessage& operator=(const CurrentMapChangedMessage& other) = default;
	// Destructor
	~CurrentMapChangedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 662;
};

#endif