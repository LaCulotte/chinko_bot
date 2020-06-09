#ifndef CREDENTIALSACKNOWLEDGEMENT_MESSAGE_H
#define CREDENTIALSACKNOWLEDGEMENT_MESSAGE_H

#include "PrefixedMessage.h"

class CredentialsAcknowledgementMessage : public PrefixedMessage {
public: 
	// Constructor
	CredentialsAcknowledgementMessage() {};
	// Copy constructor
	CredentialsAcknowledgementMessage(const CredentialsAcknowledgementMessage& other) = default;

	// Copy operator
	CredentialsAcknowledgementMessage& operator=(const CredentialsAcknowledgementMessage& other) = default;
	// Destructor
	~CredentialsAcknowledgementMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 6314;


};

#endif