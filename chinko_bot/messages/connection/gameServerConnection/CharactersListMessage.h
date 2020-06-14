#ifndef CHARACTERSLIST_MESSAGE_H
#define CHARACTERSLIST_MESSAGE_H

#include "BasicCharactersListMessage.h"

class CharactersListMessage : public BasicCharactersListMessage {
public: 
	// Constructor
	CharactersListMessage() {};
	// Constructor with hasStartupActions initialization
	CharactersListMessage(bool hasStartypActions) { this->hasStartupActions = hasStartupActions; };
	// Copy constructor
	CharactersListMessage(const CharactersListMessage& other) = default;

	// Copy operator
	CharactersListMessage& operator=(const CharactersListMessage& other) = default;
	// Destructor
	~CharactersListMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 151;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool hasStartupActions = false;

};

#endif