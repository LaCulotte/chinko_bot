#ifndef FIGHTACTIONFAILURE_MESSAGE_H
#define FIGHTACTIONFAILURE_MESSAGE_H

#include "Message.h"

// Fight action has failed
class FightActionFailureMessage : public Message {
public: 
	// Constructor
	FightActionFailureMessage() {};
	// Copy constructor
	FightActionFailureMessage(const FightActionFailureMessage& other) = default;

	// Copy operator
	FightActionFailureMessage& operator=(const FightActionFailureMessage& other) = default;
	// Destructor
	~FightActionFailureMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10069;
};

#endif