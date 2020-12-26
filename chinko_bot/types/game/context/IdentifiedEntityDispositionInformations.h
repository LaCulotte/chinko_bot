#ifndef IDENTIFIEDENTITYDISPOSITIONINFORMATIONS_H
#define IDENTIFIEDENTITYDISPOSITIONINFORMATIONS_H

#include "EntityDispositionInformations.h"


class IdentifiedEntityDispositionInformations : public EntityDispositionInformations {
public:
	// Constructor
	IdentifiedEntityDispositionInformations() {};
	// Copy constructor
	IdentifiedEntityDispositionInformations(const IdentifiedEntityDispositionInformations& other) = default;

	// Copy operator
	IdentifiedEntityDispositionInformations& operator=(const IdentifiedEntityDispositionInformations& other) = default;
	// Destructor
	~IdentifiedEntityDispositionInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 6346;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double id = 0;
};

#endif