#ifndef GAMEFIGHTREADYMESSAGE_MESSAGE_H
#define GAMEFIGHTREADYMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameFightReadyMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightReadyMessage() {};
	// Copy constructor
	GameFightReadyMessage(const GameFightReadyMessage& other) = default;

	// Copy operator
	GameFightReadyMessage& operator=(const GameFightReadyMessage& other) = default;
	// Destructor
	~GameFightReadyMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 4679;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool isReady = false;
};

#endif