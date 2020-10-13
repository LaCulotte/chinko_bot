#ifndef CHATSERVERMESSAGE_MESSAGE_H
#define CHATSERVERMESSAGE_MESSAGE_H

#include "ChatAbstractServerMessage.h"


class ChatServerMessage : public ChatAbstractServerMessage {
public:
	// Constructor
	ChatServerMessage() {};
	// Copy constructor
	ChatServerMessage(const ChatServerMessage& other) = default;

	// Copy operator
	ChatServerMessage& operator=(const ChatServerMessage& other) = default;
	// Destructor
	~ChatServerMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5722;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int senderAccountId = 0;
	string prefix;
	string senderName;
	double senderId = 0;
};

#endif