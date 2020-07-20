#ifndef ACTORALIGNMENTINFORMATIONS_H
#define ACTORALIGNMENTINFORMATIONS_H

#include "NetworkType.h"


class ActorAlignmentInformations : public NetworkType {
public:
	// Constructor
	ActorAlignmentInformations() {};
	// Copy constructor
	ActorAlignmentInformations(const ActorAlignmentInformations& other) = default;

	// Copy operator
	ActorAlignmentInformations& operator=(const ActorAlignmentInformations& other) = default;
	// Destructor
	~ActorAlignmentInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 201;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	double characterPower = 0;
	int alignmentGrade = 0;
	int alignmentValue = 0;
	int alignmentSide = 0;
};

#endif