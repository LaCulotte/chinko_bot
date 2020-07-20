#ifndef ALMANACHCALENDARDATEMESSAGE_MESSAGE_H
#define ALMANACHCALENDARDATEMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class AlmanachCalendarDateMessage : public PrefixedMessage {
public:
	// Constructor
	AlmanachCalendarDateMessage() {};
	// Copy constructor
	AlmanachCalendarDateMessage(const AlmanachCalendarDateMessage& other) = default;

	// Copy operator
	AlmanachCalendarDateMessage& operator=(const AlmanachCalendarDateMessage& other) = default;
	// Destructor
	~AlmanachCalendarDateMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 6341;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int date = 0;
};

#endif