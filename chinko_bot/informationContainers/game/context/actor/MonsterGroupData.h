#ifndef MONSTERGROUP_DATA_H
#define MONSTERGROUP_DATA_H

#include "ActorData.h"

#include "MonsterInGroupLightInformations.h"

class MonsterGroupData : public ActorData{
public:
    // Constructor
    MonsterGroupData() {};
    // Copy constructor
    MonsterGroupData(const MonsterGroupData& other) = default;

    // Copy operator
    virtual MonsterGroupData& operator=(const MonsterGroupData& other) = default;
    // Destructor
    virtual ~MonsterGroupData() = default;

    MonsterInGroupLightInformations mainMonster;
    vector<MonsterInGroupLightInformations> underlings;
};

#endif