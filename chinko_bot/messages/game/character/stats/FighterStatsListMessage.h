#ifndef FIGHTERSTATSLISTMESSAGE_MESSAGE_H
#define FIGHTERSTATSLISTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "CharacterCharacteristicsInformations.h"

class FighterStatsListMessage : public PrefixedMessage {
public:
	// Constructor
	FighterStatsListMessage() {};
	// Copy constructor
	FighterStatsListMessage(const FighterStatsListMessage& other) = default;

	// Copy operator
	FighterStatsListMessage& operator=(const FighterStatsListMessage& other) = default;
	// Destructor
	~FighterStatsListMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 6334;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	CharacterCharacteristicsInformations stats;
};

#endif