#ifndef STATEDELEMENT_H
#define STATEDELEMENT_H

#include "NetworkType.h"


class StatedElement : public NetworkType {
public:
	// Constructor
	StatedElement() {};
	// Copy constructor
	StatedElement(const StatedElement& other) = default;

	// Copy operator
	StatedElement& operator=(const StatedElement& other) = default;
	// Destructor
	~StatedElement() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 108;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	bool onCurrentMap = false;
	int elementState = 0;
	int elementCellId = 0;
	int elementId = 0;
};

#endif