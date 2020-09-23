#ifndef GAMEFIGHTTURNREADYMESSAGE_MESSAGE_H
#define GAMEFIGHTTURNREADYMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameFightTurnReadyMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightTurnReadyMessage() {};
	// Copy constructor
	GameFightTurnReadyMessage(const GameFightTurnReadyMessage& other) = default;

	// Copy operator
	GameFightTurnReadyMessage& operator=(const GameFightTurnReadyMessage& other) = default;
	// Destructor
	~GameFightTurnReadyMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 765;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool isReady = false;
};

#endif