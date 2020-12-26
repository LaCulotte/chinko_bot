#ifndef ENDTURN_MESSAGE_H
#define ENDTURN_MESSAGE_H

#include "Message.h"

// Message to end bot's turn in a fight
class EndTurnMessage : public Message {
public: 
	// Constructor
	EndTurnMessage() {};
	// Copy constructor
	EndTurnMessage(const EndTurnMessage& other) = default;

	// Copy operator
	EndTurnMessage& operator=(const EndTurnMessage& other) = default;
	// Destructor
	~EndTurnMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10064;
};

#endif