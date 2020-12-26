#ifndef ALTERNATIVEMONSTERSINGROUPLIGHTINFORMATIONS_H
#define ALTERNATIVEMONSTERSINGROUPLIGHTINFORMATIONS_H

#include "NetworkType.h"

#include "MonsterInGroupLightInformations.h"

class AlternativeMonstersInGroupLightInformations : public NetworkType {
public:
	// Constructor
	AlternativeMonstersInGroupLightInformations() {};
	// Copy constructor
	AlternativeMonstersInGroupLightInformations(const AlternativeMonstersInGroupLightInformations& other) = default;

	// Copy operator
	AlternativeMonstersInGroupLightInformations& operator=(const AlternativeMonstersInGroupLightInformations& other) = default;
	// Destructor
	~AlternativeMonstersInGroupLightInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 4329;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<MonsterInGroupLightInformations> monsters;
	int playerCount = 0;
};

#endif