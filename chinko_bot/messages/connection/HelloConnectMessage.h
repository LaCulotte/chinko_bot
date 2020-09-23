#ifndef HELLOCONNECTMESSAGE_MESSAGE_H
#define HELLOCONNECTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class HelloConnectMessage : public PrefixedMessage {
public:
	// Constructor
	HelloConnectMessage() {};
	// Copy constructor
	HelloConnectMessage(const HelloConnectMessage& other) = default;

	// Copy operator
	HelloConnectMessage& operator=(const HelloConnectMessage& other) = default;
	// Destructor
	~HelloConnectMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 1251;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<char> key;
	string salt;
};

#endif