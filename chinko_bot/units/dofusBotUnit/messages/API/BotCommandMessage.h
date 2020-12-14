#ifndef BOTCOMMAND_MESSAGE_H
#define BOTCOMMAND_MESSAGE_H

#include "Message.h"
#include "BotCommand.h"

class BotCommandMessage : public Message {
public:
	// Constructor
	BotCommandMessage() {};
	// Constructor with command initialization
	BotCommandMessage(sp<BotCommand> command) { this->command = command; };
	// Copy constructor
	BotCommandMessage(const BotCommandMessage& other) = default;

	// Copy operator
	BotCommandMessage& operator=(const BotCommandMessage& other) = default;
	// Destructor
	~BotCommandMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10107;

    sp<BotCommand> command;
};

#endif