#ifndef VERSION_H
#define VERSION_H

#include "NetworkType.h"


class Version : public NetworkType {
public:
	// Constructor
	Version() {};
	// Constructor with version initilization
	Version(int major, int minor, int code, int build, int buildType) { this->major = major; this->minor = minor; this->code = code; this->build = build; this->buildType = buildType; };
	// Copy constructor
	Version(const Version& other) = default;

	// Copy operator
	Version& operator=(const Version& other) = default;
	// Destructor
	~Version() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 11;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int buildType = 0;
	int build = 0;
	int minor = 0;
	int code = 0;
	int major = 0;
};

#endif