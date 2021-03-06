#include "APIBotConnectionFrame.h"
#include "DofusBotUnit.h"

#include "APIBotUpdatesFrame.h"

#include "AuthentificationSuccessMessage.h"
#include "AuthentificationFailureMessage.h"

#include "ServerInformationsListMessage.h"
#include "ServerSelectedMessage.h"
#include "ServerSelectionSuccessMessage.h"
#include "ServerSelectionFailureMessage.h"

#include "CharacterHardcoreOrEpicInformations.h"
#include "CharacterInformationsListMessage.h"
#include "CharacterSelectedMessage.h"
#include "CharacterSelectionSuccessMessage.h"
#include "CharacterSelectionFailureMessage.h"

#include "DisconnectedMessage.h"

bool APIBotConnectionFrame::computeMessage(sp<Message> message, int srcId) {
    sp<QueryCharacterSelectionMessage> qcsMsg;
    sp<CharacterInformationsListMessage> cilMsg;
    sp<CharacterSelectionMessage> csMsg;

    sp<QueryServerSelectionMessage> qssMsg;
    sp<ServerInformationsListMessage> silMsg;
    sp<ServerSelectionMessage> ssionMsg;
    sp<ServerSelectedMessage> ssedMsg;

    sp<CharacterSelectionMessage> csionMsg;
    sp<CharacterSelectedMessage> csedMsg;

    sp<DisconnectedMessage> dMsg;

    switch (message->getId())
    {
    case BeginAuthentificationMessage::protocolId:
        // Checks if units are available
        if(apiUnitParent->getDofusBotUnitId() == -1) {
            Logger::write("Cannot begin authentification : no dofusBotUnit linked to APIUnit.", LOG_ERROR);
            break;
        }

        if(apiUnitParent->getAPIConnectionId() == -1) {
            Logger::write("Cannot begin authentification : no APIConnectionId is set. This is not normal : check where does this BeginAuthentificationMessage was sent!", LOG_ERROR);
            break;
        }

        // Relays the message to the dofusBotUnit
        apiUnitParent->sendMessage(message, apiUnitParent->getDofusBotUnitId());
        break;

    case AuthentificationSuccessMessage::protocolId:
        // Relays the message to the API client
        apiUnitParent->sendMessage(make_shared<SendPacketRequestMessage>(dynamic_pointer_cast<AuthentificationSuccessMessage>(message), apiUnitParent->getAPIConnectionId()), apiUnitParent->getConnectionUnitId());
        break;

    case AuthentificationFailureMessage::protocolId:
        // Relays the message to the API client
        apiUnitParent->sendMessage(make_shared<SendPacketRequestMessage>(dynamic_pointer_cast<AuthentificationFailureMessage>(message), apiUnitParent->getAPIConnectionId()), apiUnitParent->getConnectionUnitId());
        break;

    case QueryCharacterSelectionMessage::protocolId:
        qcsMsg = dynamic_pointer_cast<QueryCharacterSelectionMessage>(message);
        cilMsg = make_shared<CharacterInformationsListMessage>();

        // Sets the CharacterInformationsListMessage's characters' informations
        for(int i = 0; i < qcsMsg->characters.size(); i++) {
            CharacterInformations character;

            character.id = qcsMsg->characters[i]->id;
            character.name = qcsMsg->characters[i]->name;
            character.breed = qcsMsg->characters[i]->breed;
            character.sex = qcsMsg->characters[i]->sex;
            character.level = qcsMsg->characters[i]->level;

            sp<CharacterHardcoreOrEpicInformations> hardcoreCharacter = dynamic_pointer_cast<CharacterHardcoreOrEpicInformations>(qcsMsg->characters[i]);
            // Character is not selectable if it is on an hardocre server and dead (deathState = 1)
            character.isSelectable = !(hardcoreCharacter && hardcoreCharacter->deathState);

            cilMsg->characters.push_back(character);
        }

        // Sends the characters to the API client
        apiUnitParent->sendMessage(make_shared<SendPacketRequestMessage>(cilMsg, apiUnitParent->getAPIConnectionId()), apiUnitParent->getConnectionUnitId());
        break;

    case CharacterSelectedMessage::protocolId:
        // Relays the character's selection to the dofusBotClient
        csedMsg = dynamic_pointer_cast<CharacterSelectedMessage>(message);
        csionMsg = make_shared<CharacterSelectionMessage>();
        csionMsg->id = csedMsg->id;

        apiUnitParent->sendMessage(csionMsg, apiUnitParent->getDofusBotUnitId());
        break;


    case CharacterSelectionSuccessMessage::protocolId:
        // Relays the message to the API client
        parent->sendMessage(make_shared<SendPacketRequestMessage>(dynamic_pointer_cast<CharacterSelectionSuccessMessage>(message), apiUnitParent->getAPIConnectionId()), apiUnitParent->getConnectionUnitId());
        // Adds update frame
        parent->addFrame(make_shared<APIBotUpdatesFrame>());
        // TODO : 
        // parent->removeFrame(this);
        break;

    case CharacterSelectionFailureMessage::protocolId:
        // Relays the message to the API client
        parent->sendMessage(make_shared<SendPacketRequestMessage>(dynamic_pointer_cast<CharacterSelectionFailureMessage>(message), apiUnitParent->getAPIConnectionId()), apiUnitParent->getConnectionUnitId());
        break;

    case QueryServerSelectionMessage::protocolId:
        qssMsg = dynamic_pointer_cast<QueryServerSelectionMessage>(message);
        silMsg = make_shared<ServerInformationsListMessage>();

        // Sets the ServerInformationsListMessage's servers' informations
        for(int i = 0; i < qssMsg->servers.size(); i++) {
            ServerInformations server;

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

            silMsg->servers.push_back(server);
        }

        // Sends the servers to the API client
        apiUnitParent->sendMessage(make_shared<SendPacketRequestMessage>(silMsg, apiUnitParent->getAPIConnectionId()), apiUnitParent->getConnectionUnitId());
        break;

    case ServerSelectedMessage::protocolId:
        // Relays the server's selection to the dofusBotClient
        ssedMsg = dynamic_pointer_cast<ServerSelectedMessage>(message);
        ssionMsg = make_shared<ServerSelectionMessage>();
        ssionMsg->serverId = ssedMsg->id;
        
        apiUnitParent->sendMessage(ssionMsg, apiUnitParent->getDofusBotUnitId());
        break;

    case ServerSelectionSuccessMessage::protocolId:
        // Relays the message to the API client
        parent->sendMessage(make_shared<SendPacketRequestMessage>(dynamic_pointer_cast<ServerSelectionSuccessMessage>(message), apiUnitParent->getAPIConnectionId()), apiUnitParent->getConnectionUnitId());
        break;

    case ServerSelectionFailureMessage::protocolId:
        // Relays the message to the API client
        parent->sendMessage(make_shared<SendPacketRequestMessage>(dynamic_pointer_cast<ServerSelectionFailureMessage>(message), apiUnitParent->getAPIConnectionId()), apiUnitParent->getConnectionUnitId());
        break;

        // TODO : make states : beg auth, server/char selection, ...

    default:
        return false;
    }

    return true;
}