#ifndef MONSTERINGROUPLIGHTINFORMATIONS_H
#define MONSTERINGROUPLIGHTINFORMATIONS_H

#include "NetworkType.h"


class MonsterInGroupLightInformations : public NetworkType {
public:
	// Constructor
	MonsterInGroupLightInformations() {};
	// Copy constructor
	MonsterInGroupLightInformations(const MonsterInGroupLightInformations& other) = default;

	// Copy operator
	MonsterInGroupLightInformations& operator=(const MonsterInGroupLightInformations& other) = default;
	// Destructor
	~MonsterInGroupLightInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 2648;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int level = 0;
	int grade = 0;
	int genericId = 0;
};

#endif