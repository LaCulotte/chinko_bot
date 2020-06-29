#ifndef SHORTCUT_H
#define SHORTCUT_H

#include "NetworkType.h"

class Shortcut : public NetworkType {
public: 
	// Constructor
	Shortcut() {};
	// Constructor
	Shortcut(int slot) { this->slot = slot; };
	// Copy constructor
	Shortcut(const Shortcut& other) = default;

	// Copy operator
	Shortcut& operator=(const Shortcut& other) = default;
	// Destructor
	~Shortcut() = default;

	// Returns the type's id
	virtual unsigned int getId() { return typeId; };
	// Type's id
	static const unsigned int typeId = 369;
	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int slot;

};

#endif