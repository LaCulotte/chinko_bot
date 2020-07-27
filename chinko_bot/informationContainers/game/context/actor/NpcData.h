#ifndef NPC_DATA_H
#define NPC_DATA_H

#include "ActorData.h"

class NpcData : public ActorData{
public:
    // Constructor
    NpcData() {};
    // Copy constructor
    NpcData(const NpcData& other) = default;

    // Copy operator
    virtual NpcData& operator=(const NpcData& other) = default;
    // Destructor
    virtual ~NpcData() = default;

    int npcId = 0;
};

#endif