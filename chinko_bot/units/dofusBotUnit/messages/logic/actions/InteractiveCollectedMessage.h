#ifndef INTERACTIVECOLLECTED_MESSAGE_H
#define INTERACTIVECOLLECTED_MESSAGE_H

#include "Message.h"

// Notify that an interactive has been collected
class InteractiveCollectedMessage : public Message {
public: 
	// Constructor
	InteractiveCollectedMessage() {};
	// Constructor with elementTypeId initialization
	InteractiveCollectedMessage(int elementTypeId) { this->elementTypeId = elementTypeId; };
	// Copy constructor
	InteractiveCollectedMessage(const InteractiveCollectedMessage& other) = default;

	// Copy operator
	InteractiveCollectedMessage& operator=(const InteractiveCollectedMessage& other) = default;
	// Destructor
	~InteractiveCollectedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10081;

    int elementTypeId = 0;
};

#endif