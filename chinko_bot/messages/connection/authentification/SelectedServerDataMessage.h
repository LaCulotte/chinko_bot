#ifndef SELECTEDSERVERDATA_MESSAGE_H
#define SELECTEDSERVERDATA_MESSAGE_H

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
	static const unsigned int protocolId = 42;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int serverId;
	string address;
	vector<int> ports;

	bool canCreateNewCharacter;
	
	string ticket;

};

#endif