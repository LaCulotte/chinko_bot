#ifndef API_AUTHENTIFICATIONSTATUS_MESSAGE_H
#define API_AUTHENTIFICATIONSTATUS_MESSAGE_H

#include "PrefixedMessage.h"

// Message that tells the client if the bot is already authentified/connected to a game server 
class APIAuthentificationStatusMessage : public PrefixedMessage {
public:
	// Constructor
	APIAuthentificationStatusMessage() {};
	// Constructor with authentification status initialization
	APIAuthentificationStatusMessage(bool authentified) { this->authentified = authentified; };
	// Copy constructor
	APIAuthentificationStatusMessage(const APIAuthentificationStatusMessage& other) = default;

	// Copy operator
	APIAuthentificationStatusMessage& operator=(const APIAuthentificationStatusMessage& other) = default;
	// Destructor
	~APIAuthentificationStatusMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11006;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { authentified = input->readBool(); return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { output->writeBool(authentified); return true; };

    bool authentified = false;
};


#endif