#ifndef CHARACTER_DATA_H
#define CHARACTER_DATA_H

#include "ActorData.h"

#include "ActorRestrictionsInformations.h"

class CharacterData : public ActorData {
public:
    // Constructor
    CharacterData() {};
    // Copy constructor
    CharacterData(const CharacterData& other) = default;

    // Copy operator
    virtual CharacterData& operator=(const CharacterData& other) = default;
    // Destructor
    virtual ~CharacterData() = default;

    string name;
    ActorRestrictionsInformations restrictions;
    double accountId;
};

#endif