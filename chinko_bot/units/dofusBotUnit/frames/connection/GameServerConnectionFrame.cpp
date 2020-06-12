#include "GameServerConnectionFrame.h"

bool GameServerConnectionFrame::setParent(MessagingUnit* parent) {
    if(dynamic_cast<DofusBotUnit *>(parent)){
        this->parent = parent;
        return true;
    }

    return false;
}

// TODO : reset propre en cas d'erreur : message?
bool GameServerConnectionFrame::computeMessage(sp<Message> message, int srcId) {
    DofusBotUnit* botParent = dynamic_cast<DofusBotUnit *>(parent);

    sp<BeginGameServerConnectionMessage> bgscMsg;
    sp<ConnectionSuccessMessage> csMsg;
    sp<ConnectionFailureMessage> cfMsg;

    sp<UnknownDofusMessage> udMsg;
    sp<ProtocolRequiredMessage> prMsg;

    switch (message->getId())
    {
    case BeginGameServerConnectionMessage::protocolId:
        bgscMsg = dynamic_pointer_cast<BeginGameServerConnectionMessage>(message);

        if(!manager) {
            Logger::write("Cannot begin Game server connection if there is no AuthentificationManager.", LOG_ERROR);
            // TODO : reset complet (Erreur de progammation, pas de connection/authentification)
            break;
        }

        serverAddress = bgscMsg->ssdMsg->address;
        serverPorts = bgscMsg->ssdMsg->ports;
        if(serverPorts.size() <= 0) {
            Logger::write("Cannot connect to the game server (" + serverAddress + ") : No port specified.", LOG_ERROR);
            // TODO : reset vers authentification
            break;
        }
        serverPorts_i = 0;
        
        if(!manager->connectGameServer(serverAddress, serverPorts[0])) {
            // TODO : reset vers authentification
        }

        break;
    
    case ConnectionSuccessMessage::protocolId:
        csMsg = dynamic_pointer_cast<ConnectionSuccessMessage>(message);
        manager->setDofusConnectionId(csMsg->connectionId);
        Logger::write("Connected to the game server : " + serverAddress, LOG_INFO);
        break;

    case ConnectionFailureMessage::protocolId:
        cfMsg = dynamic_pointer_cast<ConnectionFailureMessage>(message);
        Logger::write("Failed to connect to " + serverAddress + ":" + to_string(serverPorts[serverPorts_i]) + "; Reason : " + cfMsg->reason, LOG_WARNING);
        if(++serverPorts_i >= serverPorts.size()) {
            Logger::write("Cannot connect to the game server", LOG_ERROR);
            // TODO : reset authentification
            break;
        } else {
            Logger::write("Trying an next port", LOG_WARNING);
            if(!manager->connectGameServer(serverAddress, serverPorts[serverPorts_i])) {
                // TODO : reset vers authentification
            }
        }
        break;

     case ProtocolRequiredMessage::protocolId:
        prMsg = dynamic_pointer_cast<ProtocolRequiredMessage>(message);
        Logger::write("ProtocolRequiredMessage received", LOG_INFO);
        Logger::write("Required version : " + to_string(prMsg->requiredVersion) + "; Current version : " + to_string(prMsg->currentVersion), LOG_INFO);
        break;

    // TODO : enlever
    case UnknownDofusMessage::protocolId:
        udMsg = dynamic_pointer_cast<UnknownDofusMessage>(message);
        Logger::write("Got message of unkown id : " + to_string(udMsg->real_id) + ";", LOG_DEBUG);
        Logger::write("Length: " + to_string(udMsg->getLength()) + ";", LOG_DEBUG);
        if(udMsg->data)
            Logger::write("Data : " + udMsg->data->toString(), LOG_DEBUG);
        break;

    default:
        return false;
    }

    return true;
}