#ifndef NPC_DATA_H
#define NPC_DATA_H

#include "ActorData.h"

class RoleplayNpcData : public ActorData{
public:
    // Constructor
    RoleplayNpcData() : ActorData()  {};
    // Copy constructor
    RoleplayNpcData(const RoleplayNpcData& other) = default;

    // Copy operator
    virtual RoleplayNpcData& operator=(const RoleplayNpcData& other) = default;
    // Destructor
    virtual ~RoleplayNpcData() = default;

    int npcId = 0;
};

#endif