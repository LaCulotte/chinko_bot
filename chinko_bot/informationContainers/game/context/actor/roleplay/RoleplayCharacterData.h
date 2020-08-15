#ifndef CHARACTER_DATA_H
#define CHARACTER_DATA_H

#include "ActorData.h"

#include "ActorRestrictionsInformations.h"

class RoleplayCharacterData : public ActorData {
public:
    // Constructor
    RoleplayCharacterData() : ActorData() {};
    // Copy constructor
    RoleplayCharacterData(const RoleplayCharacterData& other) = default;

    // Copy operator
    virtual RoleplayCharacterData& operator=(const RoleplayCharacterData& other) = default;
    // Destructor
    virtual ~RoleplayCharacterData() = default;

    string name;
    ActorRestrictionsInformations restrictions;
    double accountId;
};

#endif