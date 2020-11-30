#include "APITypeHandler.h"
#include "APITypesIncludes.h"

APITypeHandler * APITypeHandler::typeHandler = nullptr;

APITypeHandler::APITypeHandler() {
	id_to_builder[ServerInformations::typeId] 	= make_shared<ServerInformations>;
	id_to_builder[CharacterInformations::typeId] 	= make_shared<CharacterInformations>;

	id_to_builder[SkillInformations::typeId] 	        = make_shared<SkillInformations>;
	id_to_builder[JobInformations::typeId]   	        = make_shared<JobInformations>;
	id_to_builder[PlayedCharacterInformations::typeId]  = make_shared<PlayedCharacterInformations>;
	id_to_builder[ItemInformations::typeId]             = make_shared<ItemInformations>;
}

APITypeHandler * APITypeHandler::getInstance() {
    if(!APITypeHandler::typeHandler)
        APITypeHandler::typeHandler = new APITypeHandler();

    return APITypeHandler::typeHandler;
}

sp<APIType> APITypeHandler::getTypeById(int id) {
    auto typeIt = id_to_builder.find(id);

    if(typeIt != id_to_builder.end())
        return typeIt->second();
    else
        return nullptr;
} 