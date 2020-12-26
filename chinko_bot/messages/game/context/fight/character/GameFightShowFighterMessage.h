#ifndef GAMEFIGHTSHOWFIGHTERMESSAGE_MESSAGE_H
#define GAMEFIGHTSHOWFIGHTERMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "GameFightFighterInformations.h"

#include "NetworkTypeHandler.h"

class GameFightShowFighterMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightShowFighterMessage() {};
	// Copy constructor
	GameFightShowFighterMessage(const GameFightShowFighterMessage& other) = default;

	// Copy operator
	GameFightShowFighterMessage& operator=(const GameFightShowFighterMessage& other) = default;
	// Destructor
	~GameFightShowFighterMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 4483;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	sp<GameFightFighterInformations> informations;
};

#endif