#ifndef CHARACTERLEVELUPMESSAGE_MESSAGE_H
#define CHARACTERLEVELUPMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class CharacterLevelUpMessage : public PrefixedMessage {
public:
	// Constructor
	CharacterLevelUpMessage() {};
	// Copy constructor
	CharacterLevelUpMessage(const CharacterLevelUpMessage& other) = default;

	// Copy operator
	CharacterLevelUpMessage& operator=(const CharacterLevelUpMessage& other) = default;
	// Destructor
	~CharacterLevelUpMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 366;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int newLevel = 0;
};

#endif