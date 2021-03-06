#ifndef BASICCHARACTERSLISTMESSAGE_MESSAGE_H
#define BASICCHARACTERSLISTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "CharacterBaseInformations.h"

#include "NetworkTypeHandler.h"

class BasicCharactersListMessage : public PrefixedMessage {
public:
	// Constructor
	BasicCharactersListMessage() {};
	// Copy constructor
	BasicCharactersListMessage(const BasicCharactersListMessage& other) = default;

	// Copy operator
	BasicCharactersListMessage& operator=(const BasicCharactersListMessage& other) = default;
	// Destructor
	~BasicCharactersListMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9379;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<sp<CharacterBaseInformations>> characters;
};

#endif