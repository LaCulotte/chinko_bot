#ifndef MAPINFORMATIONSREQUESTMESSAGE_MESSAGE_H
#define MAPINFORMATIONSREQUESTMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"


class MapInformationsRequestMessage : public PrefixedMessage {
public:
	// Constructor
	MapInformationsRequestMessage() {};
	// Copy constructor
	MapInformationsRequestMessage(const MapInformationsRequestMessage& other) = default;

	// Copy operator
	MapInformationsRequestMessage& operator=(const MapInformationsRequestMessage& other) = default;
	// Destructor
	~MapInformationsRequestMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 7834;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double mapId = 0;
};

#endif