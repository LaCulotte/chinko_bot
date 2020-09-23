#ifndef RETRYAUTHENTIFICATION_MESSAGE_H
#define RETRYAUTHENTIFICATION_MESSAGE_H

#include "Message.h"

// Message to request the an other authentification
class RetryAuthentificationMessage : public Message {
public : 
    // Constructor
    RetryAuthentificationMessage() {};
    // Copy constructor
    RetryAuthentificationMessage(const RetryAuthentificationMessage& other) = default;

    // Copy operator
    RetryAuthentificationMessage& operator=(const RetryAuthentificationMessage& other) = default;
    // Destructor
    ~RetryAuthentificationMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 10044;
};

#endif