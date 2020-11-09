#ifndef SKILL_INFORMATIONS_H
#define SKILL_INFORMATIONS_H

#include "APIType.h"

class SkillInformations : public APIType {
public:
    // Constructor
    SkillInformations() {};
    // Copy constructor
    SkillInformations(const SkillInformations& other) = default;

    // Copy operator
    virtual SkillInformations& operator=(const SkillInformations& other) = default;
    // Destructor
    virtual ~SkillInformations() = default;

    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 10;

    // Turns raw data into the usable data (type's attributes)
    virtual bool deserialize(shared_ptr<MessageDataBuffer> input);
    // Turns the type's attributes into raw data
    virtual bool serialize(shared_ptr<MessageDataBuffer> output);

    int skillId = 0;
    int interactiveId = 0;
    int range = 0;
};

#endif