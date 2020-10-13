#ifndef READYBEGINTURNFIGHTACTION_MESSAGE_H
#define READYBEGINTURNFIGHTACTION_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the GameContext building
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