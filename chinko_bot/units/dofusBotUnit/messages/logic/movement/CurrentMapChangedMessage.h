#ifndef CURRENTMAPCHANGED_MESSAGE_H
#define CURRENTMAPCHANGED_MESSAGE_H

#include "Message.h"

// Notify that the map has changed
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
	static const unsigned int protocolId = 10062;
};

#endif