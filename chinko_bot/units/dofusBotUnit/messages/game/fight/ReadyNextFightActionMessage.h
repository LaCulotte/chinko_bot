#ifndef READYNEXTFIGHTACTION_MESSAGE_H
#define READYNEXTFIGHTACTION_MESSAGE_H

#include "Message.h"

// Continue the current turn's fight actions
class ReadyNextFightActionMessage : public Message {
public: 
	// Constructor
	ReadyNextFightActionMessage() {};
	// Copy constructor
	ReadyNextFightActionMessage(const ReadyNextFightActionMessage& other) = default;

	// Copy operator
	ReadyNextFightActionMessage& operator=(const ReadyNextFightActionMessage& other) = default;
	// Destructor
	~ReadyNextFightActionMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10068;
};

#endif