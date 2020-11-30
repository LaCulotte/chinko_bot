#ifndef API_BOTCONNECTION_FRAME_H
#define API_BOTCONNECTION_FRAME_H

#include "APIFrame.h"

#include "QueryCharacterSelectionMessage.h"
#include "QueryServerSelectionMessage.h"
#include "CharacterSelectionMessage.h"
#include "ServerSelectionMessage.h"
#include "BeginAuthentificationMessage.h"

#include "APIHelloMessage.h"

class APIBotConnectionFrame : public APIFrame {
public :
    // Constructor
    APIBotConnectionFrame() : APIFrame() {};
    // Copy constructor
    APIBotConnectionFrame(const APIBotConnectionFrame& other) = default;

    // Copy operator
    APIBotConnectionFrame& operator=(const APIBotConnectionFrame& other) = default;
    // Destructor
    ~APIBotConnectionFrame() = default;

    virtual bool computeMessage(sp<Message> message, int srcId) override;

protected:
    unordered_map<int, string> breed_idToString = {    {1, "Feca"}, {2, "Osamodas"},
                                                        {3, "Enutrof"}, {4, "Sram"},
                                                        {5, "Xelor"}, {6, "Ecaflip"},
                                                        {7, "Eniripsa"}, {8, "Iop"},
                                                        {9, "Cra"}, {10, "Sadida"},
                                                        {11, "Sacrier"}, {12, "Pandawa"},
                                                        {13, "Roublard"}, {14, "Zobal"},
                                                        {15, "Steamer"}, {16, "Eliotrope"},
                                                        {17, "Huppermage"}, {18, "Ouginiak"}};

    unordered_map<int, string> server_idToString = {{50, "Ombre"}, {210, "Merkator"}};
};

#endif