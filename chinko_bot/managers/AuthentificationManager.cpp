#include "AuthentificationManager.h"

AuthentificationManager::AuthentificationManager() {
    username = "None";
    password = "None";
}

AuthentificationManager::AuthentificationManager(string username, string password) {
    setCredentials(username, password);
}

void AuthentificationManager::setCredentials(string username, string password) {
    this->username = username;
    this->password = password;
}

bool AuthentificationManager::beginAuthentification(string address, int port) {
    if(!bot) {
        Logger::write("Cannot begin authentification if no BotUnit was linked to the AuthentificationManager.", LOG_WARNING);
        return false;
    }

    if(username == "None" && password == "None"){
        Logger::write("Credentials most likely have not be initialized.", LOG_WARNING);
        Logger::write("Current username : " + username + "; Current password : " + password, LOG_WARNING);
    }

    bot->connectionUnitId = bot->getMessageInterfaceOutId<ConnectionUnit>();
    if(bot->connectionUnitId == -1) {
        Logger::write("Cannot begin authentification if there is no ConnectionUnit.", LOG_ERROR);
        return false;
    }

    sp<DofusClientConnection> connection( new DofusClientConnection());

    bot->sendMessage(make_shared<ConnectionRequestMessage>(connection, address, port), bot->connectionUnitId);

    return true;
}