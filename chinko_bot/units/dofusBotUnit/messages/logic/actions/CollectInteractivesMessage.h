#ifndef COLLECTALLINTERACTIVES_MESSAGE_h
#define COLLECTALLINTERACTIVES_MESSAGE_h

#include "Message.h"

// Message to request the beginning of the character selection
class CollectInteractivesMessage : public Message {
public: 
	// Constructor
	CollectInteractivesMessage() {};
	// Constructor with interactiveTypeIds initialization
	CollectInteractivesMessage(vector<int> interactiveTypeIds) { this->interactiveTypeIds = interactiveTypeIds; };
	// Copy constructor
	CollectInteractivesMessage(const CollectInteractivesMessage& other) = default;

	// Copy operator
	CollectInteractivesMessage& operator=(const CollectInteractivesMessage& other) = default;
	// Destructor
	~CollectInteractivesMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10082;

	vector<int> interactiveTypeIds;
};

#endif