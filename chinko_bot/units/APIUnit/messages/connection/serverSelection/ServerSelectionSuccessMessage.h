#ifndef SERVERSELECTION_SUCCESS_MESSAGE_H
#define SERVERSELECTION_SUCCESS_MESSAGE_H

#include "PrefixedMessage.h"

// Character selection was successful
class ServerSelectionSuccessMessage : public PrefixedMessage {
public : 
    // Constructor
    ServerSelectionSuccessMessage() {};
    // Constructor with server's id initialization
    ServerSelectionSuccessMessage(int id) { this->id = id; }
    // Copy constructor
    ServerSelectionSuccessMessage(const ServerSelectionSuccessMessage& other) = default;

    // Copy operator
    ServerSelectionSuccessMessage& operator=(const ServerSelectionSuccessMessage& other) = default;
    // Destructor
    ~ServerSelectionSuccessMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 11012;

    // Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { id = input->readVarShort(); return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { output->writeVarShort(id); return true; };

    // Selected server's id
    int id;
};

#endif