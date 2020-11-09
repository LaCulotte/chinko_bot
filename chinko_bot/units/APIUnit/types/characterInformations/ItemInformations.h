#ifndef ITEM_INFORMATIONS_H
#define ITEM_INFORMATIONS_H

#include "APIType.h"

class ItemInformations : public APIType {
public:
    // Constructor
    ItemInformations() {};
    // Copy constructor
    ItemInformations(const ItemInformations& other) = default;

    // Copy operator
    virtual ItemInformations& operator=(const ItemInformations& other) = default;
    // Destructor
    virtual ~ItemInformations() = default;

    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 11;

    // Turns raw data into the usable data (type's attributes)
    virtual bool deserialize(shared_ptr<MessageDataBuffer> input);
    // Turns the type's attributes into raw data
    virtual bool serialize(shared_ptr<MessageDataBuffer> output);

    int itemUID;
    int itemGID;
    int quantity;
};

#endif