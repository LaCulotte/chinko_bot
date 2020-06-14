#ifndef CHARACTERSLISTREQUEST_MESSAGE_H
#define CHARACTERSLISTREQUEST_MESSAGE_H

#include "PrefixedMessage.h"

class CharactersListRequestMessage : public PrefixedMessage {
public: 
	// Constructor
	CharactersListRequestMessage() {};
	// Copy constructor
	CharactersListRequestMessage(const CharactersListRequestMessage& other) = default;

	// Copy operator
	CharactersListRequestMessage& operator=(const CharactersListRequestMessage& other) = default;
	// Destructor
	~CharactersListRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 150;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };


};

#endif