#ifndef READYBEGINTURNFIGHTACTION_MESSAGE_H
#define READYBEGINTURNFIGHTACTION_MESSAGE_H

#include "Message.h"

// Begin fight actions for a new turn
class ReadyBeginTurnFightActionMessage : public Message {
public: 
	// Constructor
	ReadyBeginTurnFightActionMessage() {};
	// Copy constructor
	ReadyBeginTurnFightActionMessage(const ReadyBeginTurnFightActionMessage& other) = default;

	// Copy operator
	ReadyBeginTurnFightActionMessage& operator=(const ReadyBeginTurnFightActionMessage& other) = default;
	// Destructor
	~ReadyBeginTurnFightActionMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10067;
};

#endif