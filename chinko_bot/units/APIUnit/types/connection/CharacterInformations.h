#ifndef CHARACTERINFORMATIONS_H
#define CHARACTERINFORMATIONS_H

#include "APIType.h"

// Character's informations type
class CharacterInformations : public APIType {
public:
    // Constructor
    CharacterInformations() : APIType() {};
    // Copy constructor
    CharacterInformations(const CharacterInformations& other) = default;

    // Copy operator
    virtual CharacterInformations& operator=(const CharacterInformations& other) = default;
    // Destructor
    virtual ~CharacterInformations() = default;
  
    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 2;

    // Turns raw data into the usable data (type's attributes)
    virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
    // Turns the type's attributes into raw data
    virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

    uint64_t id;
    string name;
    int breed;
    bool sex;
    int level;
    bool isSelectable;
};

#endif