#ifndef AUTHENTIFICATION_MANAGER_H
#define AUTHENTIFICATION_MANAGER_H

#include "AuthentificationFrame.h"
#include "DofusBotUnit.h"

#include "DofusClientConnection.h"
#include "ConnectionUnit.h"

#include "ConnectionRequestMessage.h"
#include "SendPacketRequestMessage.h"
#include "IdentificationMessage.h"
#include "ClientKeyMessage.h"

// enum State_AuthentificationManager {
//     state_none = 0,
//     state_connected,
//     state_authentified
// };

#include "base64.h"
#include "openssl/rsa.h"
#include "openssl/bio.h"
#include "openssl/pem.h"

#define verify_key "-----BEGIN PUBLIC KEY-----\nMIIBUzANBgkqhkiG9w0BAQEFAAOCAUAAMIIBOwKCATIAgucoka9J2PXcNdjcu6CuDmgteIMB+rih\n2UZJIuSoNT/0J/lEKL/W4UYbDA4U/6TDS0dkMhOpDsSCIDpO1gPG6+6JfhADRfIJItyHZflyXNUj\nWOBG4zuxc/L6wldgX24jKo+iCvlDTNUedE553lrfSU23Hwwzt3+doEfgkgAf0l4ZBez5Z/ldp9it\n2NH6/2/7spHm0Hsvt/YPrJ+EK8ly5fdLk9cvB4QIQel9SQ3JE8UQrxOAx2wrivc6P0gXp5Q6bHQo\nad1aUp81Ox77l5e8KBJXHzYhdeXaM91wnHTZNhuWmFS3snUHRCBpjDBCkZZ+CxPnKMtm2qJIi57R\nslALQVTykEZoAETKWpLBlSm92X/eXY2DdGf+a7vju9EigYbX0aXxQy2Ln2ZBWmUJyZE8B58CAwEA\nAQ==\n-----END PUBLIC KEY-----\n"


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

    void setCredentials(string username, string password);
    void setBot(DofusBotUnit *bot) { this->bot = bot; };

    bool beginAuthentification(string server, int port);
    void interruptAuthentification();

    // void resetState();
    // void setState(State_AuthentificationManager new_state);

    void setDofusConnectionId(int id) { dofusConnectionId = id; };


    bool sendIdentificationMessage(char * signedKey, int signedKeyLength, string salt);
    bool sendClientKeyMessage();

    void setAESKey(string AESKey) { this->AESKey = AESKey; };
    string getAESKey() { return AESKey; };

protected:
    string username;
    string password;

    int dofusConnectionId;

    DofusBotUnit *bot = nullptr;

    bool setPublicKey(char *signedKey, int signedKeyLength);
    RSA *publicKey = nullptr;
    // State_AuthentificationManager current_state = state_none;

    void generateAESKey(int size = 32);
    string AESKey;

    string cipherCredentialsRSA(string salt);
};

#endif