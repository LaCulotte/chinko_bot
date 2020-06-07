#ifndef GETCONNECTIONFOCUS_FAILURE_MESSAGE
#define GETCONNECTIONFOCUS_FAILURE_MESSAGE

#include "Message.h"

// Tells that the focus was successfully gotten
class GetConnectionFocusFailureMessage : public Message {
public:
    // Contructor
    GetConnectionFocusFailureMessage() {};
    // Constructor; with the reason of the failure
    GetConnectionFocusFailureMessage(string reason) { this->reason = reason; };
    // Copy constuctor
    GetConnectionFocusFailureMessage(const GetConnectionFocusFailureMessage& other) = default;

    // Copy operator
    virtual GetConnectionFocusFailureMessage& operator=(const GetConnectionFocusFailureMessage& other) = default;
    // Destructor
    virtual ~GetConnectionFocusFailureMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 620;

    // Reason of the failure
    string reason = "Fail";
};

#endif