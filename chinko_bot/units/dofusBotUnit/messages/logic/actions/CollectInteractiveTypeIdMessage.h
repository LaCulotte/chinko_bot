#ifndef COLLECTINTERACTIVETYPEID_MESSAGE_H
#define COLLECTINTERACTIVETYPEID_MESSAGE_H

#include "Message.h"

// Request for an interactive type collection
class CollectInteractiveTypeIdMessage : public Message {
public: 
	// Constructor
	CollectInteractiveTypeIdMessage() {};
	// Constructor with elementTypeId initialization
	CollectInteractiveTypeIdMessage(int elementTypeId) { this->elementTypeId = elementTypeId; };
	// Copy constructor
	CollectInteractiveTypeIdMessage(const CollectInteractiveTypeIdMessage& other) = default;

	// Copy operator
	CollectInteractiveTypeIdMessage& operator=(const CollectInteractiveTypeIdMessage& other) = default;
	// Destructor
	~CollectInteractiveTypeIdMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10080;

    int elementTypeId = 0;
};

#endif