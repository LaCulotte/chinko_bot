#ifndef SELECTEDSERVERDATAMESSAGE_MESSAGE_H
#define SELECTEDSERVERDATAMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class SelectedServerDataMessage : public PrefixedMessage {
public:
	// Constructor
	SelectedServerDataMessage() {};
	// Copy constructor
	SelectedServerDataMessage(const SelectedServerDataMessage& other) = default;

	// Copy operator
	SelectedServerDataMessage& operator=(const SelectedServerDataMessage& other) = default;
	// Destructor
	~SelectedServerDataMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 7693;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<int> ticket;
	bool canCreateNewCharacter = false;
	vector<int> ports;
	string address;
	int serverId = 0;
};

#endif