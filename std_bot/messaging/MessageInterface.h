#ifndef MESSAGEINTERFACE_H
#define MESSAGEINTERFACE_H

#include "thread_include.h"
#include "Logger.h"
#include "Message.h"
#include "MessagingUnit.h"

class MessagingUnit;

/**
 * Object used to make the communication between two MessagingUnit
 * A pair of these enables a two-way communication between two asynchronus objects.
 */
class MessageInterface{
public:
    // Constructor
    MessageInterface();
    // Copy constructor
    MessageInterface(const MessageInterface &other);

    // Copy operator
    MessageInterface& operator=(const MessageInterface &other);
    // Destructor
    ~MessageInterface();

    // 'Sends' a message to the destination MessagingUnit
    bool send(sp<Message> message);

    // Used by the destination MessagingUnit in order to retrieve the sent messages
    vector<sp<Message>> receive();  
    // Returns true if there is messages to receive
    bool isThereMessages() { return (messageBuffer.size()) > 0; };

    // Destination of the message interface
    MessagingUnit* destination = nullptr;

protected:
    // Buffer for the sent messages
    vector<sp<Message>> messageBuffer;

    // Locker to synchronize the access to the messages' buffer
    timed_mutex mainMutex;
};

#define END_MESSAGEINTERFACE_H

#endif