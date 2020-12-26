#ifndef SERVERSELECTIONMESSAGE_MESSAGE_H
#define SERVERSELECTIONMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class ServerSelectionMessage : public PrefixedMessage {
public:
	// Constructor
	ServerSelectionMessage() {};
	// Copy constructor
	ServerSelectionMessage(const ServerSelectionMessage& other) = default;

	// Copy operator
	ServerSelectionMessage& operator=(const ServerSelectionMessage& other) = default;
	// Destructor
	~ServerSelectionMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 2689;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int serverId = 0;
};

#endif