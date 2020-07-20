#include "AuthentificationManager.h"

AuthentificationManager::AuthentificationManager() {
    // Sets credentials default values
    username = "None";
    password = "None";
}

AuthentificationManager::AuthentificationManager(string username, string password) {
    // Sets credentials
    setCredentials(username, password);
}

void AuthentificationManager::setCredentials(string username, string password) {
    this->username = username;
    this->password = password;
}

// TO rename
bool AuthentificationManager::beginAuthentification() {
    // Checks if the bot is launched
    if(!bot) {
        Logger::write("Cannot begin authentification if no BotUnit was linked to the AuthentificationManager.", LOG_WARNING);
        return false;
    }

    // Warn the user if the credentials are unintialized
    if(username == "None" && password == "None"){
        Logger::write("Credentials have most likely not be initialized.", LOG_WARNING);
        Logger::write("Current username : " + username + "; Current password : " + password, LOG_WARNING);
    }

    // Get connectionUnit's ID
    bot->connectionUnitId = bot->getMessageInterfaceOutId<ConnectionUnit>();
    if(bot->connectionUnitId == -1) {
        // Error if there is no ConnectionUnit attached to the bot
        Logger::write("Cannot begin authentification : there is no ConnectionUnit.", LOG_ERROR);
        return false;
    }

    // Checks if the saved address and port are actually initialized
    if(authentificationServerAddress == "" || authentificationServerPort == -1){
        Logger::write("Cannot begin authentification : no authentification server address or port has been specified.", LOG_ERROR);
        return false;
    }

    // Builds a new connection
    sp<DofusClientConnection> connection(new DofusClientConnection());

    // Asks the ConnectionUnit to manage the new connection and connect it to the authentification server
    bot->sendMessage(make_shared<ConnectionRequestMessage>(connection, authentificationServerAddress, authentificationServerPort), bot->connectionUnitId);
    // Disables auto connect to avoid being "softlocked" to a server that we cannot connect to
    this->autoConnect = false;

    return true;
}

bool AuthentificationManager::beginAuthentification(string address, int port) {
    // Checks if the bot is launched
    if(!bot) {
        Logger::write("Cannot begin authentification if no BotUnit was linked to the AuthentificationManager.", LOG_WARNING);
        return false;
    }

    // Warn the user if the credentials are unintialized
    if(username == "None" && password == "None"){
        Logger::write("Credentials have most likely not be initialized.", LOG_WARNING);
        Logger::write("Current username : " + username + "; Current password : " + password, LOG_WARNING);
    }

    // Get connectionUnit's ID
    bot->connectionUnitId = bot->getMessageInterfaceOutId<ConnectionUnit>();
    if(bot->connectionUnitId == -1) {
        // Error if there is no ConnectionUnit attached to the bot
        Logger::write("Cannot begin authentification : there is no ConnectionUnit.", LOG_ERROR);
        return false;
    }

    // Builds a new connection
    sp<DofusClientConnection> connection(new DofusClientConnection());

    // Asks the ConnectionUnit to manage the new connection and connect it to the authentification server
    bot->sendMessage(make_shared<ConnectionRequestMessage>(connection, address, port), bot->connectionUnitId);
    
    // Saves the authentification server's address and port
    authentificationServerAddress = address;
    authentificationServerPort = port;

    return true;
}

bool AuthentificationManager::setPublicKey(char *signedKey, int signedKeyLength) {
    // Gets verifyKey in string form
    string verifyKey_str = verify_key;

    // Gets verifyKey in BIO form
    BIO *verifyKey_bio = BIO_new(BIO_s_mem());
    BIO_write(verifyKey_bio, verifyKey_str.c_str(), verifyKey_str.size());

    // Gets verifyKey in RSA form
    RSA *verifyKey_rsa = RSA_new();
    verifyKey_rsa = PEM_read_bio_RSA_PUBKEY(verifyKey_bio, NULL, NULL, NULL);

    // Frees verify key's BIO form
    BIO_free(verifyKey_bio);

    //Decrypt public key in char array form
    unsigned char *publicKey_char = (unsigned char *) malloc(RSA_size(verifyKey_rsa));
    int publicKey_len = RSA_public_decrypt(signedKeyLength, (unsigned char *) signedKey, publicKey_char, verifyKey_rsa, RSA_PKCS1_PADDING);

    if(publicKey_len < 0) {
        Logger::write("Could not decrypt sent public key. Check if the verify key in AuthentificationManager.h is still up to date.", LOG_ERROR);
        return false;
    }

    // Gets public key in string form
    string publicKey_str_temp = base64_encode(publicKey_char, publicKey_len);
    // Gets it shaped for the transformation into RSA form
    string publicKey_str = "-----BEGIN PUBLIC KEY-----\n";

    for(int i = 0; i < publicKey_str_temp.size(); i+=76) 
        publicKey_str += publicKey_str_temp.substr(i, 76) + '\n';
    
    publicKey_str += "-----END PUBLIC KEY-----\n";

    // Gets public key in BIO form
    BIO *publicKey_bio = BIO_new_mem_buf(publicKey_str.c_str(), publicKey_str.size());

    // Gets public key in RSA form
    publicKey = RSA_new();
    publicKey = PEM_read_bio_RSA_PUBKEY(publicKey_bio, NULL, NULL, NULL);

    return true;
}

void AuthentificationManager::generateAESKey(int size) {
    // Generate a string of random bytes  
    AESKey = "";

    for(int i = 0; i < size; i++) 
        AESKey += (char) rand() % 256;
}

string AuthentificationManager::cipherCredentialsRSA(string salt) {
    // TODO : take certificate, token, etc into account

    string toCipher = "";

    // Checks if salt is correct
    if(salt.size() != 32) {
        Logger::write("Salt size is not 32 Bytes. Cannot cipher credentials.", LOG_ERROR);
        return "";
    }

    // Builds a string of all the elements to cipher with RSA
    toCipher += salt;
    toCipher += AESKey;
    toCipher += (char) username.size();
    toCipher += username;
    toCipher += password;

    // Checks if the RSA public key has been initialiazed
    if(!publicKey) {
        Logger::write("RSA public key was not initialized. Cannot cipher credentials", LOG_ERROR);
        return "";
    }

    // Ciphering
    char *cipheredCredentials = (char *) malloc(RSA_size(publicKey));
    int cipheredLen = RSA_public_encrypt(toCipher.size(), (unsigned char *) toCipher.c_str(),  (unsigned char *) cipheredCredentials, publicKey, RSA_PKCS1_PADDING);

    // Checks for eventual errors
    if(cipheredLen <= 0) {
        Logger::write("Could not cipher credentials.", LOG_ERROR);
        return "";
    }

    // Returns ciphered credentials
    return string(cipheredCredentials, cipheredLen);

}

sp<IdentificationMessage> AuthentificationManager::generateIdentificationMessage(char *signedKey, int signedKeyLen, string salt) {
    // Decipher and sets public key
    if(!setPublicKey(signedKey, signedKeyLen)){
        Logger::write("Public key decryption fail.", LOG_ERROR);
        return nullptr;
    }
    
    // Generate AES key
    generateAESKey();
    // Cipher credentials
    string cipheredCredentials = cipherCredentialsRSA(salt);

    // Builds IdentificationMessage
    sp<IdentificationMessage> idMsg (new IdentificationMessage());
    idMsg->credentials = vector<char>(cipheredCredentials.begin(), cipheredCredentials.end());
    idMsg->autoconnect = this->autoConnect;
    
    return idMsg;   
}

sp<ClientKeyMessage> AuthentificationManager::generateClientKeyMessage() {
    // Builds and return ClientKeyMessage
    return make_shared<ClientKeyMessage>();
}

// TODO : remove
void AuthentificationManager::interruptAuthentification() {
    bot->sendMessage(make_shared<DisconnectRequestMessage>((vector<int>) {dofusConnectionId}), bot->connectionUnitId);
    dofusConnectionId = -1;
    username = "None";
    password = "None";
}

bool AuthentificationManager::decodeAndSetTicket(string encodedTicket) {
    // Checks if AES key is correct
    if(AESKey.size() != 32) {
        Logger::write("AES key must be 32 Bytes long. It is currently : " + to_string(AESKey.size()) + " Bytes long.", LOG_ERROR);
        return false;
    }

    // Variables initialization
    unsigned char *encodedTicket_char = (unsigned char *) encodedTicket.c_str();
    int encodedSize = encodedTicket.size();
    unsigned char *decodedTicket_char = (unsigned char *) calloc(encodedSize, sizeof(unsigned char));

    // AES_Key typed variable initialization
    AES_KEY aes_key;
    unsigned char *AESKey_char = (unsigned char *) AESKey.c_str();
    unsigned char *IV = (unsigned char *) calloc(encodedSize, sizeof(unsigned char));
    memcpy(IV, AESKey_char, encodedSize);

    if(AES_set_decrypt_key(AESKey_char, 256, &aes_key) != 0) {
        Logger::write("Error, cannot set AES decrypt key", LOG_ERROR);
        return false;
    }
    // Decrypts ticket
    AES_cbc_encrypt(encodedTicket_char, decodedTicket_char, encodedSize, &aes_key, IV, AES_DECRYPT);

    clientTicket = (string) (char *) decodedTicket_char;

    return true;
}

bool AuthentificationManager::connectGameServer(string address, int port) {
    // Checks if the client ticket has been initialized
    if(clientTicket.size() == 0) {
        Logger::write("Cannot connect to game server without a client ticket", LOG_ERROR);
        return false;
    }

    // Disconnects from the authentification server
    bot->sendMessage(make_shared<DisconnectRequestMessage>((vector<int>) {dofusConnectionId}), bot->connectionUnitId);

    // Asks for a connection to the game server
    sp<DofusClientConnection> gameServerConnection (new DofusClientConnection());
    bot->sendMessage(make_shared<ConnectionRequestMessage>(gameServerConnection, address, port), bot->connectionUnitId);

    return true;
}

// TODO : remove
void AuthentificationManager::interruptConnectGameServer() {
    bot->sendMessage(make_shared<DisconnectRequestMessage>((vector<int>) {dofusConnectionId}), bot->connectionUnitId);
    dofusConnectionId = -1;
    clientTicket = "";
}

sp<AuthenticationTicketMessage> AuthentificationManager::generateAuthenticationTicketMessage() {
    // Checks if the client ticket has been initialized
    if(clientTicket.size() == 0) {
        Logger::write("Cannot generate AuthenticationTicketMessage without a ticket", LOG_ERROR);
        return nullptr;
    }

    // Builds AuthenticationTicketMessage
    sp<AuthenticationTicketMessage> atMsg(new AuthenticationTicketMessage());
    atMsg->ticket = clientTicket;

    return atMsg;
}

sp<CheckIntegrityMessage> AuthentificationManager::generateCheckIntegrityMessage() {
    // Builds CheckIntegrityMessage
    return make_shared<CheckIntegrityMessage>();
}

// TODO : remove
bool AuthentificationManager::sendCharactersListRequestMessage() {
    sp<CharactersListRequestMessage> clrMsg(new CharactersListRequestMessage());
    return bot->sendMessage(make_shared<SendPacketRequestMessage>(clrMsg, dofusConnectionId), bot->connectionUnitId);
}

// TODO : remove
bool AuthentificationManager::sendCharacterSelectionMessage(uint64_t id) {
    sp<CharacterSelectionMessage> csMsg(new CharacterSelectionMessage());
    csMsg->id = id;
    
    return bot->sendMessage(make_shared<SendPacketRequestMessage>(csMsg, dofusConnectionId), bot->connectionUnitId);
}