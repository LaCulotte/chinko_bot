#ifndef API_DISCONNECTED_MESSAGE_H
#define API_DISCONNECTED_MESSAGE_H

#include "Message.h"

// API has disconnected
class APIClientDisconnectedMessage : public Message {
public:
	// Constructor
	APIClientDisconnectedMessage() {};
	// Copy constructor
	APIClientDisconnectedMessage(const APIClientDisconnectedMessage& other) = default;

	// Copy operator
	APIClientDisconnectedMessage& operator=(const APIClientDisconnectedMessage& other) = default;
	// Destructor
	~APIClientDisconnectedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10103;
};

#endif