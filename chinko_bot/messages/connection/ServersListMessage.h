#ifndef SERVERSLISTMESSAGE_MESSAGE_H
#define SERVERSLISTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "GameServerInformations.h"

class ServersListMessage : public PrefixedMessage {
public:
	// Constructor
	ServersListMessage() {};
	// Copy constructor
	ServersListMessage(const ServersListMessage& other) = default;

	// Copy operator
	ServersListMessage& operator=(const ServersListMessage& other) = default;
	// Destructor
	~ServersListMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 8688;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool canCreateNewCharacter = false;
	vector<GameServerInformations> servers;
	int alreadyConnectedToServerId = 0;
};

#endif