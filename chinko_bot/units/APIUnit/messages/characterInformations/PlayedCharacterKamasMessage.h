#ifndef PLAYEDCHARACTER_KAMAS_MESSAGE_H
#define PLAYEDCHARACTER_KAMAS_MESSAGE_H

#include "PrefixedMessage.h"

// Bot's character update : updates character's kamas
class PlayedCharacterKamasMessage : public PrefixedMessage {
public:
	// Constructor
	PlayedCharacterKamasMessage() {};
	// Copy constructor
	PlayedCharacterKamasMessage(const PlayedCharacterKamasMessage& other) = default;

	// Copy operator
	PlayedCharacterKamasMessage& operator=(const PlayedCharacterKamasMessage& other) = default;
	// Destructor
	~PlayedCharacterKamasMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11033;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t kamas;
};

#endif