#ifndef GAMEROLEPLAYSHOWACTORMESSAGE_MESSAGE_H
#define GAMEROLEPLAYSHOWACTORMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "GameRolePlayActorInformations.h"

#include "NetworkTypeHandler.h"

class GameRolePlayShowActorMessage : public PrefixedMessage {
public:
	// Constructor
	GameRolePlayShowActorMessage() {};
	// Copy constructor
	GameRolePlayShowActorMessage(const GameRolePlayShowActorMessage& other) = default;

	// Copy operator
	GameRolePlayShowActorMessage& operator=(const GameRolePlayShowActorMessage& other) = default;
	// Destructor
	~GameRolePlayShowActorMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 6607;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	sp<GameRolePlayActorInformations> informations;
};

#endif