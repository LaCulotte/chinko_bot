#ifndef GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE_MESSAGE_H
#define GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameRolePlayAttackMonsterRequestMessage : public PrefixedMessage {
public:
	// Constructor
	GameRolePlayAttackMonsterRequestMessage() {};
	// Copy constructor
	GameRolePlayAttackMonsterRequestMessage(const GameRolePlayAttackMonsterRequestMessage& other) = default;

	// Copy operator
	GameRolePlayAttackMonsterRequestMessage& operator=(const GameRolePlayAttackMonsterRequestMessage& other) = default;
	// Destructor
	~GameRolePlayAttackMonsterRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 3866;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double monsterGroupId = 0;
};

#endif