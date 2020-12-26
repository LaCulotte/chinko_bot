#ifndef SHORTCUT_H
#define SHORTCUT_H

#include "NetworkType.h"


class Shortcut : public NetworkType {
public:
	// Constructor
	Shortcut() {};
	// Copy constructor
	Shortcut(const Shortcut& other) = default;

	// Copy operator
	Shortcut& operator=(const Shortcut& other) = default;
	// Destructor
	~Shortcut() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 1043;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int slot = 0;
};

#endif