#ifndef SERVERSELECTION_FAILURE_MESSAGE_H
#define SERVERSELECTION_FAILURE_MESSAGE_H

#include "PrefixedMessage.h"

class ServerSelectionFailureMessage : public PrefixedMessage {
public : 
    // Constructor
    ServerSelectionFailureMessage() {};
    // Constructor with server selection error initialization
    ServerSelectionFailureMessage(int error) { this->error = error; }
    // Copy constructor
    ServerSelectionFailureMessage(const ServerSelectionFailureMessage& other) = default;

    // Copy operator
    ServerSelectionFailureMessage& operator=(const ServerSelectionFailureMessage& other) = default;
    // Destructor
    ~ServerSelectionFailureMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 11013;

    // Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { error = input->readByte(); return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { output->writeByte(error); return true; };

    // Error id
    int error;
};

#endif