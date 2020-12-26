#ifndef GAMEFIGHTUPDATETEAMMESSAGE_MESSAGE_H
#define GAMEFIGHTUPDATETEAMMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "FightTeamInformations.h"

class GameFightUpdateTeamMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightUpdateTeamMessage() {};
	// Copy constructor
	GameFightUpdateTeamMessage(const GameFightUpdateTeamMessage& other) = default;

	// Copy operator
	GameFightUpdateTeamMessage& operator=(const GameFightUpdateTeamMessage& other) = default;
	// Destructor
	~GameFightUpdateTeamMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5570;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	FightTeamInformations team;
	int fightId = 0;
};

#endif