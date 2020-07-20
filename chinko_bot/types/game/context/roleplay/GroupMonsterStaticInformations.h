#ifndef GROUPMONSTERSTATICINFORMATIONS_H
#define GROUPMONSTERSTATICINFORMATIONS_H

#include "NetworkType.h"

#include "MonsterInGroupInformations.h"
#include "MonsterInGroupLightInformations.h"

class GroupMonsterStaticInformations : public NetworkType {
public:
	// Constructor
	GroupMonsterStaticInformations() {};
	// Copy constructor
	GroupMonsterStaticInformations(const GroupMonsterStaticInformations& other) = default;

	// Copy operator
	GroupMonsterStaticInformations& operator=(const GroupMonsterStaticInformations& other) = default;
	// Destructor
	~GroupMonsterStaticInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 140;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<MonsterInGroupInformations> underlings;
	MonsterInGroupLightInformations mainCreatureLightInfos;
};

#endif