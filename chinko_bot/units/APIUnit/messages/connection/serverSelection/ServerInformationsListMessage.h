#ifndef SERVERINFORMATIONS_LIST_MESSAGE
#define SERVERINFORMATIONS_LIST_MESSAGE

#include "PrefixedMessage.h"
#include "ServerInformations.h"

// List of servers to select from
class ServerInformationsListMessage : public PrefixedMessage {
public : 
    // Constructor
    ServerInformationsListMessage() {};
    // Constructor with server list initialization
    ServerInformationsListMessage(vector<ServerInformations> servers) { this->servers = servers; }
    // Copy constructor
    ServerInformationsListMessage(const ServerInformationsListMessage& other) = default;

    // Copy operator
    ServerInformationsListMessage& operator=(const ServerInformationsListMessage& other) = default;
    // Destructor
    ~ServerInformationsListMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 11010;

    // Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

    vector<ServerInformations> servers;
};

#endif