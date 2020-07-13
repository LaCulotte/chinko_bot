#ifndef AUTHENTIFICATION_MANAGER_H
#define AUTHENTIFICATION_MANAGER_H

#include "DofusBotUnit.h"

#include "DofusClientConnection.h"
#include "ConnectionUnit.h"

#include "ConnectionRequestMessage.h"
#include "SendPacketRequestMessage.h"
#include "IdentificationMessage.h"
#include "ClientKeyMessage.h"

#include "base64.h"
#include "openssl/rsa.h"
#include "openssl/bio.h"
#include "openssl/pem.h"
#include "openssl/aes.h"

// TODO : le mettre dans un fichier de config
// Current version : 2.55.15.0.0
#define verify_key "-----BEGIN PUBLIC KEY-----\nMIIBUzANBgkqhkiG9w0BAQEFAAOCAUAAMIIBOwKCATIAgucoka9J2PXcNdjcu6CuDmgteIMB+rih\n2UZJIuSoNT/0J/lEKL/W4UYbDA4U/6TDS0dkMhOpDsSCIDpO1gPG6+6JfhADRfIJItyHZflyXNUj\nWOBG4zuxc/L6wldgX24jKo+iCvlDTNUedE553lrfSU23Hwwzt3+doEfgkgAf0l4ZBez5Z/ldp9it\n2NH6/2/7spHm0Hsvt/YPrJ+EK8ly5fdLk9cvB4QIQel9SQ3JE8UQrxOAx2wrivc6P0gXp5Q6bHQo\nad1aUp81Ox77l5e8KBJXHzYhdeXaM91wnHTZNhuWmFS3snUHRCBpjDBCkZZ+CxPnKMtm2qJIi57R\nslALQVTykEZoAETKWpLBlSm92X/eXY2DdGf+a7vju9EigYbX0aXxQy2Ln2ZBWmUJyZE8B58CAwEA\nAQ==\n-----END PUBLIC KEY-----\n"


// TODO : rename : ConnectionManager
//        ou ajouter un autre manager : GameServerConnectionManager
class DofusBotUnit;
class AuthentificationManager {
public:
    // Constructor
    AuthentificationManager();
    // Constructor with username and password initialization
    AuthentificationManager(string username, string password);
    // Copy constructor
    AuthentificationManager(const AuthentificationManager& other) = default;

    // Copy operator
    AuthentificationManager& operator=(const AuthentificationManager& other) = default;
    // Destructor
    ~AuthentificationManager() = default;

    // Credentials setter
    void setCredentials(string username, string password);
    // Bot setter
    void setBot(DofusBotUnit *bot) { this->bot = bot; };

    // TODO : renommer fonction : retryAuthentification
    bool beginAuthentification();
    // Begins authentification. 'server' and 'port' are a dofus' authentification server. Credentials must be set.
    bool beginAuthentification(string server, int port);
    // TODO : remove
    // Stops authentification : not used
    void interruptAuthentification();

    // Decodes and saves ticket sent by server with the provided 'verify_key'
    bool decodeAndSetTicket(string encodedTicket);
    // Connects to 'address':'port' that should be a dofus game server
    bool connectGameServer(string address, int port);
    // TODO : remove
    // Stops game server connection : not used
    void interruptConnectGameServer();

    // Dofus connection's id
    void setDofusConnectionId(int id) { dofusConnectionId = id; };

    // TODO : rename avec build plutot que generate
    // Builds IdentificationMessage
    sp<IdentificationMessage> generateIdentificationMessage(char * signedKey, int signedKeyLength, string salt);
    // Builds ClientKeyMessage
    sp<ClientKeyMessage> generateClientKeyMessage();

    // Builds AuthentificationTicketMessage
    sp<AuthentificationTicketMessage> generateAuthentificationTicketMessage();
    // Builds CheckIntegrityMessage
    sp<CheckIntegrityMessage> generateCheckIntegrityMessage();
    // TODO : remove
    // Sends CharacterListRequestMessage : not used
    bool sendCharactersListRequestMessage();
    // TODO : remove
    // Sends CharacterSelectionMessage : not used
    bool sendCharacterSelectionMessage(uint64_t id);

    // AESKey setter
    void setAESKey(string AESKey) { this->AESKey = AESKey; };
    // AESKey getter
    string getAESKey() { return AESKey; };

protected:
    // User's username
    string username;
    // User's password
    string password;

    // Dofus' Authentification server's address
    string authentificationServerAddress = "";
    // Dofus' Authentification server's port
    int authentificationServerPort = -1;

    // Id of the dofus connection. First to the authentification server, then to the Game Server
    // TODO : check si ca prend d'abord l'authentification server
    // TODO : remove (not used?)
    int dofusConnectionId = -1;

    // Pointer to the bot
    DofusBotUnit *bot = nullptr;

    // Computes and sets public RSA key
    bool setPublicKey(char *signedKey, int signedKeyLength);
    // RSA public key
    RSA *publicKey = nullptr;

    // Generates and sets AES key
    void generateAESKey(int size = 32);
    // AES key
    string AESKey;

    // Encrypt credentials qith the public RSA key
    string cipherCredentialsRSA(string salt);

    // Client's authentification ticket
    string clientTicket = "";

    // Does the client autoconnects to the game server ?
    bool autoConnect = true;
};

#endif