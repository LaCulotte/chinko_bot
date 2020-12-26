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
    // Opens skills' json file
    ifstream skillsFile(skillsFile_path, ifstream::binary);

    Json::Value skills_json;
    Json::CharReaderBuilder skills_readerBuilder;

    // Reads the file's data
    string error_str;
    bool could_read = Json::parseFromStream(skills_readerBuilder, skillsFile, &skills_json, &error_str); 

    if(!could_read) {
        // Logs & returns if there is an error 
        Logger::write("Cannot open file '" +  skillsFile_path + "', it is not a correct json file. Error : " + error_str, LOG_ERROR);
        return;
    }

    skills.clear();

    // Loads the skills into the map
    for(auto skill_json : skills_json) {
        sp<SkillInformations> newSkill = make_shared<SkillInformations>();
        newSkill->skillId = skill_json["id"].asInt();
        newSkill->interactiveId = skill_json["interactiveId"].asInt();
        newSkill->range = skill_json["range"].asInt();

        skills.insert({newSkill->skillId, newSkill});
    }
}

void PlayedCharacterManager::addItem(int itemUID, int itemGID, int quantity) {
    auto itemIt = infos->inventory.find(itemUID);
    if(itemIt != infos->inventory.end())
        Logger::write("Overriding an already existing item. Incorrect if ObjectModifiedMessage is not the origin of this change.", LOG_WARNING);

    // Builds the instance of the item
    ItemInformations newItem;
    newItem.itemUID = itemUID;
    newItem.itemGID = itemGID;
    newItem.quantity = quantity;
    
    // Adds the item instance to the player's inventory
    infos->inventory.insert({newItem.itemUID, newItem});
}

void PlayedCharacterManager::setItemQuantity(int itemUID, int quantity) {
    auto itemIt = infos->inventory.find(itemUID);
    if(itemIt == infos->inventory.end()) {
        Logger::write("No item of uid " + to_string(itemUID) + " present in the inventory. No quantity modification is possible.", LOG_WARNING);
        return;
    }

    //Sets item's quantity
    itemIt->second.quantity = quantity;
}

void PlayedCharacterManager::removeItem(int itemUID) {
    auto itemIt = infos->inventory.find(itemUID);
    if(itemIt == infos->inventory.end()) {
        Logger::write("No item of uid " + to_string(itemUID) + " present in the inventory. No quantity modification is possible.", LOG_WARNING);
        return;
    }

    // Erases the item
    infos->inventory.erase(itemIt);
}

void PlayedCharacterManager::addJob(JobDescription job) {
    // Checks if the player already has the job
    JobInformations* newJob;
    auto oldJob = infos->jobs.find(job.jobId);

    if(oldJob != infos->jobs.end())
        // If so, gets it
        newJob = &oldJob->second;
    else
        // If not, builds a new job instance
        newJob = new JobInformations(job.jobId);
    
    // Adds skills to the jobs
    for(auto skill : job.skills) {
        auto skillIt = skills.find(skill->skillId);
        if(skillIt == skills.end())
            continue;

        newJob->skills[skillIt->second->skillId] = skillIt->second;
    }

    // Inserts the job to the player's jobs list
    if(oldJob == infos->jobs.end())
        infos->jobs.insert({newJob->jobId, *newJob});
}

void PlayedCharacterManager::loadInventory(sp<InventoryContentMessage> icMsg) {
    // Sets player's kamas
    infos->kamas = icMsg->kamas;
    
    // Adds items
    for(int i = 0; i < icMsg->objects.size(); i++)
        this->addItem(icMsg->objects[i].objectUID, icMsg->objects[i].objectGID, icMsg->objects[i].quantity);
}

void PlayedCharacterManager::loadJobs(sp<JobDescriptionMessage> jdMsg) {
    // Add jobs
    for(int i = 0; i < jdMsg->jobsDescription.size(); i++)
        this->addJob(jdMsg->jobsDescription[i]);
}

void PlayedCharacterManager::updateJobXp(JobExperience jobXp) {
    // Checks if the player already has the job
    JobInformations* job;
    auto oldJob = infos->jobs.find(jobXp.jobId);
    
    if(oldJob != infos->jobs.end())
        // If so, gets it
        job = &oldJob->second;
    else
        // If not, builds a new instance
        job = new JobInformations(jobXp.jobId);

    // Sets job's xp & lvl
    job->xp = jobXp.jobXP;
    job->level = jobXp.jobLevel;
    job->xpLevelFloor = jobXp.jobXpLevelFloor;
    job->xpNextLevelFloor = jobXp.jobXpNextLevelFloor;

    // Inserts the job to the player's jobs list
    if(oldJob == infos->jobs.end())
        infos->jobs.insert({jobXp.jobId, *job});
} 

void PlayedCharacterManager::setXp(uint64_t xp, uint64_t xpLevelFloor, uint64_t xpNextLevelFloor) {
    infos->xp = xp;
    infos->xpLevelFloor = xpLevelFloor;
    infos->xpNextLevelFloor = xpNextLevelFloor;
}

void PlayedCharacterManager::setJobLevel(int jobId, int newLevel) {
    // Checks if the player already has the job
    JobInformations* job;
    auto oldJob = infos->jobs.find(jobId);

    if(oldJob != infos->jobs.end())
        // If so, gets it
        job = &oldJob->second;
    else
        // If so, builds a new instance
        job = new JobInformations(jobId);

    // Sets job's level
    job->level = newLevel;

    // Inserts the job to the player's jobs list
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
    // Checks for all the jobs if they have the skillId
    for(auto jobIt = infos->jobs.begin(); jobIt != infos->jobs.end(); jobIt++) {
        if(jobIt->second.skills.find(skillId) != jobIt->second.skills.end())
            return true;
    }
    
    return false;
}

int PlayedCharacterManager::getSkillRange(int skillId) {
    // Gets skill and returns its range
    auto skillIt = skills.find(skillId);
    if(skillIt != skills.end())
        return skillIt->second->range;

    return -1;
}