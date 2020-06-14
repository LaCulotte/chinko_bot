#ifndef CHARACTERSELECTION_MESSAGE_H
#define CHARACTERSELECTION_MESSAGE_H

#include "PrefixedMessage.h"

class CharacterSelectionMessage : public PrefixedMessage {
public: 
	// Constructor
	CharacterSelectionMessage() {};
	// Constructor with id initialization
	CharacterSelectionMessage(uint64_t id) { this->id = id; };
	// Copy constructor
	CharacterSelectionMessage(const CharacterSelectionMessage& other) = default;

	// Copy operator
	CharacterSelectionMessage& operator=(const CharacterSelectionMessage& other) = default;
	// Destructor
	~CharacterSelectionMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 152;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t id;

};

#endif