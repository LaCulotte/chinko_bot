#ifndef MESSAGE_H
#define MESSAGE_H

#include "std_include.h"
#include "ptr_include.h"
#include "Logger.h"
#include "MessageDataBuffer.h"

// Used by MessagingUnits; they react to it according to their Frames
using namespace std;
class Message {
public:
    // Constructor
    Message() {};
    // Copy constructor
    Message(const Message& other) = default;

    // Copy operator
    virtual Message& operator=(const Message& other) = default;
    // Destructor
    virtual ~Message() = default;
  
    // Returns the message's id
    virtual unsigned int getId() { return protocolId; };
    // Message's id; used to know the type without 'try-casting'
    static const unsigned int protocolId = 0;
    
    // True if a processed message should continue to go through the Frames of a MessagingUnit
    bool keepInLoop = false;
    // Number of loops the message can make without being processed before being deleted
    int lifetime = 1;
};

#endif