#include "CommandFrame.h"

#include "ChangeToUpMapBotCommand.h"
#include "ChangeToDownMapBotCommand.h"
#include "ChangeToRightMapBotCommand.h"
#include "ChangeToLeftMapBotCommand.h"

#include "CollectInteractivesBotCommand.h"
#include "CollectInteractivesMessage.h"

#include "RequestWeightBotCommand.h"
#include "WeightReturnValues.h"

#include "WrongCommand.h"
#include "CommandSuccessReturnValue.h"

#include "ChangeToUpMapMessage.h"
#include "ChangeToDownMapMessage.h"
#include "ChangeToRightMapMessage.h"
#include "ChangeToLeftMapMessage.h"

#include "PlayerMovementErrorMessage.h"
#include "CurrentMapChangedMessage.h"
#include "AllInteractivesCollectedMessage.h"

#include "GameContextCreateMessage.h"
/*
-> si commande est une action/request joueur

-> pdn commande : potientiel softlock
    -> sol : - début combat, sauvegarder la commande en cours, à la fin d'un combat, relancer les commandes
-> juste après commande : commande potentiellement perdue
    -> sol : - si en combat, sauvegarder commande, la relancer en fin de combat
-> commande pdn combat 
    -> sol : stoppe la commande, la sauvegarde et la 'relance' à la fin du combat

-> sinon : on fait comme si de rien était
*/

#define CMD_NOT_AVAILABLE_IN_FIGHT(command)   currentProcessedCommand = command; if(inFight) break;

bool CommandFrame::computeMessage(sp<Message> message, int srcId) {
    if(!inFight) {
        if(message->getId() == GameContextCreateMessage::protocolId) {
            sp<GameContextCreateMessage> gccMsg = dynamic_pointer_cast<GameContextCreateMessage>(message);
            // TODO : remplacer avec GameContextEnum::Fight
            if(gccMsg->context == 2) {
                inFight = true;
                currentState = cf_idle;
            }

            return false;
        }
    } else {
        if(message->getId() == CurrentMapChangedMessage::protocolId) {
            inFight = false;
            if(currentProcessedCommand)
                this->processCommand(currentProcessedCommand);

            return false;
        }
    }

    switch (currentState)
    {
    case cf_idle:
        return computeMessage_idle(message, srcId);

    case cf_changeMap:
        return computeMessage_changeMap(message, srcId);

    case cf_collectInteractives:
        return computeMessage_collectInteractives(message, srcId);

    default:
        Logger::write("Command frame is not in a correct state", LOG_WARNING);
    }

    return false;
}

void CommandFrame::processCommand(sp<BotCommand> command) {
    processedCommandNumber = command->commandNumber;

    sp<CollectInteractivesBotCommand> ciCmd;
    sp<ChangeToDownMapBotCommand> ctdmCmd;
    sp<ChangeToUpMapBotCommand> ctumCmd;
    sp<ChangeToLeftMapBotCommand> ctlmCmd;
    sp<ChangeToRightMapBotCommand> ctrmCmd;

    switch (command->getCommandId())
    {
    case ChangeToUpMapBotCommand::commandId:
        CMD_NOT_AVAILABLE_IN_FIGHT(command)
        ctumCmd = dynamic_pointer_cast<ChangeToUpMapBotCommand>(command);
        dofusBotParent->sendSelfMessage(make_shared<ChangeToUpMapMessage>(ctumCmd->floor));
        currentState = cf_changeMap;
        break;

    case ChangeToDownMapBotCommand::commandId:
        CMD_NOT_AVAILABLE_IN_FIGHT(command)
        ctdmCmd = dynamic_pointer_cast<ChangeToDownMapBotCommand>(command);
        dofusBotParent->sendSelfMessage(make_shared<ChangeToDownMapMessage>(ctdmCmd->floor));
        currentState = cf_changeMap;
        break;
    
    case ChangeToLeftMapBotCommand::commandId:
        CMD_NOT_AVAILABLE_IN_FIGHT(command)
        ctlmCmd = dynamic_pointer_cast<ChangeToLeftMapBotCommand>(command);
        dofusBotParent->sendSelfMessage(make_shared<ChangeToLeftMapMessage>(ctlmCmd->floor));
        currentState = cf_changeMap;
        break;
    
    case ChangeToRightMapBotCommand::commandId:
        CMD_NOT_AVAILABLE_IN_FIGHT(command)
        ctrmCmd = dynamic_pointer_cast<ChangeToRightMapBotCommand>(command);
        dofusBotParent->sendSelfMessage(make_shared<ChangeToRightMapMessage>(ctrmCmd->floor));
        currentState = cf_changeMap;
        break;

    case CollectInteractivesBotCommand::commandId:
        CMD_NOT_AVAILABLE_IN_FIGHT(command)
        ciCmd = dynamic_pointer_cast<CollectInteractivesBotCommand>(command);
        dofusBotParent->sendSelfMessage(make_shared<CollectInteractivesMessage>(ciCmd->interactives));
        currentState = cf_collectInteractives;
        break;

    case RequestWeightBotCommand::commandId:
        {
            int weight = dofusBotParent->characterManager->getWeight();
            int maxWeight = dofusBotParent->characterManager->getMaxWeight();
            this->sendReturnValues(make_shared<WeightReturnValues>(weight, maxWeight));
        }
        break;
    
    default:
        currentProcessedCommand = nullptr;
        this->sendReturnValues(make_shared<WrongCommand>());
        currentState = cf_idle;
        break;
    }
}

void CommandFrame::sendReturnValues(sp<BotCommandReturnValues> returnValues) {
    returnValues->commmandNumber = processedCommandNumber;
    sp<BotCommandReturnValuesMessage> bcrvMsg = make_shared<BotCommandReturnValuesMessage>(returnValues);

    if(!dofusBotParent->sendMessage(bcrvMsg, dofusBotParent->getAPIUnitId())) {
        Logger::write("Could not send BotCommandReturnValuesMessage to APIUnit", LOG_ERROR);
    }

    currentProcessedCommand = nullptr;
}

bool CommandFrame::computeMessage_idle(sp<Message> message, int srcId) {
    if(message->getId() == BotCommandMessage::protocolId) {
        processCommand(dynamic_pointer_cast<BotCommandMessage>(message)->command);

        return true;
    }

    return false;
}

bool CommandFrame::computeMessage_collectInteractives(sp<Message> message, int srcId) {
    if(message->getId() == AllInteractivesCollectedMessage::protocolId) {
        sendReturnValues(make_shared<CommandSuccessReturnValue>(true));
        currentState = cf_idle;

        return true;
    }

    return false;
}

bool CommandFrame::computeMessage_changeMap(sp<Message> message, int srcId) {
    switch (message->getId())
    {
    case CurrentMapChangedMessage::protocolId:
        sendReturnValues(make_shared<CommandSuccessReturnValue>(dofusBotParent->mapInfos->areCellsLoaded()));
        currentState = cf_idle;
        message->keepInLoop = true;
        break;

    // Attention : risque de softlock si le serveur envoie ce message pour dire que le mouvement a pas pu être fait à cause d'une aggression
    case PlayerMovementErrorMessage::protocolId:
        sendReturnValues(make_shared<CommandSuccessReturnValue>(false));
        currentState = cf_idle;
        message->keepInLoop = true;
        break;

    // Il n'y a pas de message d'erreur de la part du serveur si on essaie de changer sur un mauvais id de map.  

    default:
        return false;
    }

    return true;
}