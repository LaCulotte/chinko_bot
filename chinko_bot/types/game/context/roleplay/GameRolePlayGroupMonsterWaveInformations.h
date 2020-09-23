#ifndef GAMEROLEPLAYGROUPMONSTERWAVEINFORMATIONS_H
#define GAMEROLEPLAYGROUPMONSTERWAVEINFORMATIONS_H

#include "GameRolePlayGroupMonsterInformations.h"

#include "GroupMonsterStaticInformations.h"

#include "NetworkTypeHandler.h"

class GameRolePlayGroupMonsterWaveInformations : public GameRolePlayGroupMonsterInformations {
public:
	// Constructor
	GameRolePlayGroupMonsterWaveInformations() {};
	// Copy constructor
	GameRolePlayGroupMonsterWaveInformations(const GameRolePlayGroupMonsterWaveInformations& other) = default;

	// Copy operator
	GameRolePlayGroupMonsterWaveInformations& operator=(const GameRolePlayGroupMonsterWaveInformations& other) = default;
	// Destructor
	~GameRolePlayGroupMonsterWaveInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 7041;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	vector<sp<GroupMonsterStaticInformations>> alternatives;
	int nbWaves = 0;
};

#endif