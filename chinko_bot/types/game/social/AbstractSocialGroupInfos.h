#ifndef ABSTRACTSOCIALGROUPINFOS_H
#define ABSTRACTSOCIALGROUPINFOS_H

#include "NetworkType.h"


class AbstractSocialGroupInfos : public NetworkType {
public:
	// Constructor
	AbstractSocialGroupInfos() {};
	// Copy constructor
	AbstractSocialGroupInfos(const AbstractSocialGroupInfos& other) = default;

	// Copy operator
	AbstractSocialGroupInfos& operator=(const AbstractSocialGroupInfos& other) = default;
	// Destructor
	~AbstractSocialGroupInfos() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 416;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };

};

#endif