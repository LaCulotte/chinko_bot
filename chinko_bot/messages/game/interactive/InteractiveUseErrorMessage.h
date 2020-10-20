#ifndef INTERACTIVEUSEERRORMESSAGE_MESSAGE_H
#define INTERACTIVEUSEERRORMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class InteractiveUseErrorMessage : public PrefixedMessage {
public:
	// Constructor
	InteractiveUseErrorMessage() {};
	// Copy constructor
	InteractiveUseErrorMessage(const InteractiveUseErrorMessage& other) = default;

	// Copy operator
	InteractiveUseErrorMessage& operator=(const InteractiveUseErrorMessage& other) = default;
	// Destructor
	~InteractiveUseErrorMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 9202;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int skillInstanceUid = 0;
	int elemId = 0;
};

#endif