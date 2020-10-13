#ifndef GAMEACTIONFIGHTMARKCELLSMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTMARKCELLSMESSAGE_MESSAGE_H

#include "AbstractGameActionMessage.h"

#include "GameActionMark.h"

class GameActionFightMarkCellsMessage : public AbstractGameActionMessage {
public:
	// Constructor
	GameActionFightMarkCellsMessage() {};
	// Copy constructor
	GameActionFightMarkCellsMessage(const GameActionFightMarkCellsMessage& other) = default;

	// Copy operator
	GameActionFightMarkCellsMessage& operator=(const GameActionFightMarkCellsMessage& other) = default;
	// Destructor
	~GameActionFightMarkCellsMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 7743;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	GameActionMark mark;
};

#endif