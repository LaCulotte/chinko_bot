#ifndef CHARACTERLOADINGCOMPLETE_MESSAGE_H
#define CHARACTERLOADINGCOMPLETE_MESSAGE_H

#include "PrefixedMessage.h"

class CharacterLoadingCompleteMessage : public PrefixedMessage {
public: 
	// Constructor
	CharacterLoadingCompleteMessage() {};
	// Copy constructor
	CharacterLoadingCompleteMessage(const CharacterLoadingCompleteMessage& other) = default;

	// Copy operator
	CharacterLoadingCompleteMessage& operator=(const CharacterLoadingCompleteMessage& other) = default;
	// Destructor
	~CharacterLoadingCompleteMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 6471;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };


};

#endif