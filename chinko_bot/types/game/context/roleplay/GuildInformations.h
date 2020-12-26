#ifndef GUILDINFORMATIONS_H
#define GUILDINFORMATIONS_H

#include "BasicGuildInformations.h"

#include "GuildEmblem.h"

class GuildInformations : public BasicGuildInformations {
public:
	// Constructor
	GuildInformations() {};
	// Copy constructor
	GuildInformations(const GuildInformations& other) = default;

	// Copy operator
	GuildInformations& operator=(const GuildInformations& other) = default;
	// Destructor
	~GuildInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 5897;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	GuildEmblem guildEmblem;
};

#endif