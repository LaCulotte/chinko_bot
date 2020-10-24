#include "APITypeHandler.h"
#include "APITypesIncludes.h"

APITypeHandler * APITypeHandler::typeHandler = nullptr;

APITypeHandler::APITypeHandler() {
	id_to_builder[ServerSelectInformations::typeId] 	= make_shared<ServerSelectInformations>;
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