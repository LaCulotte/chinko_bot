#ifndef DOFUS_MESSAGETYPEHANDLER_H
#define DOFUS_MESSAGETYPEHANDLER_H

#include "MessageTypeHandler.h"
#include <functional>
#include <unordered_map>

class DofusMessageTypeHandler : public MessageTypeHandler {
public:
    // Constructor
    DofusMessageTypeHandler();
    // Copy constructor
    DofusMessageTypeHandler(const DofusMessageTypeHandler& other) = delete;

    // Copy operator
    DofusMessageTypeHandler& operator=(const DofusMessageTypeHandler& other) = delete;
    // Destructor
    virtual ~DofusMessageTypeHandler() {};

    // TODO : rename to build
    // Builds a message from the message's id
    virtual sp<Message> generateMessageById(int id) override;

protected:
    // Map that links a message id to a fonction to build the message
    unordered_map<int, function<sp<Message>()>> id_to_builder;
};

#endif