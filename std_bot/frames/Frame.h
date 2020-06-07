#ifndef FRAME_H
#define FRAME_H

#include "std_include.h"
#include "ptr_include.h"
#include "MessagingUnit.h"

class MessagingUnit;

// Objects used by a MessagingUnit (parent) in that work according to unit's received messages
// Useful to because it enables a message to trigger different actions depending on the time/context
class Frame{
public:
    // Constructor
    Frame() {};
    // Copy constructor
    Frame(const Frame& other) = default;
    
    // Copy operator
    virtual Frame& operator=(const Frame &other) = default;
    // Destructor 
    virtual ~Frame() = default;

    // 'Acts' according to the message. SrcKey is there to indentify the message's source (sender)
    virtual bool computeMessage(sp<Message> message, int srcId) = 0;

    // Sets Frames's parent
    virtual bool setParent(MessagingUnit* parent) { this->parent = parent; return true; };
    // Resets Frame's parent
    void resetParent() { parent = nullptr; };
    // Returns Frame's parent
    MessagingUnit * getParent() { return parent; };

    // Sets Frame's priority
    void setPriority(int p) { priority = p; };
    // Returns Frame's priority
    int getPriority() { return priority; }; 

protected:
    // Frame's parent. Basically the object that calls 'computeMessage'
    MessagingUnit* parent = nullptr;

    // The lower, the latter it will compute messages. Can be negative. 
    int priority = 0;
};

// This define is used to tell that the Frame class was successfuly compiled
// Used for two-way #includes that are intricate
#define FINISHED_FRAME_H

#endif