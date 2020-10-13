#ifndef PORTALINFORMATION_H
#define PORTALINFORMATION_H

#include "NetworkType.h"


class PortalInformation : public NetworkType {
public:
	// Constructor
	PortalInformation() {};
	// Copy constructor
	PortalInformation(const PortalInformation& other) = default;

	// Copy operator
	PortalInformation& operator=(const PortalInformation& other) = default;
	// Destructor
	~PortalInformation() = default;

	virtual unsigned int getId() override { return typeId; };
	static const unsigned int typeId = 477;

	// Turns raw data into the usable data (type's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the type's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int areaId = 0;
	int portalId = 0;
};

#endif