#ifndef CLIENTKEY_MESSAGE_H
#define CLIENTKEY_MESSAGE_H

#include "PrefixedMessage.h"

class ClientKeyMessage : public PrefixedMessage {
public: 
	// Constructor
	ClientKeyMessage() {};
	// Constructor with flash key initialization
	ClientKeyMessage(string flashKey) { this->flashKey = flashKey; };
	// Copy constructor
	ClientKeyMessage(const ClientKeyMessage& other) = default;

	// Copy operator
	ClientKeyMessage& operator=(const ClientKeyMessage& other) = default;
	// Destructor
	~ClientKeyMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 5607;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string flashKey = "GGYo2G8nhIdGynhdd8#01";

};

#endif