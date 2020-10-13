#ifndef GAMECONTEXTREMOVEELEMENTMESSAGE_MESSAGE_H
#define GAMECONTEXTREMOVEELEMENTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class GameContextRemoveElementMessage : public PrefixedMessage {
public:
	// Constructor
	GameContextRemoveElementMessage() {};
	// Copy constructor
	GameContextRemoveElementMessage(const GameContextRemoveElementMessage& other) = default;

	// Copy operator
	GameContextRemoveElementMessage& operator=(const GameContextRemoveElementMessage& other) = default;
	// Destructor
	~GameContextRemoveElementMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 52;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double id = 0;
};

#endif