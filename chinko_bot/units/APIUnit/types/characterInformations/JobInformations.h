#ifndef JOB_INFORMATIONS_H
#define JOB_INFORMATIONS_H

#include "APIType.h"

#include <unordered_map>

#include "SkillInformations.h"

class JobInformations : public APIType {
public:
    // Constructor
    JobInformations() {};
    // Constructor with jobId initialization
    JobInformations(int jobId) { this->jobId = jobId; };
    // Copy constructor
    JobInformations(const JobInformations& other) = default;

    // Copy operator
    virtual JobInformations& operator=(const JobInformations& other) = default;
    // Destructor
    virtual ~JobInformations() = default;

    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 11;

    // Turns raw data into the usable data (type's attributes)
    virtual bool deserialize(shared_ptr<MessageDataBuffer> input);
    // Turns the type's attributes into raw data
    virtual bool serialize(shared_ptr<MessageDataBuffer> output);

    int jobId;
    int level;
    uint64_t xpNextLevelFloor;
	uint64_t xpLevelFloor;
    uint64_t xp;
    unordered_map<int, sp<SkillInformations>> skills;
};

#endif