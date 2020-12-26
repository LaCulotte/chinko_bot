#ifndef GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE_MESSAGE_H

#include "AbstractGameActionMessage.h"


class GameActionFightPointsVariationMessage : public AbstractGameActionMessage {
public:
	// Constructor
	GameActionFightPointsVariationMessage() {};
	// Copy constructor
	GameActionFightPointsVariationMessage(const GameActionFightPointsVariationMessage& other) = default;

	// Copy operator
	GameActionFightPointsVariationMessage& operator=(const GameActionFightPointsVariationMessage& other) = default;
	// Destructor
	~GameActionFightPointsVariationMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 8093;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double targetId = 0;
	int delta = 0;
};

#endif