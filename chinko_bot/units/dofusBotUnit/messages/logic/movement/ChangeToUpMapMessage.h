#ifndef CHANGETOUPMAP_MESSAGE_H
#define CHANGETOUPMAP_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class ChangeToUpMapMessage : public Message {
public: 
	// Constructor
	ChangeToUpMapMessage() {};
	// Constructor with floor initialization
	ChangeToUpMapMessage(int floor) { this->floor = floor; };
	// Copy constructor
	ChangeToUpMapMessage(const ChangeToUpMapMessage& other) = default;

	// Copy operator
	ChangeToUpMapMessage& operator=(const ChangeToUpMapMessage& other) = default;
	// Destructor
	~ChangeToUpMapMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10054;

	int floor = 0;
};

#endif