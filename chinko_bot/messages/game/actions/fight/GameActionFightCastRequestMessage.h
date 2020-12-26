#ifndef GAMEACTIONFIGHTCASTREQUESTMESSAGE_MESSAGE_H
#define GAMEACTIONFIGHTCASTREQUESTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameActionFightCastRequestMessage : public PrefixedMessage {
public:
	// Constructor
	GameActionFightCastRequestMessage() {};
	// Copy constructor
	GameActionFightCastRequestMessage(const GameActionFightCastRequestMessage& other) = default;

	// Copy operator
	GameActionFightCastRequestMessage& operator=(const GameActionFightCastRequestMessage& other) = default;
	// Destructor
	~GameActionFightCastRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 127;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int cellId = 0;
	int spellId = 0;
};

#endif