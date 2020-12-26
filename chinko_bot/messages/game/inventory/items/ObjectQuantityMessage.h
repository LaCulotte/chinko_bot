#ifndef OBJECTQUANTITYMESSAGE_MESSAGE_H
#define OBJECTQUANTITYMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class ObjectQuantityMessage : public PrefixedMessage {
public:
	// Constructor
	ObjectQuantityMessage() {};
	// Copy constructor
	ObjectQuantityMessage(const ObjectQuantityMessage& other) = default;

	// Copy operator
	ObjectQuantityMessage& operator=(const ObjectQuantityMessage& other) = default;
	// Destructor
	~ObjectQuantityMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 229;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int origin = 0;
	int quantity = 0;
	int objectUID = 0;
};

#endif