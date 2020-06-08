#ifndef HELLOCONNECT_MESSAGE_H
#define HELLOCONNECT_MESSAGE_H

#include "PrefixedMessage.h"

class HelloConnectMessage : public PrefixedMessage {
public: 
	// Constructor
	HelloConnectMessage() {};
	// Constructor with salt and key initialisation
	HelloConnectMessage(string salt, char *key, int keyLength);
	// Copy constructor
	HelloConnectMessage(const HelloConnectMessage& other) = default;

	// Copy operator
	HelloConnectMessage& operator=(const HelloConnectMessage& other) = default;
	// Destructor
	~HelloConnectMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 3;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string salt;
	char *key;
	int keyLength;

};

#endif