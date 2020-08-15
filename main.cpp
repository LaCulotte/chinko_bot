#include "DofusBotUnit.h"
#include "ConnectionUnit.h"
#include "APIUnit.h"

#include "AuthentificationFrame.h"
#include "TerminalPromptFrame.h"
#include "BasicDofusBotFrame.h"
#include "TimeFrame.h"
// #include "BasicActionsFrame.h"
// #include "MapInformationsContainer.h"
// #include <math.h>

#include "FightFrame.h"

#define USERNAME "OMAGAAD"
#define PASSWORD "420Blazeit"

int main(){    
    Logger::beginInstance();
    
    sp<ConnectionUnit> cu (new ConnectionUnit());
    sp<DofusBotUnit> dbu (new DofusBotUnit());
    sp<APIUnit> au(new APIUnit());

    dbu->addFrame(make_shared<TimeFrame>());
    dbu->addFrame(make_shared<AuthentificationFrame>());
    dbu->addFrame(make_shared<BasicDofusBotFrame>());
    dbu->addFrame(make_shared<FightFrame>());
    dbu->initFrames();
    cu->initFrames();
    au->addFrame(make_shared<TerminalPromptFrame>());

    MessagingUnit::link(cu, dbu);
    MessagingUnit::link(au, dbu);

    cu->launch().get();
    dbu->launch().get();
    au->launch().get();

    sp<BeginAuthentificationMessage> baMsg (new BeginAuthentificationMessage(USERNAME, PASSWORD));
    dbu->sendSelfMessage(baMsg);

    // usleep(1000 * 1000*1000);
    while(true);

    cu->stop();
    dbu->stop();
    au->stop();

    cu->waitThreadEnd();
    dbu->waitThreadEnd();
    au->waitThreadEnd();

    Logger::endInstance();


    return 0;
}