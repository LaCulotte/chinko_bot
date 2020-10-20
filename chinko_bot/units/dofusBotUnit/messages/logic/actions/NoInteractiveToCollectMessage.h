#ifndef NOINTERACTIVETOCOLLECT_MESSAGE_H
#define NOINTERACTIVETOCOLLECT_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class NoInteractiveToCollectMessage : public Message {
public: 
	// Constructor
	NoInteractiveToCollectMessage() {};
	// Constructor with elementTypeId initialization
	NoInteractiveToCollectMessage(int elementTypeId) { this->elementTypeId = elementTypeId; };
	// Copy constructor
	NoInteractiveToCollectMessage(const NoInteractiveToCollectMessage& other) = default;

	// Copy operator
	NoInteractiveToCollectMessage& operator=(const NoInteractiveToCollectMessage& other) = default;
	// Destructor
	~NoInteractiveToCollectMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10083;

    int elementTypeId = 0;
};

#endif