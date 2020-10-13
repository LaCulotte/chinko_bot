#ifndef GAMEFIGHTTURNFINISHMESSAGE_MESSAGE_H
#define GAMEFIGHTTURNFINISHMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameFightTurnFinishMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightTurnFinishMessage() {};
	// Copy constructor
	GameFightTurnFinishMessage(const GameFightTurnFinishMessage& other) = default;

	// Copy operator
	GameFightTurnFinishMessage& operator=(const GameFightTurnFinishMessage& other) = default;
	// Destructor
	~GameFightTurnFinishMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 385;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool isAfk = false;
};

#endif