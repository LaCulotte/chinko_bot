#ifndef SELECTEDSERVERDATAEXTENDEDMESSAGE_MESSAGE_H
#define SELECTEDSERVERDATAEXTENDEDMESSAGE_MESSAGE_H

#include "SelectedServerDataMessage.h"

#include "GameServerInformations.h"

class SelectedServerDataExtendedMessage : public SelectedServerDataMessage {
public:
	// Constructor
	SelectedServerDataExtendedMessage() {};
	// Copy constructor
	SelectedServerDataExtendedMessage(const SelectedServerDataExtendedMessage& other) = default;

	// Copy operator
	SelectedServerDataExtendedMessage& operator=(const SelectedServerDataExtendedMessage& other) = default;
	// Destructor
	~SelectedServerDataExtendedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 2106;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<GameServerInformations> servers;
};

#endif