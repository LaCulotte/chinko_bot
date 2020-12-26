#ifndef SELECTEDSERVERREFUSEDMESSAGE_MESSAGE_H
#define SELECTEDSERVERREFUSEDMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class SelectedServerRefusedMessage : public PrefixedMessage {
public:
	// Constructor
	SelectedServerRefusedMessage() {};
	// Copy constructor
	SelectedServerRefusedMessage(const SelectedServerRefusedMessage& other) = default;

	// Copy operator
	SelectedServerRefusedMessage& operator=(const SelectedServerRefusedMessage& other) = default;
	// Destructor
	~SelectedServerRefusedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 8662;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int serverStatus = 1;
	int error = 1;
	int serverId = 0;
};

#endif