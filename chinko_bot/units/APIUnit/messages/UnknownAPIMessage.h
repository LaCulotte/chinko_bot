#ifndef UNKNOWN_API_MESAGE_H
#define UNKNOWN_API_MESAGE_H

#include "PrefixedMessage.h"

class UnknownAPIMessage : public PrefixedMessage {
public:
    // Constructor
    UnknownAPIMessage() : PrefixedMessage() {};
    // Constructor with real_id initialisation
    UnknownAPIMessage(int real_id) : PrefixedMessage() { this->real_id = real_id; };
    // Copy constructor
    UnknownAPIMessage(const UnknownAPIMessage& other) = default;

    // Copy operator
    UnknownAPIMessage& operator=(const UnknownAPIMessage& other) = default;
    // Destructor
    ~UnknownAPIMessage() = default;

    virtual unsigned int getId() override { return protocolId; };
    static const unsigned int protocolId = 11000;

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