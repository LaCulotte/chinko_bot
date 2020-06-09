#ifndef IDENTIFICATION_MESSAGE_H
#define IDENTIFICATION_MESSAGE_H

#include "PrefixedMessage.h"

struct Version {
	int major;
	int minor;
	int code;
	int build;
	int type;
};

class IdentificationMessage : public PrefixedMessage {
public: 
	// Constructor
	IdentificationMessage() {};
	// Constructor with credential initialization
	IdentificationMessage(string credentials) { this->credentials = credentials; };
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

	// Basic flags
	bool useToken = false;
	bool useCertificate = false;
	bool autoConnect = true;
	
	// Version
	Version version = {2, 55, 15, 0, 0};
	// Lang
	string lang = "fr";
	// Ciphered credentials
	string credentials;

	int serverId = 0;
	int sessionOptionalSalt = 0;
	vector<int> failedAttempts;

};

#endif