#ifndef SERVERSELECTINFORMATION_H
#define SERVERSELECTINFORMATION_H

#include "APIType.h"

class ServerSelectInformations : public APIType {
public:
    // Constructor
    ServerSelectInformations() : APIType() {};
    // Copy constructor
    ServerSelectInformations(const ServerSelectInformations& other) = default;

    // Copy operator
    virtual ServerSelectInformations& operator=(const ServerSelectInformations& other) = default;
    // Destructor
    virtual ~ServerSelectInformations() = default;
  
    // Returns the type's id
    virtual unsigned int getId() { return typeId; };
    // Type's id
    static const unsigned int typeId = 1;

    // Turns raw data into the usable data (type's attributes)
    virtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;
    // Turns the type's attributes into raw data
    virtual bool serialize(shared_ptr<MessageDataBuffer> output) override;

    int id;
    string name;
    int charactersCount;
    int slotsCount;
    int status;
    bool isSelectable;

};

#endif