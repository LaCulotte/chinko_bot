#include "APIBotConnectionFrame.h"
#include "DofusBotUnit.h"

bool APIBotConnectionFrame::computeMessage(sp<Message> message, int srcId) {
    sp<QueryCharacterSelectionMessage> qcsMsg;
    sp<CharacterSelectionMessage> csMsg;

    sp<QueryServerSelectionMessage> qssMsg;
    sp<ServerSelectionMessage> ssMsg;

    switch (message->getId())
    {
    case BeginAuthentificationMessage::protocolId:
        if(apiUnitParent->botUnitId == -1) {
            apiUnitParent->botUnitId = apiUnitParent->getMessageInterfaceOutId<DofusBotUnit>();
            if(apiUnitParent->botUnitId == -1) {
                Logger::write("Cannot begin authentification : no dofusBotUnit linked to APIUnit.", LOG_ERROR);
                break;
            }
        }

        apiUnitParent->sendMessage(message, apiUnitParent->botUnitId);
        break;
    case QueryCharacterSelectionMessage::protocolId:
        qcsMsg = dynamic_pointer_cast<QueryCharacterSelectionMessage>(message);

        cout << "Choose character : " << endl;
        for(int i = 0; i < qcsMsg->characters.size(); i++) {
            sp<CharacterBaseInformations> character = qcsMsg->characters[i];
            cout << "(" << i << ") " << character->name << " : lvl " << character->level << "; ";
            cout << (character->sex?"Female ":"Male ") << breed_idToString[character->breed] << "." << endl; 
        }

        {
            int selectedCharacterId;
            do {
                cin >> selectedCharacterId;
            } while (selectedCharacterId < 0 || selectedCharacterId >= qcsMsg->characters.size());

            csMsg = make_shared<CharacterSelectionMessage>();
            csMsg->id = qcsMsg->characters[selectedCharacterId]->id;
            parent->sendMessage(csMsg, srcId);
        }
        break;

    case QueryServerSelectionMessage::protocolId:
        qssMsg = dynamic_pointer_cast<QueryServerSelectionMessage>(message);

        cout << "Choose character : " << endl;
        for(int i = 0; i < qssMsg->servers.size(); i++) {
            GameServerInformations server = qssMsg->servers[i];

            auto serverNameIt = server_idToString.find(server.id); 

            cout << "(" << i << ") " << (serverNameIt!=server_idToString.end()?serverNameIt->second:"TODO") << " (" << (server.isSelectable?"Avalaible":"Unavailable") << ") ";
            cout << server.charactersCount << "/" << server.charactersSlots << " characters." << endl;
            // cout << (character->sex?"Female ":"Male ") << breed_idToString[character->breed] << "." << endl; 
        }

        {
            int selectedServerId;
            do {
                cin >> selectedServerId;
            } while (selectedServerId < 0 || selectedServerId >= qssMsg->servers.size());

            ssMsg = make_shared<ServerSelectionMessage>();
            ssMsg->serverId = qssMsg->servers[selectedServerId].id;
            parent->sendMessage(ssMsg, srcId);
        }
        break;

    case APIHelloMessage::protocolId:
        Logger::write("Recevied APIHelloMessage. : TO REMOVE", LOG_DEBUG);    
        break;

    default:
        return false;
    }

    return true;
}