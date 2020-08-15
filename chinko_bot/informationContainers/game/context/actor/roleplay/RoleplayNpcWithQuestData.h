#ifndef NPCWITHQUEST_DATA_H
#define NPCWITHQUEST_DATA_H

#include "RoleplayNpcData.h"

#include "GameRolePlayNpcQuestFlag.h"

class RoleplayNpcWithQuestData : public RoleplayNpcData {
public:
    // Constructor
    RoleplayNpcWithQuestData() : RoleplayNpcData() {};
    // Copy constructor
    RoleplayNpcWithQuestData(const RoleplayNpcWithQuestData& other) = default;

    // Copy operator
    virtual RoleplayNpcWithQuestData& operator=(const RoleplayNpcWithQuestData& other) = default;
    // Destructor
    virtual ~RoleplayNpcWithQuestData() = default;

    GameRolePlayNpcQuestFlag questFlag;
};

#endif