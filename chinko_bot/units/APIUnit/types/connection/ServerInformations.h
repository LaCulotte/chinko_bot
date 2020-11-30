#ifndef SERVERINFORMATIONS_H
#define SERVERINFORMATIONS_H

#include "APIType.h"

class ServerInformations : public APIType {
public:
    // Constructor
    ServerInformations() : APIType() {};
    // Copy constructor
    ServerInformations(const ServerInformations& other) = default;

    // Copy operator
    virtual ServerInformations& operator=(const ServerInformations& other) = default;
    // Destructor
    virtual ~ServerInformations() = default;
  
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