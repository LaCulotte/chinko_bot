#ifndef UNKNOWN_DOFUSMESSAGE_H
#define UNKNOWN_DOFUSMESSAGE_H

#include "PrefixedMessage.h"

class UnknownDofusMessage : public PrefixedMessage {
public:
    // Constructor
    UnknownDofusMessage();
    // Constructor with length initialisation
    UnknownDofusMessage(int length);
    // Copy constructor
    UnknownDofusMessage(const UnknownDofusMessage& other) = default;

    // Copy operator
    UnknownDofusMessage& operator=(const UnknownDofusMessage& other) = default;
    // Destructor
    ~UnknownDofusMessage() = default;

    virtual unsigned int getId() override { return protocolId; };
    static const unsigned int protocolId = 630;

    // Data that was contained in the base message
    sp<MessageDataBuffer> data = nullptr;
    // Id of the real message
    int real_id = 0;

    // Turns raw data into the usable data (message's attributes)
    virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
    // Turns the message's attributes into raw data
    virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;
};

#endif