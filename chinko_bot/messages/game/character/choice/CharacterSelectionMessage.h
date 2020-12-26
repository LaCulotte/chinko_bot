#ifndef CHARACTERSELECTIONMESSAGE_MESSAGE_H
#define CHARACTERSELECTIONMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class CharacterSelectionMessage : public PrefixedMessage {
public:
	// Constructor
	CharacterSelectionMessage() {};
	// Copy constructor
	CharacterSelectionMessage(const CharacterSelectionMessage& other) = default;

	// Copy operator
	CharacterSelectionMessage& operator=(const CharacterSelectionMessage& other) = default;
	// Destructor
	~CharacterSelectionMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 3151;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t id = 0;
};

#endif