#ifndef MONSTERINGROUPINFORMATIONS_H
#define MONSTERINGROUPINFORMATIONS_H

#include "MonsterInGroupLightInformations.h"

#include "EntityLook.h"

class MonsterInGroupInformations : public MonsterInGroupLightInformations {
public:
	// Constructor
	MonsterInGroupInformations() {};
	// Copy constructor
	MonsterInGroupInformations(const MonsterInGroupInformations& other) = default;

	// Copy operator
	MonsterInGroupInformations& operator=(const MonsterInGroupInformations& other) = default;
	// Destructor
	~MonsterInGroupInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 8376;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	EntityLook look;
};

#endif