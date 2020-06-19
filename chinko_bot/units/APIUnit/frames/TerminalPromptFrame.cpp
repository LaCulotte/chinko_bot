#include "TerminalPromptFrame.h"

bool TerminalPromptFrame::setParent(MessagingUnit* parent) {
    if(dynamic_cast<APIUnit *>(parent)) {
        this->parent = parent; 
        return true;
    }

    return false;
}

bool TerminalPromptFrame::computeMessage(sp<Message> message, int srcId) {

    sp<BasicCharactersListMessage> bclMsg;
    
    sp<CharacterSelectionMessage> csMsg;

    switch(message->getId()) {
    case CharactersListMessage::protocolId:
    case BasicCharactersListMessage::protocolId:
        bclMsg = dynamic_pointer_cast<BasicCharactersListMessage>(message);

        cout << "Choose character : " << endl;
        for(int i = 0; i < bclMsg->characters.size(); i++) {
            sp<CharacterBaseInformations> character = bclMsg->characters[i];
            cout << "(" << i << ") " << character->name << " : lvl " << character->level << "; ";
            cout << (character->sex?"Female ":"Male ") << breed_idToString[character->breed] << "." << endl; 
        }

        int selectedCharacterId;
        do {
            cin >> selectedCharacterId;
            cout << "Selected" << bclMsg->characters[selectedCharacterId]->name << endl;
        } while (selectedCharacterId < 0 || selectedCharacterId >= bclMsg->characters.size());

        csMsg = make_shared<CharacterSelectionMessage>(bclMsg->characters[selectedCharacterId]->id);
        parent->sendMessage(csMsg, srcId);

        break;
    default:
        return false;
    }

    return true;
}