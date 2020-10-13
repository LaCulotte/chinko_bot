#ifndef GUILDEMBLEM_H
#define GUILDEMBLEM_H

#include "NetworkType.h"


class GuildEmblem : public NetworkType {
public:
	// Constructor
	GuildEmblem() {};
	// Copy constructor
	GuildEmblem(const GuildEmblem& other) = default;

	// Copy operator
	GuildEmblem& operator=(const GuildEmblem& other) = default;
	// Destructor
	~GuildEmblem() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 3367;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int backgroundShape = 0;
	int backgroundColor = 0;
	int symbolColor = 0;
	int symbolShape = 0;
};

#endif