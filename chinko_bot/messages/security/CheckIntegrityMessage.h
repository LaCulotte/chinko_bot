#ifndef CHECKINTEGRITYMESSAGE_MESSAGE_H
#define CHECKINTEGRITYMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class CheckIntegrityMessage : public PrefixedMessage {
public:
	// Constructor
	CheckIntegrityMessage() {};
	// Copy constructor
	CheckIntegrityMessage(const CheckIntegrityMessage& other) = default;

	// Copy operator
	CheckIntegrityMessage& operator=(const CheckIntegrityMessage& other) = default;
	// Destructor
	~CheckIntegrityMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 6372;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	// vector<int> data;
};

#endif