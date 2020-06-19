#ifndef DOFUS_BOTUNIT_H
#define DOFUS_BOTUNIT_H

#include "MessagingUnit.h"
#include "QueueFrame.h"
// #include "AuthentificationFrame.h"

#include "GameServerInformationContainer.h"

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

    int connectionUnitId = -1;
    GameServerInformationContainer gameServerInfos;
};

#endif