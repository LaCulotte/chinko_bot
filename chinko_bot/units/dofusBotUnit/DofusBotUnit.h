#ifndef DOFUS_BOTUNIT_H
#define DOFUS_BOTUNIT_H

#include "MessagingUnit.h"
#include "ConnectionUnit.h"
#include "QueueFrame.h"
// #include "AuthentificationFrame.h"

#include "GameServerInformationContainer.h"

#include "SendPacketRequestMessage.h"
#include "SendPacketSuccessMessage.h"
#include "SendPacketFailureMessage.h"

class DofusBotUnit : public MessagingUnit {
public:
    // Constructor
    DofusBotUnit() : MessagingUnit() {};
    // Copy constructor
    DofusBotUnit(const DofusBotUnit& other) = default;

    // Copy operator
    DofusBotUnit& operator=(const DofusBotUnit& other) = default;
    // Destructor
    virtual ~DofusBotUnit() = default;

    virtual void initFrames() override { addFrame(make_shared<QueueFrame>()); };

    virtual int sendPacket(sp<ConnectionMessage> message, int connectionId = -1);    

    int connectionUnitId = -1;
    GameServerInformationContainer gameServerInfos;

protected:
    int lastPacketId = 0;
};

#define FINISHED_DOFUSBOT_H

#endif