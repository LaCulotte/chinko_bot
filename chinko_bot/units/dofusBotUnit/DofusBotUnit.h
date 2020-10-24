#ifndef DOFUS_BOTUNIT_H
#define DOFUS_BOTUNIT_H

#include "MessagingUnit.h"
#include "ConnectionUnit.h"
#include "QueueFrame.h"
// #include "AuthentificationFrame.h"

#include "GameServerData.h"
#include "AbstractMapManager.h"
#include "RoleplayMapManager.h"
#include "FightMapManager.h"

#include "SendPacketRequestMessage.h"
#include "SendPacketSuccessMessage.h"
#include "SendPacketFailureMessage.h"

#include "APIUnit.h"

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
    virtual void initFrames() override;

    // Fonction to send a packet direclty to a connection throught a ConnectionUnit; Returns the id of the sent packet.
    virtual int sendPacket(sp<ConnectionMessage> message, int connectionId = -1);    

    // Get ConnectionUnit's id. Sets it if not already set
    int getConnectionUnitId();
    // Get APIUnit's id. Sets it if not already set
    int getAPIUnitId();

    // Sets the played character to a blank ActorData but containing its contextualId
    void resetPlayedCharacter();

    // Informations of the current GameServer 
    GameServerData gameServerInfos;
    sp<ActorData> playedCharacter = nullptr;

    double currentMapId = 0;
    sp<AbstractMapManager> mapInfos;
    sp<RoleplayMapManager> getMapInfosAsRoleplay() { return dynamic_pointer_cast<RoleplayMapManager>(this->mapInfos); };
    sp<FightMapManager> getMapInfosAsFight() { return dynamic_pointer_cast<FightMapManager>(this->mapInfos); };

    void resetNextTick() { toReset = true; };

protected:
    void tick() override;

    // Id of the last packet sent
    int lastPacketId = 0;

    // ConnectionUnit's MessagingInterface's id
    int connectionUnitId = -1;
    // APIUnit's MessagingInterface's id
    int apiUnitId = -1;

    bool toReset = false;
    void fullReset();
};

#define FINISHED_DOFUSBOT_H

#endif