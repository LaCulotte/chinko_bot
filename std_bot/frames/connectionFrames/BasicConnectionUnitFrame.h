#ifndef BASICCONNECTIONUNIT_FRAME_H
#define BASICCONNECTIONUNIT_FRAME_H

#include "Frame.h"
#include "ConnectionUnit.h"

#include "SendPacketRequestMessage.h"
#include "SendPacketSuccessMessage.h"
#include "SendPacketFailureMessage.h"
#include "GetConnectionFocusRequestMessage.h"
#include "GetConnectionFocusSuccessMessage.h"
#include "GetConnectionFocusFailureMessage.h"
#include "ConnectionRequestMessage.h"
#include "ConnectionSuccessMessage.h"
#include "ConnectionFailureMessage.h"
#include "ConnectionIdGetMessage.h"
#include "ConnectionIdMessage.h"
#include "DisconnectRequestMessage.h"
#include "DisconnectedMessage.h"

// Frame that implements basic ConnectionUnits action such as connection to a server or sending a message
class BasicConnectionUnitFrame : public Frame {
public:

    // Sets Frames's parent
    virtual bool setParent(MessagingUnit* parent) override;

    // 'Acts' according to the message. SrcKey is there to indentify the message's source (sender)
    virtual bool computeMessage(sp<Message> message, int srcId) override;

};

#endif