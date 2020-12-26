#ifndef GAMEFIGHTSYNCHRONIZEMESSAGE_MESSAGE_H
#define GAMEFIGHTSYNCHRONIZEMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "GameFightFighterInformations.h"

#include "NetworkTypeHandler.h"

class GameFightSynchronizeMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightSynchronizeMessage() {};
	// Copy constructor
	GameFightSynchronizeMessage(const GameFightSynchronizeMessage& other) = default;

	// Copy operator
	GameFightSynchronizeMessage& operator=(const GameFightSynchronizeMessage& other) = default;
	// Destructor
	~GameFightSynchronizeMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5218;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<sp<GameFightFighterInformations>> fighters;
};

#endif