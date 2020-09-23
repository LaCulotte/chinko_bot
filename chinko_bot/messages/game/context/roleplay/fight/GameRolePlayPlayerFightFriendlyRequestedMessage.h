#ifndef GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE_MESSAGE_H
#define GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameRolePlayPlayerFightFriendlyRequestedMessage : public PrefixedMessage {
public:
	// Constructor
	GameRolePlayPlayerFightFriendlyRequestedMessage() {};
	// Copy constructor
	GameRolePlayPlayerFightFriendlyRequestedMessage(const GameRolePlayPlayerFightFriendlyRequestedMessage& other) = default;

	// Copy operator
	GameRolePlayPlayerFightFriendlyRequestedMessage& operator=(const GameRolePlayPlayerFightFriendlyRequestedMessage& other) = default;
	// Destructor
	~GameRolePlayPlayerFightFriendlyRequestedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 8153;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t targetId = 0;
	uint64_t sourceId = 0;
	int fightId = 0;
};

#endif