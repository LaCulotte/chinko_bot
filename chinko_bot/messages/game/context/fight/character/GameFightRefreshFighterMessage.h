#ifndef GAMEFIGHTREFRESHFIGHTERMESSAGE_MESSAGE_H
#define GAMEFIGHTREFRESHFIGHTERMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "GameContextActorInformations.h"

#include "NetworkTypeHandler.h"

class GameFightRefreshFighterMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightRefreshFighterMessage() {};
	// Copy constructor
	GameFightRefreshFighterMessage(const GameFightRefreshFighterMessage& other) = default;

	// Copy operator
	GameFightRefreshFighterMessage& operator=(const GameFightRefreshFighterMessage& other) = default;
	// Destructor
	~GameFightRefreshFighterMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 3511;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	sp<GameContextActorInformations> informations;
};

#endif