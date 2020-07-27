#ifndef NPCWITHQUEST_DATA_H
#define NPCWITHQUEST_DATA_H

#include "NpcData.h"

#include "GameRolePlayNpcQuestFlag.h"

class NpcWithQuestData : public NpcData{
public:
    // Constructor
    NpcWithQuestData() {};
    // Copy constructor
    NpcWithQuestData(const NpcWithQuestData& other) = default;

    // Copy operator
    virtual NpcWithQuestData& operator=(const NpcWithQuestData& other) = default;
    // Destructor
    virtual ~NpcWithQuestData() = default;

    GameRolePlayNpcQuestFlag questFlag;
};

#endif