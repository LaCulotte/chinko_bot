#ifndef FIGHTRESULTEXPERIENCEDATA_H
#define FIGHTRESULTEXPERIENCEDATA_H

#include "FightResultAdditionalData.h"


class FightResultExperienceData : public FightResultAdditionalData {
public:
	// Constructor
	FightResultExperienceData() {};
	// Copy constructor
	FightResultExperienceData(const FightResultExperienceData& other) = default;

	// Copy operator
	FightResultExperienceData& operator=(const FightResultExperienceData& other) = default;
	// Destructor
	~FightResultExperienceData() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 5733;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	uint64_t experience = 0;
	uint64_t experienceFightDelta = 0;
	bool showExperienceLevelFloor = false;
	uint64_t experienceLevelFloor = 0;
	uint64_t experienceNextLevelFloor = 0;
	bool showExperienceNextLevelFloor = false;
	uint64_t experienceForGuild = 0;
	bool showExperienceFightDelta = false;
	bool showExperience = false;
	uint64_t experienceForMount = 0;
	bool showExperienceForGuild = false;
	int rerollExperienceMul = 0;
	bool showExperienceForMount = false;
	bool isIncarnationExperience = false;
};

#endif