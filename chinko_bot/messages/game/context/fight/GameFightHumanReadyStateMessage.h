#ifndef GAMEFIGHTHUMANREADYSTATEMESSAGE_MESSAGE_H
#define GAMEFIGHTHUMANREADYSTATEMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameFightHumanReadyStateMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightHumanReadyStateMessage() {};
	// Copy constructor
	GameFightHumanReadyStateMessage(const GameFightHumanReadyStateMessage& other) = default;

	// Copy operator
	GameFightHumanReadyStateMessage& operator=(const GameFightHumanReadyStateMessage& other) = default;
	// Destructor
	~GameFightHumanReadyStateMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5755;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool isReady = false;
	uint64_t characterId = 0;
};

#endif