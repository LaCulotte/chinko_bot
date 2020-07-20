#ifndef CHARACTERSELECTEDERRORMESSAGE_MESSAGE_H
#define CHARACTERSELECTEDERRORMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class CharacterSelectedErrorMessage : public PrefixedMessage {
public:
	// Constructor
	CharacterSelectedErrorMessage() {};
	// Copy constructor
	CharacterSelectedErrorMessage(const CharacterSelectedErrorMessage& other) = default;

	// Copy operator
	CharacterSelectedErrorMessage& operator=(const CharacterSelectedErrorMessage& other) = default;
	// Destructor
	~CharacterSelectedErrorMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5836;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override{ return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override{ return true; };

};

#endif