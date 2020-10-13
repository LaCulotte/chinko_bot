#ifndef ACTOREXTENDEDALIGNMENTINFORMATIONS_H
#define ACTOREXTENDEDALIGNMENTINFORMATIONS_H

#include "ActorAlignmentInformations.h"


class ActorExtendedAlignmentInformations : public ActorAlignmentInformations {
public:
	// Constructor
	ActorExtendedAlignmentInformations() {};
	// Copy constructor
	ActorExtendedAlignmentInformations(const ActorExtendedAlignmentInformations& other) = default;

	// Copy operator
	ActorExtendedAlignmentInformations& operator=(const ActorExtendedAlignmentInformations& other) = default;
	// Destructor
	~ActorExtendedAlignmentInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 6556;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int aggressable = 0;
	int honorNextGradeFloor = 0;
	int honorGradeFloor = 0;
	int honor = 0;
};

#endif