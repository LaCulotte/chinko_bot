#ifndef GAMEACTIONFIGHTCLOSECOMBATMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTCLOSECOMBATMESSAGE_MESSAGE_H

#include "AbstractGameActionFightTargetedAbilityMessage.h"


class GameActionFightCloseCombatMessage : public AbstractGameActionFightTargetedAbilityMessage {
public:
	// Constructor
	GameActionFightCloseCombatMessage() {};
	// Copy constructor
	GameActionFightCloseCombatMessage(const GameActionFightCloseCombatMessage& other) = default;

	// Copy operator
	GameActionFightCloseCombatMessage& operator=(const GameActionFightCloseCombatMessage& other) = default;
	// Destructor
	~GameActionFightCloseCombatMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 2232;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int weaponGenericId = 0;
};

#endif