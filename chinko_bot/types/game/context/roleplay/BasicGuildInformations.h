#ifndef BASICGUILDINFORMATIONS_H
#define BASICGUILDINFORMATIONS_H

#include "AbstractSocialGroupInfos.h"


class BasicGuildInformations : public AbstractSocialGroupInfos {
public:
	// Constructor
	BasicGuildInformations() {};
	// Copy constructor
	BasicGuildInformations(const BasicGuildInformations& other) = default;

	// Copy operator
	BasicGuildInformations& operator=(const BasicGuildInformations& other) = default;
	// Destructor
	~BasicGuildInformations() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 4801;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int guildLevel = 0;
	string guildName;
	int guildId = 0;
};

#endif