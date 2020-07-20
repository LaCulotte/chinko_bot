#ifndef CURRENTMAPMESSAGE_MESSAGE_H
#define CURRENTMAPMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class CurrentMapMessage : public PrefixedMessage {
public:
	// Constructor
	CurrentMapMessage() {};
	// Copy constructor
	CurrentMapMessage(const CurrentMapMessage& other) = default;

	// Copy operator
	CurrentMapMessage& operator=(const CurrentMapMessage& other) = default;
	// Destructor
	~CurrentMapMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 220;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	string mapKey;
	double mapId = 0;
};

#endif