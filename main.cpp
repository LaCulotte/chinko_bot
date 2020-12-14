#include "DofusBotUnit.h"
#include "ConnectionUnit.h"
#include "APIUnit.h"

#include "AuthentificationFrame.h"
// #include "TerminalPromptFrame.h"
#include "APIBotConnectionFrame.h"
#include "APIClientConnectionFrame.h"
#include "BasicDofusBotFrame.h"
#include "TimeFrame.h"
// #include "BasicActionsFrame.h"
// #include "MapInformationsContainer.h"
// #include <math.h>

#include "FightFrame.h"

#include "ScriptManager.h"
#include "ScriptFrame.h"

int main(){    
    Logger::beginInstance();
        
    sp<ConnectionUnit> cu (new ConnectionUnit());
    sp<DofusBotUnit> dbu (new DofusBotUnit());
    sp<APIUnit> au(new APIUnit());

    // dbu->addFrame(make_shared<TimeFrame>());
    // dbu->addFrame(make_shared<AuthentificationFrame>());
    // dbu->addFrame(make_shared<BasicDofusBotFrame>());
    // dbu->addFrame(make_shared<FightFrame>());
    dbu->initFrames();
    cu->initFrames();
    au->addFrame(make_shared<APIBotConnectionFrame>());
    au->addFrame(make_shared<APIClientConnectionFrame>());
    au->addFrame(make_shared<ScriptFrame>(), true);

    MessagingUnit::link(cu, dbu);
    MessagingUnit::link(au, dbu);
    MessagingUnit::link(cu, au);

    au->launchListeningServer();

    cu->launch().get();
    dbu->launch().get();
    au->launch().get();

    // sp<BeginAuthentificationMessage> baMsg (new BeginAuthentificationMessage(USERNAME, PASSWORD, false));
    // dbu->sendSelfMessage(baMsg);

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
