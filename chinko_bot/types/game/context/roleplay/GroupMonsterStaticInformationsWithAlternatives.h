#ifndef GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES_H
#define GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES_H

#include "GroupMonsterStaticInformations.h"

#include "AlternativeMonstersInGroupLightInformations.h"

class GroupMonsterStaticInformationsWithAlternatives : public GroupMonsterStaticInformations {
public:
	// Constructor
	GroupMonsterStaticInformationsWithAlternatives() {};
	// Copy constructor
	GroupMonsterStaticInformationsWithAlternatives(const GroupMonsterStaticInformationsWithAlternatives& other) = default;

	// Copy operator
	GroupMonsterStaticInformationsWithAlternatives& operator=(const GroupMonsterStaticInformationsWithAlternatives& other) = default;
	// Destructor
	~GroupMonsterStaticInformationsWithAlternatives() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 5848;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<AlternativeMonstersInGroupLightInformations> alternatives;
};

#endif