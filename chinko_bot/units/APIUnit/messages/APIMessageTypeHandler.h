#ifndef API_MESSAGEHANDLER_H
#define API_MESSAGEHANDLER_H

#include "MessageTypeHandler.h"
#include <functional>
#include <unordered_map>

class APIMessageTypeHandler : public MessageTypeHandler {
public:
    // Constructor
    APIMessageTypeHandler();
    // Copy constructor
    APIMessageTypeHandler(const APIMessageTypeHandler& other) = delete;

    // Copy operator
    APIMessageTypeHandler& operator=(const APIMessageTypeHandler& other) = delete;
    // Destructor
    virtual ~APIMessageTypeHandler() {};

    // TODO : rename to build
    // Builds a message from the message's id
    virtual sp<Message> generateMessageById(int id) override;

protected:
    // Map that links a message id to a fonction to build the message
    unordered_map<int, function<sp<Message>()>> id_to_builder;
};

#endif