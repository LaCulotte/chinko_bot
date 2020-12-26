#ifndef ALLINTERACTIVESCOLLECTED_MESSAGE_H
#define ALLINTERACTIVESCOLLECTED_MESSAGE_H

#include "Message.h"

// Notify that all interactives requested on the map are collected
class AllInteractivesCollectedMessage : public Message {
public: 
	// Constructor
	AllInteractivesCollectedMessage() {};
	// Copy constructor
	AllInteractivesCollectedMessage(const AllInteractivesCollectedMessage& other) = default;

	// Copy operator
	AllInteractivesCollectedMessage& operator=(const AllInteractivesCollectedMessage& other) = default;
	// Destructor
	~AllInteractivesCollectedMessage() = default;

	virtual unsigned int getId() override { return protocolId; };
	static const unsigned int protocolId = 10084;
};

#endif