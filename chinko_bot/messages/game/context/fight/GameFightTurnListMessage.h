#ifndef GAMEFIGHTTURNLISTMESSAGE_MESSAGE_H
#define GAMEFIGHTTURNLISTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameFightTurnListMessage : public PrefixedMessage {
public:
	// Constructor
	GameFightTurnListMessage() {};
	// Copy constructor
	GameFightTurnListMessage(const GameFightTurnListMessage& other) = default;

	// Copy operator
	GameFightTurnListMessage& operator=(const GameFightTurnListMessage& other) = default;
	// Destructor
	~GameFightTurnListMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9365;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<double> deadsIds;
	vector<double> ids;
};

#endif