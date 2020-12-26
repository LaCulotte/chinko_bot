#ifndef ENTITYDISPOSITIONINFORMATIONS_H
#define ENTITYDISPOSITIONINFORMATIONS_H

#include "NetworkType.h"


class EntityDispositionInformations : public NetworkType {
public:
	// Constructor
	EntityDispositionInformations() {};
	// Copy constructor
	EntityDispositionInformations(const EntityDispositionInformations& other) = default;

	// Copy operator
	EntityDispositionInformations& operator=(const EntityDispositionInformations& other) = default;
	// Destructor
	~EntityDispositionInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 3023;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int direction = 1;
	int cellId = 0;
};

#endif