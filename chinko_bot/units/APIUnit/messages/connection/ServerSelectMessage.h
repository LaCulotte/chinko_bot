#ifndef SERVERSELECT_MESSAGE
#define SERVERSELECT_MESSAGE

#include "PrefixedMessage.h"

class ServerSelectMessage : public PrefixedMessage {
public : 
    // Constructor
    ServerSelectMessage() {};
    // Constructor with server's id initialization
    ServerSelectMessage(int id) { this->id = id; }
    // Copy constructor
    ServerSelectMessage(const ServerSelectMessage& other) = default;

    // Copy operator
    ServerSelectMessage& operator=(const ServerSelectMessage& other) = default;
    // Destructor
    ~ServerSelectMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 11011;

    // Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { id = input->readInt(); return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { output->writeInt(id); return true; };

    // Selected server's id
    int id;
};

#endif