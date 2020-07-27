#ifndef DOFUS_BOTUNIT_H
#define DOFUS_BOTUNIT_H

#include "MessagingUnit.h"
#include "ConnectionUnit.h"
#include "QueueFrame.h"
// #include "AuthentificationFrame.h"

#include "GameServerData.h"
#include "CurrentMapManager.h"

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

    // Initializes the basic frames
    virtual void initFrames() override { addFrame(make_shared<QueueFrame>()); };

    // Fonction to send a packet direclty to a connection throught a ConnectionUnit; Returns the id of the sent packet.
    virtual int sendPacket(sp<ConnectionMessage> message, int connectionId = -1);    

    // TODO : protected ?
    // ConnectionUnit's MessagingInterface's id
    int connectionUnitId = -1;

    // Informations of the current GameServer 
    GameServerData gameServerInfos;
    CurrentMapManager mapInfos;
    sp<CharacterData> playedCharacer = nullptr;

protected:
    // Id of the last packet sent
    int lastPacketId = 0;
};

#define FINISHED_DOFUSBOT_H

#endif