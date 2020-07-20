#ifndef IDENTIFICATIONMESSAGE_MESSAGE_H
#define IDENTIFICATIONMESSAGE_MESSAGE_H

#include "PrefixedMessage.h"

#include "Version.h"

class IdentificationMessage : public PrefixedMessage {
public:
	// Constructor
	IdentificationMessage() {};
	// Copy constructor
	IdentificationMessage(const IdentificationMessage& other) = default;

	// Copy operator
	IdentificationMessage& operator=(const IdentificationMessage& other) = default;
	// Destructor
	~IdentificationMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 4;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t sessionOptionalSalt = 0;
	bool useLoginToken = false;
	vector<int> failedAttempts;
	bool useCertificate = false;
	bool autoconnect = false;
	int serverId = 0;
	vector<char> credentials;
	string lang = "fr";
	Version version = Version(2, 56, 0, 0, 0);
};

#endif