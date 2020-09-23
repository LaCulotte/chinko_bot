#ifndef MOVETOCELL_MESSAGE_H
#define MOVETOCELL_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class MoveToCellMessage : public Message {
public: 
	// Constructor
	MoveToCellMessage() {};
	// Constructor with destinationCellId initialization
	MoveToCellMessage(int destinationCellId) { this->destinationCellId = destinationCellId; };
	// Copy constructor
	MoveToCellMessage(const MoveToCellMessage& other) = default;

	// Copy operator
	MoveToCellMessage& operator=(const MoveToCellMessage& other) = default;
	// Destructor
	~MoveToCellMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10050;

    int destinationCellId = -1;
};

#endif