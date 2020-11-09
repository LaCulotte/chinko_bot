#ifndef KAMASUPDATEMESSAGE_MESSAGE_H
#define KAMASUPDATEMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class KamasUpdateMessage : public PrefixedMessage {
public:
	// Constructor
	KamasUpdateMessage() {};
	// Copy constructor
	KamasUpdateMessage(const KamasUpdateMessage& other) = default;

	// Copy operator
	KamasUpdateMessage& operator=(const KamasUpdateMessage& other) = default;
	// Destructor
	~KamasUpdateMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 2022;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t kamasTotal = 0;
};

#endif