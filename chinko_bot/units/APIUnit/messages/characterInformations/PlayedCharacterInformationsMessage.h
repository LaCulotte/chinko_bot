#ifndef PLAYEDCHARACTER_INFORMATIONS_MESSAGE_H
#define PLAYEDCHARACTER_INFORMATIONS_MESSAGE_H

#include "PrefixedMessage.h"

#include "PlayedCharacterInformations.h"

// Bot's character informations
class PlayedCharacterInformationsMessage : public PrefixedMessage {
public:
	// Constructor
	PlayedCharacterInformationsMessage() {};
	// Constructor with infos initialization
	PlayedCharacterInformationsMessage(sp<PlayedCharacterInformations> infos) { this->infos = infos; };
	// Copy constructor
	PlayedCharacterInformationsMessage(const PlayedCharacterInformationsMessage& other) = default;

	// Copy operator
	PlayedCharacterInformationsMessage& operator=(const PlayedCharacterInformationsMessage& other) = default;
	// Destructor
	~PlayedCharacterInformationsMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11030;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override{ infos = make_shared<PlayedCharacterInformations>(); infos->deserialize(input); return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override{ if(!infos) return false; infos->serialize(output); return true; };

    sp<PlayedCharacterInformations> infos = nullptr;

};

#endif