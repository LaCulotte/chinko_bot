#ifndef SERVERSELECTION_LIST_MESSAGE
#define SERVERSELECTION_LIST_MESSAGE

#include "PrefixedMessage.h"
#include "ServerSelectInformations.h"

class ServerSelectionListMessage : public PrefixedMessage {
public : 
    // Constructor
    ServerSelectionListMessage() {};
    // Constructor with username and password initialization
    ServerSelectionListMessage(vector<ServerSelectInformations> servers) { this->servers = servers; }
    // Copy constructor
    ServerSelectionListMessage(const ServerSelectionListMessage& other) = default;

    // Copy operator
    ServerSelectionListMessage& operator=(const ServerSelectionListMessage& other) = default;
    // Destructor
    ~ServerSelectionListMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 11010;

    // Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

    vector<ServerSelectInformations> servers;
};

#endif