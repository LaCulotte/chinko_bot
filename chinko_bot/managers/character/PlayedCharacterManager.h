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

    // Initialization of the manager
    void init() { infos = make_shared<PlayedCharacterInformations>(); loadSkills(); }

    // Copy operator
    PlayedCharacterManager& operator=(const PlayedCharacterManager& other) = delete;
    // Destructor
    ~PlayedCharacterManager() = default;

    // void getInfosFromCharacterInformations(CharacterBaseInformations baseInfos);

    // Sets player's actor Id
    void setId(double id) { infos->id = id; };
    // Gets player's actor Id
    double getId() { return infos->id; }
    // Sets player's name
    void setName(string name) { infos->name = name; };
    // Sets player's breed
    void setBreed(int breed) { infos->breedId = breed; }
    // Sets player's sex
    void setSex(bool sex) { infos->sex = sex; }

    // Sets player's level
    void setLevel(int level) { infos->level = level; }
    // Sets players Xp count
    void setXp(uint64_t xp, uint64_t xpLevelFloor, uint64_t xpNextLevelFloor);
    // Adds to players Xp count
    void addXp(uint64_t xpDelta) { infos->xp += xpDelta; };

    // Loads player's inventory from an InventoryContentMessage
    void loadInventory(sp<InventoryContentMessage> icMsg);
    // Adds an item to the player's inventory
    void addItem(int itemUID, int itemGID, int quantity);
    // Sets an item in the player's inventory
    void setItemQuantity(int itemUID, int quantity);
    // Removes an item from the player's inventory
    void removeItem(int itemUID);
    // Sets the player's kamas count
    void setKamas(uint64_t kamas) { infos->kamas = kamas; };

    // Sets player's weight
    void setWeight(int weight) { infos->weight = weight; };
    // Sets player's maximum weight
    void setMaxWeight(int maxWeight) { infos->maxWeight = maxWeight; };
    // Gets player's weight
    int getWeight() { return infos->weight; };
    // Gets player's maximum weight
    int getMaxWeight() { return infos->maxWeight; };

    // Loads player's jobs from a JobDescriptionMessage
    void loadJobs(sp<JobDescriptionMessage> jdMsg);
    // Sets a player's job's level
    void setJobLevel(int jobId, int newLevel);
    // Adds a job to the player's
    void addJob(JobDescription job);
    // Updates a player's job Xp count
    void updateJobXp(JobExperience jobXp);

    // Function to launch when the character is fully loaded
    void loadingFinished() { this->fullyLoaded = true; sendCharacterInformationsMessage(); };

    // Sends message for character's updates to the API clients
    void sendJobsXpMessage(vector<int> jobsids);
    void sendJobsInformationsMessage(vector<int> jobsids);
    void sendCharacterLevelMessage();
    void sendCharacterXpMessage();
    void sendCharacterInformationsMessage();
    void sendItemsAddMessage(vector<int> itemsId);
    void sendItemsRemoveMessage(vector<int> itemsId);
    void sendInventoryWeightMessage();
    void sendKamasMessage();

    // Checks if the player's jobs allow it to use the skillId 
    bool hasSkill(int skillId);
    // Returns the skillId skill's range 
    int getSkillRange(int skillId);

    // DofusBotUnit
    DofusBotUnit* dofusBot = nullptr;

protected:
    // Informations about the played character
    sp<PlayedCharacterInformations> infos;

    // Path to the json file containing skills' data
    string skillsFile_path = "database/skills/json/Skills.json";
    // Loads skills from the skillFile
    void loadSkills();
    // Maps the skillId to its SkillInformations
    unordered_map<int, sp<SkillInformations>> skills;

    // True if the player's inforamtions are fully loaded
    bool fullyLoaded = false;
};

#endif