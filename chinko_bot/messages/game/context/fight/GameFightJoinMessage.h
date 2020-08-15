#ifndef GAMEFIGHTJOINMESSAGE_MESSAGE_H
#define GAMEFIGHTJOINMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameFightJoinMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightJoinMessage() {};
	// Copy constructor
	GameFightJoinMessage(const GameFightJoinMessage& other) = default;

	// Copy operator
	GameFightJoinMessage& operator=(const GameFightJoinMessage& other) = default;
	// Destructor
	~GameFightJoinMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 702;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int fightType = 0;
	int timeMaxBeforeFightStart = 0;
	bool isFightStarted = false;
	bool canSayReady = false;
	bool canBeCancelled = false;
	bool isTeamPhase = false;
};

#endif