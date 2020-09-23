#ifndef GAMEACTIONFIGHTEXCHANGEPOSITIONSMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTEXCHANGEPOSITIONSMESSAGE_MESSAGE_H

#include "AbstractGameActionMessage.h"


class GameActionFightExchangePositionsMessage : public AbstractGameActionMessage {
public:
	// Constructor
	GameActionFightExchangePositionsMessage() {};
	// Copy constructor
	GameActionFightExchangePositionsMessage(const GameActionFightExchangePositionsMessage& other) = default;

	// Copy operator
	GameActionFightExchangePositionsMessage& operator=(const GameActionFightExchangePositionsMessage& other) = default;
	// Destructor
	~GameActionFightExchangePositionsMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 640;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int targetCellId = 0;
	int casterCellId = 0;
	double targetId = 0;
};

#endif