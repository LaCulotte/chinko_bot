#include "PlayedCharacterManager.h"

#include "JobsXpMessage.h"
#include "JobsInformationsMessage.h"
#include "PlayedCharacterLevelMessage.h"
#include "PlayedCharacterInformationsMessage.h"
#include "PlayedCharacterXpMessage.h"
#include "PlayedCharacterKamasMessage.h"
#include "ItemsAddMessage.h"
#include "PlayedCharacterInventoryWeightMessage.h"

void PlayedCharacterManager::loadSkills() {
    ifstream skillsFile(skillsFile_path, ifstream::binary);

    Json::Value skills_json;
    Json::CharReaderBuilder skills_readerBuilder;

    string error_str;
    bool could_read = Json::parseFromStream(skills_readerBuilder, skillsFile, &skills_json, &error_str); 

    if(!could_read) {
        Logger::write("Cannot open file '" +  skillsFile_path + "', it is not a correct json file. Error : " + error_str, LOG_ERROR);
        return;
    }

    skillId_to_elementId.clear();
    skillId_to_range.clear();

    for(auto skill_json : skills_json) {
        int id = skill_json["id"].asInt();

        skillId_to_elementId[id] = skill_json["interactiveId"].asInt();
        skillId_to_range[id] = skill_json["range"].asInt();
    }
}

void PlayedCharacterManager::addItem(int itemUID, int itemGID, int quantity) {
    auto itemIt = infos->inventory.find(itemUID);
    if(itemIt != infos->inventory.end())
        Logger::write("Overriding an already existing item. Incorrect if ObjectModifiedMessage is not the origin of this change.", LOG_WARNING);

    ItemInformations newItem;
    newItem.itemUID = itemUID;
    newItem.itemGID = itemGID;
    newItem.quantity = quantity;
    
    infos->inventory.insert({newItem.itemUID, newItem});
}

void PlayedCharacterManager::setItemQuantity(int itemUID, int quantity) {
    auto itemIt = infos->inventory.find(itemUID);
    if(itemIt == infos->inventory.end()) {
        Logger::write("No item of uid " + to_string(itemUID) + " present in the inventory. No quantity modification is possible.", LOG_WARNING);
        return;
    }

    itemIt->second.quantity = quantity;
}

void PlayedCharacterManager::removeItem(int itemUID) {
    auto itemIt = infos->inventory.find(itemUID);
    if(itemIt == infos->inventory.end()) {
        Logger::write("No item of uid " + to_string(itemUID) + " present in the inventory. No quantity modification is possible.", LOG_WARNING);
        return;
    }

    infos->inventory.erase(itemIt);
}

void PlayedCharacterManager::addJob(JobDescription job) {
    JobInformations* newJob;
    auto oldJob = infos->jobs.find(job.jobId);

    if(oldJob != infos->jobs.end())
        newJob = &oldJob->second;
    else
        newJob = new JobInformations(job.jobId);
    

    for(auto skill : job.skills) {
        if(skillId_to_elementId.find(skill->skillId) == skillId_to_elementId.end())
            continue;

        SkillInformations newSkill;
        newSkill.skillId = skill->skillId;
        newSkill.interactiveId = skillId_to_elementId.find(skill->skillId)->second;
        newSkill.range = skillId_to_range.find(skill->skillId)->second;

        newJob->skills[newSkill.skillId] = newSkill;
    }

    if(oldJob == infos->jobs.end())
        infos->jobs.insert({newJob->jobId, *newJob});
}

void PlayedCharacterManager::loadInventory(sp<InventoryContentMessage> icMsg) {
    infos->kamas = icMsg->kamas;
    
    for(int i = 0; i < icMsg->objects.size(); i++)
        this->addItem(icMsg->objects[i].objectUID, icMsg->objects[i].objectGID, icMsg->objects[i].quantity);
}

void PlayedCharacterManager::loadJobs(sp<JobDescriptionMessage> jdMsg) {
    for(int i = 0; i < jdMsg->jobsDescription.size(); i++)
        this->addJob(jdMsg->jobsDescription[i]);
}

void PlayedCharacterManager::updateJobXp(JobExperience jobXp) {
    JobInformations* job;
    auto oldJob = infos->jobs.find(jobXp.jobId);

    if(oldJob != infos->jobs.end())
        job = &oldJob->second;
    else
        job = new JobInformations(jobXp.jobId);

    job->xp = jobXp.jobXP;
    job->level = jobXp.jobLevel;
    job->xpLevelFloor = jobXp.jobXpLevelFloor;
    job->xpNextLevelFloor = jobXp.jobXpNextLevelFloor;

    if(oldJob == infos->jobs.end())
        infos->jobs.insert({jobXp.jobId, *job});
} 

void PlayedCharacterManager::setXp(uint64_t xp, uint64_t xpLevelFloor, uint64_t xpNextLevelFloor) {
    infos->xp = xp;
    infos->xpLevelFloor = xpLevelFloor;
    infos->xpNextLevelFloor = xpNextLevelFloor;
}

void PlayedCharacterManager::setJobLevel(int jobId, int newLevel) {
    JobInformations* job;
    auto oldJob = infos->jobs.find(jobId);

    if(oldJob != infos->jobs.end())
        job = &oldJob->second;
    else
        job = new JobInformations(jobId);

    job->level = newLevel;

    if(oldJob == infos->jobs.end())
        infos->jobs.insert({jobId, *job});
}

void PlayedCharacterManager::sendCharacterLevelMessage() {
    if(!fullyLoaded)
        return;

    sp<PlayedCharacterLevelMessage> clMsg = make_shared<PlayedCharacterLevelMessage>();

    clMsg->level = infos->level;

    if(!dofusBot || !dofusBot->sendMessage(clMsg, dofusBot->getAPIUnitId()))
        Logger::write("Could not send PlayedCharacterLevelMessage. No dofusBotUnit or APIUnit.", LOG_DEBUG);
}

void PlayedCharacterManager::sendCharacterInformationsMessage() {
    if(!fullyLoaded)
        return;

    sp<PlayedCharacterInformationsMessage> pciMsg = make_shared<PlayedCharacterInformationsMessage>();

    pciMsg->infos = infos;

    if(!dofusBot || !dofusBot->sendMessage(pciMsg, dofusBot->getAPIUnitId()))
        Logger::write("Could not send PlayedCharacterInformationsMessage. No dofusBotUnit or APIUnit.", LOG_DEBUG);
}

void PlayedCharacterManager::sendCharacterXpMessage() {
    if(!fullyLoaded)
        return;
        
    sp<PlayedCharacterXpMessage> pcxMsg = make_shared<PlayedCharacterXpMessage>();

    pcxMsg->xp = infos->xp;
    pcxMsg->xpLevelFloor = infos->xpLevelFloor;
    pcxMsg->xpNextLevelFloor = infos->xpNextLevelFloor;

    if(!dofusBot || !dofusBot->sendMessage(pcxMsg, dofusBot->getAPIUnitId()))
        Logger::write("Could not send PlayedCharacterXpMessage. No dofusBotUnit or APIUnit.", LOG_DEBUG);
}

void PlayedCharacterManager::sendKamasMessage() {
    if(!fullyLoaded)
        return;
        
    sp<PlayedCharacterKamasMessage> pckMsg = make_shared<PlayedCharacterKamasMessage>();

    pckMsg->kamas = infos->kamas;

    if(!dofusBot || !dofusBot->sendMessage(pckMsg, dofusBot->getAPIUnitId()))
        Logger::write("Could not send PlayedCharacterKamasMessage. No dofusBotUnit or APIUnit.", LOG_DEBUG);
}

void PlayedCharacterManager::sendInventoryWeightMessage() {
    if(!fullyLoaded)
        return;
        
    sp<PlayedCharacterInventoryWeightMessage> pciwMsg = make_shared<PlayedCharacterInventoryWeightMessage>();

    pciwMsg->weight = infos->weight;
    pciwMsg->maxWeight = infos->maxWeight;

    if(!dofusBot || !dofusBot->sendMessage(pciwMsg, dofusBot->getAPIUnitId()))
        Logger::write("Could not send PlayedCharacterInventoryWeightMessage. No dofusBotUnit or APIUnit.", LOG_DEBUG);
}

void PlayedCharacterManager::sendJobsXpMessage(vector<int> jobsId) {
    if(!fullyLoaded)
        return;
        
    sp<JobsXpMessage> jxMsg = make_shared<JobsXpMessage>();

    for(int jobId : jobsId) {
        auto jobIt = infos->jobs.find(jobId);
        if(jobIt != infos->jobs.end()) {
            JobXp xp;
            xp.jobId = jobId;
            xp.jobXp = jobIt->second.xp;
            xp.jobXpLevelFloor = jobIt->second.xpLevelFloor;
            xp.jobXpNextLevelFloor = jobIt->second.xpNextLevelFloor;

            jxMsg->jobsXp.push_back(xp);
        } else {
            Logger::write("Could not find job of id : " + to_string(jobId), LOG_WARNING);
        }
    }

    if(!dofusBot || !dofusBot->sendMessage(jxMsg, dofusBot->getAPIUnitId()))
        Logger::write("Could not send JobsXpMessage. No dofusBotUnit or APIUnit.", LOG_DEBUG);
}

void PlayedCharacterManager::sendJobsInformationsMessage(vector<int> jobsId) {
    if(!fullyLoaded)
        return;
        
    sp<JobsInformationsMessage> jiMsg = make_shared<JobsInformationsMessage>();

    for(int jobId : jobsId) {
        auto jobIt = infos->jobs.find(jobId);
        if(jobIt != infos->jobs.end()) {
            jiMsg->jobs.push_back(jobIt->second);
        } else {
            Logger::write("Could not find job of id : " + to_string(jobId), LOG_WARNING);
        }
    }

    if(!dofusBot || !dofusBot->sendMessage(jiMsg, dofusBot->getAPIUnitId()))
        Logger::write("Could not send JobsInformationsMessage. No dofusBotUnit or APIUnit.", LOG_DEBUG);
}

void PlayedCharacterManager::sendItemsAddMessage(vector<int> itemsId) {
    if(!fullyLoaded)
        return;
        
    sp<ItemsAddMessage> iaMsg = make_shared<ItemsAddMessage>();

    for(int itemId : itemsId) {
        auto itemIt = infos->inventory.find(itemId);
        if(itemIt != infos->inventory.end()) {
            iaMsg->items.push_back(itemIt->second);
        } else {
            Logger::write("Could not find item of id : " + to_string(itemId), LOG_WARNING);
        }
    }

    if(!dofusBot || !dofusBot->sendMessage(iaMsg, dofusBot->getAPIUnitId()))
        Logger::write("Could not send ItemsAddMessage. No dofusBotUnit or APIUnit.", LOG_DEBUG);
}

void PlayedCharacterManager::sendItemsRemoveMessage(vector<int> itemsId) {
    if(!fullyLoaded)
        return;
        
    sp<ItemsAddMessage> iaMsg = make_shared<ItemsAddMessage>();

    for(int itemId : itemsId) {
        ItemInformations item;
        item.itemUID = itemId;
        item.quantity = 0;

        iaMsg->items.push_back(item);
    }

    if(!dofusBot || !dofusBot->sendMessage(iaMsg, dofusBot->getAPIUnitId()))
        Logger::write("Could not send ItemsAddMessage. No dofusBotUnit or APIUnit.", LOG_DEBUG);
}

bool PlayedCharacterManager::hasSkill(int skillId) {
    for(auto jobIt = infos->jobs.begin(); jobIt != infos->jobs.end(); jobIt++) {
        if(jobIt->second.skills.find(skillId) != jobIt->second.skills.end())
            return true;
    }
    
    return false;
}

int PlayedCharacterManager::getSkillRange(int skillId) {
    auto skillIt = skillId_to_range.find(skillId);
    if(skillIt != skillId_to_range.end())
        return skillIt->second;

    return -1;
}