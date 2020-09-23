#ifndef HUMANOPTIONGUILD_H
#define HUMANOPTIONGUILD_H

#include "HumanOption.h"

#include "GuildInformations.h"

class HumanOptionGuild : public HumanOption {
public:
	// Constructor
	HumanOptionGuild() {};
	// Copy constructor
	HumanOptionGuild(const HumanOptionGuild& other) = default;

	// Copy operator
	HumanOptionGuild& operator=(const HumanOptionGuild& other) = default;
	// Destructor
	~HumanOptionGuild() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 7229;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	GuildInformations guildInformations;
};

#endif