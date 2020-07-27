#ifndef TIMED_MESSAGE
#define TIMED_MESSAGE

#include "Message.h"
#include "time_include.h"

class TimedMessage : public Message {
public:
   // Default constructor.
    TimedMessage() {};
    // Constructor with time (in milliseconds) initialization
    TimedMessage(sp<Message> message, int time) { this->message = message; beginTime = chrono::steady_clock::now(); waitTime = chrono::duration<double>(chrono::milliseconds(time)); };
    // Copy contructor
    TimedMessage(const TimedMessage& other) = default;

    // Copy operator
    virtual TimedMessage& operator=(const TimedMessage& other) = default;
    // Destructor
    virtual ~TimedMessage() = default;

    chrono::time_point<chrono::steady_clock> beginTime;
    chrono::duration<double> waitTime;

    sp<Message> message;
};

#endif