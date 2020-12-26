#ifndef CLIENTKEYMESSAGE_MESSAGE_H
#define CLIENTKEYMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class ClientKeyMessage : public PrefixedMessage {
public:
	// Constructor
	ClientKeyMessage() {};
	// Constructor with withHash initialization
	ClientKeyMessage(bool withHash) { this->withHash = withHash; };
	// Copy constructor
	ClientKeyMessage(const ClientKeyMessage& other) = default;

	// Copy operator
	ClientKeyMessage& operator=(const ClientKeyMessage& other) = default;
	// Destructor
	~ClientKeyMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 3071;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string key = "GGYo2G8nhIdGynhdd8#01";
	bool withHash = false;
};

#endif