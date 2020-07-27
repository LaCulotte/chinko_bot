#ifndef CHANGEMAPMESSAGE_MESSAGE_H
#define CHANGEMAPMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class ChangeMapMessage : public PrefixedMessage {
public:
	// Constructor
	ChangeMapMessage() {};
	// Copy constructor
	ChangeMapMessage(const ChangeMapMessage& other) = default;

	// Copy operator
	ChangeMapMessage& operator=(const ChangeMapMessage& other) = default;
	// Destructor
	~ChangeMapMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 221;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool autopilot = false;
	double mapId = 0;
};

#endif