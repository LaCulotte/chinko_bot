#ifndef GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWERMESSAGE_MESSAGE_H
#define GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWERMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameRolePlayPlayerFightFriendlyAnswerMessage : public PrefixedMessage {
public:
	// Constructor
	GameRolePlayPlayerFightFriendlyAnswerMessage() {};
	// Copy constructor
	GameRolePlayPlayerFightFriendlyAnswerMessage(const GameRolePlayPlayerFightFriendlyAnswerMessage& other) = default;

	// Copy operator
	GameRolePlayPlayerFightFriendlyAnswerMessage& operator=(const GameRolePlayPlayerFightFriendlyAnswerMessage& other) = default;
	// Destructor
	~GameRolePlayPlayerFightFriendlyAnswerMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9249;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool accept = false;
	int fightId = 0;
};

#endif