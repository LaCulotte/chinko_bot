#ifndef CHATABSTRACTSERVERMESSAGE_MESSAGE_H
#define CHATABSTRACTSERVERMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class ChatAbstractServerMessage : public PrefixedMessage {
public:
	// Constructor
	ChatAbstractServerMessage() {};
	// Copy constructor
	ChatAbstractServerMessage(const ChatAbstractServerMessage& other) = default;

	// Copy operator
	ChatAbstractServerMessage& operator=(const ChatAbstractServerMessage& other) = default;
	// Destructor
	~ChatAbstractServerMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 880;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string fingerprint;
	int timestamp = 0;
	string content;
	int channel = 0;
};

#endif