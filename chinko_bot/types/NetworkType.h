#ifndef NETWORK_TYPE
#define NETWORK_TYPE

#include "std_include.h"
#include "ptr_include.h"
#include "MessageDataBuffer.h"

class NetworkType {
public:
    // Constructor
    NetworkType() {};
    // Copy constructor
    NetworkType(const NetworkType& other) = default;

    // Copy operator
    virtual NetworkType& operator=(const NetworkType& other) = default;
    // Destructor
    virtual ~NetworkType() = default;
  
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