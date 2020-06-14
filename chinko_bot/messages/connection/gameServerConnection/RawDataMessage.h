#ifndef RAWDATA_MESSAGE_H
#define RAWDATA_MESSAGE_H

#include "PrefixedMessage.h"

class RawDataMessage : public PrefixedMessage {
public: 
	// Constructor
	RawDataMessage() {};
	// Constructor with content initialization
	RawDataMessage(vector<char> content) { this->content = content; };
	// Copy constructor
	RawDataMessage(const RawDataMessage& other) = default;

	// Copy operator
	RawDataMessage& operator=(const RawDataMessage& other) = default;
	// Destructor
	~RawDataMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 6253;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<char> content;

};

#endif