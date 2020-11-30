#ifndef PLAYEDCHARACTER_MANAGER_H
#define PLAYEDCHARACTER_MANAGER_H

#include "DofusBotUnit.h"
#include "PlayedCharacterInformations.h"

#include <json/value.h>
#include <json/reader.h>

#include "JobDescription.h"
#include "CharacterBaseInformations.h"

#include "InventoryContentMessage.h"
#include "JobDescriptionMessage.h"
#include "JobExperience.h"

#define DEFAULT_DATAFILE_PATH "/database/skills/json/skills.json"

class DofusBotUnit;
class PlayedCharacterManager {
public:
    // Constructor
    PlayedCharacterManager() { init(); };
    // Constructor with specified skill file path
    PlayedCharacterManager(string skillsFile_path) { this->skillsFile_path = skillsFile_path; init(); };
    // Copy constructor
    PlayedCharacterManager(const PlayedCharacterManager& other) = delete;

    void init() { infos = make_shared<PlayedCharacterInformations>(); loadSkills(); }

    // Copy operator
    PlayedCharacterManager& operator=(const PlayedCharacterManager& other) = delete;
    // Destructor
    ~PlayedCharacterManager() = default;

    void getInfosFromCharacterInformations(CharacterBaseInformations baseInfos);

    void setId(double id) { infos->id = id; };
    double getId() { return infos->id; }
    void setName(string name) { infos->name = name; };
    void setBreed(int breed) { infos->breedId = breed; }
    void setSex(bool sex) { infos->sex = sex; }

    void setLevel(int level) { infos->level = level; }
    void setXp(uint64_t xp, uint64_t xpLevelFloor, uint64_t xpNextLevelFloor);
    void addXp(uint64_t xpDelta) { infos->xp += xpDelta; };

    void loadInventory(sp<InventoryContentMessage> icMsg);
    void addItem(int itemUID, int itemGID, int quantity);
    void setItemQuantity(int itemUID, int quantity);
    void removeItem(int itemUID);
    void setKamas(uint64_t kamas) { infos->kamas = kamas; };

    void setWeight(int weight) { infos->weight = weight; };
    void setMaxWeight(int maxWeight) { infos->maxWeight = maxWeight; };

    void loadJobs(sp<JobDescriptionMessage> jdMsg);
    void setJobLevel(int jobId, int newLevel);
    void addJob(JobDescription job);
    void updateJobXp(JobExperience jobXp);

    void loadingFinished() { this->fullyLoaded = true; sendCharacterInformationsMessage(); };

    void sendJobsXpMessage(vector<int> jobsids);
    void sendJobsInformationsMessage(vector<int> jobsids);
    void sendCharacterLevelMessage();
    void sendCharacterXpMessage();
    void sendCharacterInformationsMessage();
    void sendItemsAddMessage(vector<int> itemsId);
    void sendItemsRemoveMessage(vector<int> itemsId);
    void sendInventoryWeightMessage();
    void sendKamasMessage();

    bool hasSkill(int skillId);
    int getSkillRange(int skillId);

    DofusBotUnit* dofusBot = nullptr;

protected:
    sp<PlayedCharacterInformations> infos;

    string skillsFile_path = "database/skills/json/Skills.json";
    void loadSkills();
    unordered_map<int, int> skillId_to_elementId;
    unordered_map<int, int> skillId_to_range;

    bool fullyLoaded = false;
};

#endif