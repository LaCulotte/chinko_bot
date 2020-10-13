#ifndef GAMECONTEXTCREATEREQUESTMESSAGE_MESSAGE_H
#define GAMECONTEXTCREATEREQUESTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameContextCreateRequestMessage : public PrefixedMessage {
public:
	// Constructor
	GameContextCreateRequestMessage() {};
	// Copy constructor
	GameContextCreateRequestMessage(const GameContextCreateRequestMessage& other) = default;

	// Copy operator
	GameContextCreateRequestMessage& operator=(const GameContextCreateRequestMessage& other) = default;
	// Destructor
	~GameContextCreateRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 7493;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override{ return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override{ return true; };

};

#endif