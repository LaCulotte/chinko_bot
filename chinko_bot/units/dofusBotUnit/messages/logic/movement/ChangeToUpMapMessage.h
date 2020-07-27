#ifndef CHANGETOUPMAP_MESSAGE_H
#define CHANGETOUPMAP_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class ChangeToUpMapMessage : public Message {
public: 
	// Constructor
	ChangeToUpMapMessage() {};
	// Copy constructor
	ChangeToUpMapMessage(const ChangeToUpMapMessage& other) = default;

	// Copy operator
	ChangeToUpMapMessage& operator=(const ChangeToUpMapMessage& other) = default;
	// Destructor
	~ChangeToUpMapMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 654;
};

#endif