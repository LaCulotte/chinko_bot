#ifndef SERVERSELECTED_MESSAGE_H
#define SERVERSELECTED_MESSAGE_H

#include "PrefixedMessage.h"

class ServerSelectedMessage : public PrefixedMessage {
public : 
    // Constructor
    ServerSelectedMessage() {};
    // Constructor with server's id initialization
    ServerSelectedMessage(int id) { this->id = id; }
    // Copy constructor
    ServerSelectedMessage(const ServerSelectedMessage& other) = default;

    // Copy operator
    ServerSelectedMessage& operator=(const ServerSelectedMessage& other) = default;
    // Destructor
    ~ServerSelectedMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 11011;

    // Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { id = input->readVarShort(); return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { output->writeVarShort(id); return true; };

    // Selected server's id
    int id;
};

#endif