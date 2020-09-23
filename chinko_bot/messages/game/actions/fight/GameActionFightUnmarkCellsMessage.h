#ifndef GAMEACTIONFIGHTUNMARKCELLSMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTUNMARKCELLSMESSAGE_MESSAGE_H

#include "AbstractGameActionMessage.h"


class GameActionFightUnmarkCellsMessage : public AbstractGameActionMessage {
public:
	// Constructor
	GameActionFightUnmarkCellsMessage() {};
	// Copy constructor
	GameActionFightUnmarkCellsMessage(const GameActionFightUnmarkCellsMessage& other) = default;

	// Copy operator
	GameActionFightUnmarkCellsMessage& operator=(const GameActionFightUnmarkCellsMessage& other) = default;
	// Destructor
	~GameActionFightUnmarkCellsMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 4963;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int markId = 0;
};

#endif