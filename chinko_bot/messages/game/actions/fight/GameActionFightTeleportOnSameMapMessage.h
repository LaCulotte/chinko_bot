#ifndef GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE_MESSAGE_H

#include "AbstractGameActionMessage.h"


class GameActionFightTeleportOnSameMapMessage : public AbstractGameActionMessage {
public:
	// Constructor
	GameActionFightTeleportOnSameMapMessage() {};
	// Copy constructor
	GameActionFightTeleportOnSameMapMessage(const GameActionFightTeleportOnSameMapMessage& other) = default;

	// Copy operator
	GameActionFightTeleportOnSameMapMessage& operator=(const GameActionFightTeleportOnSameMapMessage& other) = default;
	// Destructor
	~GameActionFightTeleportOnSameMapMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 2698;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int cellId = 0;
	double targetId = 0;
};

#endif