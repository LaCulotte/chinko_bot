#ifndef BOTCOMMAND_RETURNVALUES_MESSAGE_H
#define BOTCOMMAND_RETURNVALUES_MESSAGE_H

#include "Message.h"
#include "BotCommandReturnValues.h"

class BotCommandReturnValuesMessage : public Message {
public:
	// Constructor
	BotCommandReturnValuesMessage() {};
	// Constructor with returnValues initialization
	BotCommandReturnValuesMessage(sp<BotCommandReturnValues> returnValues) { this->returnValues = returnValues; };
	// Copy constructor
	BotCommandReturnValuesMessage(const BotCommandReturnValuesMessage& other) = default;

	// Copy operator
	BotCommandReturnValuesMessage& operator=(const BotCommandReturnValuesMessage& other) = default;
	// Destructor
	~BotCommandReturnValuesMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10108;

    sp<BotCommandReturnValues> returnValues;
};

#endif