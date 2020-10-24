#ifndef API_TYPE
#define API_TYPE

#include "std_include.h"
#include "ptr_include.h"
#include "MessageDataBuffer.h"

class APIType {
public:
    // Constructor
    APIType() {};
    // Copy constructor
    APIType(const APIType& other) = default;

    // Copy operator
    virtual APIType& operator=(const APIType& other) = default;
    // Destructor
    virtual ~APIType() = default;
  
    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 0;

    // Turns raw data into the usable data (type's attributes)
    virtual bool deserialize(shared_ptr<MessageDataBuffer> input) = 0;
    // Turns the type's attributes into raw data
    virtual bool serialize(shared_ptr<MessageDataBuffer> output) = 0;

};


#endif