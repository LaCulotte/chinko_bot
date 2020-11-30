#ifndef PLAYEDCHARACTER_INFORMATIONS_H
#define PLAYEDCHARACTER_INFORMATIONS_H

#include "APIType.h"

#include <unordered_map>

#include "SkillInformations.h"
#include "JobInformations.h"
#include "ItemInformations.h"

class PlayedCharacterInformations : public APIType {
public:
    // Constructor
    PlayedCharacterInformations() {};
    // Copy constructor
    PlayedCharacterInformations(const PlayedCharacterInformations& other) = default;

    // Copy operator
    virtual PlayedCharacterInformations& operator=(const PlayedCharacterInformations& other) = default;
    // Destructor
    virtual ~PlayedCharacterInformations() = default;

    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 12;

    // Turns raw data into the usable data (type's attributes)
    virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
    // Turns the type's attributes into raw data
    virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

    double id;

    string name;
    int breedId;
    bool sex;

    int level;
    uint64_t xp = 0;
    uint64_t xpLevelFloor = 0;
    uint64_t xpNextLevelFloor = 0;

    uint64_t kamas;
    int weight;
    int maxWeight;
    
    // Maps item's id to quantity
    unordered_map<int, ItemInformations> inventory;
    unordered_map<int, JobInformations> jobs;
};

#endif