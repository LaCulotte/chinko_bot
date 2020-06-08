#ifndef BEGINAUTHENTIFICATION_MESSAGE_H
#define BEGINAUTHENTIFICATION_MESSAGE_H

#include "Message.h"

class BeginAuthentificationMessage : public Message {
public : 
    // Constructor
    BeginAuthentificationMessage() {};
    // Constructor with username and password initialization
    BeginAuthentificationMessage(string username, string password) { this->username = username; this->password = password; }
    // Copy constructor
    BeginAuthentificationMessage(const BeginAuthentificationMessage& other) = default;

    // Copy operator
    BeginAuthentificationMessage& operator=(const BeginAuthentificationMessage& other) = default;
    // Destructor
    ~BeginAuthentificationMessage() = default;

    // Protocol id getter
    unsigned int getId() override { return protocolId; };
    // Message's protocol Id
    static const unsigned int protocolId = 640;

    string username;
    string password;

    string serverAdress = "52.17.231.202";
    int port = 5555;
};

#endif