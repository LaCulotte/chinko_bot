#ifndef AUTHENTIFICATION_FRAME_H
#define AUTHENTIFICATION_FRAME_H

#include "Frame.h"
#include "DofusBotUnit.h"
#include "DofusClientConnection.h"
#include "ConnectionUnit.h"

// TODO : enlever, le message sera à compute à partir d'une autre frame de base
#include "UnknownDofusMessage.h"
#include "BeginAuthentificationMessage.h"
#include "ConnectionRequestMessage.h"

class AuthentificationFrame : public Frame {
public :
    // Constructor
    AuthentificationFrame() {};
    // Copy constructor
    AuthentificationFrame(const AuthentificationFrame& other) = default;

    // Copy operator
    AuthentificationFrame& operator=(const AuthentificationFrame& other) = default;
    // Destructor
    ~AuthentificationFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;

    virtual bool setParent(MessagingUnit* parent) override;
};

#endif