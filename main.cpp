#include "DofusMessageTypeHandler.h"

int main(){
    sp<DofusMessageTypeHandler> dmth(new DofusMessageTypeHandler());

    cout << dynamic_pointer_cast<UnknownDofusMessage>(dmth->generateMessageById(UnknownDofusMessage::protocolId))->real_id << endl;
    cout << dynamic_pointer_cast<UnknownDofusMessage>(dmth->generateMessageById(7))->real_id << endl;

    return 0;
}