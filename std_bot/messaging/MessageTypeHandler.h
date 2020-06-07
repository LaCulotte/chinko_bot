#ifndef MESSAGETYPEHANDLER_H
#define MESSAGETYPEHANDLER_H

#include "Message.h"

// Class made to generate a message based on its id
class MessageTypeHandler {
public:
    // Constructor
    MessageTypeHandler() {};
    // Copy constructor
    MessageTypeHandler(const MessageTypeHandler& other) = delete;

    // Copy operator
    MessageTypeHandler& operator=(const MessageTypeHandler& other) = delete;
    // Destructor
    virtual ~MessageTypeHandler() {};

    // Generates a message based on its id
    virtual sp<Message> generateMessageById(int id) = 0;
};

#endif