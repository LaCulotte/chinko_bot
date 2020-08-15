#ifndef CHANGETOMAP_MESSAGE_H
#define CHANGETOMAP_MESSAGE_H

#include "Message.h"

// Message to request the beginning of the character selection
class ChangeToMapMessage : public Message {
public: 
	// Constructor
	ChangeToMapMessage() {};
	// Constructor with mapId initialization
	ChangeToMapMessage(double mapId) { this->mapId = mapId; };
	// Copy constructor
	ChangeToMapMessage(const ChangeToMapMessage& other) = default;

	// Copy operator
	ChangeToMapMessage& operator=(const ChangeToMapMessage& other) = default;
	// Destructor
	~ChangeToMapMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 657;

    double mapId = 0;
};

#endif