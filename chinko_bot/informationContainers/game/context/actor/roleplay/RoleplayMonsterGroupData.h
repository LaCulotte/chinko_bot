#ifndef MONSTERGROUP_DATA_H
#define MONSTERGROUP_DATA_H

#include "ActorData.h"

#include "MonsterInGroupLightInformations.h"

class RoleplayMonsterGroupData : public ActorData{
public:
    // Constructor
    RoleplayMonsterGroupData() : ActorData() {};
    // Copy constructor
    RoleplayMonsterGroupData(const RoleplayMonsterGroupData& other) = default;

    // Copy operator
    virtual RoleplayMonsterGroupData& operator=(const RoleplayMonsterGroupData& other) = default;
    // Destructor
    virtual ~RoleplayMonsterGroupData() = default;

    MonsterInGroupLightInformations mainMonster;
    vector<MonsterInGroupLightInformations> underlings;
};

#endif