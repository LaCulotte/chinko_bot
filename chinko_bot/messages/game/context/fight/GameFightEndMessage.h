#ifndef GAMEFIGHTENDMESSAGE_MESSAGE_H
#define GAMEFIGHTENDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "NamedPartyTeamWithOutcome.h"
#include "FightResultListEntry.h"

#include "NetworkTypeHandler.h"

class GameFightEndMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightEndMessage() {};
	// Copy constructor
	GameFightEndMessage(const GameFightEndMessage& other) = default;

	// Copy operator
	GameFightEndMessage& operator=(const GameFightEndMessage& other) = default;
	// Destructor
	~GameFightEndMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 1090;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<NamedPartyTeamWithOutcome> namedPartyTeamsOutcomes;
	vector<sp<FightResultListEntry>> results;
	int lootShareLimitMalus = 0;
	int rewardRate = 0;
	int duration = 0;
};

#endif