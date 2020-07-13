#include "DofusBotFrame.h"

bool DofusBotFrame::setParent(MessagingUnit* parent) {
    dofusBotParent = dynamic_cast<DofusBotUnit *>(parent);
    if(dofusBotParent) {
        this->parent = parent;
        return true; 
    }

    return false;
}

void DofusBotFrame::killBot(){
    if(!dofusBotParent)
        return;

    dofusBotParent->stop();
    // TODO :   Ajouter un moyen de clear completement le bot : Frames, connections, messagingInterfaces, etc...
    //          A faire directement dans les classes WorkingUnit, MessagingUnit & DofusBotUnit (+ comportement pour ConnectionUnit)
}