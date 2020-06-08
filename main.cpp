#include "DofusBotUnit.h"
#include "ConnectionUnit.h"

int main(){
    Logger::beginInstance();

    sp<ConnectionUnit> cu (new ConnectionUnit());
    sp<DofusBotUnit> dbu (new DofusBotUnit());

    dbu->addFrame(make_shared<AuthentificationFrame>());
    cu->initFrames();

    MessagingUnit::link(cu, dbu);

    cu->launch().get();
    dbu->launch().get();

    sp<BeginAuthentificationMessage> baMsg (new BeginAuthentificationMessage("salut", "prout"));
    dbu->sendSelfMessage(baMsg);

    usleep(5000*1000);

    cu->stop();
    dbu->stop();

    cu->waitThreadEnd();
    dbu->waitThreadEnd();

    Logger::endInstance();

    return 0;
}