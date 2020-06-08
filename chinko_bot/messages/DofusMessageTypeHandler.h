#ifndef DOFUS_MESSAGETYPEHANDLER_H
#define DOFUS_MESSAGETYPEHANDLER_H

#include "MessageTypeHandler.h"
#include <functional>
#include <unordered_map>

#include "UnknownDofusMessage.h"

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

    virtual sp<Message> generateMessageById(int id) override;

protected:
    unordered_map<int, function<sp<Message>()>> id_to_builder;
};

#endif