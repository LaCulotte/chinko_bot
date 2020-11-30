#ifndef PLAYEDCHARACTER_LEVEL_MESSAGE_H
#define PLAYEDCHARACTER_LEVEL_MESSAGE_H

#include "PrefixedMessage.h"

class PlayedCharacterLevelMessage : public PrefixedMessage {
public:
	// Constructor
	PlayedCharacterLevelMessage() {};
	// Copy constructor
	PlayedCharacterLevelMessage(const PlayedCharacterLevelMessage& other) = default;

	// Copy operator
	PlayedCharacterLevelMessage& operator=(const PlayedCharacterLevelMessage& other) = default;
	// Destructor
	~PlayedCharacterLevelMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11037;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { level = input->readByte(); return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { output->writeByte(level); return true; };

    int level;
};

#endif