#include "DofusBotFrame.h"

bool DofusBotFrame::setParent(MessagingUnit* parent) {
    dofusBotParent = dynamic_cast<DofusBotUnit *>(parent);
    if(dofusBotParent) {
        this->parent = parent;
        return true; 
    }

    return false;
}