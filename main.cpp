#include "DofusBotUnit.h"
#include "ConnectionUnit.h"
#include "APIUnit.h"

#include "AuthentificationFrame.h"
#include "TerminalPromptFrame.h"
#include "BasicDofusBotFrame.h"

#define USERNAME "OMAGAAD"
#define PASSWORD "420Blazeit"

int main(){
    Logger::beginInstance();

    sp<ConnectionUnit> cu (new ConnectionUnit());
    sp<DofusBotUnit> dbu (new DofusBotUnit());
    sp<APIUnit> au(new APIUnit());

    dbu->addFrame(make_shared<AuthentificationFrame>());
    dbu->addFrame(make_shared<BasicDofusBotFrame>());
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

    usleep(100000*1000);

    cu->stop();
    dbu->stop();
    au->stop();

    cu->waitThreadEnd();
    dbu->waitThreadEnd();
    au->waitThreadEnd();

    Logger::endInstance();

    return 0;
}