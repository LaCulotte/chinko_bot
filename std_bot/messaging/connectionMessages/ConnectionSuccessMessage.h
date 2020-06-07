#ifndef CONNECTION_SUCCESS_MESSAGE_H
#define CONNECTION_SUCCESS_MESSAGE_H

#include "Message.h"

// Used to tell that the requested connection was successfuly connected
class ConnectionSuccessMessage : public Message {
public:
    // Constructor
    ConnectionSuccessMessage() {};
    // Constructor with the connection id
    ConnectionSuccessMessage(int connectionId) { this->connectionId = connectionId; };
    // Copy construtor
    ConnectionSuccessMessage(const ConnectionSuccessMessage& other) = default;

    // Copy operator
    virtual ConnectionSuccessMessage& operator=(const ConnectionSuccessMessage& other) = default;
    // Destructor
    virtual ~ConnectionSuccessMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; }

    // Message's protocol Id
    static const unsigned int protocolId = 614;

    // Id of the connection just made
    int connectionId = -1;
};

#endif