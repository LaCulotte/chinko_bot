#ifndef ENTITYLOOK_H
#define ENTITYLOOK_H

#include "NetworkType.h"

class EntityLook : public NetworkType {
public: 
	// Constructor
	EntityLook() {};
	// Copy constructor
	EntityLook(const EntityLook& other) = default;

	// Copy operator
	EntityLook& operator=(const EntityLook& other) = default;
	// Destructor
	~EntityLook() = default;

    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 55;

	// Turns raw data into the usable data (message's attributes)
	virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
	// Turns the message's attributes into raw data
	virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

	int bonesId;
	vector<int> skins;
	vector<int> indexedColors;
	vector<int> scales;
	vector<EntityLook> subEntities;

};

#endif