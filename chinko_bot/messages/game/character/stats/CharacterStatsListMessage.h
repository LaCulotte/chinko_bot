#ifndef CHARACTERSTATSLISTMESSAGE_MESSAGE_H
#define CHARACTERSTATSLISTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "CharacterCharacteristicsInformations.h"

class CharacterStatsListMessage : public PrefixedMessage {
public:
	// Constructor
	CharacterStatsListMessage() {};
	// Copy constructor
	CharacterStatsListMessage(const CharacterStatsListMessage& other) = default;

	// Copy operator
	CharacterStatsListMessage& operator=(const CharacterStatsListMessage& other) = default;
	// Destructor
	~CharacterStatsListMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 8872;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	CharacterCharacteristicsInformations stats;
};

#endif