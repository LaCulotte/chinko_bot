#include "CharacterUpdatesFrame.h"

#include "ShortcutBarContentMessage.h"
#include "JobExperienceUpdateMessage.h"
#include "JobExperienceMultiUpdateMessage.h"
#include "JobDescriptionMessage.h"
#include "AlmanachCalendarDateMessage.h"
#include "CharacterExperienceGainMessage.h"
#include "SpellListMessage.h"
#include "CharacterStatsListMessage.h"
#include "CharacterLevelUpMessage.h"
#include "JobLevelUpMessage.h"

#include "InventoryContentMessage.h"
#include "InventoryWeightMessage.h"
#include "ObjectAddedMessage.h"
#include "ObjectsAddedMessage.h"
#include "ObjectQuantityMessage.h"
#include "ObjectsQuantityMessage.h"
#include "ObjectModifiedMessage.h"
#include "ObjectDeletedMessage.h"
#include "ObjectsDeletedMessage.h"
#include "KamasUpdateMessage.h"

#include "JobsXpMessage.h"

bool CharacterUpdatesFrame::computeMessage(sp<Message> message, int srcId) {
    sp<ShortcutBarContentMessage> sbcMsg;
    sp<JobExperienceUpdateMessage> jeuMsg;
    sp<JobExperienceMultiUpdateMessage> jemuMsg;
    sp<AlmanachCalendarDateMessage> acdMsg;
    sp<CharacterExperienceGainMessage> cegMsg;
    sp<SpellListMessage> slMsg;
    sp<JobDescriptionMessage> jdMsg;
    sp<CharacterStatsListMessage> cslMsg;
    sp<CharacterLevelUpMessage> cluMsg;
    sp<JobLevelUpMessage> jluMsg;

    sp<InventoryContentMessage> icMsg;
    sp<InventoryWeightMessage> iwMsg;
    sp<ObjectQuantityMessage> oqMsg;
    sp<ObjectsQuantityMessage> osqMsg;
    sp<ObjectAddedMessage> oaMsg;
    sp<ObjectsAddedMessage> osaMsg;
    sp<ObjectDeletedMessage> odMsg;
    sp<ObjectsDeletedMessage> osdMsg;
    sp<ObjectModifiedMessage> omMsg;
    sp<KamasUpdateMessage> kuMsg;

    vector<int> updatesId;

    switch (message->getId())
    {
    case ShortcutBarContentMessage::protocolId:
        sbcMsg = dynamic_pointer_cast<ShortcutBarContentMessage>(message);
        Logger::write("Received ShortcutBarContentMessage", LOG_INFO);
        break;

    case JobExperienceUpdateMessage::protocolId:
        jeuMsg = dynamic_pointer_cast<JobExperienceUpdateMessage>(message);
        Logger::write("Received JobExperienceUpdateMessage", LOG_INFO);
        dofusBotParent->characterManager->updateJobXp(jeuMsg->experiencesUpdate);

        dofusBotParent->characterManager->sendJobsXpMessage({jeuMsg->experiencesUpdate.jobId});
        break;

    case JobExperienceMultiUpdateMessage::protocolId:
        jemuMsg = dynamic_pointer_cast<JobExperienceMultiUpdateMessage>(message);
        Logger::write("Received JobExperienceMultiUpdateMessage", LOG_INFO);


        for(int i = 0; i < jemuMsg->experiencesUpdate.size(); i++) {
            dofusBotParent->characterManager->updateJobXp(jemuMsg->experiencesUpdate[i]);

            updatesId.push_back(jemuMsg->experiencesUpdate[i].jobId);
        }

        dofusBotParent->characterManager->sendJobsXpMessage(updatesId);
        break;

    case JobDescriptionMessage::protocolId:
        jdMsg = dynamic_pointer_cast<JobDescriptionMessage>(message);
        Logger::write("Received JobDescriptionMessage", LOG_INFO);
        dofusBotParent->characterManager->loadJobs(jdMsg);
        
        for(int i = 0; i < jdMsg->jobsDescription.size(); i++)
            updatesId.push_back(jdMsg->jobsDescription[i].jobId);
        dofusBotParent->characterManager->sendJobsInformationsMessage(updatesId);
        break;

    case AlmanachCalendarDateMessage::protocolId:
        acdMsg = dynamic_pointer_cast<AlmanachCalendarDateMessage>(message);
        Logger::write("Received AlmanachCalendarDateMessage", LOG_INFO);
        break;

    case CharacterExperienceGainMessage::protocolId:
        cegMsg = dynamic_pointer_cast<CharacterExperienceGainMessage>(message);
        Logger::write("Received CharacterExperienceGainMessage", LOG_INFO);
        // TODO à enlever? : ne fait rien : déjà fait dans le CharacterStatsListMessage (envoyé à chaque fin de combat)
        // dofusBotParent->characterManager->addXp(cegMsg->experienceCharacter);
        break;

    case CharacterLevelUpMessage::protocolId:
        cluMsg = dynamic_pointer_cast<CharacterLevelUpMessage>(message);
        dofusBotParent->characterManager->setLevel(cluMsg->newLevel);

        dofusBotParent->characterManager->sendCharacterLevelMessage();
        break;

    case JobLevelUpMessage::protocolId:
        jluMsg = dynamic_pointer_cast<JobLevelUpMessage>(message);
        dofusBotParent->characterManager->addJob(jluMsg->jobsDescription);
        dofusBotParent->characterManager->setJobLevel(jluMsg->jobsDescription.jobId, jluMsg->newLevel);

        dofusBotParent->characterManager->sendJobsInformationsMessage({jluMsg->jobsDescription.jobId});
        break;

    case SpellListMessage::protocolId:
        slMsg = dynamic_pointer_cast<SpellListMessage>(message);
        Logger::write("Received SpellListMessage", LOG_INFO);
        break;

    case CharacterStatsListMessage::protocolId:
        cslMsg = dynamic_pointer_cast<CharacterStatsListMessage>(message);
        Logger::write("Received CharacterStatsListMessage", LOG_INFO);

        dofusBotParent->characterManager->setXp(cslMsg->stats.experience, cslMsg->stats.experienceLevelFloor, cslMsg->stats.experienceNextLevelFloor);
        dofusBotParent->characterManager->setKamas(cslMsg->stats.kamas);

        dofusBotParent->characterManager->sendCharacterXpMessage();
        dofusBotParent->characterManager->sendKamasMessage();
        break;

    case InventoryContentMessage::protocolId:
        icMsg = dynamic_pointer_cast<InventoryContentMessage>(message);
        Logger::write("Received InventoryContentMessage", LOG_INFO);
        dofusBotParent->characterManager->loadInventory(icMsg);

        for(int i = 0; i < icMsg->objects.size(); i++)
            updatesId.push_back(icMsg->objects[i].objectUID);
        dofusBotParent->characterManager->sendItemsAddMessage(updatesId);
        break;

    case InventoryWeightMessage::protocolId:
        iwMsg = dynamic_pointer_cast<InventoryWeightMessage>(message);
        Logger::write("Received InventoryWeightMessage", LOG_INFO);
        Logger::write("Current weight : " + to_string(iwMsg->inventoryWeight) + "/" + to_string(iwMsg->weightMax), LOG_INFO);

        dofusBotParent->characterManager->setWeight(iwMsg->inventoryWeight);
        dofusBotParent->characterManager->setMaxWeight(iwMsg->weightMax);
        dofusBotParent->characterManager->sendInventoryWeightMessage();
        break;

    case ObjectQuantityMessage::protocolId:
        oqMsg = dynamic_pointer_cast<ObjectQuantityMessage>(message);
        Logger::write("Received ObjectQuantityMessage.", LOG_INFO);
        dofusBotParent->characterManager->setItemQuantity(oqMsg->objectUID, oqMsg->quantity);

        dofusBotParent->characterManager->sendItemsAddMessage({oqMsg->objectUID});
        break;

    case ObjectsQuantityMessage::protocolId:
        osqMsg = dynamic_pointer_cast<ObjectsQuantityMessage>(message);
        Logger::write("Received ObjectsQuantityMessage.", LOG_INFO);

        for(auto uidAndQtt : osqMsg->objectsUIDAndQty) {
            dofusBotParent->characterManager->setItemQuantity(uidAndQtt.objectUID, uidAndQtt.quantity);
            updatesId.push_back(uidAndQtt.objectUID);
        }
        dofusBotParent->characterManager->sendItemsAddMessage(updatesId);
        break;

    case ObjectAddedMessage::protocolId:
        oaMsg = dynamic_pointer_cast<ObjectAddedMessage>(message);
        Logger::write("Received ObjectAddedMessage.", LOG_INFO);
        
        dofusBotParent->characterManager->addItem(oaMsg->object.objectUID, oaMsg->object.objectGID, oaMsg->object.quantity);
        dofusBotParent->characterManager->sendItemsAddMessage({oaMsg->object.objectUID});
        break;

    case ObjectsAddedMessage::protocolId:
        osaMsg = dynamic_pointer_cast<ObjectsAddedMessage>(message);
        Logger::write("Received ObjectsAddedMessage.", LOG_INFO);
        
        for(auto o : osaMsg->object) {
            dofusBotParent->characterManager->addItem(o.objectUID, o.objectGID, o.quantity);
            updatesId.push_back(o.objectUID);
        }
        dofusBotParent->characterManager->sendItemsAddMessage(updatesId);
        break;

    case ObjectModifiedMessage::protocolId:
        omMsg = dynamic_pointer_cast<ObjectModifiedMessage>(message);
        Logger::write("Received ObjectModifiedMessage.", LOG_INFO);
        
        dofusBotParent->characterManager->addItem(omMsg->object.objectUID, omMsg->object.objectGID, omMsg->object.quantity);
        dofusBotParent->characterManager->sendItemsAddMessage({omMsg->object.objectUID});
        break;

    case ObjectDeletedMessage::protocolId:
        odMsg = dynamic_pointer_cast<ObjectDeletedMessage>(message);
        Logger::write("Received ObjectDeletedMessage.", LOG_INFO);
        
        dofusBotParent->characterManager->removeItem(odMsg->objectUID);
        dofusBotParent->characterManager->sendItemsRemoveMessage({odMsg->objectUID});
        break;

    case ObjectsDeletedMessage::protocolId:
        osdMsg = dynamic_pointer_cast<ObjectsDeletedMessage>(message);
        Logger::write("Received ObjectsDeletedMessage.", LOG_INFO);
        
        for(auto uid : osdMsg->objectUID) {
            dofusBotParent->characterManager->removeItem(uid);
            updatesId.push_back(uid);
        }

        dofusBotParent->characterManager->sendItemsRemoveMessage(updatesId);
        break;

    case KamasUpdateMessage::protocolId:
        kuMsg = dynamic_pointer_cast<KamasUpdateMessage>(message);
        Logger::write("Received KamasUpdateMessage.", LOG_INFO);
        dofusBotParent->characterManager->setKamas(kuMsg->kamasTotal);

        dofusBotParent->characterManager->sendKamasMessage();
        break;

    default:
        return false;
    }

    return true;
}