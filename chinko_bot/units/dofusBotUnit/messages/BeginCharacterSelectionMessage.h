#ifndef BEGINCHARACTERSELECTION_MESSAGE_H
#define BEGINCHARACTERSELECTION_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class BeginCharacterSelectionMessage : public Message {
public: 
	// Constructor
	BeginCharacterSelectionMessage() {};
	// Copy constructor
	BeginCharacterSelectionMessage(const BeginCharacterSelectionMessage& other) = default;

	// Copy operator
	BeginCharacterSelectionMessage& operator=(const BeginCharacterSelectionMessage& other) = default;
	// Destructor
	~BeginCharacterSelectionMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 642;


};

#endif