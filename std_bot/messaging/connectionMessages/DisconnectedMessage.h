#ifndef DISCONNECT_SUCCESS_MESSAGE
#define DISCONNECT_SUCCESS_MESSAGE

#include "Message.h"

// Tells that the focus was successfully gotten
class DisconnectedMessage : public Message {
public:
    // Contructor
    DisconnectedMessage() {};
    // Constructor; with the ids of the connection that was disconnected
    DisconnectedMessage(vector<int> connectionIds) { this->connectionIds = connectionIds; };
    // Copy constuctor
    DisconnectedMessage(const DisconnectedMessage& other) = default;

    // Copy operator
    virtual DisconnectedMessage& operator=(const DisconnectedMessage& other) = default;
    // Destructor
    virtual ~DisconnectedMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 622;

    // Ids of the connection that was disconnected
    vector<int> connectionIds = {};
};

#endif