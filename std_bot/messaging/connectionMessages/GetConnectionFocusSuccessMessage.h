#ifndef GETCONNECTIONFOCUS_SUCCESS_MESSAGE
#define GETCONNECTIONFOCUS_SUCCESS_MESSAGE

#include "Message.h"

// Tells that the focus was successfully gotten
class GetConnectionFocusSuccessMessage : public Message {
public:
    // Contructor
    GetConnectionFocusSuccessMessage() {};
    // Constructor; with the ids of the connection whose focus was changed
    GetConnectionFocusSuccessMessage(vector<int> connectionIds) { this->connectionIds = connectionIds; };
    // Copy constuctor
    GetConnectionFocusSuccessMessage(const GetConnectionFocusSuccessMessage& other) = default;

    // Copy operator
    virtual GetConnectionFocusSuccessMessage& operator=(const GetConnectionFocusSuccessMessage& other) = default;
    // Destructor
    virtual ~GetConnectionFocusSuccessMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 619;

    // Ids of the connection whose focus was changed
    vector<int> connectionIds = {};
};

#endif