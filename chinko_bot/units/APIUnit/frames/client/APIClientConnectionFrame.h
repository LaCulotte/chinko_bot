#ifndef API_CLIENTCONNECTION_FRAME_H
#define API_CLIENTCONNECTION_FRAME_H

#include "APIFrame.h"

class APIClientConnectionFrame : public APIFrame {
public :
    // Constructor
    APIClientConnectionFrame() : APIFrame() {};
    // Copy constructor
    APIClientConnectionFrame(const APIClientConnectionFrame& other) = default;

    // Copy operator
    APIClientConnectionFrame& operator=(const APIClientConnectionFrame& other) = default;
    // Destructor
    ~APIClientConnectionFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;

};

#endif