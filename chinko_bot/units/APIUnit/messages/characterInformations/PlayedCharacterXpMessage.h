#ifndef PLAYEDCHARACTER_XP_MESSAGE_H
#define PLAYEDCHARACTER_XP_MESSAGE_H

#include "PrefixedMessage.h"

// Bot's character update : updates character's xp count
class PlayedCharacterXpMessage : public PrefixedMessage {
public:
	// Constructor
	PlayedCharacterXpMessage() {};
	// Copy constructor
	PlayedCharacterXpMessage(const PlayedCharacterXpMessage& other) = default;

	// Copy operator
	PlayedCharacterXpMessage& operator=(const PlayedCharacterXpMessage& other) = default;
	// Destructor
	~PlayedCharacterXpMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11031;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t xp;
	uint64_t xpLevelFloor;
	uint64_t xpNextLevelFloor;
};

#endif