#ifndef AUTHENTIFICATION_SUCCESS_MESSAGE_H
#define AUTHENTIFICATION_SUCCESS_MESSAGE_H

#include "PrefixedMessage.h"


class AuthentificationSuccessMessage : public PrefixedMessage {
public:
	// Constructor
	AuthentificationSuccessMessage() {};
	// Copy constructor
	AuthentificationSuccessMessage(const AuthentificationSuccessMessage& other) = default;

	// Copy operator
	AuthentificationSuccessMessage& operator=(const AuthentificationSuccessMessage& other) = default;
	// Destructor
	~AuthentificationSuccessMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 11004;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override{ return true; };
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override{ return true; };

};


#endif