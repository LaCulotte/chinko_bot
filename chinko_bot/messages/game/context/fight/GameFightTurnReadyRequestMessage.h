#ifndef GAMEFIGHTTURNREADYREQUESTMESSAGE_MESSAGE_H
#define GAMEFIGHTTURNREADYREQUESTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameFightTurnReadyRequestMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightTurnReadyRequestMessage() {};
	// Copy constructor
	GameFightTurnReadyRequestMessage(const GameFightTurnReadyRequestMessage& other) = default;

	// Copy operator
	GameFightTurnReadyRequestMessage& operator=(const GameFightTurnReadyRequestMessage& other) = default;
	// Destructor
	~GameFightTurnReadyRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9173;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double id = 0;
};

#endif