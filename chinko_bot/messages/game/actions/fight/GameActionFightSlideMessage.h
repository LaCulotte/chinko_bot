#ifndef GAMEACTIONFIGHTSLIDEMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTSLIDEMESSAGE_MESSAGE_H

#include "AbstractGameActionMessage.h"


class GameActionFightSlideMessage : public AbstractGameActionMessage {
public:
	// Constructor
	GameActionFightSlideMessage() {};
	// Copy constructor
	GameActionFightSlideMessage(const GameActionFightSlideMessage& other) = default;

	// Copy operator
	GameActionFightSlideMessage& operator=(const GameActionFightSlideMessage& other) = default;
	// Destructor
	~GameActionFightSlideMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9185;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int endCellId = 0;
	int startCellId = 0;
	double targetId = 0;
};

#endif