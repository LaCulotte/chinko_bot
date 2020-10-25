#include "APIBotConnectionFrame.h"
#include "DofusBotUnit.h"

#include "AuthentificationFailureMessage.h"

#include "ServerSelectionListMessage.h"
#include "ServerSelectMessage.h"
#include "DisconnectedMessage.h"

bool APIBotConnectionFrame::computeMessage(sp<Message> message, int srcId) {
    sp<QueryCharacterSelectionMessage> qcsMsg;
    sp<CharacterSelectionMessage> csMsg;

    sp<QueryServerSelectionMessage> qssMsg;
    sp<ServerSelectionListMessage> sslMsg;
    sp<ServerSelectionMessage> ssionMsg;
    // TODO : faire mieux (au minimum un meilleur nom)
    sp<ServerSelectMessage> ssMsg;

    sp<ConnectionIdMessage> ciMsg;
    sp<DisconnectedMessage> dMsg;

    switch (message->getId())
    {
    case ConnectionIdMessage::protocolId:
        ciMsg = dynamic_pointer_cast<ConnectionIdMessage>(message);
        if(ciMsg->ids.size() > 0)
            apiUnitParent->setAPIConnectionId(ciMsg->ids[0]);
        break;

    case BeginAuthentificationMessage::protocolId:
        if(apiUnitParent->getDofusBotUnitId() == -1) {
            Logger::write("Cannot begin authentification : no dofusBotUnit linked to APIUnit.", LOG_ERROR);
            break;
        }

        if(apiUnitParent->getAPIConnectionId() == -1) {
            Logger::write("Cannot begin authentification : no APIConnectionId is set. This is not normal : check where does this BeginAuthentificationMessage was sent!", LOG_ERROR);
            break;
        }

        apiUnitParent->sendMessage(message, apiUnitParent->getDofusBotUnitId());
        break;

    case AuthentificationFailureMessage::protocolId:
        apiUnitParent->sendMessage(make_shared<SendPacketRequestMessage>(dynamic_pointer_cast<AuthentificationFailureMessage>(message), apiUnitParent->getAPIConnectionId()), apiUnitParent->getConnectionUnitId());
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
        sslMsg = make_shared<ServerSelectionListMessage>();

        for(int i = 0; i < qssMsg->servers.size(); i++) {
            ServerSelectInformations server;

            server.id = qssMsg->servers[i].id;

            auto serverNameIt = server_idToString.find(qssMsg->servers[i].id); 
            if(serverNameIt != server_idToString.end())
                server.name = serverNameIt->second;
            else
                server.name = to_string(server.id);

            server.charactersCount = qssMsg->servers[i].charactersCount;
            server.slotsCount = qssMsg->servers[i].charactersSlots;
            server.status = qssMsg->servers[i].status;
            server.isSelectable = qssMsg->servers[i].isSelectable;

            sslMsg->servers.push_back(server);
        }

        apiUnitParent->sendMessage(make_shared<SendPacketRequestMessage>(sslMsg), apiUnitParent->getConnectionUnitId());
        // cout << "Choose character : " << endl;
        // for(int i = 0; i < qssMsg->servers.size(); i++) {
        //     GameServerInformations server = qssMsg->servers[i];

        //     auto serverNameIt = server_idToString.find(server.id); 

        //     cout << "(" << i << ") " << (serverNameIt!=server_idToString.end()?serverNameIt->second:"TODO") << " (" << (server.isSelectable?"Avalaible":"Unavailable") << ") ";
        //     cout << server.charactersCount << "/" << server.charactersSlots << " characters." << endl;
        //     // cout << (character->sex?"Female ":"Male ") << breed_idToString[character->breed] << "." << endl; 
        // }

        // {
        //     int selectedServerId;
        //     do {
        //         cin >> selectedServerId;
        //     } while (selectedServerId < 0 || selectedServerId >= qssMsg->servers.size());

        //     ssMsg = make_shared<ServerSelectionMessage>();
        //     ssMsg->serverId = qssMsg->servers[selectedServerId].id;
        //     parent->sendMessage(ssMsg, srcId);
        // }
        break;

    case ServerSelectMessage::protocolId:
        ssMsg = dynamic_pointer_cast<ServerSelectMessage>(message);
        ssionMsg = make_shared<ServerSelectionMessage>();
        ssionMsg->serverId = ssMsg->id;
        apiUnitParent->sendMessage(ssionMsg, apiUnitParent->getDofusBotUnitId());
        break;

        // TODO : make states : beg auth, server/char selection, ...

    default:
        return false;
    }

    return true;
}